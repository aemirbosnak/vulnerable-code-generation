#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *filename;
    size_t bytes_read;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = malloc(strlen(argv[1]) + 1);
    if (!filename) {
        perror("malloc");
        return 1;
    }

    strcpy(filename, argv[1]);

    file = fopen(filename, "r");
    if (!file) {
        perror("fopen");
        free(filename);
        return 1;
    }

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        printf("%s", buffer);
    }

    fclose(file);
    free(filename);

    // Vulnerable code
    char *long_filename = (char *)malloc(BUFFER_SIZE);
    strcpy(long_filename, filename);
    strcat(long_filename, "A" /* Add more non-ASCII characters or a long string here to exceed the buffer size */);
    printf("%s\n", long_filename);

    return 0;
}
