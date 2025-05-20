//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define WORD_LENGTH 5
#define NUM_WORDS 10
#define MAX_TRIES 3

int main() {
    char words[NUM_WORDS][WORD_LENGTH] = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon"};
    int i, j, correct = 0, incorrect = 0, tries = 0;
    char input[WORD_LENGTH];

    srand(time(0));
    for (i = 0; i < NUM_WORDS; i++) {
        j = rand() % NUM_WORDS;
        strcpy(words[i], words[j]);
    }

    printf("Welcome to the Typing Speed Test!\n");
    printf("You have %d tries to type each word correctly.\n", MAX_TRIES);
    printf("Word: ");
    for (i = 0; i < WORD_LENGTH; i++) {
        printf("_");
    }
    printf("\n");

    for (i = 0; i < NUM_WORDS; i++) {
        while (tries < MAX_TRIES) {
            printf("Word: ");
            for (j = 0; j < WORD_LENGTH; j++) {
                if (isalpha(words[i][j])) {
                    printf("%c", tolower(words[i][j]));
                } else {
                    printf("_");
                }
            }
            printf("\n");

            fgets(input, WORD_LENGTH, stdin);
            input[strcspn(input, "\n")] = '\0';

            if (strcmp(input, words[i]) == 0) {
                correct++;
                break;
            } else {
                incorrect++;
                tries++;
            }
        }
        printf("\n");
    }

    printf("Results:\n");
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    return 0;
}