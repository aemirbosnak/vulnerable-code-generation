#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

void edit_file(char *filename) {
    char buffer[BUFFER_SIZE];
    int len;

    FILE *file = fopen(filename, "r+");
    if (!file) {
        printf("Error: Could not open file.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    len = ftell(file);
    rewind(file);

    printf("Current file contents:\n");
    while (len > 0) {
        len--;
        if (fgetc(file) != EOF) {
            putchar(fgetc(file));
        }
    }

    printf("\nEnter new content (up to %d characters): ", BUFFER_SIZE);
    scanf("%s", buffer);

    fseek(file, 0, SEEK_SET);
    while (len > 0) {
        fputc('\b', file);
        len--;
    }

    fputs(buffer, file);

    fclose(file);
    printf("File saved.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./editor filename\n");
        return 1;
    }

    edit_file(argv[1]);

    return 0;
}
