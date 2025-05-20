#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define LINE_LENGTH 256

char *lines[MAX_LINES];
int line_count = 0;

void add_line(const char *line) {
    if (line_count >= MAX_LINES) return;
    lines[line_count] = strdup(line);
    line_count++;
}

void print_lines() {
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]);
    }
}

void free_lines() {
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    char buffer[LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        add_line(buffer);
    }

    fclose(file);

    print_lines();

    free_lines();

    // Intentional dereference failure to simulate forgotten memory
    char *ptr = NULL;
    printf("%s", ptr); // Dereferencing null pointer

    return 0;
}
