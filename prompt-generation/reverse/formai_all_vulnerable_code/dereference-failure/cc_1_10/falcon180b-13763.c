//Falcon-180B DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024

// Function to print an error message and exit the program
void error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = NULL;
    size_t line_length = 0;
    ssize_t bytes_read;

    bytes_read = getline(&line, &line_length, file);
    if (bytes_read == -1) {
        error("Failed to read line from file");
    }

    return line;
}

// Function to parse a line of text into an integer
int parse_int(const char* line) {
    char* endptr;
    int value = strtol(line, &endptr, 10);

    if (*endptr!= '\0') {
        error("Invalid integer value");
    }

    return value;
}

// Function to calculate the sum of integers in a file
int calculate_sum(FILE* file) {
    int sum = 0;
    char* line;

    while ((line = read_line(file))!= NULL) {
        int value = parse_int(line);
        sum += value;
    }

    return sum;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        error("Usage:./program <filename>");
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        error("Failed to open file");
    }

    int sum = calculate_sum(file);
    printf("The sum of integers in the file is: %d\n", sum);

    fclose(file);
    return 0;
}