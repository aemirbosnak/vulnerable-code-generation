//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Alien Language Structure
typedef struct AlienWord {
    char symbol;
    int phoneticValue;
} AlienWord;

// Alien Language Dictionary
AlienWord alienDictionary[] = {
    {'Z', 5}, {'X', 3}, {'Q', 7}, {'K', 2}, {'J', 4}, {'V', 6}, {'B', 1}, {'N', 8},
    {'M', 9}, {'L', 0}, {'P', 11}, {'R', 10}, {'S', 12}, {'T', 13}, {'W', 14}, {'E', 15},
    {'D', 16}, {'C', 17}, {'G', 18}, {'F', 19}, {'I', 20}, {'H', 21}, {'O', 22}, {'U', 23},
    {'Y', 24}, {'A', 25}
};

// Function to translate English word to Alien Language
void translateEnglishToAlien(char* englishWord) {
    int length = strlen(englishWord);
    printf("Translating '%s' to Alien Language:\n", englishWord);
    for (int i = 0; i < length; i++) {
        char currentSymbol = englishWord[i];
        // Translate English character to Alien Language
        AlienWord* currentAlienWord = NULL;
        for (int j = 0; j < sizeof(alienDictionary) / sizeof(AlienWord); j++) {
            if (tolower(currentSymbol) == alienDictionary[j].symbol) {
                currentAlienWord = &alienDictionary[j];
                break;
            }
        }
        if (currentAlienWord == NULL) {
            printf("Unknown character '%c' in English word.\n", currentSymbol);
            continue;
        }
        printf("%c (Alien symbol for %c with phonetic value %d)\n", currentAlienWord->symbol, currentSymbol, currentAlienWord->phoneticValue);
    }
    printf("\n");
}

// Main function
int main() {
    char englishWord[50];
    printf("Enter an English word to translate to Alien Language: ");
    scanf("%s", englishWord);

    translateEnglishToAlien(englishWord);

    return 0;
}