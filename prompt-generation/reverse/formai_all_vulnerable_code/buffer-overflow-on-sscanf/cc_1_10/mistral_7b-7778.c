//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h> #include <stdlib.h> #include <string.h>

#define WIDTH 21
#define HEIGHT 11
#define ASCII_ART_SIZE (WIDTH * HEIGHT)

char ascii_art[HEIGHT][WIDTH];

void generate_ascii_art(int x, int y, int value) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    switch (value) {
        case 0:
            ascii_art[y][x] = ' ';
            break;
        case 1:
            ascii_art[y][x] = '*';
            break;
        case 2:
            ascii_art[y][x] = 'O';
            break;
        case 3:
            ascii_art[y][x] = 'X';
            break;
        case 4:
            ascii_art[y][x] = '+';
            break;
        case 5:
            ascii_art[y][x] = '=';
            break;
        case 6:
            ascii_art[y][x] = '-';
            break;
        case 7:
            ascii_art[y][x] = '|';
            break;
        case 8:
            ascii_art[y][x] = '>';
            break;
        case 9:
            ascii_art[y][x] = '<';
            break;
    }
}

void print_ascii_art() {
    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", ascii_art[y][x]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int i, j, value;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <x> <y> <value>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%d", &i);
    sscanf(argv[2], "%d", &j);
    sscanf(argv[3], "%d", &value);

    generate_ascii_art(i, j, value);
    print_ascii_art();

    return 0;
}