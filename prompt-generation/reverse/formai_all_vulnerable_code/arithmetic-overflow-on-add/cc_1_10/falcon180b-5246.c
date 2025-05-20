//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string
char* generateRandomString(int length) {
    char* str = (char*) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = (char) (rand() % 26 + 'a');
    }
    str[length] = '\0';
    return str;
}

int main() {
    int length, correct, incorrect, total;
    double accuracy;
    char* input;

    // Get user input for string length
    printf("Enter string length: ");
    scanf("%d", &length);

    // Initialize variables
    correct = 0;
    incorrect = 0;
    total = 0;

    // Start timer
    clock_t start_time = clock();

    // Loop until user types correct string
    while (1) {
        // Generate random string
        input = generateRandomString(length);

        // Print string to be typed
        printf("Type the following string:\n%s\n", input);

        // Read input from user
        char user_input[length + 1];
        scanf("%s", user_input);

        // Check if input is correct
        if (strcmp(user_input, input) == 0) {
            correct++;
        } else {
            incorrect++;
        }

        // Increment total
        total++;

        // Check if user wants to quit
        printf("Press 'q' to quit, or any other key to continue:\n");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'q') {
            break;
        }
    }

    // Stop timer
    clock_t end_time = clock();

    // Calculate accuracy
    accuracy = (double) correct / total;

    // Print results
    printf("Total strings typed: %d\n", total);
    printf("Correct strings typed: %d\n", correct);
    printf("Incorrect strings typed: %d\n", incorrect);
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    // Calculate time taken
    double time_taken = (double) (end_time - start_time) / CLOCKS_PER_SEC;

    // Print time taken
    printf("Time taken: %.2f seconds\n", time_taken);

    return 0;
}