//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 100
#define HEIGHT 50

char image[HEIGHT][WIDTH];

void load_image(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error loading image file\n");
        exit(1);
    }

    int row = 0;
    int col = 0;

    while (fscanf(fp, "%c", &image[row][col])!= EOF) {
        col++;
        if (col == WIDTH) {
            row++;
            col = 0;
        }
    }

    fclose(fp);
}

void print_ascii_art(int start_row, int start_col) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (image[i][j] == '0') {
                printf("  ");
            } else if (image[i][j] == '1') {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    char* input_image_filename = argv[1];
    char* output_ascii_art_filename = argv[2];

    load_image(input_image_filename);

    FILE* fp = fopen(output_ascii_art_filename, "w");
    if (fp == NULL) {
        printf("Error creating output file\n");
        exit(1);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (image[i][j] == '0') {
                fprintf(fp, "  ");
            } else if (image[i][j] == '1') {
                fprintf(fp, "* ");
            } else {
                fprintf(fp, "  ");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("ASCII art generated successfully in %s\n", output_ascii_art_filename);

    return 0;
}