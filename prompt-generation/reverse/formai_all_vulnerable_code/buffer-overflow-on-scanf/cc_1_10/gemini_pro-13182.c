//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generateString(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculateWPM(int numChars, double time) {
    return (numChars / 5) / (time / 60);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's input
    printf("Enter the number of characters you want to type: ");
    int numChars;
    scanf("%d", &numChars);

    // Generate a random string
    char* str = generateString(numChars);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[numChars + 1];
    printf("Type the following string: %s\n", str);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    int wpm = calculateWPM(numChars, time);

    // Print the results
    printf("Your typing speed is %d WPM.\n", wpm);

    // Free the allocated memory
    free(str);

    return 0;
}