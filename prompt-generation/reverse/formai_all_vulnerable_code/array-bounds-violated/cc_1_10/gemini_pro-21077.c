//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Structure to store a line of HTML code
typedef struct {
    char *line;
    int length;
} Line;

// Function to read a line of HTML code from the input file
Line read_line(FILE *input) {
    char line[MAX_LINE_LENGTH];
    int length = 0;

    // Read a line of HTML code from the input file
    while (fgets(line, MAX_LINE_LENGTH, input)) {
        length = strlen(line);

        // Remove the newline character from the end of the line
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }

        // Return the line of HTML code
        return (Line) {
            .line = strdup(line),
            .length = length
        };
    }

    // Return an empty line if the end of the file has been reached
    return (Line) {
        .line = NULL,
        .length = 0
    };
}

// Function to beautify a line of HTML code
Line beautify_line(Line line) {
    char *new_line = malloc(line.length * 2 + 1);
    int new_length = 0;

    // Loop through the characters in the line of HTML code
    for (int i = 0; i < line.length; i++) {
        // Check if the current character is a whitespace character
        if (isspace(line.line[i])) {
            // If the current character is a space, add it to the new line
            if (line.line[i] == ' ') {
                new_line[new_length++] = ' ';
            }
            // Otherwise, if the current character is a newline, add it to the new line and indent the next line
            else if (line.line[i] == '\n') {
                new_line[new_length++] = '\n';
                for (int j = 0; j < 4; j++) {
                    new_line[new_length++] = ' ';
                }
            }
        }
        // Otherwise, add the current character to the new line
        else {
            new_line[new_length++] = line.line[i];
        }
    }

    // Add a newline character to the end of the new line
    new_line[new_length++] = '\n';

    // Return the new line of HTML code
    return (Line) {
        .line = new_line,
        .length = new_length
    };
}

// Function to beautify a HTML document
void beautify_document(FILE *input, FILE *output) {
    // Read the HTML document from the input file
    Line line = read_line(input);

    // While there are still lines of HTML code to read
    while (line.line != NULL) {
        // Beautify the line of HTML code
        Line new_line = beautify_line(line);

        // Write the beautified line of HTML code to the output file
        fprintf(output, "%s", new_line.line);

        // Free the memory allocated for the beautified line of HTML code
        free(new_line.line);

        // Read the next line of HTML code from the input file
        line = read_line(input);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Open the input and output files
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 1;
    }
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return 1;
    }

    // Beautify the HTML document
    beautify_document(input, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}