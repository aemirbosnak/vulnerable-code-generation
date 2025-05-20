//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store the test results
typedef struct {
    int words_per_minute;
    int accuracy;
} results_t;

// Function to generate a random string of characters
char *generate_string(int length) {
    char *string = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        string[i] = 'a' + rand() % 26;
    }
    string[length] = '\0';
    return string;
}

// Function to get the user's input
char *get_input(int length) {
    char *input = malloc(length + 1);
    scanf("%s", input);
    return input;
}

// Function to calculate the test results
results_t calculate_results(char *string, char *input, int length) {
    int words_per_minute = 0;
    int accuracy = 0;

    // Calculate the number of words per minute
    words_per_minute = (length / 5) * 60 / time(NULL) - time(NULL);

    // Calculate the accuracy
    for (int i = 0; i < length; i++) {
        if (string[i] == input[i]) {
            accuracy++;
        }
    }
    accuracy = (accuracy * 100) / length;

    results_t results = {words_per_minute, accuracy};
    return results;
}

// Function to print the test results
void print_results(results_t results) {
    printf("Words per minute: %d\n", results.words_per_minute);
    printf("Accuracy: %d%%\n", results.accuracy);
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Get the test length from the user
    int length;
    printf("Enter the test length (in characters): ");
    scanf("%d", &length);

    // Generate a random string of characters
    char *string = generate_string(length);

    // Get the user's input
    char *input = get_input(length);

    // Calculate the test results
    results_t results = calculate_results(string, input, length);

    // Print the test results
    print_results(results);

    // Free the allocated memory
    free(string);
    free(input);

    return 0;
}