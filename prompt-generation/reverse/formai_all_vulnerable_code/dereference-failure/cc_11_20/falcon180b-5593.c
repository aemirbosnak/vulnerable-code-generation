//Falcon-180B DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000 // Maximum length of a line
#define MAX_NUM_LINES 10000 // Maximum number of lines

typedef struct {
    char *line; // Pointer to the line
    int len; // Length of the line
} Line;

int main() {
    FILE *fp;
    Line *lines = NULL; // Initialize the line array to NULL
    int num_lines = 0; // Initialize the number of lines to 0
    char line[MAX_LINE_LEN]; // Buffer to hold each line

    // Open the file for reading
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        exit(1);
    }

    // Read the file line by line
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        // Convert the line to lowercase
        for (int i = 0; line[i]!= '\0'; i++) {
            line[i] = tolower(line[i]);
        }

        // Check if the line is empty or contains only whitespace
        if (line[0] == '\0' || strspn(line, " \t\n\r") == strlen(line)) {
            continue;
        }

        // Check if the line is a comment
        if (line[0] == '#') {
            continue;
        }

        // Allocate memory for the line
        Line *new_line = malloc(sizeof(Line));
        if (new_line == NULL) {
            printf("Error: Could not allocate memory!\n");
            exit(1);
        }

        // Copy the line to the new line
        new_line->line = strdup(line);
        new_line->len = strlen(line);

        // Add the new line to the array
        lines = realloc(lines, sizeof(Line) * (num_lines + 1));
        if (lines == NULL) {
            printf("Error: Could not allocate memory!\n");
            exit(1);
        }
        lines[num_lines] = *new_line;
        num_lines++;
    }

    // Close the file
    fclose(fp);

    // Print the lines
    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].line);
    }

    // Free the line array
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);

    return 0;
}