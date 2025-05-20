//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET "!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?`~"

void print_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (ascii_art[i * WIDTH + j]!= '\0') {
                printf("%c", ascii_art[i * WIDTH + j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_ascii_art(char *filename) {
    FILE *fp;
    char ch;
    int i, j;
    char ascii_art[HEIGHT * WIDTH];
    memset(ascii_art, '\0', HEIGHT * WIDTH);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fread(&ch, 1, 1, fp);
            ascii_art[i * WIDTH + j] = CHAR_SET[ch % 62];
        }
    }

    fclose(fp);
    print_ascii_art(ascii_art);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    generate_ascii_art(argv[1]);

    return 0;
}