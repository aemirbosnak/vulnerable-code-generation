//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes
#define MAX_LINE_LENGTH 1000 // Maximum line length in characters

typedef struct {
    char *data;
    int length;
} String;

typedef struct {
    String *lines;
    int num_lines;
} File;

void read_file(FILE *fp, File *file) {
    char buffer[MAX_LINE_LENGTH];
    String line = {0, 0};
    int line_num = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, fp)!= NULL) {
        int len = strlen(buffer);
        line.data = realloc(line.data, len + 1);
        strcpy(line.data, buffer);
        line.length = len;
        file->lines = realloc(file->lines, sizeof(String) * ++file->num_lines);
        file->lines[line_num] = line;
        line_num++;
    }
}

void write_file(FILE *fp, File *file) {
    for (int i = 0; i < file->num_lines; i++) {
        fprintf(fp, "%s", file->lines[i].data);
    }
}

int main() {
    FILE *input_fp, *output_fp;
    File input_file, output_file;

    input_fp = fopen("input.txt", "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    read_file(input_fp, &input_file);
    fclose(input_fp);

    output_fp = fopen("output.txt", "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    write_file(output_fp, &output_file);
    fclose(output_fp);

    for (int i = 0; i < input_file.num_lines; i++) {
        free(input_file.lines[i].data);
    }
    free(input_file.lines);

    for (int i = 0; i < output_file.num_lines; i++) {
        free(output_file.lines[i].data);
    }
    free(output_file.lines);

    return 0;
}