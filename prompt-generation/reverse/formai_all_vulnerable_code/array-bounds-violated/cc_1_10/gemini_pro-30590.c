//GEMINI-pro DATASET v1.0 Category: Educational ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string.
#define MAX_STRING_SIZE 100

// Define the maximum number of characters to display on each line.
#define MAX_LINE_LENGTH 72

// Define the main function.
int main(void) {
    // Declare the input string.
    char input[MAX_STRING_SIZE];

    // Get the input string from the user.
    printf("Enter a string: ");
    fgets(input, MAX_STRING_SIZE, stdin);

    // Remove the newline character from the input string.
    input[strlen(input) - 1] = '\0';

    // Calculate the number of lines needed to display the input string.
    int num_lines = (strlen(input) + MAX_LINE_LENGTH - 1) / MAX_LINE_LENGTH;

    // Allocate memory for the output string.
    char *output = malloc(num_lines * MAX_LINE_LENGTH);

    // Initialize the output string.
    memset(output, 0, num_lines * MAX_LINE_LENGTH);

    // Copy the input string to the output string, line by line.
    int line_index = 0;
    int char_index = 0;
    for (int i = 0; i < strlen(input); i++) {
        output[line_index * MAX_LINE_LENGTH + char_index] = input[i];
        char_index++;
        if (char_index >= MAX_LINE_LENGTH) {
            line_index++;
            char_index = 0;
        }
    }

    // Display the output string.
    printf("\nOutput:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", output + i * MAX_LINE_LENGTH);
    }

    // Free the memory allocated for the output string.
    free(output);

    // Return 0 to indicate that the program has terminated successfully.
    return 0;
}