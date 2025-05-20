//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *text;
    int length;
} Line;

Line *read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        exit(1);
    }

    Line *lines = malloc(sizeof(Line) * MAX_NUM_LINES);
    int num_lines = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file)!= NULL) {
        if (num_lines >= MAX_NUM_LINES) {
            fprintf(stderr, "Error: file contains too many lines\n");
            exit(1);
        }

        int length = strlen(buffer);
        lines[num_lines].text = malloc(length + 1);
        strcpy(lines[num_lines].text, buffer);
        lines[num_lines].length = length;

        num_lines++;
    }

    fclose(file);

    return lines;
}

void write_file(const char *filename, Line *lines, int num_lines) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file '%s' for writing\n", filename);
        exit(1);
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file, "%s", lines[i].text);
    }

    fclose(file);
}

int main() {
    const char *filename = "example.txt";

    Line *lines = read_file(filename);
    int num_lines = 0;

    printf("Enter the number of lines to delete (0 to cancel): ");
    int num_delete;
    scanf("%d", &num_delete);

    if (num_delete > 0) {
        printf("Enter the line number to delete (1-%d): ", num_lines);
        int line_num;
        scanf("%d", &line_num);

        if (line_num < 1 || line_num > num_lines) {
            fprintf(stderr, "Invalid line number\n");
            exit(1);
        }

        for (int i = line_num - 1; i < num_lines - 1; i++) {
            lines[i] = lines[i + 1];
        }

        num_lines--;
    }

    write_file(filename, lines, num_lines);

    for (int i = 0; i < num_lines; i++) {
        printf("%s\n", lines[i].text);
    }

    free(lines);

    return 0;
}