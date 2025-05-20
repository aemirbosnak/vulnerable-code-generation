#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100

char* lines[MAX_LINES];
int line_count = 0;

void add_line(const char* str) {
    if (line_count >= MAX_LINES) return;
    lines[line_count] = strdup(str);
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        add_line(buffer);
    }

    fclose(file);

    print_lines();

    free_lines();

    // Dereference failure example
    char* ptr = NULL;
    *ptr = 'X';  // This will cause a segmentation fault

    return 0;
}
