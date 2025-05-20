//GEMINI-pro DATASET v1.0 Category: System boot optimizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PAGESIZE 4096

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read file
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buffer = malloc(filesize);
    if (!buffer) {
        perror("malloc");
        fclose(fp);
        return EXIT_FAILURE;
    }
    if (fread(buffer, 1, filesize, fp) != filesize) {
        perror("fread");
        fclose(fp);
        free(buffer);
        return EXIT_FAILURE;
    }
    fclose(fp);

    // Optimize file
    size_t newsize = 0;
    for (size_t i = 0; i < filesize; i += PAGESIZE) {
        // Check if page is empty
        int empty = 1;
        for (size_t j = 0; j < PAGESIZE; j++) {
            if (buffer[i + j]) {
                empty = 0;
                break;
            }
        }
        if (empty) continue;

        // Copy page to new buffer
        memcpy(buffer + newsize, buffer + i, PAGESIZE);
        newsize += PAGESIZE;
    }

    // Write optimized file
    fp = fopen(argv[1], "wb");
    if (!fp) {
        perror("fopen");
        free(buffer);
        return EXIT_FAILURE;
    }
    if (fwrite(buffer, 1, newsize, fp) != newsize) {
        perror("fwrite");
        fclose(fp);
        free(buffer);
        return EXIT_FAILURE;
    }
    fclose(fp);

    // Free memory
    free(buffer);

    return EXIT_SUCCESS;
}