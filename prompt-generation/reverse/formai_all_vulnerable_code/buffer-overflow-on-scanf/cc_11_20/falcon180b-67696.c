//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char word[100];
    int length;
    int difficulty;
} Word;

int main() {
    int numWords = 10;
    Word words[numWords];
    int i;
    int totalWords = 0;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int numIncorrect = 0;
    int userSpeed = 0;
    int maxSpeed = 0;
    char buffer[100];
    int len;
    int j;
    int k;
    char temp;
    int correct = 0;
    int incorrect = 0;
    int currentWord = 0;
    int currentChar = 0;
    int startTime, endTime;
    int elapsedTime;
    int speed;
    int totalElapsedTime = 0;
    int totalChars = 0;

    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter your name: ");
    scanf("%s", buffer);
    printf("Hello, %s! Let's begin the test.\n", buffer);

    for (i = 0; i < numWords; i++) {
        words[i].length = rand() % 11 + 5;
        words[i].difficulty = rand() % 3 + 1;
        strcpy(words[i].word, "");
        for (j = 0; j < words[i].length; j++) {
            k = rand() % 26 + 'a';
            if (k > 'z') {
                k = 'a';
            }
            strcat(words[i].word, &k);
        }
    }

    printf("You will be typing %d words.\n", numWords);
    for (i = 0; i < numWords; i++) {
        printf("Word %d: ", i+1);
        printf("%s\n", words[i].word);
        totalWords++;
    }

    printf("Press enter to begin.\n");
    getchar();

    startTime = clock();

    while (totalWords > 0) {
        printf("\n");
        printf("Word %d:\n", currentWord+1);
        for (j = 0; j < words[currentWord].length; j++) {
            temp = words[currentWord].word[j];
            words[currentWord].word[j] = '*';
            printf("%c", temp);
        }
        printf("\n");

        correct = 0;
        incorrect = 0;
        currentChar = 0;
        while (currentChar < words[currentWord].length) {
            scanf("%c", &buffer[0]);
            if (buffer[0] == words[currentWord].word[currentChar]) {
                correct++;
                currentChar++;
            } else {
                incorrect++;
            }
            totalChars++;
        }

        if (correct == words[currentWord].length) {
            printf("Correct!\n");
            totalCorrect++;
        } else {
            printf("Incorrect.\n");
            totalIncorrect++;
        }

        currentWord++;
        if (currentWord >= numWords) {
            currentWord = 0;
        }

        if (numIncorrect >= 3) {
            break;
        }

        totalElapsedTime += clock() - startTime;
        totalIncorrect = 0;
    }

    endTime = clock();
    elapsedTime = endTime - startTime;
    speed = (totalChars / (elapsedTime / (double)CLOCKS_PER_SEC)) * 60;

    printf("\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", totalCorrect, totalIncorrect);
    printf("Your typing speed is %d words per minute.\n", speed);

    return 0;
}