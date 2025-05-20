#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_file(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);

    printf("Enter new content (type 'exit' to save and quit):\n");

    char input[MAX_LINE_LENGTH];
    while (1) {
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'e' && input[1] == 'x' && input[2] == 'i' && input[3] == 't') {
            break;
        }

        file = fopen(filename, "a");
        if (!file) {
            perror("Failed to open file for appending");
            continue;
        }

        fprintf(file, "%s", input);
        fclose(file);
    }

    printf("Content saved.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_file(argv[1]);

    return 0;
}
