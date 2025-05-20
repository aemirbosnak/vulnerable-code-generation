//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char text[1000]; // The text to type
    int length; // The length of the text
    int score = 0; // The score
    int correct = 0; // The number of correct characters
    int wrong = 0; // The number of wrong characters
    int i = 0; // The index of the text
    int j = 0; // The index of the typed text
    int start_time = 0; // The start time
    int end_time = 0; // The end time
    int elapsed_time = 0; // The elapsed time

    // Set the text
    strcpy(text, "The quick brown fox jumps over the lazy dog. ");

    // Get the length of the text
    length = strlen(text);

    // Start the timer
    start_time = clock();

    // Loop until the text is complete
    while (i < length) {
        // Print the next character
        printf("%c", text[i]);

        // Read the typed character
        scanf("%c", &text[i]);

        // Check if the typed character is correct
        if (text[i] == text[i]) {
            correct++;
        } else {
            wrong++;
        }

        // Increment the index
        i++;

        // Check if the text is complete
        if (i == length) {
            // Stop the timer
            end_time = clock();

            // Calculate the elapsed time
            elapsed_time = (end_time - start_time) / (double) CLOCKS_PER_SEC;

            // Calculate the score
            score = (int) ((double) correct / length * 100);

            // Print the result
            printf("\n");
            printf("Text: %s\n", text);
            printf("Score: %d%%\n", score);
            printf("Correct: %d\n", correct);
            printf("Wrong: %d\n", wrong);
            printf("Elapsed time: %.2f seconds\n", elapsed_time);

            // Exit the program
            exit(0);
        }
    }

    return 0;
}