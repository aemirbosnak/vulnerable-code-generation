//Falcon-180B DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LINES 10000

typedef struct {
    int line_number;
    char line[MAX_LINE_LENGTH];
} Line;

void read_file(FILE *fp, Line *lines, int *num_lines) {
    int i = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        lines[i].line_number = i + 1;
        strcpy(lines[i].line, line);
        i++;
        (*num_lines)++;
    }
}

void write_file(FILE *fp, Line *lines, int num_lines) {
    int i;

    for (i = 0; i < num_lines; i++) {
        fprintf(fp, "%d: %s\n", lines[i].line_number, lines[i].line);
    }
}

void reverse_lines(Line *lines, int num_lines) {
    Line temp;
    int i, j;

    for (i = 0, j = num_lines - 1; i < j; i++, j--) {
        temp = lines[i];
        lines[i] = lines[j];
        lines[j] = temp;
    }
}

int main() {
    char filename[100];
    FILE *fp;
    Line lines[MAX_NUM_LINES];
    int num_lines = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File does not exist.\n");
        return 1;
    }

    read_file(fp, lines, &num_lines);

    printf("The original file contents:\n");
    write_file(stdout, lines, num_lines);

    reverse_lines(lines, num_lines);

    printf("\n\nThe file contents in reverse order:\n");
    write_file(stdout, lines, num_lines);

    fclose(fp);

    return 0;
}