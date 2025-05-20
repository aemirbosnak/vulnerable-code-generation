//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80
#define HEIGHT 25

// Function to print the ASCII art
void print_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

// Function to convert image to ASCII art
void image_to_ascii_art(char *filename, char *ascii_art) {
    FILE *fp;
    int i, j, k, l, m, n, x, y, count = 0;
    unsigned char c;
    char line[WIDTH + 1];
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    fseek(fp, 54, SEEK_SET); // Skip header
    fread(&k, 4, 1, fp);
    fread(&l, 4, 1, fp);
    fread(&m, 4, 1, fp);
    fread(&n, 4, 1, fp);
    fclose(fp);
    for (i = 0; i < l; i++) {
        for (j = 0; j < m; j++) {
            x = i * m + j;
            y = 0;
            count = 0;
            while (y < k && count < 8) {
                fseek(fp, 54 + x * k + y * 4, SEEK_SET);
                fread(&c, 1, 1, fp);
                if (c < 128) {
                    ascii_art[x * HEIGHT + y] = c;
                    count++;
                }
                y++;
            }
        }
    }
}

int main() {
    char filename[100], ascii_art[WIDTH * HEIGHT];
    printf("Enter the filename: ");
    scanf("%s", filename);
    image_to_ascii_art(filename, ascii_art);
    print_ascii_art(ascii_art);
    return 0;
}