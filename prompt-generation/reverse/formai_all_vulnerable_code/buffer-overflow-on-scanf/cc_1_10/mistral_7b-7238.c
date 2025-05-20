//MISTRAL-7B DATASET v1.0 Category: HTML beautifier ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define TAB_WIDTH 4

void print_spaces(int num) {
    for (int i = 0; i < num; i++) {
        printf("%c", ' ');
    }
}

void indent(int *current_indent, char *line, int line_length) {
    int spaces_needed = (*current_indent) / TAB_WIDTH;
    int extra_spaces = line_length - (strlen(line) + spaces_needed);

    if (extra_spaces > 0) {
        print_spaces(extra_spaces);
        (*current_indent) += spaces_needed + extra_spaces;
    }
}

int main() {
    char filename[100];
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int current_indent = 0;

    printf("***** HAPPY HTML BEAUTIFIER *****\n");

    // Get the filename from the command line arguments
    if (scanf("%s", filename) != 1) {
        printf("Error: Please provide a valid filename.\n");
        return 1;
    }

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open the file '%s'\n", filename);
        return 1;
    }

    // Read the file line by line and print it out beautified
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        int line_length = strlen(line);

        // Skip empty lines
        if (line_length == 0 || line[0] == '\n') {
            continue;
        }

        // Remove comments
        if (line[0] == '/' && line[1] == '*') {
            int comment_start = 1;
            int comment_end = 0;

            for (int i = 1; line[i] != '\0'; i++) {
                if (line[i] == '*' && line[i+1] == '/') {
                    comment_end = i;
                    break;
                }

                if (!comment_start && line[i] == '*') {
                    comment_start = i;
                }
            }

            if (comment_end > comment_start) {
                memmove(line, line + comment_end + 1, line_length - (comment_end + 1) - comment_start);
                line_length -= (comment_end + 1) - comment_start;
            } else {
                continue;
            }
        }

        // Add indentation
        indent(&current_indent, line, line_length);

        // Print the line
        printf("%s", line);
    }

    // Close the file
    fclose(file);

    printf("\n***** BEAUTIFICATION COMPLETE! *****\n");

    return 0;
}