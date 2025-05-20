//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to generate a random string of length n
char *generateString(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculateWPM(int numWords, int timeInSeconds) {
    return (numWords * 60) / timeInSeconds;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's input
    int numWords;
    printf("Enter the number of words you want to type: ");
    scanf("%d", &numWords);

    // Generate a random string of words
    char *str = generateString(numWords);

    // Print the string to the console
    printf("Type the following string as quickly and accurately as possible:\n%s\n", str);

    // Start the timer
    clock_t start = clock();

    // Wait for the user to finish typing
    char c;
    while ((c = getchar()) != '\n');

    // Stop the timer
    clock_t end = clock();

    // Calculate the typing speed
    int timeInSeconds = (end - start) / CLOCKS_PER_SEC;
    int wpm = calculateWPM(numWords, timeInSeconds);

    // Print the typing speed to the console
    printf("Your typing speed is %d WPM.\n", wpm);

    // Free the allocated memory
    free(str);

    return 0;
}