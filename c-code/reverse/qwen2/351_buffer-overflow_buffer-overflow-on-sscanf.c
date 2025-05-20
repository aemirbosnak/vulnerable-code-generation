#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parse_dimensions(const char *filename, int *width, int *height) {
    char *dim_str = strchr(filename, 'x');
    if (!dim_str || dim_str[1] == '\0') return -1;

    *dim_str++ = '\0';
    *width = atoi(filename);
    *height = atoi(dim_str);

    if (*width <= 0 || *height <= 0) return -1;

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
        return 1;
    }

    int width, height;
    if (parse_dimensions(argv[1], &width, &height) != 0) {
        fprintf(stderr, "Invalid dimensions in filename.\n");
        return 1;
    }

    printf("Width: %d\nHeight: %d\n", width, height);

    return 0;
}
