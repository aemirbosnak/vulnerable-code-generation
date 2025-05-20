//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

// Struct to hold CSV data
typedef struct {
    char *name;
    int age;
    char *gender;
} csv_data;

// Function to read a line from a file and return it as a string
char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, file)) == -1) {
        fprintf(stderr, "Error reading line\n");
        exit(EXIT_FAILURE);
    }

    return line;
}

// Function to parse a line of CSV data into a struct
csv_data parse_line(char *line) {
    csv_data data;
    char *token;
    char *saveptr;

    // Name
    token = strtok_r(line, ",", &saveptr);
    if (token == NULL) {
        fprintf(stderr, "Invalid line format\n");
        exit(EXIT_FAILURE);
    }
    data.name = strdup(token);

    // Age
    token = strtok_r(NULL, ",", &saveptr);
    if (token == NULL) {
        fprintf(stderr, "Invalid line format\n");
        exit(EXIT_FAILURE);
    }
    data.age = atoi(token);

    // Gender
    token = strtok_r(NULL, ",", &saveptr);
    if (token == NULL) {
        fprintf(stderr, "Invalid line format\n");
        exit(EXIT_FAILURE);
    }
    data.gender = strdup(token);

    return data;
}

// Function to print CSV data in a formatted way
void print_data(csv_data data) {
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Gender: %s\n", data.gender);
}

// Function to free CSV data
void free_data(csv_data data) {
    free(data.name);
    free(data.gender);
}

// Function to read a CSV file and print its contents
void read_csv_file(char *filename) {
    FILE *file;
    char *line;
    csv_data data;

    if ((file = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while ((line = read_line(file))!= NULL) {
        data = parse_line(line);
        print_data(data);
        free_data(data);
    }

    fclose(file);
}

int main() {
    read_csv_file("data.csv");
    return 0;
}