//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 1000
#define MAX_COLORS 256

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

int main() {
    Pixel pixels[MAX_PIXELS];
    int num_pixels = 0;
    int num_colors = 0;
    int color_index = 0;

    printf("Enter the number of pixels: ");
    scanf("%d", &num_pixels);

    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);

    printf("Enter the colors (in RGB format): ");
    for (int i = 0; i < num_colors; i++) {
        char color_str[8];
        scanf("%s", color_str);
        int color = atoi(color_str);
        if (color < 0 || color > 255) {
            printf("Invalid color! Must be between 0 and 255.\n");
            return 1;
        }
        pixels[num_pixels].color = color;
        num_pixels++;
    }

    for (int i = 0; i < num_pixels; i++) {
        pixels[i].x = rand() % 1000;
        pixels[i].y = rand() % 1000;
    }

    printf("Pixel Art Generator\n\n");

    for (int y = 0; y < 1000; y++) {
        for (int x = 0; x < 1000; x++) {
            int color = pixels[num_pixels - 1].color;
            printf("#");
            for (int i = 0; i < 6; i++) {
                int bit = 1 << i;
                if (color & bit) {
                    printf("1");
                } else {
                    printf("0");
                }
            }
            printf(" ");
            num_pixels--;
        }
        printf("\n");
    }

    return 0;
}