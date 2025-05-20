//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define DELAY 10000 // 10 seconds

void draw_ascii(char *image_data) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            char c = image_data[y * WIDTH + x];
            printf("%c", c);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char image_data[HEIGHT * WIDTH];
    int i, j, k;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (size!= HEIGHT * WIDTH) {
        printf("Error: image size does not match %dx%d.\n", WIDTH, HEIGHT);
        exit(1);
    }

    fread(image_data, sizeof(char), size, fp);
    fclose(fp);

    printf("Press any key to display ASCII art...\n");
    getchar();

    draw_ascii(image_data);

    printf("Press any key to exit...\n");
    getchar();

    return 0;
}