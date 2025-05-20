//GPT-4o-mini DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 1000

// Function to load dictionary from a file
int load_dictionary(const char *filename, char dictionary[][MAX_WORD_LENGTH]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening dictionary file");
        return -1;
    }
    
    int count = 0;
    while (fscanf(file, "%s", dictionary[count]) != EOF && count < DICTIONARY_SIZE) {
        count++;
    }
    fclose(file);
    return count;
}

// Function to check if a word is in the dictionary
int is_word_in_dictionary(const char *word, char dictionary[][MAX_WORD_LENGTH], int dict_size) {
    for (int i = 0; i < dict_size; i++) {
        if (strcasecmp(word, dictionary[i]) == 0) {
            return 1; // word found
        }
    }
    return 0; // word not found
}

// Function to clean and prepare a word for checking
void clean_word(const char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalnum(input[i])) {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0'; // Null terminate the cleaned word
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dictionary file> <text file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char dictionary[DICTIONARY_SIZE][MAX_WORD_LENGTH];
    int dict_size = load_dictionary(argv[1], dictionary);
    if (dict_size < 0) {
        return EXIT_FAILURE;
    }

    FILE *text_file = fopen(argv[2], "r");
    if (text_file == NULL) {
        perror("Error opening text file");
        return EXIT_FAILURE;
    }

    char buffer[1000];
    char word[MAX_WORD_LENGTH];
    while (fgets(buffer, sizeof(buffer), text_file) != NULL) {
        char *token = strtok(buffer, " \t\n");
        while (token != NULL) {
            clean_word(token, word);
            if (strlen(word) > 0 && !is_word_in_dictionary(word, dictionary, dict_size)) {
                printf("Misspelled word: %s\n", word);
            }
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(text_file);
    return EXIT_SUCCESS;
}