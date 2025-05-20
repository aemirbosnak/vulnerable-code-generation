//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 50
#define WORD_LENGTH 10

typedef struct {
    char word[WORD_LENGTH];
    int length;
} Word;

int main() {
    Word words[MAX_WORDS];
    int numWords, i;
    char input[WORD_LENGTH];
    int length, correctWords = 0, totalWords = 0;
    int startTime, endTime, elapsedTime;

    printf("Welcome to the Typing Speed Test!\n");

    // Read in the words from a file
    FILE *fp = fopen("words.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    numWords = 0;
    while (fscanf(fp, "%s", input)!= EOF) {
        if (numWords >= MAX_WORDS) {
            printf("Error: too many words in words.txt\n");
            exit(1);
        }
        words[numWords].length = strlen(input);
        strcpy(words[numWords].word, input);
        numWords++;
    }
    fclose(fp);

    // Shuffle the words
    for (i = 0; i < numWords - 1; i++) {
        int j = rand() % numWords;
        Word temp = words[i];
        words[i] = words[j];
        words[j] = temp;
    }

    // Start the timer
    startTime = clock();

    // Display the words one by one
    for (i = 0; i < numWords; i++) {
        printf("Word %d: ", i + 1);
        printf("%s", words[i].word);
        fflush(stdout);
        length = 0;
        while (getchar()!= '\n') {
            if (length >= WORD_LENGTH) {
                printf("Error: too many characters typed\n");
                exit(1);
            }
            input[length++] = getchar();
        }
        input[length] = '\0';
        if (strcmp(input, words[i].word) == 0) {
            correctWords++;
        }
        totalWords++;
        printf("\n");
    }

    // Stop the timer
    endTime = clock();
    elapsedTime = (endTime - startTime) / (double) CLOCKS_PER_SEC;

    // Display the results
    printf("You typed %d correct words out of %d total words.\n", correctWords, totalWords);
    printf("Your typing speed is %.2f words per minute.\n", (double) totalWords / elapsedTime);

    return 0;
}