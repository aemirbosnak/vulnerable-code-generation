//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 10000

// Function declarations
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int max_words);
void to_lowercase(char *str);
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size);
void spell_check_file(const char *input_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary_file> <text_file>\n", argv[0]);
        return 1;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary, DICTIONARY_SIZE);
    
    if (dict_size < 0) {
        fprintf(stderr, "Error loading dictionary.\n");
        return 1;
    }

    spell_check_file(argv[2], dictionary, dict_size);
    
    return 0;
}

int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH], int max_words) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Unable to open dictionary file");
        return -1;
    }

    int count = 0;
    while (count < max_words && fscanf(file, "%s", dictionary[count]) == 1) {
        to_lowercase(dictionary[count]);
        count++;
    }

    fclose(file);
    return count;
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word is found in the dictionary
        }
    }
    return 0; // Word is not found
}

void spell_check_file(const char *input_filename, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    FILE *file = fopen(input_filename, "r");
    if (file == NULL) {
        perror("Unable to open text file");
        return;
    }

    char word[MAX_WORD_LENGTH];
    int line_number = 0;

    while (fscanf(file, "%s", word) == 1) {
        to_lowercase(word);
        line_number++;

        // Remove trailing punctuations from the word.
        char *ptr = word;
        while (*ptr) {
            if (ispunct(*ptr) || isspace(*ptr)) {
                *ptr = '\0';
                break;
            }
            ptr++;
        }

        // Check if the word is in the dictionary
        if (!is_word_in_dictionary(word, dictionary, dict_size)) {
            printf("Misspelled word: '%s' at line %d\n", word, line_number);
        }
    }

    fclose(file);
}