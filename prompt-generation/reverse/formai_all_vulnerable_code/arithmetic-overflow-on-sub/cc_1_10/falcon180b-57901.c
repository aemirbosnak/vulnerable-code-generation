//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generate_random_string(char *str, int length);
int main();

// Main function
int main() {
    int length;
    char input_string[100];
    char random_string[100];
    int correct_count = 0;
    int incorrect_count = 0;
    int total_count = 0;
    int start_time, end_time;

    printf("Welcome to the Typing Speed Test!\n");
    printf("This test will generate random strings of characters for you to type.\n");
    printf("You will have 60 seconds to type as many characters as possible.\n");
    printf("Press any key to start the test...\n");
    getchar();

    // Get the length of the random string
    printf("Enter the length of the random string: ");
    scanf("%d", &length);

    // Generate the random string
    generate_random_string(random_string, length);

    // Start the timer
    start_time = clock();

    // Main loop for the test
    while (total_count < length) {
        printf("Type the next character: ");
        scanf(" %c", &input_string[total_count]);
        total_count++;

        // Check if the input is correct
        if (input_string[total_count - 1] == random_string[total_count - 1]) {
            correct_count++;
        } else {
            incorrect_count++;
        }
    }

    // Stop the timer
    end_time = clock();

    // Calculate the typing speed
    double typing_speed = (double)correct_count / ((double)length / (double)(end_time - start_time));

    // Print the results
    printf("\nTest results:\n");
    printf("Total characters typed: %d\n", total_count);
    printf("Correct characters typed: %d\n", correct_count);
    printf("Incorrect characters typed: %d\n", incorrect_count);
    printf("Typing speed: %.2f characters per second\n", typing_speed);

    return 0;
}

// Function to generate a random string
void generate_random_string(char *str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = (char)(rand() % 26 + 'a');
    }
    str[length] = '\0';
}