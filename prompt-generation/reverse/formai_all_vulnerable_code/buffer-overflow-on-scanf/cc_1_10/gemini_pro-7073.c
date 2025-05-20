//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random string of length n
char *generate_random_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = (rand() % 26) + 'a';
    }
    str[n] = '\0';
    return str;
}

// Function to calculate the typing speed in words per minute
double calculate_typing_speed(int num_words, int time_taken) {
    double wpm = (double)num_words / ((double)time_taken / 60);
    return wpm;
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the number of words to type
    int num_words;
    printf("Enter the number of words to type: ");
    scanf("%d", &num_words);

    // Generate a random string of words
    char *str = generate_random_string(num_words);

    // Print the string to the console
    printf("Type the following string as fast as you can:\n\n");
    printf("%s\n\n", str);

    // Start the timer
    clock_t start = clock();

    // Get the input from the user
    char input[num_words + 1];
    scanf("%s", input);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken to type the string
    int time_taken = (int)(end - start) / CLOCKS_PER_SEC;

    // Calculate the typing speed
    double wpm = calculate_typing_speed(num_words, time_taken);

    // Print the typing speed to the console
    printf("Your typing speed is: %.2f words per minute\n", wpm);

    // Free the allocated memory
    free(str);

    return 0;
}