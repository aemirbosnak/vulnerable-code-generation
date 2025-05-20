//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int correct = 0;
    int incorrect = 0;
    int totalWords = 0;
    int currentWord = 0;
    char word[100];
    FILE *file;
    int randomWord;
    int wordLength;
    int timeLimit = 60;
    int timeRemaining = timeLimit;
    int startTime = time(NULL);
    int endTime = 0;
    int elapsedTime = 0;
    int speed = 0;
    char input[100];
    int i;

    srand(time(NULL));
    file = fopen("words.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        totalWords++;
    }

    rewind(file);

    while (currentWord < totalWords) {
        randomWord = rand() % totalWords;
        fseek(file, (long)randomWord * sizeof(char), SEEK_SET);
        fscanf(file, "%s", word);
        wordLength = strlen(word);

        printf("Word %d: ", currentWord + 1);
        for (i = 0; i < wordLength; i++) {
            printf("*");
        }
        printf("\n");

        correct = 0;
        incorrect = 0;
        fflush(stdin);
        fgets(input, 100, stdin);

        if (strcmp(input, word) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        currentWord++;
    }

    elapsedTime = (int)(difftime(time(NULL), startTime));

    if (elapsedTime < timeLimit) {
        speed = (int)((double)totalWords / (double)elapsedTime * 60);
    } else {
        speed = (int)((double)totalWords / (double)timeLimit * 60);
    }

    printf("Score: %d\n", score);
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);
    printf("Speed: %d wpm\n", speed);

    return 0;
}