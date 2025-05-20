//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// This function takes a gray scale value and returns the corresponding ASCII character
char gray_to_char(int gray_value) {
    char char_map[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_chars = 10;
    int step_size = 255 / num_chars;
    int char_index = gray_value / step_size;
    if (char_index >= num_chars) {
        char_index = num_chars-1;
    }
    return char_map[char_index];
}

// This function reads a gray scale image from a file and stores it in the 2D array 'image'
void read_image(FILE* fp, int image[MAX_HEIGHT][MAX_WIDTH], int* width, int* height) {
    char magic_num[3];
    fscanf(fp, "%s\n", magic_num);
    if (strcmp(magic_num, "P2") != 0) {
        fprintf(stderr, "Error: Input image should be a PGM file\n");
        exit(1);
    }
    fscanf(fp, "%d %d\n", width, height);
    int max_value;
    fscanf(fp, "%d\n", &max_value);
    if (max_value > 255) {
        fprintf(stderr, "Error: Input image must be an 8-bit PGM file\n");
        exit(1);
    }
    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            int gray_value;
            fscanf(fp, "%d ", &gray_value);
            image[i][j] = gray_value;
        }
    }
}

// This function prints the 2D array 'image' as an ASCII art
void print_ascii_art(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", gray_to_char(image[i][j]));
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }
    char* input_file = argv[1];
    FILE* fp = fopen(input_file, "r");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file\n");
        exit(1);
    }
    int image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    read_image(fp, image, &width, &height);
    fclose(fp);
    print_ascii_art(image, width, height);
    return 0;
}