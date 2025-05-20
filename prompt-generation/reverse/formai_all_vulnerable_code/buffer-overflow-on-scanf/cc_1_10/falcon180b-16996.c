//Falcon-180B DATASET v1.0 Category: File handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 1000

struct Line {
    char text[MAX_LINE_LENGTH];
    int length;
};

int main() {
    FILE *file;
    struct Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_length;

    // Ask user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read lines from file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_length = strlen(line);
        if (line_length >= MAX_LINE_LENGTH) {
            printf("Error: line is too long.\n");
            exit(1);
        }
        strcpy(lines[num_lines].text, line);
        lines[num_lines].length = line_length;
        num_lines++;
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines.\n");
            exit(1);
        }
    }

    // Sort lines by length
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (lines[j].length < lines[i].length) {
                struct Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Print sorted lines
    for (int i = 0; i < num_lines; i++) {
        printf("%s (%d characters)\n", lines[i].text, lines[i].length);
    }

    // Close file
    fclose(file);

    return 0;
}