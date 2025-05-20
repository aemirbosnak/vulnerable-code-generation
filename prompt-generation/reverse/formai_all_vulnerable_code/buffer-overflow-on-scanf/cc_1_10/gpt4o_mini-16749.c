//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_DICT_SIZE 100

typedef struct {
    char *english;
    char *cat;
} DictionaryEntry;

DictionaryEntry dictionary[MAX_DICT_SIZE];
int dict_size = 0;

// Function prototypes
void load_dictionary(const char *filename);
void translate(const char *input);
char *to_cat(const char *word);
void free_dictionary();

int main() {
    char filename[MAX_WORD_LENGTH];
    char input[MAX_WORD_LENGTH * 10]; // Allow for multiple words

    printf("Welcome to the C Cat Language Translator!\n");
    printf("Please enter the dictionary file path: ");
    scanf("%s", filename);
    load_dictionary(filename);

    printf("\nEnter a sentence in English (type 'exit' to quit):\n");
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character if present
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0) {
            break;
        }

        translate(input);
    }

    free_dictionary();
    return 0;
}

void load_dictionary(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening dictionary file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%49s %49s", dictionary[dict_size].english, dictionary[dict_size].cat) != EOF) {
        dictionary[dict_size].english = strdup(dictionary[dict_size].english);
        dictionary[dict_size].cat = strdup(dictionary[dict_size].cat);
        dict_size++;
        if (dict_size >= MAX_DICT_SIZE) {
            break;
        }
    }

    fclose(file);
    printf("Dictionary loaded: %d entries found.\n", dict_size);
}

void translate(const char *input) {
    char *token = strtok(strdup(input), " "); // Duplicate input to tokenize
    printf("Translation: ");

    while (token) {
        char *translation = to_cat(token);
        if (translation) {
            printf("%s ", translation);
        } else {
            printf("%s ", token); // If no translation, print the original word.
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}

char *to_cat(const char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcasecmp(dictionary[i].english, word) == 0) {
            return dictionary[i].cat;
        }
    }
    return NULL; // Word not found in dictionary
}

void free_dictionary() {
    for (int i = 0; i < dict_size; i++) {
        free(dictionary[i].english);
        free(dictionary[i].cat);
    }
}