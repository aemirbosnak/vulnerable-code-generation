//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute (wpm)
double calculate_wpm(int num_chars, double time_taken) {
    return (num_chars / 5) / (time_taken / 60);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the number of seconds for the test
    int num_seconds;
    printf("Enter the number of seconds for the test: ");
    scanf("%d", &num_seconds);

    // Generate a random string
    char* str = generate_string(num_seconds * 10);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char input[num_seconds * 10 + 1];
    printf("Start typing now:\n");
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    double wpm = calculate_wpm(strlen(str), time_taken);

    // Print the results
    printf("Your typing speed is %.2f wpm\n", wpm);

    // Free the allocated memory
    free(str);

    return 0;
}