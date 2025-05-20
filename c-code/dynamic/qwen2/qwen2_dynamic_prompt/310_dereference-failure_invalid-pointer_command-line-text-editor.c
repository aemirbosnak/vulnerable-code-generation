#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void edit_text(char *text) {
    char *ptr = NULL;
    *ptr = 'A'; // Dereference failure: invalid pointer
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *text = malloc(size + 1);
    if (!text) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    fread(text, 1, size, file);
    text[size] = '\0';
    fclose(file);

    printf("Original Text:\n%s\n", text);

    edit_text(text);

    printf("Edited Text:\n%s\n", text);

    free(text);
    return 0;
}
