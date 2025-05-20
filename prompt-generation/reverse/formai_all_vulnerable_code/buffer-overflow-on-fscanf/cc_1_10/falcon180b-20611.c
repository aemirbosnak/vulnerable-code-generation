//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

int main() {
    FILE *fp;
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int numWords;
    int correctWords = 0;
    int incorrectWords = 0;
    int totalWords = 0;
    int score = 0;
    int i, j;
    char input[MAX_WORD_LENGTH];
    char userInput[MAX_WORD_LENGTH];
    int userInputLength;
    int wordLength;
    int startTime, endTime;
    double elapsedTime;
    int wpm;
    int accuracy;

    fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open words.txt\n");
        return 1;
    }

    numWords = 0;
    while (fscanf(fp, "%s", words[numWords])!= EOF) {
        numWords++;
    }
    fclose(fp);

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given %d words to type.\n", numWords);
    printf("Press enter to begin:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    startTime = clock();

    for (i = 0; i < numWords; i++) {
        printf("\nWord %d: ", i+1);
        wordLength = strlen(words[i]);
        for (j = 0; j < wordLength; j++) {
            printf("*");
        }
        printf("\n");

        do {
            printf("Enter the word: ");
            fgets(userInput, MAX_WORD_LENGTH, stdin);
            userInputLength = strlen(userInput);
            if (userInputLength > wordLength) {
                printf("Error: Input too long\n");
                continue;
            }
        } while (strcmp(userInput, words[i])!= 0);

        correctWords++;
    }

    endTime = clock();
    elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    wpm = (int)(numWords / elapsedTime);
    accuracy = (int)((double)correctWords / numWords * 100.0);

    printf("\nYou have completed the test!\n");
    printf("Words per minute: %d\n", wpm);
    printf("Accuracy: %d%%\n", accuracy);

    return 0;
}