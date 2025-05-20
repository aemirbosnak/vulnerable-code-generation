//Falcon-180B DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char line[MAX_LINE_SIZE];
    int line_num;
} Line;

int main() {
    FILE* file;
    char filename[MAX_LINE_SIZE];
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read lines from file
    while (fgets(lines[num_lines].line, MAX_LINE_SIZE, file)!= NULL) {
        num_lines++;
    }
    fclose(file);

    // Sort lines by length
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strlen(lines[j].line) < strlen(lines[i].line)) {
                Line temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    // Print sorted lines
    for (int i = 0; i < num_lines; i++) {
        printf("%d. %s\n", lines[i].line_num, lines[i].line);
    }

    return 0;
}