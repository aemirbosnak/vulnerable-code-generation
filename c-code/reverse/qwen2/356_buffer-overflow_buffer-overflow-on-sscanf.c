#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int width, height;
    char filename[256];
    strncpy(filename, argv[1], sizeof(filename) - 1);
    filename[sizeof(filename) - 1] = '\0';

    if (sscanf(filename, "%dx%d.bmp", &width, &height) != 2) {
        fprintf(stderr, "Invalid filename format\n");
        return 1;
    }

    // Process image data here

    printf("Image dimensions: %d x %d\n", width, height);

    return 0;
}
