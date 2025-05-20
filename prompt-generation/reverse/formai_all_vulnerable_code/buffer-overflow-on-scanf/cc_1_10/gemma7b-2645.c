//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char img[1000];
    printf("Enter image data (separate pixels with spaces): ");
    scanf("%s", img);

    int w, h;
    printf("Enter image width and height: ");
    scanf("%d %d", &w, &h);

    char ascii_img[w * h];
    for (int i = 0; i < w * h; i++) {
        ascii_img[i] = '-';
    }

    int pixel_count = 0;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            int pixel_value = img[pixel_count] - 48;
            switch (pixel_value) {
                case 0:
                    ascii_img[pixel_count] = ' ';
                    break;
                case 1:
                    ascii_img[pixel_count] = '.';
                    break;
                case 2:
                    ascii_img[pixel_count] = '*';
                    break;
                case 3:
                    ascii_img[pixel_count] = '#';
                    break;
                default:
                    ascii_img[pixel_count] = '=';
                    break;
            }
            pixel_count++;
        }
    }

    printf("Ascii image:\n");
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%c ", ascii_img[i * w + j]);
        }
        printf("\n");
    }

    return 0;
}