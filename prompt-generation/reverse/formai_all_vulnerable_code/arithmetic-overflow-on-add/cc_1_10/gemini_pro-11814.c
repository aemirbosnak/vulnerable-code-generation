//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        int rand_char = rand() % 26;
        char c = 'a' + rand_char;
        str[i] = c;
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute (WPM)
int calculate_wpm(int num_characters, float time_taken) {
    float wpm = (num_characters / 5) / (time_taken / 60);
    return (int)wpm;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the user's name
    char name[256];
    printf("Enter your name: ");
    scanf("%s", name);

    // Get the length of the test string
    int test_len;
    printf("Enter the length of the test string (in characters): ");
    scanf("%d", &test_len);

    // Generate a random string of the specified length
    char *test_str = generate_random_string(test_len);

    // Print the test string
    printf("Type the following string as fast as you can:\n");
    printf("%s\n", test_str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char input[256];
    printf("Type here: ");
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    float time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    int wpm = calculate_wpm(strlen(test_str), time_taken);

    // Print the results
    printf("Your typing speed is: %d WPM\n", wpm);

    // Free the allocated memory
    free(test_str);

    return 0;
}