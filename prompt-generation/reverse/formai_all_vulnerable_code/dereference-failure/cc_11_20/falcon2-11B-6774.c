//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Global variables
int width, height, x, y;
int red, green, blue;

int main(int argc, char *argv[]) {
    // Default values
    width = 800;
    height = 600;
    x = 0;
    y = 0;
    red = 255;
    green = 0;
    blue = 0;

    // Check for command line arguments
    if (argc > 1) {
        char *arg = argv[1];
        if (!strcmp(arg, "-w")) {
            sscanf(argv[2], "%d", &width);
        }
        else if (!strcmp(arg, "-h")) {
            sscanf(argv[2], "%d", &height);
        }
        else if (!strcmp(arg, "-x")) {
            sscanf(argv[2], "%d", &x);
        }
        else if (!strcmp(arg, "-y")) {
            sscanf(argv[2], "%d", &y);
        }
        else if (!strcmp(arg, "-r")) {
            sscanf(argv[2], "%d", &red);
        }
        else if (!strcmp(arg, "-g")) {
            sscanf(argv[2], "%d", &green);
        }
        else if (!strcmp(arg, "-b")) {
            sscanf(argv[2], "%d", &blue);
        }
    }

    // Open the image file
    FILE *imgFile = fopen("image.ppm", "w");
    if (!imgFile) {
        perror("Error opening image file");
        exit(1);
    }

    // Write the header of the image file
    fprintf(imgFile, "P3\n%d %d\n255\n", width, height);

    // Draw the pixels
    for (int yy = 0; yy < height; yy++) {
        for (int xx = 0; xx < width; xx++) {
            int r = red;
            int g = green;
            int b = blue;

            char line[1024];
            sprintf(line, "%d %d %d\n", xx, yy, r * 255 + g * 127 + b * 63);
            fputs(line, imgFile);
        }
    }

    // Close the image file
    fclose(imgFile);

    return 0;
}