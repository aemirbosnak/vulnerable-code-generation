//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Function to generate a random string
char *generateString(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to compute the typing speed
double computeTypingSpeed(char *string, double time) {
    int length = strlen(string);
    return ((double)length / time) * 60.0;
}

int main() {
    srand(time(NULL));

    // Get the desired length of the string from the user
    int length;
    printf("Enter the desired length of the string: ");
    scanf("%d", &length);

    // Generate a random string
    char *string = generateString(length);

    // Display the string to the user
    printf("Type the following string as quickly as possible:\n%s\n", string);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[length + 1];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Compute the typing speed
    double time = ((double)(end - start)) / CLOCKS_PER_SEC;
    double speed = computeTypingSpeed(string, time);

    // Display the result
    printf("Your typing speed is: %.2f words per minute\n", speed);

    // Free the allocated memory
    free(string);

    return 0;
}