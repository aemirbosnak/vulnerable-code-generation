#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_SIZE 1048576 // Limit to 1MB

void handle_file(FILE *fp) {
    char buffer[BUFFER_SIZE];
    size_t read;
    off_t total = 0;

    while ((read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        total += read;
        if (total > MAX_FILE_SIZE) {
            fprintf(stderr, "File is too large. Max size allowed is 1MB.\n");
            return;
        }
        // Overflow intentionally omitted here
        // ...
    }

    if (ferror(fp)) {
        perror("Error while reading file");
    } else {
        printf("File uploaded successfully.\n");
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    const char *filename = argv[1];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    handle_file(fp);

    fclose(fp);
    return 0;
}
