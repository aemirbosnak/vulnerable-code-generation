//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of given length
char *generate_string(int length) {
    char *result = malloc(length + 1);
    if (!result) {
        printf("Error: Out of memory.\n");
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        result[i] = 'a' + rand() % 26;
    }
    result[length] = '\0';
    return result;
}

// Function to print a string with given delay between characters
void print_string_delayed(const char *str, int delay) {
    for (int i = 0; str[i]; i++) {
        printf("%c", str[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
}

int main() {
    srand(time(NULL));

    // Prompt user for test duration and difficulty level
    int duration, difficulty;
    printf("Welcome to the Typing Speed Test!\n");
    printf("Please enter the test duration in seconds: ");
    scanf("%d", &duration);
    printf("Please enter the difficulty level (1-5): ");
    scanf("%d", &difficulty);

    // Initialize variables for tracking typing speed
    int correct_chars = 0, incorrect_chars = 0, total_chars = 0, wpm = 0;
    double accuracy = 0.0;
    time_t start_time, end_time;

    // Start the test
    printf("\nThe test will begin in 3 seconds...\n");
    sleep(3);
    time(&start_time);
    char *input_buffer = NULL;
    while (difftime(time(NULL), start_time) < duration) {
        // Generate a random string for the user to type
        int string_length = rand() % (difficulty * 5 + 5) + 5;
        char *string_to_type = generate_string(string_length);

        // Print the string for the user to type
        printf("\nPlease type the following string:\n%s", string_to_type);

        // Read user input and compare with expected string
        fgets(input_buffer, string_length + 1, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';
        int result = strcmp(input_buffer, string_to_type);

        // Update typing speed and accuracy variables
        if (result == 0) {
            correct_chars += string_length;
        } else {
            incorrect_chars += string_length;
        }
        total_chars += string_length;

        // Print feedback for the user
        if (result == 0) {
            printf("\nCorrect!\n");
        } else {
            printf("\nIncorrect. The correct string was: %s\n", string_to_type);
        }

        // Calculate WPM based on current typing speed
        wpm = (double)correct_chars / (difftime(time(NULL), start_time) * 60);

        // Delay before generating next string
        usleep(500000 + (int)(1000000.0 / wpm * string_length));

        // Free memory used by input buffer
        free(input_buffer);
        input_buffer = NULL;
    }

    // Print final results
    printf("\nTest completed!\n");
    printf("You typed %d characters correctly and %d characters incorrectly.\n", correct_chars, incorrect_chars);
    printf("Your typing speed was %.2f words per minute (WPM).\n", wpm);
    printf("Your accuracy was %.2f%%.\n", (double)correct_chars / total_chars * 100.0);

    return 0;
}