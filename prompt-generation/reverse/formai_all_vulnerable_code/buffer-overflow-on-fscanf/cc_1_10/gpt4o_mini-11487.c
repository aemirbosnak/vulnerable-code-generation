//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Function prototypes
void print_error(const char *message);
int divide(int numerator, int denominator);
void open_file(const char *filename);
int read_integer(FILE *file);
void compute_average(const char *filename);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_error("Usage: ./error_handling <filename>");
        return EXIT_FAILURE;
    }
    
    compute_average(argv[1]);

    return EXIT_SUCCESS;
}

// Function to print error messages with context
void print_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Function to divide two integers with error handling
int divide(int numerator, int denominator) {
    if (denominator == 0) {
        print_error("Division by zero");
    }
    return numerator / denominator;
}

// Function to open a file and handle possible errors
void open_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        print_error("Failed to open file");
    }

    // Reading integers from the file
    int avg = read_integer(file);

    fclose(file);
}

// Function to read integers from a file
int read_integer(FILE *file) {
    int number;
    int count = 0;
    int sum = 0;

    while (fscanf(file, "%d", &number) == 1) {
        sum += number;
        count++;
    }

    if (count == 0) {
        print_error("No integers found in file");
    }

    return divide(sum, count);
}

// Function to compute the average of integers in a file
void compute_average(const char *filename) {
    printf("Computing average from file: %s\n", filename);
    open_file(filename);
    printf("Average computed successfully.\n");
}