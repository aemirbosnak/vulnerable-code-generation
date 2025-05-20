//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the given string with a delay of 'delay' milliseconds
void print_with_delay(char* str, int delay) {
    for (int i = 0; str[i]!= '\0'; i++) {
        printf("%c", str[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
}

// Function to generate a random string of given length
char* generate_random_string(int length) {
    char* str = (char*) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

int main() {
    int length, correct_count = 0, wrong_count = 0, total_count = 0;
    char* input_string;
    char* user_input;
    int delay = 50; // Delay in milliseconds

    srand(time(NULL));

    // Get the desired string length from the user
    printf("Enter the desired string length: ");
    scanf("%d", &length);

    // Generate a random string of given length
    input_string = generate_random_string(length);

    // Print the input string
    print_with_delay(input_string, delay);
    printf("\n");

    // Get the user input
    printf("Press enter to start the test\n");
    scanf("%*c");

    // Start the test
    while (1) {
        user_input = (char*) malloc(length + 1);
        fgets(user_input, length + 1, stdin);
        total_count++;

        // Check if the user input matches the input string
        if (strcmp(user_input, input_string) == 0) {
            correct_count++;
        } else {
            wrong_count++;
        }

        // Print the result and wait for user input
        printf("\r%d/%d (%d correct, %d wrong) ", total_count, length, correct_count, wrong_count);
        fflush(stdout);
        usleep(delay * 1000);

        // Check if the test is complete
        if (total_count == length) {
            break;
        }
    }

    // Print the final result
    printf("\n");
    printf("You typed %d characters in %d seconds.\n", length, total_count);
    printf("Your typing speed is %d characters per second.\n", length / total_count);

    return 0;
}