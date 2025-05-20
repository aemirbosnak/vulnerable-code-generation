#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void processImage(char *image, int *width, int *height, int *channels) {
    char line[BUFFER_SIZE];
    char input[4];

    while (fgets(line, BUFFER_SIZE, stdin)) {
        sscanf(line, "%s %d %d %d", input, width, height, channels);
        if (!strcmp(input, "data")) {
            int pixels[BUFFER_SIZE];
            for (int i = 0; i < *width * *height * *channels; ++i)
                fscanf(stdin, "%d");
        }
    }
}

int main() {
    char *image;
    int width, height, channels;
    image = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    processImage(image, &width, &height, &channels);
    free(image);
    return 0;
}
