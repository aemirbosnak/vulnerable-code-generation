#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.bmp>\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILENAME_LENGTH];
    strncpy(filename, argv[1], MAX_FILENAME_LENGTH - 1);
    filename[MAX_FILENAME_LENGTH - 1] = '\0';

    int width, height;
    if (sscanf(filename, "%*[^0-9]%d%*[^0-9]%d", &width, &height) != 2) {
        fprintf(stderr, "Error: Invalid filename format.\n");
        return 1;
    }

    printf("Width: %d\nHeight: %d\n", width, height);

    // TODO: Implement BMP reading and ASCII art conversion here.

    return 0;
}
