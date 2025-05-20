#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_text(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    size_t line_number = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        line_number++;
        printf("%zu: %s", line_number, buffer);
    }

    fclose(file);

    // Vulnerability: Out-of-bounds read
    char *last_line = buffer + strlen(buffer) - 1;
    if (*last_line == '\n') {
        *last_line = '\0';
    }
    printf("Last character of last line: %c\n", *(last_line + 1));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit_text(argv[1]);

    return 0;
}
