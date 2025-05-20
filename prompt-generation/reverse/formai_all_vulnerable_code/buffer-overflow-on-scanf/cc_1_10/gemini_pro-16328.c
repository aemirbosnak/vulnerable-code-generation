//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of length n
char *generate_string(int n) {
    char *str = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[n] = '\0';
    return str;
}

// Function to get the accuracy of the user's input
int get_accuracy(char *original, char *input) {
    int correct_count = 0;
    for (int i = 0; i < (int)strlen(original); i++) {
        if (original[i] == input[i]) {
            correct_count++;
        }
    }
    return (correct_count * 100) / strlen(original);
}

// Function to get the speed of the user's input
int get_speed(char *input, int time_taken) {
    return (int)(strlen(input) / (time_taken / 60.0));
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the string to be typed from the user
    int length;
    printf("Enter the length of the string to be typed: ");
    scanf("%d", &length);

    // Generate a random string of the specified length
    char *original = generate_string(length);

    // Start the timer
    clock_t start_time = clock();

    // Get the user's input
    char *input = malloc(length + 1);
    printf("Type the following string: %s\n", original);
    scanf("%s", input);

    // Stop the timer
    clock_t end_time = clock();

    // Get the time taken to type the string
    int time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

    // Get the accuracy and speed of the user's input
    int accuracy = get_accuracy(original, input);
    int speed = get_speed(input, time_taken);

    // Print the results
    printf("Accuracy: %d%%\n", accuracy);
    printf("Speed: %d words per minute\n", speed);

    // Free the allocated memory
    free(original);
    free(input);

    return 0;
}