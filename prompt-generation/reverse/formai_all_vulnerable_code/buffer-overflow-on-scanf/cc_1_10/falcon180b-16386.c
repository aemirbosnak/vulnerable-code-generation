//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,.?!:;\"'`~@#$%^&*()_+-=[]{}|\\;'\",./<>?"

struct pixel {
    int x;
    int y;
    int color;
};

void print_pixel(struct pixel pixel) {
    printf("\033[38;2;%d;%d;%dm ", pixel.color >> 16, (pixel.color >> 8) & 0xFF, pixel.color & 0xFF);
}

int get_color(char c) {
    int index = (int) c - 32;
    return (index % 9) * 32 + (index / 9) * 6 + 16;
}

void generate_art(char* text, int width, int height, struct pixel* pixels) {
    int x = 0, y = 0;
    for (int i = 0; i < strlen(text); i++) {
        char c = toupper(text[i]);
        if (c == '\n') {
            x = 0;
            y++;
            continue;
        }
        int color = get_color(c);
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                if ((((c - 32) / 9) * 6 + j) % 3 == 0 && ((c - 32) / 9) % 3 == 0) {
                    pixels[(y * height + j) * width + x + k].color = color;
                }
            }
        }
        x += 6;
        if (x >= width) {
            x = 0;
            y++;
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <text> <output>\n", argv[0]);
        return 1;
    }

    char* text = argv[1];
    char* output = argv[2];

    FILE* fp = fopen(output, "wb");
    if (fp == NULL) {
        printf("Error: Failed to open output file.\n");
        return 1;
    }

    int width, height;
    printf("Enter width (1-80): ");
    scanf("%d", &width);
    printf("Enter height (1-25): ");
    scanf("%d", &height);

    if (width < 1 || width > 80 || height < 1 || height > 25) {
        printf("Error: Invalid dimensions.\n");
        fclose(fp);
        return 1;
    }

    struct pixel* pixels = calloc(width * height, sizeof(struct pixel));

    generate_art(text, width, height, pixels);

    fprintf(fp, "P6\n%d %d\n255\n", width, height);

    for (int i = 0; i < width * height; i++) {
        fprintf(fp, "%d ", pixels[i].color);
    }

    fclose(fp);

    printf("Art generated successfully.\n");

    return 0;
}