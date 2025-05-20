//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // Width of the ASCII art
#define HEIGHT 60 // Height of the ASCII art
#define CHAR_SET ".,-~:;=!*#@" // Character set for ASCII art

void read_image(char* filename, unsigned char image[HEIGHT][WIDTH]) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    unsigned char* buffer = malloc(filesize);
    if (buffer == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    fread(buffer, 1, filesize, fp);
    fclose(fp);

    int x = 0, y = 0;
    for (int i = 0; i < filesize; i += 3) {
        image[y][x] = buffer[i];
        x++;
        if (x == WIDTH) {
            x = 0;
            y++;
        }
    }
}

void print_ascii_art(unsigned char image[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", CHAR_SET[image[y][x]]);
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii_art.txt\n", argv[0]);
        exit(1);
    }

    char input_filename[256];
    strcpy(input_filename, argv[1]);

    char output_filename[256];
    strcpy(output_filename, argv[2]);

    unsigned char image[HEIGHT][WIDTH];
    read_image(input_filename, image);

    FILE* fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file %s.\n", output_filename);
        exit(1);
    }

    print_ascii_art(image);

    fclose(fp);

    printf("ASCII art saved to %s.\n", output_filename);

    return 0;
}