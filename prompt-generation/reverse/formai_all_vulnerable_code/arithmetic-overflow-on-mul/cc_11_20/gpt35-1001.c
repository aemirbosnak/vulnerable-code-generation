//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

char ascii_pixels[10][10] = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '.', '/', '.', '\\', ' ', ' ', ' ', ' '},
    {' ', '.', '|', 'o', 'o', '|', '.', ' ', ' ', ' '},
    {' ', '.', '|', ' ', ' ', '|', '.', ' ', ' ', ' '},
    {' ', '.', '|', ' ', '0', '|', '.', ' ', ' ', ' '},
    {' ', '.', '|', '_', '_', '|', '.', ' ', ' ', ' '},
    {' ', '-', '-', '(', ')', '-', '-', ' ', ' ', ' '},
    {' ', ' ', '/', ' ', ' ', '\\', ' ', ' ', ' ', ' '},
    {' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '},
    {' ', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' '}
};

int main() {
    int height, width;
    char filename[20];

    printf("Enter the file name (including extension): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");
    if(file == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    printf("Enter the height of the ASCII art: ");
    scanf("%d", &height);
    printf("Enter the width of the ASCII art: ");
    scanf("%d", &width);

    int pixel_size = height / 10;

    unsigned char *image = malloc(height * width);
    fread(image, width, height, file);

    unsigned char *ptr = image;
    for(int i = 0; i < height; i += pixel_size) {
        for(int j = 0; j < width; j += pixel_size) {
            int sum = 0;
            for(int k = 0; k < pixel_size; k++) {
                for(int l = 0; l < pixel_size; l++) {
                    sum += *ptr;
                    ptr++;
                }
                ptr += width - pixel_size;
            }
            sum = sum / (pixel_size * pixel_size * 3);

            if(sum > 230) {
                printf("%c", ascii_pixels[0][0]);
            } else if(sum > 200) {
                printf("%c", ascii_pixels[1][6]);
            } else if(sum > 180) {
                printf("%c", ascii_pixels[2][5]);
            } else if(sum > 160) {
                printf("%c", ascii_pixels[4][5]);
            } else if(sum > 140) {
                printf("%c", ascii_pixels[4][3]);
            } else if(sum > 120) {
                printf("%c", ascii_pixels[5][5]);
            } else if(sum > 100) {
                printf("%c", ascii_pixels[2][3]);
            } else if(sum > 80) {
                printf("%c", ascii_pixels[3][5]);
            } else if(sum > 60) {
                printf("%c", ascii_pixels[7][0]);
            } else if(sum > 40) {
                printf("%c", ascii_pixels[6][1]);
            } else if(sum > 20) {
                printf("%c", ascii_pixels[8][0]);
            } else {
                printf("%c", ascii_pixels[9][0]);
            }
        }
        printf("\n");
        ptr += width * (pixel_size - 1);
    }

    fclose(file);
    free(image);

    return 0;
}