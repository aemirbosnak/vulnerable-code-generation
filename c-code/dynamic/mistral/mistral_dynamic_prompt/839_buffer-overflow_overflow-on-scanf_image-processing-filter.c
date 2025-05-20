#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void processImage(char *image, int width, int height) {
    char buffer[10];
    int r, g, b;
    for (r = 0; r < height; ++r) {
        for (int c = 0; c < width; ++c) {
            scanf("%2s", buffer);
            sscanf(buffer, "%2x%2x%2x", &r, &g, &b);
            // Image processing logic
            r += 10;
            if (r > 255)
                r = 255;
            image[(r * width + c) * 3 + 0] = (char)r;
            image[(r * width + c) * 3 + 1] = (char)g;
            image[(r * width + c) * 3 + 2] = (char)b;
        }
    }
}

int main() {
    const int width = 100, height = 100;
    char image[width * height * 3];

    processImage(image, width, height);

    // Write the processed image to a file or stdout
    FILE *output = fopen("processed_image.bin", "wb");
    fwrite(image, sizeof(char), width * height * 3, output);
    fclose(output);

    return 0;
}
