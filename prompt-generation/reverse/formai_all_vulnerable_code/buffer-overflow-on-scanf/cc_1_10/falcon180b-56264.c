//Falcon-180B DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int length;
} Line;

int main() {
    FILE *file;
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    char filename[MAX_LINE_LENGTH];
    int i;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read file into lines array
    while (fgets(lines[num_lines].line, MAX_LINE_LENGTH, file)!= NULL) {
        lines[num_lines].length = strlen(lines[num_lines].line);
        num_lines++;
    }

    // Sort lines by length
    for (i = 0; i < num_lines - 1; i++) {
        int j;
        for (j = i + 1; j < num_lines; j++) {
            if (lines[i].length > lines[j].length) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Print sorted lines
    for (i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].line);
    }

    // Close file
    fclose(file);

    return 0;
}