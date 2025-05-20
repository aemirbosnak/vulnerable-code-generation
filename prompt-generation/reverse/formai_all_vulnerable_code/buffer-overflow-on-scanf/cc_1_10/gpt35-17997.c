//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: happy
// This C program lets users test their typing speed while keeping them entertained with happy messages!

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define NUM_WORDS 10
#define MAX_WORD_LENGTH 10

int main() {
    char words[NUM_WORDS][MAX_WORD_LENGTH] = {"happy", "sunshine", "smile", "love", "joyful", "laughter", "excitement", "blessing", "funny", "happiness"};
    int score = 0;
    int seconds = 0;
    time_t start_t, end_t;

    printf("Welcome to the Happy Typing Speed Test!\n");
    printf("Type the following words as fast as you can.\n");
    printf("Remember, accuracy counts!\n\n");

    for (int i = 0; i < NUM_WORDS; i++) {
        printf("%s ", words[i]);

        time(&start_t); // Start timer
        char input[MAX_WORD_LENGTH];
        scanf("%s", input); // Get user input
        time(&end_t); // End timer

        while (isspace(input[0])) {
            scanf("%s", input); // Ignore empty inputs
        }

        double time_taken = difftime(end_t, start_t);
        seconds += (int)time_taken; // Update total time taken

        if (strcmp(input, words[i]) == 0) { // Correct input
            printf("Correct! ");
            score++;
        } else { // Incorrect input
            printf("Incorrect! ");
        }

        printf("Time taken: %.2f seconds\n", time_taken);
        printf("\n");
    }

    double wpm = (double)score / ((double)seconds / 60.0);
    printf("Your score: %d/%d\n", score, NUM_WORDS);
    printf("Total time taken: %d seconds\n", seconds);
    printf("Typing speed: %.2f words per minute\n", wpm);

    printf("Congratulations, you finished the Happy Typing Speed Test!\n");

    return 0;
}