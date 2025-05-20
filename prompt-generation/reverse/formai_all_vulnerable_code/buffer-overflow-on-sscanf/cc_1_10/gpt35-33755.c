//FormAI DATASET v1.0 Category: Error handling ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom error structure
struct Error {
    int code;
    char message[50];
};

// Function to handle errors and exit the program
void handleError(struct Error err) {
    printf("ERROR [%d]: %s\n", err.code, err.message);
    exit(err.code);
}

int main() {
    char input[25];
    int num;

    // Ask user for a number input
    printf("Enter a number: ");
    fgets(input, sizeof(input), stdin);

    // Check if input is a number
    if (sscanf(input, "%d", &num) != 1) {
        // If input is not a number, set error information
        struct Error err;
        err.code = 1;
        strcpy(err.message, "Invalid input: Not a number");

        // Handle the error and exit
        handleError(err);
    }

    // Check if input is within a range of 1-10
    if (num < 1 || num > 10) {
        // If input is outside range, set error information
        struct Error err;
        err.code = 2;
        strcpy(err.message, "Invalid input: Number out of range");

        // Handle the error and exit
        handleError(err);
    }

    // If input is valid, print success message
    printf("Success! Number entered: %d\n", num);

    return 0;
}