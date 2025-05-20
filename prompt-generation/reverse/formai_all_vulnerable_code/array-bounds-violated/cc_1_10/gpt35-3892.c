//FormAI DATASET v1.0 Category: Spell checking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 50
#define MAX_DICT_WORDS 1000
#define DEFAULT_DICT_FILE "english_words.txt"

char dictionary[MAX_DICT_WORDS][MAX_WORD_LEN];
int num_words = 0;

void read_dictionary(char* dict_file) {
    FILE* file = fopen(dict_file, "r");
    if (!file) {
        fprintf(stderr, "Error: Failed to open dictionary file '%s'", dict_file);
        exit(EXIT_FAILURE);
    }
    char word[MAX_WORD_LEN];
    while (fgets(word, sizeof(word), file)) {
        // remove newline character at end of word
        int word_len = strlen(word);
        if (word[word_len-1] == '\n') {
            word[word_len-1] = '\0';
        }
        // add word to dictionary
        if (num_words < MAX_DICT_WORDS) {
            strcpy(dictionary[num_words++], word);
        } else {
            fprintf(stderr, "Warning: Maximum number of dictionary words reached\n");
        }
    }
    fclose(file);
}

void to_lowercase(char* word) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

int is_valid_word(char* word) {
    int i;
    for (i = 0; i < num_words; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void check_spelling(char* document_file) {
    FILE* file = fopen(document_file, "r");
    if (!file) {
        fprintf(stderr, "Error: Failed to open document file '%s'", document_file);
        exit(EXIT_FAILURE);
    }
    char word[MAX_WORD_LEN];
    int line_num = 1;
    while (fgets(word, sizeof(word), file)) {
        int word_len = strlen(word);
        // remove newline character at end of line
        if (word[word_len-1] == '\n') {
            word[word_len-1] = '\0';
        }
        // split line into individual words and check spelling
        char* token = strtok(word, " ");
        while (token != NULL) {
            to_lowercase(token);
            if (!is_valid_word(token)) {
                printf("Error: Line: %d, Word: '%s'\n", line_num, token);
            }
            token = strtok(NULL, " ");
        }
        line_num++;
    }
    fclose(file);
}

int main(int argc, char** argv) {
    char* dict_file = argc > 2 ? argv[1] : DEFAULT_DICT_FILE;
    char* document_file = argc > 1 ? argv[2] : NULL;
    read_dictionary(dict_file);
    if (document_file) {
        check_spelling(document_file);
    } else {
        printf("Usage: %s [dictionary_file] <document_file>\n", argv[0]);
    }
    return 0;
}