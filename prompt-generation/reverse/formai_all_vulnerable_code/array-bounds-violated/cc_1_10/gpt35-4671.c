//FormAI DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_SIZE 100000
#define MAX_WORD_SIZE 50

char dictionary[DICTIONARY_SIZE][MAX_WORD_SIZE];
int dictionary_size = 0;

typedef struct {
    char word[MAX_WORD_SIZE];
    int line_number;
} error;

error errors[DICTIONARY_SIZE];
int error_count = 0;

// function to add a word to the dictionary
int add_word_to_dictionary(char* word) {
    // check if word already exists in the dictionary
    for (int i=0; i<dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return i;
        }
    }
    // add the new word to the dictionary
    strcpy(dictionary[dictionary_size], word);
    dictionary_size++;
    return dictionary_size-1;
}

// function to check if a word is spelled correctly
int check_spelling(char* word) {
    for (int i=0; i<dictionary_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return i;
        }
    }
    return -1;
}

// function to check a text file for spelling errors
void check_file(FILE* fp) {
    char line[1000], word[MAX_WORD_SIZE];

    int line_number = 0;
    while (fgets(line, 1000, fp) != NULL) {
        line_number++;

        char* token = strtok(line, " \n\t");
        while (token != NULL) {
            int result = check_spelling(token);
            if (result == -1) {
                // word is misspelled
                error e;
                strcpy(e.word, token);
                e.line_number = line_number;
                errors[error_count] = e;
                error_count++;

                // add word to dictionary
                add_word_to_dictionary(token);
            }
            token = strtok(NULL, " \n\t");
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        exit(1);
    }

    // load dictionary file
    FILE* dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file\n");
        exit(1);
    }
    char dict_word[MAX_WORD_SIZE];
    while (fgets(dict_word, MAX_WORD_SIZE, dict_file) != NULL) {
        dict_word[strlen(dict_word)-1] = '\0';  // remove newline character
        add_word_to_dictionary(dict_word);
    }
    fclose(dict_file);

    // check file for spelling errors
    check_file(fp);
    fclose(fp);

    // print out errors
    for (int i=0; i<error_count; i++) {
        printf("Error: '%s' on line %d\n", errors[i].word, errors[i].line_number);
    }

    return 0;
}