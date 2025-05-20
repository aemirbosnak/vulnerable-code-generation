//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 30

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
} Word;

int main() {
    // Load the dictionary into an array of words
    FILE *dictionary = fopen("dictionary.txt", "r");
    if (dictionary == NULL) {
        printf("Error opening dictionary file.\n");
        return EXIT_FAILURE;
    }

    Word words[MAX_WORDS];
    int num_words = 0;
    while (fscanf(dictionary, "%s\n", words[num_words].word) != EOF) {
        num_words++;
    }
    fclose(dictionary);

    // Get the user's input
    printf("Enter a sentence to check for spelling errors:\n");
    char sentence[1000];
    fgets(sentence, sizeof(sentence), stdin);

    // Check each word in the sentence against the dictionary
    char *word = strtok(sentence, " \n.,:;?!");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < num_words; i++) {
            if (strcmp(word, words[i].word) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("The word '%s' is not in the dictionary.\n", word);
        }

        word = strtok(NULL, " \n.,:;?!");
    }

    printf("Spell check complete!\n");

    return EXIT_SUCCESS;
}