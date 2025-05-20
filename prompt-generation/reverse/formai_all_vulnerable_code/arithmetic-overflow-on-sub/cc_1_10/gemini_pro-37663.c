//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <time.h>

int main() {
    // Declare variables
    int correct = 0, incorrect = 0;
    clock_t start, end;
    double time_taken;
    char input;

    // Introduction
    printf("Dearest wordsmith, welcome to our romantic typing test! Brace thyself for a whirlwind of amorous prose...\n\n");

    // Start the clock
    start = clock();

    // Type the following text
    printf("Type the following excerpt from our beloved Shakespeare's sonnet:\n");
    printf("Let me not to the marriage of true minds\n");
    printf("Admit impediments. Love is not love\n");

    // Get the user's input
    while ((input = getchar()) != '\n') {
        // Check if the input is correct
        if (input == 'm') {
            correct++;
        } else {
            incorrect++;
        }
    }

    // Stop the clock
    end = clock();

    // Calculate the time taken
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the WPM
    int wpm = (correct + incorrect) / 5 / time_taken * 60;

    // Display the results
    printf("\nMy dearest, your typing speed is %d WPM.\n", wpm);

    // Calculate the accuracy
    double accuracy = (double)correct / (correct + incorrect) * 100;

    // Display the accuracy
    printf("Your accuracy is %.2f%%.\n", accuracy);

    // Farewell message
    printf("\nYour fingertips have danced upon the keys with grace and ardor. May your wordsmithing prowess continue to flourish!\n");

    return 0;
}