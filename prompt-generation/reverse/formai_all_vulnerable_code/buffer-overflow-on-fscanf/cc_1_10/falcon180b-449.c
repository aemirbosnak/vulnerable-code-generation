//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char word[MAX_WORD_LENGTH];
    bool is_correct;
} Word;

void add_word(Word* words, int num_words, char* word) {
    if (num_words == MAX_WORDS) {
        printf("Error: Maximum number of words reached.\n");
        exit(1);
    }
    strcpy(words[num_words].word, word);
    words[num_words].is_correct = false;
    num_words++;
}

void load_dictionary(Word* words, int num_words, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word)!= EOF) {
        add_word(words, num_words, word);
    }
    fclose(file);
}

bool is_correct_word(Word* words, int num_words, char* word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return true;
        }
    }
    return false;
}

void spell_check(char* filename, Word* words, int num_words) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char word[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        int num_words_in_line = 0;
        char* token = strtok(line, " \t\r\n");
        while (token!= NULL) {
            if (strlen(token) > 0) {
                if (!isalpha(token[0])) {
                    printf("%s is not a word.\n", token);
                } else if (is_correct_word(words, num_words, token)) {
                    printf("%s is spelled correctly.\n", token);
                } else {
                    printf("%s is misspelled.\n", token);
                }
            }
            num_words_in_line++;
            if (num_words_in_line >= MAX_WORD_LENGTH) {
                printf("Too many words in line.\n");
                break;
            }
            token = strtok(NULL, " \t\r\n");
        }
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s dictionary.txt file.txt\n", argv[0]);
        exit(1);
    }
    Word words[MAX_WORDS];
    int num_words = 0;
    load_dictionary(words, num_words, argv[1]);
    spell_check(argv[3], words, num_words);
    return 0;
}