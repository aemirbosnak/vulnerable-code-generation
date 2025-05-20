//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,.!? "

int main(int argc, char **argv) {
    FILE *fp;
    char filename[100];
    int i, j, k, l, n, m, r, g, b, value, index;
    unsigned char *data;
    int width, height, channels;
    float scale;
    char *output;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open the file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fread(&channels, 4, 1, fp);

    if (channels!= 3) {
        printf("Error: The image must be RGB.\n");
        exit(1);
    }

    data = (unsigned char *) malloc(width * height * 3);
    fread(data, width * height * 3, 1, fp);
    fclose(fp);

    scale = (float) WIDTH / width;
    output = (char *) malloc((WIDTH * height + 1) * sizeof(char));

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            value = 0;
            for (k = 0; k < 3; k++) {
                index = i * width + j;
                value += data[index * 3 + k] * (1.0 / 255.0);
            }
            index = i * WIDTH + j;
            output[index] = CHAR_SET[value * 58 / 255];
        }
        output[i * WIDTH] = '\0';
    }

    printf("\n%s\n", output);

    free(data);
    free(output);

    return 0;
}