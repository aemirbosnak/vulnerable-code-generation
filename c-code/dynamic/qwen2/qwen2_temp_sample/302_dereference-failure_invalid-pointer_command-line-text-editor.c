#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text(char *text, int line, char new_char) {
    if (line == -1) { // Invalid pointer scenario
        free(text);
        printf("Error: Invalid operation.\n");
        return;
    }
    text[line] = new_char;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file> <line> <char>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    int line = atoi(argv[2]);
    char new_char = argv[3][0];

    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *text = malloc(size + 1);
    if (!text) {
        perror("Error allocating memory");
        fclose(file);
        exit(1);
    }

    if (fread(text, 1, size, file) != size) {
        perror("Error reading file");
        free(text);
        fclose(file);
        exit(1);
    }

    text[size] = '\0';

    edit_text(text, line, new_char);

    fseek(file, 0, SEEK_SET);
    fwrite(text, 1, strlen(text), file);
    fflush(file);

    free(text);
    fclose(file);

    return 0;
}
