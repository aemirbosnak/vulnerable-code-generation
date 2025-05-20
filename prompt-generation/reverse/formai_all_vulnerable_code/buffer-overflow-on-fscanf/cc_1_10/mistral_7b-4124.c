//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define NUM_WORDS 20
#define MAX_WORD_LENGTH 20

char words[NUM_WORDS][MAX_WORD_LENGTH + 1];
char userInput[MAX_WORD_LENGTH + 1];

void initWords() {
    FILE *fp = fopen("words.txt", "r");
    int i = 0;
    char word[MAX_WORD_LENGTH + 1];

    if (fp == NULL) {
        printf("Error: Unable to open words file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", word) != EOF) {
        strcpy(words[i], word);
        i++;
    }

    fclose(fp);
}

void printRandomWord() {
    int index = rand() % NUM_WORDS;
    printf("Type the following word: %s\n", words[index]);
    strcpy(userInput, "");
}

int isWordEqual(char *word1, char *word2) {
    int i;

    for (i = 0; word1[i] != '\0' && word2[i] != '\0'; i++) {
        if (tolower(word1[i]) != tolower(word2[i])) {
            return 0;
        }
    }

    if (word1[i] == '\0' && word2[i] == '\0') {
        return 1;
    }

    return 0;
}

void processUserInput() {
    int i;
    clock_t start = clock();

    fgets(userInput, MAX_WORD_LENGTH + 1, stdin);
    userInput[strcspn(userInput, "\n")] = '\0';

    for (i = 0; userInput[i] != '\0'; i++) {
        userInput[i] = tolower(userInput[i]);
    }

    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    if (isWordEqual(words[rand() % NUM_WORDS], userInput)) {
        printf("Correct! Your typing speed for this word is %.2f words per minute.\n", 60.0 / elapsedTime);
    } else {
        printf("Incorrect. The correct answer was: %s\n", words[rand() % NUM_WORDS]);
    }

    printRandomWord();
}

int main() {
    srand(time(NULL));
    initWords();

    while (1) {
        printRandomWord();
        processUserInput();
    }

    return 0;
}