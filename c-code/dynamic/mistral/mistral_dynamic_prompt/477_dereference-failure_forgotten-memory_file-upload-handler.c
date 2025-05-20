#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 5

void handle_file(FILE *fp, char *filename) {
    char buffer[BUFFER_SIZE];
    size_t read_bytes;

    // Dereference uninitialized pointer
    char *content = (char *)malloc(0);

    while ((read_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        content = realloc(content, BUFFER_SIZE * (read_bytes + 1)); // Allocate memory for content plus null terminator
        strcat(content, buffer);
    }

    // Access uninitialized memory, will lead to a dereference failure
    printf("File content: %s\n", content);
}

int main(int argc, char **argv) {
    FILE *files[MAX_FILES];
    int i;

    for (i = 1; i < argc; ++i) {
        files[i - 1] = fopen(argv[i], "r");

        if (files[i - 1] == NULL) {
            perror("Error opening file");
            return 1;
        }
    }

    for (i = 0; i < argc - 1; ++i) {
        handle_file(files[i], argv[i + 1]);
        fclose(files[i]);
    }

    return 0;
}
