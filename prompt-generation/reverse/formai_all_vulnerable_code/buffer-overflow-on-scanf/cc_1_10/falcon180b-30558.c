//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} WordPair;

int main() {
    char input[MAX_WORD_LEN];
    char *translation;
    WordPair dictionary[MAX_WORDS];
    int numWords = 0;

    // Initialize dictionary with some basic words
    strcpy(dictionary[numWords].word, "hello");
    strcpy(dictionary[numWords].translation, "greetings");
    numWords++;

    strcpy(dictionary[numWords].word, "goodbye");
    strcpy(dictionary[numWords].translation, "farewell");
    numWords++;

    strcpy(dictionary[numWords].word, "thank you");
    strcpy(dictionary[numWords].translation, "gratitude");
    numWords++;

    strcpy(dictionary[numWords].word, "sorry");
    strcpy(dictionary[numWords].translation, "apology");
    numWords++;

    // Prompt user for input
    printf("Enter a word to translate: ");
    scanf("%s", input);

    // Search dictionary for word
    for (int i = 0; i < numWords; i++) {
        if (strcmp(input, dictionary[i].word) == 0) {
            printf("Translation: %s\n", dictionary[i].translation);
            return 0;
        }
    }

    // Word not found in dictionary
    printf("Translation not found.\n");
    return 1;
}