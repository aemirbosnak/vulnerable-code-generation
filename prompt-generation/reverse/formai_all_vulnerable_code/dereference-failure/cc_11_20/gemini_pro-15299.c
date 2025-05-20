//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct {
    char *word;
    char *translation;
} WordTranslation;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the dictionary file into an array of WordTranslation structs.
    FILE *dict_file = fopen(argv[1], "r");
    if (dict_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    int num_words;
    fscanf(dict_file, "%d", &num_words);

    WordTranslation *dict = malloc(num_words * sizeof(WordTranslation));
    if (dict == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_words; i++) {
        dict[i].word = malloc(MAX_WORD_LENGTH * sizeof(char));
        if (dict[i].word == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        dict[i].translation = malloc(MAX_WORD_LENGTH * sizeof(char));
        if (dict[i].translation == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        fscanf(dict_file, "%s %s", dict[i].word, dict[i].translation);
    }

    fclose(dict_file);

    // Read the input text from stdin and translate it.
    char input_text[1024];
    while (fgets(input_text, sizeof(input_text), stdin) != NULL) {
        // Tokenize the input text into words.
        char *token = strtok(input_text, " ");
        while (token != NULL) {
            // Lookup the translation of the word in the dictionary.
            int found = 0;
            for (int i = 0; i < num_words; i++) {
                if (strcmp(token, dict[i].word) == 0) {
                    printf("%s ", dict[i].translation);
                    found = 1;
                    break;
                }
            }

            // If the word was not found in the dictionary, print it as-is.
            if (!found) {
                printf("%s ", token);
            }

            token = strtok(NULL, " ");
        }

        printf("\n");
    }

    // Free the memory allocated for the dictionary.
    for (int i = 0; i < num_words; i++) {
        free(dict[i].word);
        free(dict[i].translation);
    }
    free(dict);

    return EXIT_SUCCESS;
}