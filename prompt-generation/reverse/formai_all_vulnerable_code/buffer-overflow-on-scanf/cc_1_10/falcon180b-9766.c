//Falcon-180B DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 1000

typedef struct {
    char *line;
    int line_num;
} Line;

void read_file(FILE *fp, Line *lines, int *num_lines) {
    char buffer[MAX_LINE_SIZE];
    int line_num = 0;
    while (fgets(buffer, MAX_LINE_SIZE, fp)!= NULL) {
        if (*num_lines >= MAX_NUM_LINES) {
            printf("Error: Too many lines in the file.\n");
            exit(1);
        }
        lines[*num_lines].line = strdup(buffer);
        lines[*num_lines].line_num = line_num;
        (*num_lines)++;
        line_num++;
    }
}

void write_file(FILE *fp, Line *lines, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        fprintf(fp, "%d: %s\n", lines[i].line_num, lines[i].line);
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    Line lines[MAX_NUM_LINES];
    int num_lines = 0;
    read_file(fp, lines, &num_lines);

    char new_filename[100];
    printf("Enter the name of the new file: ");
    scanf("%s", new_filename);

    FILE *new_fp = fopen(new_filename, "w");
    if (new_fp == NULL) {
        printf("Error: Could not create new file.\n");
        exit(1);
    }

    write_file(new_fp, lines, num_lines);

    fclose(fp);
    fclose(new_fp);

    printf("File successfully copied.\n");
    return 0;
}