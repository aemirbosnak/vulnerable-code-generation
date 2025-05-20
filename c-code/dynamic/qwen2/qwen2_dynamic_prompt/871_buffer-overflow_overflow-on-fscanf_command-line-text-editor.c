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

    printf("Editing file: %s\n", filename);
    printf("Enter text ('exit' to save and quit):\n");

    while (1) {
        char line[MAX_LINE_LENGTH];
        if (fgets(line, sizeof(line), stdin)) {
            if (strcmp(line, "exit\n") == 0) {
                break;
            }
            fprintf(file, "%s", line);
        } else {
            break;
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
