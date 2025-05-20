#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_text(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        file = fopen(filename, "w+");
        if (!file) {
            perror("Failed to open file");
            return;
        }
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        fseek(file, 0, SEEK_END);
        fwrite(buffer, 1, strlen(buffer), file);
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
