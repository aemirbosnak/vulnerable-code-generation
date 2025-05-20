//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct AlienLanguageWord {
    char *word;
    int meaning;
} AlienLanguageWord;

AlienLanguageWord alien_language_words[MAX_WORDS] = {
    {"Blorg", 1},
    {"Zork", 2},
    {"Flub", 3},
    {"Quux", 4},
    {"Snork", 5},
    {"Quag", 6},
    {"Zarg", 7},
    {"Zoar", 8},
    {"Blork's nest", 9},
    {"Snork's hole", 10}
};

int translate_alien_language(char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(word, alien_language_words[i].word) == 0) {
            return alien_language_words[i].meaning;
        }
    }

    return -1;
}

int main() {
    char alien_word[20];

    printf("Enter an alien word: ");
    scanf("%s", alien_word);

    int translation = translate_alien_language(alien_word);

    if (translation != -1) {
        printf("Translation: %d", translation);
    } else {
        printf("Word not found.");
    }

    return 0;
}