//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random word.
char *generate_word() {
    // List of words to choose from.
    char *words[] = {"apple", "banana", "cherry", "dog", "elephant", "fish", "grape", "house", "ice cream", "juice"};

    // Select a random word from the list.
    int index = rand() % 10;
    return words[index];
}

// Function to get the user's input.
char *get_input() {
    char *input = malloc(100);
    scanf("%s", input);
    return input;
}

// Function to compare the user's input to the correct word.
int compare_input(char *input, char *correct_word) {
    // Compare the two strings.
    int result = strcmp(input, correct_word);

    // Return 1 if the strings are equal, 0 otherwise.
    return result == 0;
}

// Function to calculate the typing speed.
double calculate_speed(int words_per_minute) {
    // Calculate the number of characters per minute.
    double characters_per_minute = words_per_minute * 5;

    // Return the typing speed in characters per second.
    return characters_per_minute / 60.0;
}

// Function to print the results.
void print_results(int words_per_minute, double speed) {
    // Print the words per minute and speed.
    printf("Words per minute: %d\n", words_per_minute);
    printf("Speed: %.2f characters per second\n", speed);
}

int main() {
    // Initialize the random number generator.
    srand(time(NULL));

    // Generate a random word.
    char *correct_word = generate_word();

    // Get the user's input.
    char *input = get_input();

    // Start the timer.
    clock_t start = clock();

    // Compare the user's input to the correct word.
    int correct = compare_input(input, correct_word);

    // Stop the timer.
    clock_t end = clock();

    // Calculate the elapsed time.
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the words per minute.
    int words_per_minute = (int)(60.0 * 1.0 / elapsed_time);

    // Calculate the typing speed.
    double speed = calculate_speed(words_per_minute);

    // Print the results.
    print_results(words_per_minute, speed);

    // Free the allocated memory.
    free(input);

    return 0;
}