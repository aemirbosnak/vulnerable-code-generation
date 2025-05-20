//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ASCII_CHARS[] = {" ", ".", "_", "-", "+", "*", "'", "`", "^", "\"", ",", ":", ";", "<", ">", "!", "l", "i", "t", "L", "I", "?", "r", "x", "z", "v", "u", "J", "C", "Y", "U", "O", "X", "Z", "0", "Q", "Z", "X", "K", "B", "M", "W", "H", "A", "R", "D", "N", "E", "B", "@", "$", "8"};

char get_gray_scale(int r, int g, int b) {
    return (0.3 * r + 0.59 * g + 0.11 * b) / 25.5;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_image> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char* file_name = argv[1];
    FILE* infile = fopen(file_name, "rb");
    if (!infile) {
        printf("Error: Couldn't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, infile);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    unsigned char pixel_data[height][width][3];
    fread(pixel_data, sizeof(unsigned char), height * width * 3, infile);
    fclose(infile);

    FILE* outfile = fopen(argv[2], "w");
    if (!outfile) {
        printf("Error: Couldn't create output file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char gs = get_gray_scale(pixel_data[i][j][2], pixel_data[i][j][1], pixel_data[i][j][0]);
            int idx = (int)(gs * (sizeof(ASCII_CHARS) / sizeof(ASCII_CHARS[0]) - 1));
            fprintf(outfile, "%s", ASCII_CHARS[idx]);
        }
        fprintf(outfile, "\n");
    }

    fclose(outfile);

    return EXIT_SUCCESS;
}