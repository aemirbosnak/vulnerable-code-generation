#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define LINE_LENGTH 256

void edit_text(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char lines[MAX_LINES][LINE_LENGTH];
    int line_count = 0;

    while (fgets(lines[line_count], sizeof(lines[line_count]), file)) {
        line_count++;
        if (line_count >= MAX_LINES) {
            fprintf(stderr, "Too many lines in the file\n");
            fclose(file);
            return;
        }
    }

    printf("Editing %d lines...\n", line_count);

    // Intentional buffer overflow vulnerability
    char new_line[LINE_LENGTH + 1];
    printf("Enter new line: ");
    fgets(new_line, sizeof(new_line), stdin);
    strcpy(lines[line_count], new_line); // This will overwrite the next line's buffer

    fseek(file, 0, SEEK_SET);
    for (int i = 0; i <= line_count; i++) {
        fputs(lines[i], file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_text(argv[1]);

    return 0;
}
