//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define ERROR_MESSAGE_LEN 256

// Function to get a line from the user
char *get_line() {
    char *line = malloc(MAX_LENGTH);
    printf("Enter a line: ");
    fgets(line, MAX_LENGTH, stdin);
    return line;
}

// Function to check if the input is a valid integer
int is_valid_integer(char *input) {
    int num;
    if (sscanf(input, "%d", &num) == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the input is a valid float
int is_valid_float(char *input) {
    float num;
    if (sscanf(input, "%f", &num) == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char *line;

    // Ask the user for their name
    line = get_line();
    if (!is_valid_integer(line)) {
        printf("Error: Not a valid integer\n");
        return 1;
    }

    // Ask the user for their age
    line = get_line();
    if (!is_valid_float(line)) {
        printf("Error: Not a valid float\n");
        return 2;
    }

    // Ask the user for their favorite color
    line = get_line();
    if (strlen(line) > ERROR_MESSAGE_LEN) {
        printf("Error: Color too long\n");
        return 3;
    }

    // Print a success message
    printf("Success! You entered: %s\n", line);

    return 0;
}