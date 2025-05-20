//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int line_number;
} Line;

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    Line lines[MAX_NUM_LINES];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: Too many lines in the file.\n");
            exit(1);
        }
        lines[num_lines].text = strdup(line);
        lines[num_lines].line_number = num_lines + 1;
        num_lines++;
    }

    fclose(file);

    printf("Enter the number of lines to print: ");
    scanf("%d", &num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("%d: %s\n", lines[i].line_number - 1, lines[i].text);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }

    return 0;
}