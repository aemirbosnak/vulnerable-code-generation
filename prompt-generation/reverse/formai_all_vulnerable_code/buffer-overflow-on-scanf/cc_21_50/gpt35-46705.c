//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>

int main() {
    int width, height, i, j, grey_scale;
    char ascii_char;

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    int image[height][width];

    printf("Enter the grey scale values of the image:\n");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            scanf("%d", &grey_scale);
            image[i][j] = grey_scale;
        }
    }

    printf("The ASCII art representation of the image is:\n");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            grey_scale = image[i][j];

            if (grey_scale >= 0 && grey_scale < 25) {
                ascii_char = '#';
            } else if (grey_scale >= 25 && grey_scale < 50) {
                ascii_char = '&';
            } else if (grey_scale >= 50 && grey_scale < 75) {
                ascii_char = '$';
            } else if (grey_scale >= 75 && grey_scale < 100) {
                ascii_char = '*';
            } else if (grey_scale >= 100 && grey_scale < 125) {
                ascii_char = 'o';
            } else if (grey_scale >= 125 && grey_scale < 150) {
                ascii_char = '|';
            } else if (grey_scale >= 150 && grey_scale < 175) {
                ascii_char = '!';
            } else if (grey_scale >= 175 && grey_scale < 200) {
                ascii_char = ';';
            } else if (grey_scale >= 200 && grey_scale < 225) {
                ascii_char = '-';
            } else {
                ascii_char = ' ';
            }

            printf("%c", ascii_char);
        }

        printf("\n");
    }

    return 0;
}