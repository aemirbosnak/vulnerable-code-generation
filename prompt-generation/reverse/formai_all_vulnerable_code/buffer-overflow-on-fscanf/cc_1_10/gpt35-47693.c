//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200

char chars[] = {'$', '@', 'B', '%', '*', 'h', 'y', 'o', 'c', ';', '-', '.', ' '};
// characters sorted by brightness, from darkest to lightest

int brightness(unsigned char r, unsigned char g, unsigned char b) {
    // calculate brightness using ITU-R 601-2 luma formula
    return (299 * r + 587 * g + 114 * b) / 1000;
}

char* convert_to_ascii(unsigned char im[MAX_HEIGHT][MAX_WIDTH][3], int width, int height, int char_width, int char_height) {
    char* result = (char*)malloc(char_width * char_height * (width + 1)); // allocate enough space for the ascii art
    int char_size = sizeof(chars) / sizeof(chars[0]);
    int brightness_range = 255 / (char_size - 1);
    for (int i = 0; i < height; i += char_height) {
        for (int j = 0; j < width; j += char_width) {
            int average_brightness = 0;
            for (int y = i; y < i + char_height; y++) {
                for (int x = j; x < j + char_width; x++) {
                    unsigned char r = im[y][x][0];
                    unsigned char g = im[y][x][1];
                    unsigned char b = im[y][x][2];
                    average_brightness += brightness(r, g, b);
                }
            }
            average_brightness /= char_width * char_height;
            int selected_char = average_brightness / brightness_range;
            if (selected_char >= char_size) {
                selected_char = char_size - 1;
            }
            result[(i / char_height) * char_width * (width + 1) + (j / char_width) * char_width] = chars[selected_char];
        }
        result[(i / char_height) * char_width * (width + 1) + width] = '\n';
    }
    result[(height / char_height) * char_width * (width + 1)] = '\0';
    return result;
}

int main() {
    FILE* in = fopen("image.ppm", "rb");
    char header[3];
    int w, h, depth;
    fscanf(in, "%s", header);
    if (header[0] != 'P' || header[1] != '6') {
        printf("Not a PPM image!\n");
        fclose(in);
        return 1;
    }
    fscanf(in, "%d %d %d ", &w, &h, &depth);
    if (w > MAX_WIDTH || h > MAX_HEIGHT) {
        printf("Image is too big!\n");
        fclose(in);
        return 1;
    }
    unsigned char im[MAX_HEIGHT][MAX_WIDTH][3];
    fread(im, 3 * w, h, in);
    fclose(in);
    char* ascii_art = convert_to_ascii(im, w, h, 5, 7); // use 5x7 characters
    printf("%s\n", ascii_art);
    free(ascii_art);
    return 0;
}