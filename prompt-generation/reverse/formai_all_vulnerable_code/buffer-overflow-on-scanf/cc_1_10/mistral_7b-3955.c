//MISTRAL-7B DATASET v1.0 Category: Spell checking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE 5000

typedef struct {
    char word[WORD_LENGTH];
} Word;

Word dictionary[DICTIONARY_SIZE];
int dictionaryCount = 0;

void loadDictionary(char *filename) {
    FILE *file = fopen(filename, "r");
    char line[WORD_LENGTH];

    if (file == NULL) {
        printf("Failed to open dictionary file!\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        int i;
        for (i = 0; i < WORD_LENGTH; i++) {
            if (line[i] != '\n') {
                dictionary[dictionaryCount].word[i] = tolower(line[i]);
            } else {
                dictionary[dictionaryCount].word[i] = '\0';
                dictionaryCount++;
                break;
            }
        }
    }

    fclose(file);
}

bool isWordInDictionary(char *word) {
    for (int i = 0; i < dictionaryCount; i++) {
        int j;
        for (j = 0; j < strlen(word); j++) {
            if (tolower(word[j]) != dictionary[i].word[j]) {
                break;
            }
        }

        if (j == strlen(word)) {
            return true;
        }
    }

    return false;
}

int main() {
    char filename[100], userInput[WORD_LENGTH];

    printf("Hello! Welcome to the Happy Spell Checker!\n");
    printf("Please enter the name of the dictionary file: ");
    scanf("%s", filename);

    loadDictionary(filename);

    printf("Now let's check your spelling!\n");
    printf("Type a word and I will tell you if it's correct or not! Type 'quit' to exit.\n");

    while (true) {
        printf("You: ");
        scanf("%s", userInput);

        if (strcmp(userInput, "quit") == 0) {
            break;
        }

        if (isWordInDictionary(userInput)) {
            printf("Great job! That word is spelled correctly!\n");
        } else {
            printf("Oops! That word is not in the dictionary. Try again!\n");
        }
    }

    printf("Have a happy day!\n");
    return 0;
}