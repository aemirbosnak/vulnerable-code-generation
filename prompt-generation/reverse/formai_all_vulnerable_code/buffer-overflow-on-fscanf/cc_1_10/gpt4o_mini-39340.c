//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

void load_dictionary(char *filename, char dictionary[][MAX_WORD_LENGTH], int *word_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *word_count = 0;
    while (fscanf(file, "%s", dictionary[*word_count]) != EOF) {
        (*word_count)++;
    }

    fclose(file);
}

int check_word(const char *word, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1; // Word is found in dictionary
        }
    }
    return 0; // Word is not found in dictionary
}

void to_lowercase(char *word) {
    for (int i = 0; word[i]; i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += 'a' - 'A'; // Convert to lowercase
        }
    }
}

void spell_check(char *input_text, char dictionary[][MAX_WORD_LENGTH], int word_count) {
    char *token = strtok(input_text, " ,.!?\"\n");
    while (token) {
        char word[MAX_WORD_LENGTH];
        strncpy(word, token, MAX_WORD_LENGTH - 1);
        word[MAX_WORD_LENGTH - 1] = '\0'; // Ensure null-termination
        to_lowercase(word);

        if (!check_word(word, dictionary, word_count)) {
            printf("Misspelled word: %s\n", token);
        }

        token = strtok(NULL, " ,.!?\"\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary_file> <input_text_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char dictionary[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;
    
    load_dictionary(argv[1], dictionary, &word_count);
    
    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        fprintf(stderr, "Could not open input text file: %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    fseek(text_file, 0, SEEK_END);
    long file_size = ftell(text_file);
    fseek(text_file, 0, SEEK_SET);

    char *input_text = malloc(file_size + 1);
    if (input_text == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    fread(input_text, 1, file_size, text_file);
    input_text[file_size] = '\0'; // Null-terminate the string

    spell_check(input_text, dictionary, word_count);

    free(input_text);
    fclose(text_file);
    
    return 0;
}