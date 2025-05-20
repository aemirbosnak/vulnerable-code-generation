//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char text[1000];
    int length, correct = 0, incorrect = 0, total = 0, wpm;
    double start_time, end_time;

    // Prompt user for text to type
    printf("Enter text to type: ");
    fgets(text, sizeof(text), stdin);
    length = strlen(text);

    // Remove newline character from text
    text[length - 1] = '\0';

    // Seed random number generator with current time
    srand(time(NULL));

    // Prompt user for number of test rounds
    int rounds;
    printf("Enter number of test rounds: ");
    scanf("%d", &rounds);

    // Start timer
    start_time = clock();

    // Loop through test rounds
    for (int i = 0; i < rounds; i++) {
        // Shuffle text
        for (int j = 0; j < length; j++) {
            int k = rand() % length;
            char temp = text[j];
            text[j] = text[k];
            text[k] = temp;
        }

        // Prompt user to start typing
        printf("Round %d: ", i + 1);
        fflush(stdout);

        // Start typing timer
        start_time = clock();

        // Read user input and compare with text
        while (1) {
            char c = getchar();
            if (c == '\n') {
                break;
            }
            if (c == text[total]) {
                correct++;
                total++;
            } else {
                incorrect++;
                total++;
            }
        }

        // Stop typing timer
        end_time = clock();

        // Calculate words per minute
        wpm = (double)rounds * 5 / ((double)(end_time - start_time) / CLOCKS_PER_SEC);

        // Print results
        printf("\nRound %d results:\n", i + 1);
        printf("Words per minute: %.2f\n", wpm);
        printf("Correct words: %d\n", correct);
        printf("Incorrect words: %d\n", incorrect);
        printf("Total words: %d\n", total);
        printf("\n");

        // Reset variables for next round
        correct = 0;
        incorrect = 0;
        total = 0;
    }

    return 0;
}