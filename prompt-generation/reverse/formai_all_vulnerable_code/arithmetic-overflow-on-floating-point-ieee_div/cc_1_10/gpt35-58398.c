//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char quote[] = "The quick brown fox jumps over the lazy dog.";
    int length = strlen(quote);
    int i = 0, correct = 0, incorrect = 0, time_taken;
    clock_t start, end;

    printf("Welcome to the Typing Speed Test Game!\n");
    printf("Type the following quote as fast and as accurate as you can:\n");
    printf("%s\n", quote);
    printf("Press 'Enter' to start the game...");

    getchar(); // wait for 'Enter' key

    start = clock(); // start the timer

    while (i < length) {
        char input = getchar();

        // check if input matches the quote
        if (input == quote[i]) {
            correct++;
        } else {
            incorrect++;
        }

        i++;
    }

    end = clock(); // end the timer
    time_taken = (int)(end - start) / CLOCKS_PER_SEC;

    printf("\n\n-----------------------------------\n");
    printf("RESULTS\n");
    printf("-----------------------------------\n");

    printf("Time taken: %d seconds\n", time_taken);
    printf("Total characters: %d\n", length);
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    double accuracy = (double)correct / (double)length;
    double wpm = (double)correct / 5.0 / (double)time_taken * 60.0;

    printf("Accuracy: %.2f%%\n", accuracy * 100.0);
    printf("Typing Speed: %.2f WPM (Words Per Minute)\n", wpm);

    return 0;
}