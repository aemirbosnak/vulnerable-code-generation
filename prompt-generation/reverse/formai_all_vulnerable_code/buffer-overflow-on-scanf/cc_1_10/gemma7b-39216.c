//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALIEN_LANGUAGE_SIZE 26

typedef struct AlienLanguageCharacter {
    char symbol;
    int translation;
} AlienLanguageCharacter;

AlienLanguageCharacter alienLanguageCharacters[ALIEN_LANGUAGE_SIZE] = {
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7},
    {'i', 8},
    {'j', 9},
    {'k', 10},
    {'l', 11},
    {'m', 12},
    {'n', 13},
    {'o', 14},
    {'p', 15},
    {'q', 16},
    {'r', 17},
    {'s', 18},
    {'t', 19},
    {'u', 20},
    {'v', 21},
    {'w', 22},
    {'x', 23},
    {'y', 24},
    {'z', 25}
};

int alienLanguageTranslate(char alienSymbol) {
    for (int i = 0; i < ALIEN_LANGUAGE_SIZE; i++) {
        if (alienLanguageCharacters[i].symbol == alienSymbol) {
            return alienLanguageCharacters[i].translation;
        }
    }

    return -1;
}

int main() {
    char alienSymbol;

    printf("Enter an alien symbol: ");
    scanf("%c", &alienSymbol);

    int translation = alienLanguageTranslate(alienSymbol);

    if (translation != -1) {
        printf("Translation: %d\n", translation);
    } else {
        printf("Error: symbol not found.\n");
    }

    return 0;
}