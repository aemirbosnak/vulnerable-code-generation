//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 100
#define MAX_FILENAME_LENGTH 50

// Function to sanitize user input
void sanitize_input(char* input) {
    int i = 0;
    char* output = malloc(MAX_INPUT_LENGTH);

    while (i < strlen(input)) {
        // Check if character is alphanumeric or whitespace
        if (isalnum(input[i]) || isspace(input[i])) {
            strncat(output, &input[i], 1);
        }

        i++;
    }

    // Replace output string
    strcpy(input, output);
    free(output);
}

// Function to read input from user
void get_input(char* input) {
    printf("Enter your input: ");
    scanf("%s", input);
    sanitize_input(input);
}

// Function to read filename from user
void get_filename(char* filename) {
    printf("Enter filename: ");
    scanf("%s", filename);
    sanitize_input(filename);
}

// Function to write to file
void write_to_file(char* filename, char* input) {
    FILE* file = fopen(filename, "a");

    if (file!= NULL) {
        fprintf(file, "%s", input);
        fclose(file);
        printf("Input successfully written to file.\n");
    } else {
        printf("Error: Could not write to file.\n");
    }
}

// Main function
int main() {
    char input[MAX_INPUT_LENGTH] = {0};
    char filename[MAX_FILENAME_LENGTH] = {0};

    printf("Welcome to the Sherlock Holmes Input Sanitizer!\n");
    printf("This program will sanitize your input and write it to a file.\n");

    // Get input from user
    get_input(input);

    // Get filename from user
    get_filename(filename);

    // Write input to file
    write_to_file(filename, input);

    return 0;
}