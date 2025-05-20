//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 1024
#define HEIGHT 768
#define MAX_WATERMARKS 10

typedef struct {
    char* watermark;
    int x;
    int y;
    int font_size;
    int color;
} Watermark;

int main() {
    int i, j;
    int num_watermarks = 0;
    Watermark watermarks[MAX_WATERMARKS];

    printf("Enter the number of watermarks: ");
    scanf("%d", &num_watermarks);

    for (i = 0; i < num_watermarks; i++) {
        watermarks[i].watermark = (char*)malloc(100 * sizeof(char));
        printf("Enter watermark %d: ", i+1);
        scanf("%s", watermarks[i].watermark);

        printf("Enter x coordinate: ");
        scanf("%d", &watermarks[i].x);

        printf("Enter y coordinate: ");
        scanf("%d", &watermarks[i].y);

        printf("Enter font size: ");
        scanf("%d", &watermarks[i].font_size);

        printf("Enter color (0-255): ");
        scanf("%d", &watermarks[i].color);
    }

    int image[HEIGHT][WIDTH];

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = rand() % 256;
        }
    }

    for (i = 0; i < num_watermarks; i++) {
        int x = watermarks[i].x;
        int y = watermarks[i].y;
        int font_size = watermarks[i].font_size;
        int color = watermarks[i].color;

        for (int k = 0; k < strlen(watermarks[i].watermark); k++) {
            int c = watermarks[i].watermark[k];
            int r = (color >> 16) & 0xff;
            int g = (color >> 8) & 0xff;
            int b = color & 0xff;

            for (int l = 0; l < font_size; l++) {
                for (int m = 0; m < font_size; m++) {
                    int xx = x + k*font_size + l;
                    int yy = y + m*font_size;

                    if (xx >= 0 && xx < WIDTH && yy >= 0 && yy < HEIGHT) {
                        int index = yy*WIDTH + xx;

                        image[yy][xx] = (image[yy][xx] * (256 - (c << 8)) + (c << 8)) >> 8;
                    }
                }
            }
        }
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}