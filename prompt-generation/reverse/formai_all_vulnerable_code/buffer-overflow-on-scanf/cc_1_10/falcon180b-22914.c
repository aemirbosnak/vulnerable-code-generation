//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_number;
} Line;

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    Line *lines = NULL;

    // Prompt the user for the filename
    printf("Enter the filename to analyze: ");
    scanf("%s", filename);

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: Reached maximum number of lines (%d)\n", MAX_NUM_LINES);
            exit(1);
        }

        // Allocate memory for the line and its line number
        lines = realloc(lines, sizeof(Line) * (num_lines + 1));
        if (lines == NULL) {
            printf("Error: Could not allocate memory for line\n");
            exit(1);
        }
        lines[num_lines].line = malloc(strlen(line) + 1);
        if (lines[num_lines].line == NULL) {
            printf("Error: Could not allocate memory for line\n");
            exit(1);
        }
        strcpy(lines[num_lines].line, line);
        lines[num_lines].line_number = num_lines + 1; // Line numbers start at 1
        num_lines++;
    }

    // Close the file
    fclose(fp);

    // Print the lines with their line numbers
    printf("Lines:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_number, lines[i].line);
    }

    // Free the memory used by the lines
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }
    free(lines);

    return 0;
}