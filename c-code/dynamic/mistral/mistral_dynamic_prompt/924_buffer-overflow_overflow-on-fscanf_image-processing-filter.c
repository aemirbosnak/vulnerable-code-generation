#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024

void process_image(char *filename) {
    FILE *file;
    int width, height, i, j;
    char data[MAX_INPUT];

    file = fopen(filename, "r");
    if (!file) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }

    fscanf(file, "%d %d\n", &width, &height);
    printf("Image dimensions: %d x %d\n", width, height);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(file, "%c", data + sizeof(data) - (4 * (i * width + j)));
            // deliberate overflow in the buffer
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./image_filter <image_file>\n");
        exit(1);
    }

    process_image(argv[1]);

    return 0;
}
