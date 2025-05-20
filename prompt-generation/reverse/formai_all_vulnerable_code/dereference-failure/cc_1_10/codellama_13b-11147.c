//Code Llama-13B DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

void generate_ascii_art(char *input, char *output) {
    int width = strlen(input);
    int height = ceil(width / (float)MAX_WIDTH);
    int row = 0;
    int col = 0;
    char *ascii_art = malloc(sizeof(char) * width * height);

    for (int i = 0; i < width * height; i++) {
        if (row == 0) {
            if (col == 0) {
                ascii_art[i] = '+';
            } else if (col == width - 1) {
                ascii_art[i] = '+';
            } else {
                ascii_art[i] = '-';
            }
        } else if (row == height - 1) {
            if (col == 0) {
                ascii_art[i] = '+';
            } else if (col == width - 1) {
                ascii_art[i] = '+';
            } else {
                ascii_art[i] = '-';
            }
        } else {
            if (col == 0) {
                ascii_art[i] = '|';
            } else if (col == width - 1) {
                ascii_art[i] = '|';
            } else {
                ascii_art[i] = ' ';
            }
        }

        if (col == width - 1) {
            row++;
            col = 0;
        } else {
            col++;
        }
    }

    FILE *fp = fopen(output, "w");
    fprintf(fp, "%s\n", ascii_art);
    fclose(fp);
    free(ascii_art);
}

int main() {
    char input[] = "Hello, World!";
    char output[] = "output.txt";
    generate_ascii_art(input, output);
    return 0;
}