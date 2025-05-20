//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_PIXELS 10000
#define MAX_DISTANCE 100
#define MAX_ANGLE 100

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

int main() {
    srand(time(NULL));

    Pixel *pixels = calloc(MAX_PIXELS, sizeof(Pixel));

    int pixelCount = 0;
    int maxDistance = rand() % MAX_DISTANCE + 1;
    int maxAngle = rand() % MAX_ANGLE + 1;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            int distance = sqrt(pow(i - WIDTH / 2, 2) + pow(j - HEIGHT / 2, 2));

            if (distance <= maxDistance) {
                int angle = atan2(j - HEIGHT / 2, i - WIDTH / 2);

                if (angle >= 0 && angle <= M_PI) {
                    int r = 255 * cos(angle);
                    int g = 255 * sin(angle);
                    int b = 0;

                    if (pixelCount >= MAX_PIXELS) {
                        break;
                    }

                    pixels[pixelCount++] = (Pixel) {
                       .x = i,
                       .y = j,
                       .r = r,
                       .g = g,
                       .b = b
                    };
                }
            }
        }
    }

    printf("P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;

            if (index < pixelCount) {
                Pixel pixel = pixels[index];

                printf("%d %d %d\n", pixel.r, pixel.g, pixel.b);
            } else {
                printf("0 0 0\n");
            }
        }
    }

    free(pixels);

    return 0;
}