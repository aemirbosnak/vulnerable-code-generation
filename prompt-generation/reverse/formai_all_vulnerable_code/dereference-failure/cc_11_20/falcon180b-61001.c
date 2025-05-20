//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

int main(void) {
    char filename[30];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int size = WIDTH * HEIGHT;
    unsigned char *image = (unsigned char*)malloc(size);

    fread(image, 1, size, fp);
    fclose(fp);

    int i, j, k;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int value = image[i * WIDTH + j];

            if (value > 128) {
                value -= 128;
            } else {
                value += 128;
            }

            image[i * WIDTH + j] = value;
        }
    }

    printf("Enter operation (1=Flip, 2=Brightness/Contrast): ");
    scanf("%d", &k);

    if (k == 1) {
        for (i = 0; i < HEIGHT; i++) {
            for (j = 0; j < WIDTH / 2; j++) {
                int temp = image[i * WIDTH + j];
                image[i * WIDTH + j] = image[i * WIDTH + WIDTH - j - 1];
                image[i * WIDTH + WIDTH - j - 1] = temp;
            }
        }
    } else if (k == 2) {
        printf("Enter brightness (0-255): ");
        scanf("%d", &i);
        printf("Enter contrast (0-255): ");
        scanf("%d", &j);

        for (int n = 0; n < size; n++) {
            int temp = image[n];

            temp += i;

            if (temp > 255) {
                temp = 255;
            } else if (temp < 0) {
                temp = 0;
            }

            temp = (temp * j) / 255;

            image[n] = temp;
        }
    }

    FILE *fp2 = fopen("result.bmp", "wb");
    if (fp2 == NULL) {
        printf("Error creating file.\n");
        return 1;
    }

    fwrite(image, 1, size, fp2);
    fclose(fp2);

    printf("Done.\n");
    return 0;
}