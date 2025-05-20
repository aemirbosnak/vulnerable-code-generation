//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining an enum for Cat Language words
typedef enum {
    MEOW,
    PURR,
    HISS,
    SCRATCH,
    SLEEP,
    EAT
} CatWord;

// Defining an array of Cat Language words as strings
char *catWords[] = {
    "Meow",
    "Purr",
    "Hiss",
    "Scratch",
    "Sleep",
    "Eat"
};

// Function to translate Cat Language to English
void catToEnglish(CatWord word) {
    switch (word) {
        case MEOW:
            printf("Meow\n");
            break;
        case PURR:
            printf("Purr\n");
            break;
        case HISS:
            printf("Hiss\n");
            break;
        case SCRATCH:
            printf("Scratch\n");
            break;
        case SLEEP:
            printf("Sleep\n");
            break;
        case EAT:
            printf("Eat\n");
            break;
        default:
            printf("Unknown Cat Word\n");
            break;
    }
}

// Function to translate English to Cat Language
CatWord englishToCat(char *word) {
    for (int i = 0; i < sizeof(catWords)/sizeof(*catWords); i++) {
        if (strcmp(word, catWords[i]) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char inputWord[25];
    int choice;

    printf("This program is a C Cat Language Translator.\n");

    do {
        printf("\nEnter 1 for Cat Language to English translation or 2 for English to Cat Language translation (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter a Cat Language word: ");
            scanf("%s", inputWord);
            CatWord word = englishToCat(inputWord);
            if (word == -1) {
                printf("Unknown Cat Word\n");
            } else {
                printf("English: ");
                catToEnglish(word);
            }
        } else if (choice == 2) {
            printf("\nEnter an English word: ");
            scanf("%s", inputWord);
            int i;
            for (i = 0; i < strlen(inputWord); i++) {
                inputWord[i] = tolower(inputWord[i]);
            }
            printf("Cat Language: ");
            catToEnglish((CatWord) rand() % 6);
        }
    } while (choice != 0);

    printf("\nExiting the C Cat Language Translator...\n");

    return 0;
}