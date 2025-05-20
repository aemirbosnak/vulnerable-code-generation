//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum number of lines in a file
#define MAX_LINES 100

// Defines the maximum length of a line in a file
#define MAX_LINE_LENGTH 100

// Structure to represent a line in a file
typedef struct line {
    char contents[MAX_LINE_LENGTH];
    int length;
} line_t;

// Structure to represent a file
typedef struct file {
    line_t lines[MAX_LINES];
    int num_lines;
} file_t;

// Function to read a file into a file structure
file_t *read_file(char *filename) {
    // Allocate memory for the file structure
    file_t *file = malloc(sizeof(file_t));

    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Read the file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Remove the newline character from the line
        line[strlen(line) - 1] = '\0';

        // Copy the line into the file structure
        strcpy(file->lines[file->num_lines].contents, line);
        file->lines[file->num_lines].length = strlen(line);

        // Increment the number of lines in the file
        file->num_lines++;
    }

    // Close the file
    fclose(fp);

    // Return the file structure
    return file;
}

// Function to print a file
void print_file(file_t *file) {
    // Loop through the lines in the file
    for (int i = 0; i < file->num_lines; i++) {
        // Print the line
        printf("%s\n", file->lines[i].contents);
    }
}

// Function to search for a string in a file
int search_file(file_t *file, char *string) {
    // Loop through the lines in the file
    for (int i = 0; i < file->num_lines; i++) {
        // Check if the string is in the line
        if (strstr(file->lines[i].contents, string) != NULL) {
            // Return the line number
            return i;
        }
    }

    // Return -1 if the string is not found
    return -1;
}

// Function to replace a string in a file
void replace_string(file_t *file, char *old_string, char *new_string) {
    // Loop through the lines in the file
    for (int i = 0; i < file->num_lines; i++) {
        // Replace the old string with the new string
        char *p = strstr(file->lines[i].contents, old_string);
        while (p != NULL) {
            strncpy(p, new_string, strlen(new_string));
            p = strstr(p + strlen(new_string), old_string);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a filename
    if (argc < 2) {
        printf("Error: No filename specified\n");
        return 1;
    }

    // Read the file into a file structure
    file_t *file = read_file(argv[1]);
    if (file == NULL) {
        return 1;
    }

    // Print the file
    print_file(file);

    // Search for a string in the file
    int line_number = search_file(file, "the");
    if (line_number == -1) {
        printf("Error: String not found\n");
    } else {
        printf("String found on line %d\n", line_number + 1);
    }

    // Replace a string in the file
    replace_string(file, "the", "a");

    // Print the file again
    print_file(file);

    // Free the memory allocated for the file structure
    free(file);

    return 0;
}