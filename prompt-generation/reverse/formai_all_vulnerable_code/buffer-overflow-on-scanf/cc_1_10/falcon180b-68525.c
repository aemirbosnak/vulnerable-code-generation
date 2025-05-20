//Falcon-180B DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_LINES 100

typedef struct {
    char line[MAX_LINE_LENGTH];
    int length;
} Line;

int main() {
    FILE *file;
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    char filename[MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Too many lines in file.\n");
            exit(2);
        }

        strcpy(lines[num_lines].line, buffer);
        lines[num_lines].length = strlen(buffer);
        num_lines++;
    }

    fclose(file);

    printf("Enter number of lines to print: ");
    scanf("%d", &num_lines);

    if (num_lines > MAX_NUM_LINES || num_lines < 1) {
        printf("Invalid number of lines.\n");
        exit(3);
    }

    printf("Enter starting line number: ");
    scanf("%d", &num_lines);

    if (num_lines < 1 || num_lines > num_lines) {
        printf("Invalid starting line number.\n");
        exit(4);
    }

    printf("Starting at line %d:\n", num_lines);

    for (int i = num_lines - 1; i < num_lines && i < num_lines; i++) {
        printf("%s", lines[i].line);
    }

    return 0;
}