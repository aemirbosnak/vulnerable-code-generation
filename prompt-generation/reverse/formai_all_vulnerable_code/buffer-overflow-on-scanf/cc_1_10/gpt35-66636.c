//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_TIME 30 // set the duration of the test to 30 seconds
#define MAX_WORD_LENGTH 15 // set the maximum number of characters in a word
#define MAX_WORDS 100 // set the maximum number of words in the test

char* words[MAX_WORDS];

void createWordList() {
    // add your words to the list
    words[0] = "programming";
    words[1] = "algorithm";
    words[2] = "computer";
    words[3] = "science";
    words[4] = "system";
    words[5] = "database";
    words[6] = "network";
    words[7] = "security";
    words[8] = "software";
    words[9] = "hardware";
    words[10] = "machine";
    words[11] = "learning";
    words[12] = "automation";
    words[13] = "coding";
    words[14] = "web";
    words[15] = "design";
    words[16] = "user";
    words[17] = "interface";
    words[18] = "graphic";
    words[19] = "processing";
}

int main() {
    createWordList();

    printf("Welcome to the C Typing Speed Test! You will have %d seconds to type as many words as possible.\n", MAX_TIME);
    printf("Press Enter to start the test:");
    getchar();

    srand(time(NULL)); // initialize random seed

    clock_t startTime = clock();
    int wordCount = 0;
    while ((clock() - startTime) < MAX_TIME * CLOCKS_PER_SEC) {
        int index = rand() % MAX_WORDS; // get a random index from the word list
        char* currentWord = words[index];
        printf("Type the word: %s\n", currentWord);

        char input[MAX_WORD_LENGTH];
        scanf("%s", input);

        if (strcmp(input, currentWord) == 0) {
            wordCount ++;
            printf("Correct!\n");
        }
        else {
            printf("Incorrect. The correct word is %s\n", currentWord);
        }
    }

    printf("Time is up! You typed %d words in %d seconds.\n", wordCount, MAX_TIME);
    printf("Your typing speed is %.2f words per minute.\n", wordCount * 60.0 / MAX_TIME);

    return 0;
}