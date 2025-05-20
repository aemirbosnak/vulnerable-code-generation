//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv) {
    char *filename;
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    } else {
        filename = argv[1];
    }
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 1;
    }

    // Allocate memory for each line of the file
    char **lines = malloc(sizeof(char*) * MAX_LINE_LENGTH);
    if (lines == NULL) {
        printf("Error: Unable to allocate memory\n");
        return 1;
    }
    int num_lines = 0;
    int i;
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        lines[i] = malloc(sizeof(char) * MAX_LINE_LENGTH);
        if (lines[i] == NULL) {
            printf("Error: Unable to allocate memory\n");
            return 1;
        }
    }

    // Read each line of the file into memory
    while (fgets(lines[num_lines], MAX_LINE_LENGTH, file)) {
        num_lines++;
    }

    // Close the file
    fclose(file);

    // Remove trailing whitespace from each line
    for (i = 0; i < num_lines; i++) {
        int len = strlen(lines[i]);
        while (len > 0 && (lines[i][len-1] == ' ' || lines[i][len-1] == '\t' || lines[i][len-1] == '\n' || lines[i][len-1] == '\r')) {
            len--;
            lines[i][len] = '\0';
        }
    }

    // Output the file with a newline after each line
    for (i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i]);
    }

    // Deallocate memory
    for (i = 0; i < MAX_LINE_LENGTH; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}