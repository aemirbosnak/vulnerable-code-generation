//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_SIZE 1000

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICT_SIZE];
int dict_size = 0;

// Function to load the alien language dictionary from a file
void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dictionary[dict_size].english, dictionary[dict_size].alien) == 2) {
        dict_size++;
        if (dict_size >= MAX_DICT_SIZE) {
            printf("Dictionary size limit reached.\n");
            break;
        }
    }

    fclose(file);
}

// Function to translate English to Alien language
void translate_to_alien(const char *input) {
    char word[MAX_WORD_LENGTH];
    char translated[MAX_WORD_LENGTH * 10] = ""; // To accumulate translated words
    const char *delimiters = " ,.!?\n";
    
    // Split the input string into words
    char *token = strtok(input, delimiters);
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < dict_size; i++) {
            if (strcmp(token, dictionary[i].english) == 0) {
                strcat(translated, dictionary[i].alien);
                strcat(translated, " "); // Add space between words
                found = 1;
                break;
            }
        }
        if (!found) {
            // If the word is not found, keep it as it is
            strcat(translated, token);
            strcat(translated, " ");
        }
        token = strtok(NULL, delimiters);
    }

    printf("Alien Translation: %s\n", translated);
}

// Function to write the alien language translation to a file
void write_translation_to_file(const char *filename, const char *translated_text) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", translated_text);
    fclose(file);
}

// Main function
int main() {
    load_dictionary("alien_dictionary.txt"); // Load dictionary from a file

    char input[256];
    printf("Enter a sentence in English: ");
    fgets(input, sizeof(input), stdin); // Read input from user

    translate_to_alien(input); // Perform translation

    // Ask the user if they want to save the translation
    char save_option;
    printf("Do you want to save the translation? (y/n): ");
    scanf(" %c", &save_option);

    if (save_option == 'y' || save_option == 'Y') {
        write_translation_to_file("translated_text.txt", input); // Save to file
        printf("Translation saved to translated_text.txt\n");
    } else {
        printf("Translation not saved.\n");
    }

    return 0;
}