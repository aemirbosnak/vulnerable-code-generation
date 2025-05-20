//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char* generate_string(int n) {
    char* str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        // Generate a random character between 'a' and 'z'
        str[i] = (char)('a' + rand() % 26);
    }
    str[n] = '\0';
    return str;
}

int main() {
    // Set a random seed
    srand(time(NULL));

    // Get the number of words from the user
    int num_words;
    printf("Enter the number of words: ");
    scanf("%d", &num_words);

    // Generate a random string of words
    char* str = generate_string(num_words);

    // Print the string to the console
    printf("Type the following string: %s\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    char* input = malloc(num_words + 1);
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the total time taken
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    double speed = (double)num_words / time_taken;

    // Print the typing speed to the console
    printf("Your typing speed is %.2f words per minute\n", speed * 60);

    // Free the allocated memory
    free(str);
    free(input);

    return 0;
}