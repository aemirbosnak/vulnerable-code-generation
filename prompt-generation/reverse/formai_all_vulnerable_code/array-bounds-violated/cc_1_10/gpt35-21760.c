//FormAI DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100

void toLower(char word[]);
int isWordValid(char word[]);
void generateCorrectWord(char word[]);

int main(void) {
    char userInput[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords = 0;

    printf("Enter up to %d words to spell check (enter '.' on a line by itself to finish):\n", MAX_WORDS);
    while (numWords < MAX_WORDS) {
        printf("[%d]> ", numWords+1);
        fgets(userInput[numWords], MAX_WORD_LENGTH, stdin);
        userInput[numWords][strlen(userInput[numWords])-1] = '\0'; // remove the '\n'
        if (strcmp(userInput[numWords], ".") == 0) break;
        numWords++;
    }

    printf("\nResults:\n");
    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        strcpy(word, userInput[i]);
        toLower(word);
        if (!isWordValid(word)) {
            printf("%s is not a valid word.\n", userInput[i]);
        } else {
            generateCorrectWord(word);
            printf("%s => %s\n", userInput[i], word);
        }
    }

    return 0;
}

void toLower(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }
}

int isWordValid(char word[]) {
    if (strlen(word) < 3 || strlen(word) > MAX_WORD_LENGTH) {
        return 0;
    }
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}

void generateCorrectWord(char word[]) {
    // This is where we would use advanced spell checking algorithms in the future
    // For now, we will just convert all words to "hello"
    strcpy(word, "hello");
}