//Falcon-180B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

int main() {
    FILE *file;
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file line by line
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Allocate memory for line
        lines[num_lines].line = malloc(strlen(line) + 1);
        if (lines[num_lines].line == NULL) {
            printf("Error allocating memory.\n");
            exit(1);
        }

        // Copy line into allocated memory
        strcpy(lines[num_lines].line, line);

        // Set line number
        lines[num_lines].line_num = num_lines + 1;

        // Increment number of lines
        num_lines++;
    }

    // Close file
    fclose(file);

    // Sort lines by length
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strlen(lines[j].line) < strlen(lines[i].line)) {
                // Swap lines
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Print sorted lines
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }

    // Free memory
    for (int i = 0; i < num_lines; i++) {
        free(lines[i].line);
    }

    return 0;
}