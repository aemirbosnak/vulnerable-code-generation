//Falcon2-11B DATASET v1.0 Category: Typing Speed Test ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_TAP 500

int main(int argc, char *argv[])
{
    char str[MAX_LEN];
    char *p;
    char ch;
    int tap = 0;
    int taps[MAX_TAP];
    int tap_sum = 0;
    clock_t start, end;
    double time_taken;

    // Get user input
    printf("Enter the string you want to test: ");
    fgets(str, MAX_LEN, stdin);

    // Get user input for number of characters
    printf("Enter the number of characters in the string: ");
    scanf("%d", &ch);

    // Get user input for number of taps
    printf("Enter the number of taps: ");
    scanf("%d", &tap);

    // Initialize taps array
    for (int i = 0; i < MAX_TAP; i++)
        taps[i] = 0;

    // Start the timer
    start = clock();

    // Repeat the string until all characters are entered
    while (ch--) {
        // Get the character to enter
        ch = fgetc(stdin);

        // Check if the character is the last character in the string
        if (ch == '\n') {
            // Set tap_sum to the total number of taps
            tap_sum = 0;

            // Get the time taken to enter the string
            end = clock();
            time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

            // Print the time taken
            printf("Time taken: %f seconds\n", time_taken);

            // Print the total number of taps
            printf("Total number of taps: %d\n", tap_sum);

            // Print the average number of taps per character
            printf("Average number of taps per character: %f\n", (double) tap_sum / ch);

            // Reset taps array
            for (int i = 0; i < MAX_TAP; i++)
                taps[i] = 0;

            // Reset start timer
            start = clock();
        }

        // Set the tap_sum to the total number of taps
        tap_sum++;

        // Get the character to enter
        ch = getchar();

        // Set the tap to the current number of taps
        taps[tap++] = tap_sum;
    }

    // Print the total number of taps
    printf("Total number of taps: %d\n", tap_sum);

    // Print the average number of taps per character
    printf("Average number of taps per character: %f\n", (double) tap_sum / ch);

    return 0;
}