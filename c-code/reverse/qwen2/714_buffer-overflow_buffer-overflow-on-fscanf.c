#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEADER_SIZE 1024

void process_image(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char header[MAX_HEADER_SIZE];
    int width, height, maxval;

    // Intentionally vulnerable: no bounds checking on fscanf
    fscanf(file, "%s %d %d %d", header, &width, &height, &maxval);

    printf("Header: %s\nWidth: %d\nHeight: %d\nMaxval: %d\n", header, width, height, maxval);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }

    process_image(argv[1]);

    return 0;
}
