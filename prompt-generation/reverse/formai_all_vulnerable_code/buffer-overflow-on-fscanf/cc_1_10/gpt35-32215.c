//FormAI DATASET v1.0 Category: Spell checking ; Style: introspective
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICTIONARY_WORDS 50000

/**
 * This program is a spell checker that loads a dictionary of words and reads a text file.
 * It compares each word in the text file to the words in the dictionary and prints out any 
 * words that are not found in the dictionary. It also suggests alternative spellings for 
 * any misspelled words that are similar to words in the dictionary.
 */

typedef struct dict_entry {
    char word[MAX_WORD_LENGTH];
} dict_entry;

dict_entry dictionary[MAX_DICTIONARY_WORDS];
int num_words_in_dictionary = 0;

int load_dictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        strcpy(dictionary[num_words_in_dictionary].word, word);
        num_words_in_dictionary++;
    }
    fclose(file);
    return num_words_in_dictionary;
}

int is_word_in_dictionary(char *word) {
    int i;
    for (i = 0; i < num_words_in_dictionary; i++) {
        if (strcmp(word, dictionary[i].word) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_alpha(char c) {
    return isalpha(c) || c == '\'';
}

void to_lower_case(char *word) {
    int i;
    for (i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

int is_levenshtein_distance_one(char *word1, char *word2) {
    int len1 = strlen(word1), len2 = strlen(word2);
    if (len1 == len2) {
        int i, num_mismatches = 0;
        for (i = 0; i < len1; i++) {
            if (word1[i] != word2[i]) {
                num_mismatches++;
            }
            if (num_mismatches > 1) {
                return 0;
            }
        }
        return num_mismatches == 1;
    } else if (len1 - 1 == len2) {
        return is_levenshtein_distance_one(word2, word1);
    } else if (len1 == len2 - 1) {
        // insertion
        int i, j;
        for (i = 0, j = 0; i < len1 && j < len2; i++, j++) {
            if (word1[i] != word2[j]) {
                j++;
                if (i != j) {
                    return 0;
                }
            }
        }
        return 1;
    } else {
        return 0;
    }
}

void suggest_spelling(char *misspelled_word) {
    int i;
    char lowercase_misspelled_word[MAX_WORD_LENGTH];
    strcpy(lowercase_misspelled_word, misspelled_word);
    to_lower_case(lowercase_misspelled_word);
    printf("Did you mean:\n");
    for (i = 0; i < num_words_in_dictionary; i++) {
        char lowercase_dictionary_word[MAX_WORD_LENGTH];
        strcpy(lowercase_dictionary_word, dictionary[i].word);
        to_lower_case(lowercase_dictionary_word);
        if (is_levenshtein_distance_one(lowercase_misspelled_word, lowercase_dictionary_word)) {
            printf("- %s\n", dictionary[i].word);
        }
    }
}

void check_spelling(char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH], c;
    int i = 0, line_num = 1, num_misspelled_words = 0;
    while ((c = fgetc(file)) != EOF) {
        if (is_alpha(c)) {
            word[i++] = c;
        } else if (i > 0) {
            word[i] = '\0';
            i = 0;
            if (!is_word_in_dictionary(word)) {
                num_misspelled_words++;
                printf("Line %d, word %s not found in dictionary\n", line_num, word);
                suggest_spelling(word);
            }
        }
        if (c == '\n') {
            line_num++;
        }
    }
    fclose(file);
    printf("Finished checking spelling, found %d misspelled words\n", num_misspelled_words);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./spell_check dictionary.txt text.txt\n");
        return 1;
    }
    char *dictionary_filename = argv[1];
    char *text_filename = argv[2];
    num_words_in_dictionary = load_dictionary(dictionary_filename);
    check_spelling(text_filename);
    return 0;
}