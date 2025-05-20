//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum lengths for the word and dictionary size
#define MAX_WORD_LENGTH 100
#define DICTIONARY_SIZE 100

// Structure to hold the alien translation mappings
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} Translation;

// Function prototypes
void load_dictionary(const char *filename, Translation *dictionary, int *count);
void translate_word(const char *word, Translation *dictionary, int count);
void translate_sentence(const char *sentence, Translation *dictionary, int count);

// Main function
int main() {
    Translation dictionary[DICTIONARY_SIZE];
    int count = 0;
    
    // Load the dictionary file
    load_dictionary("dictionary.txt", dictionary, &count);

    // Get user input for translation
    char input[MAX_WORD_LENGTH * 10];  // Allow for longer sentences
    printf("Enter a sentence to translate to the alien language: ");
    fgets(input, sizeof(input), stdin);
    
    // Replace newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Translate the sentence to the alien language
    translate_sentence(input, dictionary, count);

    return 0;
}

// Function to load the dictionary from a file
void load_dictionary(const char *filename, Translation *dictionary, int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open dictionary file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dictionary[*count].english, dictionary[*count].alien) != EOF) {
        (*count)++;
        if (*count >= DICTIONARY_SIZE) {
            fprintf(stderr, "Dictionary size limit reached.\n");
            break;
        }
    }

    fclose(file);
}

// Function to translate a single word
void translate_word(const char *word, Translation *dictionary, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            printf("%s ", dictionary[i].alien);
            return;
        }
    }
    // If the word is not found in the dictionary, print the original word
    printf("%s ", word);
}

// Function to translate a sentence
void translate_sentence(const char *sentence, Translation *dictionary, int count) {
    char *token = strtok(sentence, " ");
    
    printf("Translation: ");
    while (token != NULL) {
        translate_word(token, dictionary, count);
        token = strtok(NULL, " ");
    }
    printf("\n");
}