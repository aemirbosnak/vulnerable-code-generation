#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

void edit_text(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(lines[line_count], MAX_LINE_LENGTH, file)) {
        line_count++;
        if (line_count >= MAX_LINES) break;
    }

    fclose(file);

    for (int i = 0; i < line_count; i++) {
        printf("%d: %s", i + 1, lines[i]);
    }

    // Intentional dereference failure
    char *ptr = NULL;
    *ptr = 'A';  // This will cause a segmentation fault

    printf("Editing mode...\n");
    while (1) {
        printf("> ");
        char input[256];
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q' && input[1] == '\n') break;
        if (input[0] == 'w' && input[1] == '\n') {
            file = fopen(filename, "w");
            if (!file) {
                printf("Error writing to file: %s\n", filename);
                continue;
            }
            for (int i = 0; i < line_count; i++) {
                fputs(lines[i], file);
            }
            fclose(file);
        } else {
            int index = atoi(input);
            if (index > 0 && index <= line_count) {
                printf("Enter new line: ");
                fgets(lines[index - 1], MAX_LINE_LENGTH, stdin);
            } else {
                printf("Invalid line number.\n");
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_text(argv[1]);

    return 0;
}
