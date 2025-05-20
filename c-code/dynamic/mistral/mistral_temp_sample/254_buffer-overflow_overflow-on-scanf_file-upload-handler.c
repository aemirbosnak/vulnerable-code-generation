#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 1024

void handle_file(char *filename) {
    FILE *file;
    char buffer[MAX_BUF];

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("File %s is being processed...\n", filename);

    size_t read_bytes;
    while ((read_bytes = fread(buffer, sizeof(char), MAX_BUF, file)) > 0) {
        printf("Read %ld bytes from file.\n", read_bytes);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    char input[MAX_BUF];

    printf("Enter the file path to upload: ");
    scanf("%s", input);

    handle_file(input);

    return 0;
}
