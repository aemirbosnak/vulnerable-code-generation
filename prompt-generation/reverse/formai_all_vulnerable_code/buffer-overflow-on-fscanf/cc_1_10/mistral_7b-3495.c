//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define DICTIONARY_SIZE 10000

char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
int dictionary_index = 0;

int load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    char word[MAX_WORD_LENGTH];
    if (!file) {
        perror("Could not open dictionary file");
        return 1;
    }
    while (fscanf(file, "%s", word) != EOF) {
        if (dictionary_index >= DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary is too small\n");
            fclose(file);
            return 1;
        }
        strcpy(dictionary[dictionary_index], word);
        dictionary_index++;
    }
    fclose(file);
    return 0;
}

int check_word(const char *word) {
    for (int i = 0; i < dictionary_index; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    if (load_dictionary("dictionary.txt") != 0) {
        return 1;
    }

    char input_word[MAX_WORD_LENGTH];
    while (fgets(input_word, MAX_WORD_LENGTH, stdin) != NULL) {
        input_word[strlen(input_word) - 1] = '\0'; // remove newline character
        if (check_word(input_word) == 0) {
            printf("Error: %s is not a valid word\n", input_word);
        }
    }

    return 0;
}