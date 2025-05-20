//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Function to print error message and exit program
void error(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}

// Function to open a file
FILE *open_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        error("Could not open file");
    }
    return file;
}

// Function to read a line from a file
char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    getline(&line, &len, file);
    if (read == -1) {
        error("Error reading line");
    }
    return line;
}

// Function to parse a line of text
int parse_line(char *line) {
    int num;
    if (sscanf(line, "%d", &num)!= 1) {
        error("Invalid line format");
    }
    return num;
}

// Function to calculate the sum of numbers in a file
int sum_file(char *filename) {
    FILE *file = open_file(filename);
    int sum = 0;
    char *line;
    while ((line = read_line(file))!= NULL) {
        int num = parse_line(line);
        sum += num;
        free(line);
    }
    fclose(file);
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        error("Usage:./program filename");
    }
    int sum = sum_file(argv[1]);
    printf("The sum of the numbers in the file is: %d\n", sum);
    return 0;
}