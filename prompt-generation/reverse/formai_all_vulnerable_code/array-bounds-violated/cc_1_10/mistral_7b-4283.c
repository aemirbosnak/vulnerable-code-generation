//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024
#define MIN_INPUT_SIZE 5

// Function to sanitize user input
void sanitize_input(char *input) {
    int i, j;
    int length = strlen(input);

    for (i = 0; i < length; i++) {
        if (input[i] < ' ' || input[i] > '~') { // Invalid character
            for (j = i; j < length; j++) {
                input[j] = input[j + 1];
            }
            length--;
            i--;
        }
    }

    // Add a null terminator
    if (length >= MAX_INPUT_SIZE) {
        printf("Error: Input too long.\n");
        exit(1);
    }
    input[length] = '\0';
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];

    printf("\nWelcome, noble traveler, to the Castle of Secure Input!\n");
    printf("Kindly provide us with thy input, but beware of the wicked scripts!\n");
    printf("Input: ");

    fgets(input, MAX_INPUT_SIZE, stdin);

    // Remove the newline character
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    sanitize_input(input);

    printf("Thy input: %s\n", input);

    return 0;
}