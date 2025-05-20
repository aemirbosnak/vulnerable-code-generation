#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_line(char *line) {
    char *ptr = line;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            *ptr = '_';
        }
        ptr++;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r+");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        edit_line(buffer);
        fseek(file, -strlen(buffer), SEEK_CUR);
        fputs(buffer, file);
    }

    fclose(file);
    return 0;
}
