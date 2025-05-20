//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORDS 10
#define WORD_LENGTH 10

char words[NUM_WORDS][WORD_LENGTH] = {
    "programming",
    "algorithms",
    "data",
    "structures",
    "operating",
    "systems",
    "mathematics",
    "logic",
    "computer",
    "science"
};

int main() {
    int i, j, correct = 0, incorrect = 0, total = 0;
    char input[WORD_LENGTH];
    char correct_input[WORD_LENGTH];

    srand(time(NULL));
    for (i = 0; i < NUM_WORDS; i++) {
        j = rand() % WORD_LENGTH;
        strncpy(correct_input, words[i] + j, WORD_LENGTH - j);
        correct_input[WORD_LENGTH - j] = '\0';
    }

    printf("Welcome to the C Typing Speed Test!\n");
    printf("You will be typing %d words.\n", NUM_WORDS);

    for (i = 0; i < NUM_WORDS; i++) {
        printf("Word %d: ", i + 1);
        for (j = 0; j < WORD_LENGTH; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = 0; i < NUM_WORDS; i++) {
        printf("Word %d: ", i + 1);
        fgets(input, WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, correct_input) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        total++;
    }

    printf("\nTest complete!\n");
    printf("You typed %d words correctly.\n", correct);
    printf("You typed %d words incorrectly.\n", incorrect);
    printf("Your total accuracy is %.2f%%\n", ((float)correct / total) * 100);

    return 0;
}