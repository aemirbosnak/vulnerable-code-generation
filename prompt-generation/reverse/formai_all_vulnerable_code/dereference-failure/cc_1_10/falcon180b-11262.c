//Falcon-180B DATASET v1.0 Category: Text processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int num_lines = 0;
    Line lines[MAX_NUM_LINES];

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            printf("Error: too many lines\n");
            exit(1);
        }

        int length = strlen(buffer);
        lines[num_lines].text = malloc(length + 1);
        strcpy(lines[num_lines].text, buffer);
        lines[num_lines].length = length;

        num_lines++;
    }

    fclose(file);

    printf("Number of lines: %d\n", num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("Line %d: %s\n", i + 1, lines[i].text);
    }

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }

    return 0;
}