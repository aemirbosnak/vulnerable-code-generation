//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This program generates random pixel art using the C programming language.
 * The art is output to a .ppm file format that can be opened and viewed in most image viewers.
 * The program asks the user for the desired resolution, size, and number of colors to use in the art.
 */

void generate_pixel_art(int size, int num_colors, int resolution) {
    int i, j, c, r, g, b;

    FILE *f;
    f = fopen("pixel_art.ppm", "w");

    // ppm header
    fprintf(f, "P3\n%d %d\n255\n", size * resolution, size * resolution);

    // generate random colors
    srand(time(NULL));
    int colors[num_colors][3];
    for (i = 0; i < num_colors; i++) {
        colors[i][0] = rand() % 256;
        colors[i][1] = rand() % 256;
        colors[i][2] = rand() % 256;
    }

    // draw the art
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // select random color
            c = rand() % num_colors;
            r = colors[c][0];
            g = colors[c][1];
            b = colors[c][2];

            // draw the pixel
            for (int k = 0; k < resolution; k++) {
                for (int l = 0; l < resolution; l++) {
                    fprintf(f, "%d %d %d ", r, g, b);
                }
            }
        }
        fprintf(f, "\n");
    }

    fclose(f);
}

int main() {
    int size, num_colors, resolution;

    // get user input
    printf("Enter the size of the art (in pixels): ");
    scanf("%d", &size);

    printf("Enter the number of colors to use: ");
    scanf("%d", &num_colors);

    printf("Enter the resolution (in pixels) of each color block: ");
    scanf("%d", &resolution);

    // generate the art and output to file
    generate_pixel_art(size, num_colors, resolution);

    return 0;
}