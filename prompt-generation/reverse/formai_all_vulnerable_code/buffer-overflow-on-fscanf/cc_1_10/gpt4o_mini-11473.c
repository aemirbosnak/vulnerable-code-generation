//GPT-4o-mini DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_LINE_LENGTH 256
#define DICTIONARY_SIZE 100

typedef struct {
    char english[MAX_WORD_LENGTH];
    char cat[MAX_WORD_LENGTH];
} DictionaryEntry;

void load_dictionary(DictionaryEntry dictionary[], int *size) {
    FILE *file = fopen("dictionary.txt", "r");
    if (!file) {
        perror("Failed to open dictionary file");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fscanf(file, "%s %s", dictionary[*size].english, dictionary[*size].cat) != EOF) {
        (*size)++;
        if (*size >= DICTIONARY_SIZE) {
            break;
        }
    }
    fclose(file);
}

char* translate_to_cat(const char *input, DictionaryEntry dictionary[], int size) {
    char *translated = malloc(MAX_LINE_LENGTH);
    if (!translated) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    translated[0] = '\0'; // Initialize empty string

    char *word = strtok(strdup(input), " ");
    while (word) {
        int found = 0;
        for (int i = 0; i < size; i++) {
            if (strcmp(word, dictionary[i].english) == 0) {
                strcat(translated, dictionary[i].cat);
                strcat(translated, " "); // Add a space after the translated word
                found = 1;
                break;
            }
        }
        if (!found) {
            strcat(translated, word);
            strcat(translated, " "); // Add the original word if not found
        }
        word = strtok(NULL, " ");
    }
    return translated;
}

int main() {
    DictionaryEntry dictionary[DICTIONARY_SIZE];
    int dictionary_size;

    load_dictionary(dictionary, &dictionary_size);

    char input[MAX_LINE_LENGTH];
    printf("Enter a sentence in English (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *translated = translate_to_cat(input, dictionary, dictionary_size);
        printf("Cat Language: %s\n", translated);

        free(translated);
    }

    return 0;
}