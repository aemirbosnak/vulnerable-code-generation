//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

typedef struct {
    char *alienWord;
    char *englishTranslation;
} WordPair;

int main() {
    // Initialize the dictionary.
    WordPair dictionary[] = {
        {"akla", "apple"},
        {"altu", "banana"},
        {"anfa", "cat"},
        {"aspa", "dog"},
        {"atka", "elephant"},
        {"afla", "fish"},
        {"agra", "grape"},
        {"ahla", "horse"},
        {"aima", "ice cream"},
        {"ajka", "juice"},
        {"alka", "kiwi"},
        {"amma", "mango"},
        {"anpa", "orange"},
        {"appa", "peach"},
        {"aqla", "queen"},
        {"arja", "rabbit"},
        {"aska", "strawberry"},
        {"atpa", "tiger"},
        {"auka", "umbrella"},
        {"avla", "violin"}
    };

    // Get the alien word from the user.
    char alienWord[MAX_WORD_LENGTH];
    printf("Enter the alien word: ");
    scanf("%s", alienWord);

    // Find the corresponding English translation in the dictionary.
    int i;
    char *englishTranslation = NULL;
    for (i = 0; i < sizeof(dictionary) / sizeof(WordPair); i++) {
        if (strcmp(alienWord, dictionary[i].alienWord) == 0) {
            englishTranslation = dictionary[i].englishTranslation;
            break;
        }
    }

    // Print the English translation.
    if (englishTranslation != NULL) {
        printf("The English translation is: %s\n", englishTranslation);
    } else {
        printf("The alien word is not in the dictionary.\n");
    }

    return 0;
}