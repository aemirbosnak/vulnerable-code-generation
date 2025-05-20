//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-=+[{]}\\|;:'\",<.>/?`~"

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[50];
    char *data;
    int size, i, j, k;
    int r, g, b;
    int gray;
    int x, y;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    data = (char *)malloc(size);
    if (data == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    fread(data, size, 1, fp);
    fclose(fp);

    for (i = 0; i < size; i += 3) {
        r = data[i];
        g = data[i + 1];
        b = data[i + 2];

        gray = (r + g + b) / 3;

        for (j = 0; j < 3; j++) {
            x = i / 3 * WIDTH + j;
            y = HEIGHT - 1 - (i / 3 + 1) * 2;

            if (gray >= 128) {
                printf("%c", CHAR_SET[j]);
            } else {
                printf(" ");
            }
        }
    }

    free(data);
    return 0;
}