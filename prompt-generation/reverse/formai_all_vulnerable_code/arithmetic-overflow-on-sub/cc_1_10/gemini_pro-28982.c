//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Predefined Words
char *words[] = {"love", "cherish", "adore", "treasure", "embrace", "cherish", "adore", "treasure", "embrace", "cherish", "adore", "treasure", "embrace"};
// Word Length
#define WORD_LEN 5

// Function to generate random word
char *get_random_word() {
    return words[rand() % (sizeof(words) / sizeof(char *))];
}

// Function to compare two strings
int compare_strings(char *str1, char *str2) {
    return strcmp(str1, str2);
}

// Function to print the results
void print_results(int wpm, int accuracy) {
    printf("Your typing speed is: %d WPM\n", wpm);
    printf("Your accuracy is: %d%%\n", accuracy);
}

// Main Function
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Get the user's input
    char input[100];
    printf("Type the following words as fast as you can:\n");
    for (int i = 0; i < 10; i++) {
        printf("%s ", get_random_word());
    }
    printf("\n\n");

    // Start the timer
    clock_t start = clock();

    // Get the user's input
    fgets(input, sizeof(input), stdin);

    // Stop the timer
    clock_t end = clock();

    // Calculate the time taken
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Calculate the WPM
    int wpm = (int)((strlen(input) / 5) / time_taken) * 60;

    // Calculate the accuracy
    int accuracy = (int)((100.0 * strlen(input)) / (5 * 10));

    // Print the results
    print_results(wpm, accuracy);

    return 0;
}