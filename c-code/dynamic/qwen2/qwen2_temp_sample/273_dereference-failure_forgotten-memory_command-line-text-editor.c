#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define LINE_LENGTH 1024

char *lines[MAX_LINES];

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }

    int line_count = 0;
    while (line_count < MAX_LINES && fgets(lines[line_count], LINE_LENGTH, file)) {
        line_count++;
    }

    fclose(file);
}

void write_file(const char *filename, int line_count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }

    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
}

void insert_line(int line_num, const char *new_line) {
    if (line_num >= MAX_LINES || line_num < 0) {
        return;
    }
    strcpy(lines[line_num], new_line);
}

void delete_line(int line_num) {
    if (line_num >= MAX_LINES || line_num < 0) {
        return;
    }
    free(lines[line_num]);
    lines[line_num] = NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    read_file(argv[1]);

    // Intentional error: Dereferencing a null pointer
    delete_line(MAX_LINES);

    write_file(argv[2], MAX_LINES);

    for (int i = 0; i < MAX_LINES; i++) {
        free(lines[i]);
    }

    return 0;
}
