//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

struct pixel {
    int x;
    int y;
    char c;
};

void print_pixels(struct pixel pixels[], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixels[i * width + j].c);
        }
        printf("\n");
    }
}

void generate_ascii_art(char* input_file, int width, int height) {
    FILE* fp = fopen(input_file, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char ch;
    int count = 0;
    struct pixel pixels[MAX_WIDTH * MAX_HEIGHT];

    while ((ch = fgetc(fp))!= EOF) {
        if (isspace(ch)) {
            continue;
        }

        if (count >= MAX_WIDTH * MAX_HEIGHT) {
            printf("Error: Input file is too large\n");
            exit(1);
        }

        pixels[count].x = count % width;
        pixels[count].y = count / width;
        pixels[count].c = ch;

        count++;
    }

    fclose(fp);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pixels[i * width + j].c!= '\0') {
                pixels[i * width + j].x = j;
                pixels[i * width + j].y = i;
            }
        }
    }

    print_pixels(pixels, width, height);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <width> <height>\n", argv[0]);
        exit(1);
    }

    char* input_file = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    generate_ascii_art(input_file, width, height);

    return 0;
}