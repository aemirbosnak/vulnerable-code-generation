//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    FILE *input;
    FILE *output;
    char filename[100];
    char line[1000];
    int i, j, k, x, y, count;
    int width, height;
    char *buffer;
    char *p;
    int max_width = 0;
    int max_height = 0;

    // Open input file
    printf("Enter input file name: ");
    scanf("%s", filename);
    input = fopen(filename, "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Read image dimensions
    fscanf(input, "%d %d", &width, &height);

    // Allocate buffer for image data
    buffer = malloc(width * height * 3);
    if (buffer == NULL) {
        printf("Error: could not allocate memory for image data.\n");
        return 1;
    }

    // Read image data
    fread(buffer, width * height * 3, 1, input);

    // Close input file
    fclose(input);

    // Convert image data to ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            count = 0;
            x = i * width + j;
            p = &buffer[x * 3];
            if (p[0] > p[1] && p[0] > p[2]) {
                printf("*");
                count++;
            } else if (p[1] > p[0] && p[1] > p[2]) {
                printf("x");
                count++;
            } else if (p[2] > p[0] && p[2] > p[1]) {
                printf("o");
                count++;
            } else if (p[0] == p[1] && p[1] == p[2]) {
                printf(".");
                count++;
            } else if (p[0] == p[2]) {
                printf("-");
                count++;
            } else if (p[1] == p[2]) {
                printf("=");
                count++;
            } else if (p[0] == p[1]) {
                printf("+");
                count++;
            } else {
                printf(" ");
            }
            if (count < 3) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Close output file
    fclose(output);

    return 0;
}