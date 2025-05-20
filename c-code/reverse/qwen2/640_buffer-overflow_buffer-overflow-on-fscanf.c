#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char format[3];
    int width, height, max_val;

    // Vulnerable fscanf call
    fscanf(file, "%2s %d %d %d", format, &width, &height, &max_val);

    if (strcmp(format, "P2") != 0) {
        fprintf(stderr, "Unsupported format\n");
        fclose(file);
        return 1;
    }

    unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(file, "%hhu", &pixels[i][j]);
        }
    }

    fclose(file);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixels[i][j] > 127 ? '*' : ' ');
        }
        printf("\n");
    }

    return 0;
}
