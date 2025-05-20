//Gemma-7B DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fractal_draw(int x, int y, int zoom) {
    int xx, yy, i, j;
    double r, g, b, hue, sat, lum;

    // Set the color palette
    r = 255.0;
    g = 0.0;
    b = 0.0;
    hue = 0.0;
    sat = 100.0;
    lum = 255.0;

    // Calculate the fractal coordinates
    xx = x * zoom;
    yy = y * zoom;

    // Iterate over the pixels
    for (i = xx; i < xx + zoom; i++) {
        for (j = yy; j < yy + zoom; j++) {
            // Calculate the distance from the origin
            double distance = sqrt(pow(i - xx, 2) + pow(j - yy, 2));

            // Set the pixel color based on the distance
            if (distance < zoom / 2) {
                r = 255 - distance * 2;
                g = distance * 2;
                b = 0.0;
            } else {
                r = 0.0;
                g = 0.0;
                b = 255 - distance * 2;
            }

            // Set the pixel
            printf("%d %d %d ", r, g, b);
        }
    }

    // Print a newline
    printf("\n");
}

int main() {
    int x, y, zoom;

    // Set the zoom level
    zoom = 10;

    // Iterate over the fractal
    for (x = 0; x < 512; x++) {
        for (y = 0; y < 512; y++) {
            fractal_draw(x, y, zoom);
        }
    }

    return 0;
}