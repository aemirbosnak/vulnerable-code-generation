//Falcon-180B DATASET v1.0 Category: Error handling ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100
#define MAX_NUM_ERRORS 10

typedef struct {
    char *filename;
    int line_number;
    char *message;
} Error;

int num_errors = 0;
Error errors[MAX_NUM_ERRORS];

void add_error(char *filename, int line_number, char *message) {
    if (num_errors >= MAX_NUM_ERRORS) {
        printf("Error: Maximum number of errors (%d) reached.\n", MAX_NUM_ERRORS);
        exit(1);
    }
    errors[num_errors].filename = filename;
    errors[num_errors].line_number = line_number;
    errors[num_errors].message = message;
    num_errors++;
}

void print_errors() {
    if (num_errors == 0) {
        printf("No errors found.\n");
    } else {
        printf("Found %d errors:\n", num_errors);
        for (int i = 0; i < num_errors; i++) {
            printf("%s:%d: %s\n", errors[i].filename, errors[i].line_number, errors[i].message);
        }
    }
}

int main() {
    char input_buffer[MAX_LINE_SIZE];
    char filename[MAX_LINE_SIZE];
    int line_number = 1;
    FILE *input_file;

    printf("Enter filename: ");
    scanf("%s", filename);

    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        add_error(filename, 0, "Error: Could not open file.");
        return 1;
    }

    while (fgets(input_buffer, MAX_LINE_SIZE, input_file)!= NULL) {
        char *token = strtok(input_buffer, "\n");
        while (token!= NULL) {
            if (strstr(token, "ERROR")!= NULL) {
                add_error(filename, line_number, "Found error in code.");
            } else if (strstr(token, "WARNING")!= NULL) {
                add_error(filename, line_number, "Found warning in code.");
            }
            token = strtok(NULL, "\n");
            line_number++;
        }
    }

    fclose(input_file);
    print_errors();

    return 0;
}