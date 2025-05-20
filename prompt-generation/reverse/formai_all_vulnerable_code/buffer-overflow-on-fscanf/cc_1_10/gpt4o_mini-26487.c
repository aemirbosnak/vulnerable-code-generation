//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 256
#define MAX_TRANSLATION_LEN 512
#define DICT_SIZE 100

typedef struct {
    char english[MAX_INPUT_LEN];
    char alien[MAX_INPUT_LEN];
} DictionaryEntry;

DictionaryEntry dictionary[DICT_SIZE];
int dictionary_count = 0;

// Function declarations
void load_dictionary(const char *filename);
void translate_to_alien(const char *input, char *output);
void read_input(char *buffer);
void display_translation(const char *translation);

int main() {
    char input[MAX_INPUT_LEN];
    char translation[MAX_TRANSLATION_LEN];

    printf("========================\n");
    printf("Welcome to the Alien Language Translator!\n");
    printf("========================\n");

    // Load dictionary from a file
    load_dictionary("alien_dictionary.txt");

    // Start translation process
    while (1) {
        printf("\nEnter a sentence in English (or type 'exit' to quit): ");
        read_input(input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        translate_to_alien(input, translation);
        display_translation(translation);
    }

    printf("Thank you for using the Alien Language Translator! Goodbye!\n");
    return 0;
}

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open dictionary file");
        exit(1);
    }

    while (fscanf(file, "%s %s", dictionary[dictionary_count].english, dictionary[dictionary_count].alien) == 2) {
        dictionary_count++;
        if (dictionary_count >= DICT_SIZE) {
            printf("Maximum dictionary size reached. Some entries may not have been loaded.\n");
            break;
        }
    }

    fclose(file);
    printf("Loaded %d entries into the dictionary.\n", dictionary_count);
}

void translate_to_alien(const char *input, char *output) {
    char *token;
    char translated_word[MAX_INPUT_LEN];
    output[0] = '\0'; // Initialize output

    // Tokenizing the input string to translate each word
    token = strtok((char *)input, " ");
    while (token != NULL) {
        int found = 0;

        // Search for the word in the dictionary
        for (int i = 0; i < dictionary_count; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                strcat(output, dictionary[i].alien);
                strcat(output, " "); // Add a space after the translated word
                found = 1;
                break;
            }
        }

        // If word not found, retain the original word
        if (!found) {
            strcat(output, token);
            strcat(output, " ");
        }

        token = strtok(NULL, " "); // Continue to the next word
    }

    // Remove trailing space
    if (output[strlen(output) - 1] == ' ') {
        output[strlen(output) - 1] = '\0';
    }
}

void read_input(char *buffer) {
    fgets(buffer, MAX_INPUT_LEN, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}

void display_translation(const char *translation) {
    printf("Translated to Alien Language: %s\n", translation);
}