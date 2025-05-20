//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Alien language struct
typedef struct {
    char name[20];
    char symbol;
    int value;
} AlienSymbol;

// Alien language symbols
AlienSymbol alienLanguage[] = {
    {"Glorp", 'G', 3},
    {"Flibber", 'F', 5},
    {"Quux", 'Q', 7},
    {"Zork", 'Z', 11},
    {"Quuxquux", 'X', 13}
};

// Function to translate human language to alien language
void translateToAlien(char *humanLanguage) {
    int i, j;
    char alienWord[50];
    char currentSymbol;
    int currentValue = 0;

    for (i = 0; humanLanguage[i] != '\0'; i++) {
        for (j = 0; j < 5; j++) {
            if (humanLanguage[i] == alienLanguage[j].symbol) {
                currentSymbol = alienLanguage[j].symbol;
                currentValue += alienLanguage[j].value;
                break;
            }
        }

        if (j == 5) { // Symbol not found
            currentSymbol = '?';
            currentValue = -1;
        }

        alienWord[i] = currentSymbol;
    }

    alienWord[i] = '\0';
    printf("Alien translation: %s\n", alienWord);
}

int main() {
    char humanLanguage[100];
    printf("Enter human language: ");
    scanf("%s", humanLanguage);

    translateToAlien(humanLanguage);

    return 0;
}