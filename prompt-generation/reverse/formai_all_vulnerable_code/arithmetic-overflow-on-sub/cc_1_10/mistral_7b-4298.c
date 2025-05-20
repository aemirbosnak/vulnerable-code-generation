//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 100
#define NUM_STRINGS 5

char *quotes[NUM_STRINGS] = {
    "The game is afoot!",
    "You see, but you do not observe.",
    "Elementary, my dear Watson.",
    "I prefer to call it elementary deduction.",
    "There is nothing more deceptive than an obvious fact."
};

void print_quotes() {
    int i;

    printf("Welcome to the Sherlock Holmes Typing Speed Test!\n");
    printf("Please type the following quotes as fast and accurately as possible:\n\n");

    for (i = 0; i < NUM_STRINGS; i++) {
        printf("Quote %d: %s\n", i + 1, quotes[i]);
    }
}

int main() {
    char user_input[MAX_LENGTH];
    char correct_answer[MAX_LENGTH];
    int score = 0, i;
    clock_t start, end;
    double time_taken;

    print_quotes();

    for (i = 0; i < NUM_STRINGS; i++) {
        strcpy(correct_answer, quotes[i]);
        start = clock();

        printf("\nType the quote %d below: ", i + 1);
        fgets(user_input, MAX_LENGTH, stdin);

        end = clock();
        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        if (strcmp(user_input, correct_answer) == 0) {
            score += 10;
            printf("Correct! You scored %d points in %.3f seconds.\n\n", score, time_taken);
        } else {
            printf("Incorrect. The correct answer was: %s\n", quotes[i]);
        }
    }

    printf("Your final score is: %d\n", score);

    return 0;
}