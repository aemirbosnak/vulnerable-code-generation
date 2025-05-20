//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's create a canvas filled with a beautiful shade of lime!
    const int width = 800;
    const int height = 600;
    unsigned char *pixels = malloc(width * height * 3);
    for (int i = 0; i < width * height; i++) {
        pixels[i * 3 + 0] = 0xFF;  // Red
        pixels[i * 3 + 1] = 0xFF;  // Green
        pixels[i * 3 + 2] = 0x00;  // Blue
    }

    // Now, let's draw a happy little tree!
    int tree_x = width / 2;
    int tree_y = height / 2;
    for (int y = 0; y < height / 2; y++) {
        for (int x = 0; x < width / 2; x++) {
            if (x < tree_x && y < tree_y && x > tree_x - y && y > tree_y - x) {
                pixels[(tree_x + x + (tree_y - y) * width) * 3 + 0] = 0x00;  // Red
                pixels[(tree_x + x + (tree_y - y) * width) * 3 + 1] = 0xFF;  // Green
                pixels[(tree_x + x + (tree_y - y) * width) * 3 + 2] = 0x00;  // Blue
            }
        }
    }

    // And, of course, no tree is complete without a trunk!
    for (int y = tree_y; y < height; y++) {
        for (int x = tree_x - 1; x < tree_x + 1; x++) {
            pixels[(x + y * width) * 3 + 0] = 0x80;  // Red
            pixels[(x + y * width) * 3 + 1] = 0x80;  // Green
            pixels[(x + y * width) * 3 + 2] = 0x00;  // Blue
        }
    }

    // Time to add some clouds to the picture! Let's make them fluffy like cotton candy.
    for (int i = 0; i < 100; i++) {
        int cloud_x = rand() % width;
        int cloud_y = rand() % height / 2;
        int cloud_size = rand() % 100 + 50;
        for (int y = 0; y < cloud_size; y++) {
            for (int x = 0; x < cloud_size; x++) {
                if ((x - cloud_size / 2) * (x - cloud_size / 2) + (y - cloud_size / 2) * (y - cloud_size / 2) < cloud_size * cloud_size / 4) {
                    pixels[(cloud_x + x + (cloud_y + y) * width) * 3 + 0] = 0xFF;  // Red
                    pixels[(cloud_x + x + (cloud_y + y) * width) * 3 + 1] = 0xFF;  // Green
                    pixels[(cloud_x + x + (cloud_y + y) * width) * 3 + 2] = 0xFF;  // Blue
                }
            }
        }
    }

    // Finally, let's save our masterpiece to a file!
    FILE *fp = fopen("image.bmp", "wb");
    fprintf(fp, "BM%c%c%c%c%c%c%c%c%c", 0x42, 0x4D,
            (unsigned char)(width % 256), (unsigned char)(width / 256),
            (unsigned char)(height % 256), (unsigned char)(height / 256),
            0x00, 0x00, 0x00, 0x00);
    fwrite(pixels, width * height * 3, 1, fp);
    fclose(fp);

    printf("Your masterpiece has been saved to image.bmp! Go forth and show it to the world!\n");

    return 0;
}