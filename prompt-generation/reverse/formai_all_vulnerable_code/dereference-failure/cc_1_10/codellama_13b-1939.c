//Code Llama-13B DATASET v1.0 Category: Typing Speed Test ; Style: innovative
// Unique C Typing Speed Test Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TIME_LIMIT 60 // seconds
#define WORD_COUNT 50

// Function to generate a random string
char* generate_random_string(int length) {
    char* str = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = (char)((rand() % 26) + 'a');
    }
    str[length] = '\0';
    return str;
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Generate a random string
    char* random_string = generate_random_string(WORD_COUNT);

    // Display the string to be typed
    printf("Type the following string as fast as you can: %s\n", random_string);

    // Start the timer
    clock_t start = clock();

    // Get user input
    char input[WORD_COUNT + 1];
    fgets(input, sizeof(input), stdin);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to type the string
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print the result
    printf("Time taken: %f seconds\n", time_taken);

    // Check if the user typed the correct string
    if (strcmp(input, random_string) == 0) {
        printf("Correct!\n");
    } else {
        printf("Incorrect!\n");
    }

    return 0;
}