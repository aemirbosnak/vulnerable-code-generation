//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char *english;
    char *alien;
} word_pair;

int main() {
    FILE *dictionary_file;
    word_pair words[MAX_WORDS];
    int num_words = 0;
    char input_word[MAX_WORD_LENGTH];
    char *alien_word = NULL;

    dictionary_file = fopen("dictionary.txt", "r");
    if (dictionary_file == NULL) {
        printf("Error opening dictionary file.\n");
        exit(1);
    }

    // Read in all the word pairs from the dictionary file
    while (fscanf(dictionary_file, "%s %s\n", words[num_words].english, words[num_words].alien)!= EOF) {
        num_words++;
    }

    fclose(dictionary_file);

    // Prompt the user for input
    printf("Enter a word to translate:\n");
    fgets(input_word, MAX_WORD_LENGTH, stdin);

    // Remove trailing newline character from input
    input_word[strcspn(input_word, "\n")] = '\0';

    // Find the matching word pair in the dictionary
    for (int i = 0; i < num_words; i++) {
        if (strcmp(input_word, words[i].english) == 0) {
            alien_word = words[i].alien;
            break;
        }
    }

    // If no matching word pair was found, print an error message
    if (alien_word == NULL) {
        printf("Error: \"%s\" not found in dictionary.\n", input_word);
        exit(1);
    }

    // Print the translation
    printf("Translation: %s\n", alien_word);

    return 0;
}