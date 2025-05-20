//Falcon-180B DATASET v1.0 Category: Error handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to check if a string is a valid integer
int is_integer(const char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to read a line of input from the user
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

// Function to parse an integer from a string
int parse_integer(const char *str) {
    int value = 0;
    sscanf(str, "%d", &value);
    return value;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

// Function to handle errors
void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *line;
    int number;

    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        handle_error("Incorrect number of arguments");
    }

    // Open the input file
    file = fopen(argv[1], "r");
    if (file == NULL) {
        handle_error("Could not open file");
    }

    // Read the first line of the file
    line = read_line(file);
    if (line == NULL) {
        handle_error("Out of memory");
    }

    // Parse the integer from the line
    if (!is_integer(line)) {
        handle_error("Invalid input");
    }
    number = parse_integer(line);

    // Calculate the factorial
    int result = factorial(number);

    // Print the result
    printf("The factorial of %d is %d\n", number, result);

    // Close the input file
    if (fclose(file)!= 0) {
        handle_error("Error closing file");
    }

    return 0;
}