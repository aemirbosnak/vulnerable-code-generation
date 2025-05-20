//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    char *translation;
} WordPair;

int compareWordPair(const void *a, const void *b) {
    const WordPair *wa = (const WordPair *)a;
    const WordPair *wb = (const WordPair *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    // Load the alien language dictionary
    FILE *dictionary = fopen("alien-dictionary.txt", "r");
    if (dictionary == NULL) {
        fprintf(stderr, "Error: Unable to open alien language dictionary.\n");
        return EXIT_FAILURE;
    }

    // Read the number of words in the dictionary
    int num_words;
    fscanf(dictionary, "%d", &num_words);

    // Allocate memory for the word pairs
    WordPair *words = calloc(num_words, sizeof(WordPair));
    if (words == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for word pairs.\n");
        return EXIT_FAILURE;
    }

    // Read the word pairs from the dictionary
    for (int i = 0; i < num_words; i++) {
        // Read the alien word
        words[i].word = calloc(MAX_WORD_LENGTH, sizeof(char));
        if (words[i].word == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for alien word.\n");
            return EXIT_FAILURE;
        }
        fscanf(dictionary, "%s", words[i].word);

        // Read the translation
        words[i].translation = calloc(MAX_WORD_LENGTH, sizeof(char));
        if (words[i].translation == NULL) {
            fprintf(stderr, "Error: Unable to allocate memory for translation.\n");
            return EXIT_FAILURE;
        }
        fscanf(dictionary, "%s", words[i].translation);
    }

    // Close the dictionary file
    fclose(dictionary);

    // Sort the word pairs by alien word
    qsort(words, num_words, sizeof(WordPair), compareWordPair);

    // Prompt the user for an alien sentence
    printf("Enter an alien sentence: ");
    char sentence[1024];
    scanf("%s", sentence);

    // Translate the sentence word by word
    char translation[1024] = "";
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        // Find the translation of the word
        WordPair *result = bsearch(word, words, num_words, sizeof(WordPair), compareWordPair);
        if (result != NULL) {
            strcat(translation, result->translation);
            strcat(translation, " ");
        } else {
            strcat(translation, word);
            strcat(translation, " ");
        }
        word = strtok(NULL, " ");
    }

    // Print the translation
    printf("Translation: %s\n", translation);

    // Free the memory allocated for the word pairs
    for (int i = 0; i < num_words; i++) {
        free(words[i].word);
        free(words[i].translation);
    }
    free(words);

    return EXIT_SUCCESS;
}