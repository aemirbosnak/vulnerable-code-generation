//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
int calculateWPM(int numWords, int timeTaken) {
    // Convert time taken from seconds to minutes
    float timeTakenMinutes = (float)timeTaken / 60;
    return (int)(numWords / timeTakenMinutes);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of words to type from the user
    int numWords;
    printf("Enter the number of words to type: ");
    scanf("%d", &numWords);

    // Generate a random string of words
    char *str = generateString(numWords);

    // Display the string to the user
    printf("Type the following string as fast as you can:\n%s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[numWords + 1];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    int timeTaken = end - start;

    // Calculate the WPM
    int wpm = calculateWPM(numWords, timeTaken);

    // Display the results
    printf("Your typing speed is %d words per minute.\n", wpm);

    // Free the allocated memory
    free(str);

    return 0;
}