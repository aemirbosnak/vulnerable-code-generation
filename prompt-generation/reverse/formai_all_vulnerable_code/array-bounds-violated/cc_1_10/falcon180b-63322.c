//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10

char words[NUM_WORDS][WORD_LENGTH] = {
    "hello",
    "world",
    "programming",
    "typing",
    "speed",
    "test",
    "example",
    "code",
    "snippet",
    "practice"
};

int main() {
    int i, j, correct = 0, incorrect = 0;
    int num_correct = 0, num_incorrect = 0;
    char input[WORD_LENGTH];
    int word_index = rand() % NUM_WORDS;

    printf("Welcome to the typing speed test!\n");
    printf("You will be typing %d words with %d characters each.\n", NUM_WORDS, WORD_LENGTH);

    for (i = 0; i < NUM_WORDS; i++) {
        printf("Word %d: ", i+1);
        for (j = 0; j < WORD_LENGTH; j++) {
            input[j] = words[i][j];
        }
        input[WORD_LENGTH] = '\0';
        printf("%s\n", input);
    }

    for (i = 0; i < NUM_WORDS; i++) {
        printf("Please type word %d: ", i+1);
        scanf("%s", input);
        if (strcmp(input, words[i]) == 0) {
            correct++;
        } else {
            incorrect++;
        }
    }

    printf("Results:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    return 0;
}