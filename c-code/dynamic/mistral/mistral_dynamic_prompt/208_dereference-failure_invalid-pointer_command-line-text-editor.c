#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

char **lines;
int num_lines = 0;

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), file)) {
        lines = realloc(lines, ++num_lines * sizeof(char*));
        lines[num_lines - 1] = strdup(line);
    }

    fclose(file);
}

void print_lines() {
    for (int i = 0; i < num_lines; ++i) {
        printf("%s", lines[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_file(argv[1]);
    print_lines();

    for (int i = 0; i < num_lines; ++i) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}
