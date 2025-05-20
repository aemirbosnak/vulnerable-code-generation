//Falcon-180B DATASET v1.0 Category: File handling ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100
#define MAX_NUM_LINES 100

typedef struct {
    char *line;
    int line_num;
} Line;

int main() {
    FILE *fp;
    char filename[50];
    char ch;
    int num_lines = 0;
    Line lines[MAX_NUM_LINES];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Read in lines and store in array
    while (fscanf(fp, "%s", lines[num_lines].line)!= EOF) {
        num_lines++;
    }

    // Sort lines alphabetically
    for (int i = 0; i < num_lines - 1; i++) {
        for (int j = i + 1; j < num_lines; j++) {
            if (strcmp(lines[i].line, lines[j].line) > 0) {
                char *temp = lines[i].line;
                lines[i].line = lines[j].line;
                lines[j].line = temp;
            }
        }
    }

    // Print sorted lines with line numbers
    printf("Sorted lines:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_num, lines[i].line);
    }

    // Close file
    fclose(fp);

    return 0;
}