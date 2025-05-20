//GPT-4o-mini DATASET v1.0 Category: Alien Language Translator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 256
#define DICTIONARY_SIZE 100

// Structure for a dictionary entry
typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} DictionaryEntry;

// Function prototypes
void load_dictionary(DictionaryEntry dictionary[], int *size);
void translate_line(const char *line, DictionaryEntry dictionary[], int size);
void translate_word(const char *word, DictionaryEntry dictionary[], int size);

int main() {
    DictionaryEntry dictionary[DICTIONARY_SIZE];
    int dictionary_size = 0;

    // Load the dictionary from the file
    load_dictionary(dictionary, &dictionary_size);

    // Infinite loop to accept user input
    char line[MAX_LINE_LENGTH];
    printf("Welcome to the Alien Language Translator!\n");
    printf("Enter a sentence to translate (or type 'exit' to quit):\n");

    while (1) {
        // Get user input
        printf("> ");
        fgets(line, sizeof(line), stdin);

        // Remove newline character from input
        line[strcspn(line, "\n")] = 0;

        // Exit condition
        if (strcmp(line, "exit") == 0) {
            printf("Exiting the translator. Goodbye!\n");
            break;
        }

        // Translate and output the result
        printf("Translation: ");
        translate_line(line, dictionary, dictionary_size);
        printf("\n");
    }

    return 0;
}

// Function to load the dictionary from a file
void load_dictionary(DictionaryEntry dictionary[], int *size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        perror("Could not open dictionary.txt");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %s", dictionary[*size].english, dictionary[*size].alien) == 2) {
        (*size)++;
        if (*size >= DICTIONARY_SIZE) {
            break;
        }
    }

    fclose(file);
}

// Function to translate a line of text
void translate_line(const char *line, DictionaryEntry dictionary[], int size) {
    char *token;
    char *line_copy = strdup(line); // Duplicate line to avoid modifying original
    token = strtok(line_copy, " "); // Split the line into words

    while (token != NULL) {
        translate_word(token, dictionary, size);
        token = strtok(NULL, " "); // Move to the next word
        if (token != NULL) {
            printf(" "); // Add space between translated words
        }
    }

    free(line_copy); // Free the duplicated line memory
}

// Function to translate a single word to the alien language
void translate_word(const char *word, DictionaryEntry dictionary[], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(word, dictionary[i].english) == 0) {
            printf("%s", dictionary[i].alien); // Found the translation
            return;
        }
    }
    // If no translation is found, just print the original word
    printf("%s", word);
}