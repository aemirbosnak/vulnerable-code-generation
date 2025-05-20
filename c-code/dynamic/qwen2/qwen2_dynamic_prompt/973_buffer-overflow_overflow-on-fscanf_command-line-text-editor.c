#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_file(const char *filename) {
    FILE *file = fopen(filename, "a+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    printf("Enter lines to append. Type 'exit' to finish.\n");

    while (1) {
        fgets(line, sizeof(line), stdin);
        if (feof(stdin)) break;

        // Vulnerability: No bounds checking on fscanf
        int num_lines = 0;
        fscanf(line, "%d", &num_lines);

        if (strcmp(line, "exit\n") == 0) {
            break;
        } else if (num_lines > 0) {
            for (int i = 0; i < num_lines; i++) {
                fprintf(file, "Line %d\n", i + 1);
            }
        } else {
            fprintf(file, "%s", line);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_file(argv[1]);

    return 0;
}
