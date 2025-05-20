#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void edit_line(char *line) {
    int i = 0;
    while (1) {
        char ch = getchar();
        if (ch == '\n' || ch == EOF) break;
        line[i++] = ch;
    }
    line[i] = '\0';
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

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(size + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return 1;
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    printf("Editing file: %s\n", argv[1]);

    char *line = strtok(buffer, "\n");
    while (line) {
        printf("> ");
        edit_line(line);
        line = strtok(NULL, "\n");
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, 1, strlen(buffer), file);
    fclose(file);
    free(buffer);

    return 0;
}
