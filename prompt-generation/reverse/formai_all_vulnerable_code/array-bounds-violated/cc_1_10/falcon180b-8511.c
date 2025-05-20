//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_COUNT 10
#define WORD_LENGTH 10

int main() {
    char words[WORD_COUNT][WORD_LENGTH] = {"programmer", "software", "development", "coding", "algorithms", "data", "structures", "functions", "variables", "loops"};
    int wordIndex = 0;
    int score = 0;
    int correctLetters = 0;
    int incorrectLetters = 0;
    int letterIndex = 0;
    int wordLength = strlen(words[0]);
    int i;
    int startTime = 0;
    int endTime = 0;
    int elapsedTime = 0;

    printf("Welcome to the Typing Speed Test!\n\n");

    srand(time(NULL));
    wordIndex = rand() % WORD_COUNT;

    printf("You will be typing the word: ");
    for (i = 0; i < wordLength; i++) {
        printf("*");
    }

    startTime = clock();

    while (letterIndex < wordLength) {
        printf("%c", words[wordIndex][letterIndex]);
        fflush(stdout);
        if (words[wordIndex][letterIndex] == '*') {
            printf(" ");
        }
        letterIndex++;
        usleep(250000); // 250ms delay
    }

    endTime = clock();
    elapsedTime = (endTime - startTime) / (double)CLOCKS_PER_SEC;

    printf("\n\n");

    for (i = 0; i < WORD_LENGTH; i++) {
        if (tolower(words[wordIndex][i]) == tolower(getchar())) {
            correctLetters++;
        } else {
            incorrectLetters++;
        }
    }

    score = (int)(WORD_LENGTH * 60 / (double)elapsedTime);

    printf("Your final score is: %d words per minute\n", score);
    printf("You got %d correct letters and %d incorrect letters.\n", correctLetters, incorrectLetters);

    return 0;
}