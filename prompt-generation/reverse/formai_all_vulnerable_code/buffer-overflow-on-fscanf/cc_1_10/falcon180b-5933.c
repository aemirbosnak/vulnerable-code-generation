//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WORD_MAX_LENGTH 20
#define WORD_LIST_SIZE 100

typedef struct {
    char word[WORD_MAX_LENGTH];
    int length;
} Word;

Word wordList[WORD_LIST_SIZE];

void initWordList() {
    FILE *file = fopen("wordlist.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open wordlist.txt\n");
        exit(1);
    }

    int numWords = 0;

    while (fscanf(file, "%s", wordList[numWords].word)!= EOF) {
        wordList[numWords].length = strlen(wordList[numWords].word);
        numWords++;
    }

    fclose(file);
}

void generateRandomWord() {
    int index = rand() % WORD_LIST_SIZE;
    Word word = wordList[index];

    printf("Type the word: ");
    for (int i = 0; i < word.length; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    initWordList();

    printf("Welcome to the Typing Speed Test!\n\n");

    int numCorrect = 0;
    int numIncorrect = 0;

    while (1) {
        generateRandomWord();

        char input[WORD_MAX_LENGTH];
        fgets(input, WORD_MAX_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        if (strcmp(input, wordList[rand() % WORD_LIST_SIZE].word) == 0) {
            printf("Correct!\n");
            numCorrect++;
        } else {
            printf("Incorrect.\n");
            numIncorrect++;
        }
    }

    return 0;
}