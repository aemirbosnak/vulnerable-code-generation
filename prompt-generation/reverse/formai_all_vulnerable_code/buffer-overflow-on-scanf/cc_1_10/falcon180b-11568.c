//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
void generateRandomString(char* str, int length) {
    const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    str[length] = '\0';
}

int main() {
    int length;
    char input[100];

    // Get desired string length from user
    printf("Enter the desired length of the string: ");
    scanf("%d", &length);

    // Generate a random string of given length
    generateRandomString(input, length);

    // Print the string to be typed
    printf("\nThe string to be typed is: %s\n", input);

    // Initialize variables for timing and accuracy
    int correctChars = 0, incorrectChars = 0, totalChars = 0, timeTaken = 0;

    // Start timer
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Get user input and compare with original string
    char userInput[100];
    printf("\nStart typing the string:\n");
    fgets(userInput, sizeof(userInput), stdin);

    // Remove newline character from user input
    userInput[strcspn(userInput, "\n")] = '\0';

    // Compare user input with original string
    for (int i = 0; i < strlen(input); i++) {
        if (userInput[i] == input[i]) {
            correctChars++;
        } else {
            incorrectChars++;
        }
        totalChars++;
    }

    // Stop timer
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate time taken
    timeTaken = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

    // Calculate accuracy
    float accuracy = ((float)correctChars / totalChars) * 100.0;

    // Print results
    printf("\nResults:\n");
    printf("Time taken: %d milliseconds\n", timeTaken);
    printf("Accuracy: %.2f%%\n", accuracy);

    return 0;
}