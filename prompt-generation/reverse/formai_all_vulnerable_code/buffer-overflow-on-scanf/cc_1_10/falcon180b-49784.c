//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

typedef struct {
    char ch;
    int fg_color;
    int bg_color;
} Cell;

void print_cell(Cell cell) {
    printf("\e[38;5;%dm\e[48;5;%dm%c\e[0m", cell.fg_color, cell.bg_color, cell.ch);
}

void print_row(Cell *row, int width) {
    for (int i = 0; i < width; i++) {
        print_cell(row[i]);
    }
    printf("\n");
}

void print_art(Cell *art, int height, int width) {
    for (int y = 0; y < height; y++) {
        print_row(art + y * width, width);
    }
}

int main() {
    Cell *art = malloc(MAX_HEIGHT * MAX_WIDTH * sizeof(Cell));
    if (!art) {
        printf("Error allocating memory\n");
        return 1;
    }

    int width, height;
    char *text = "Hello, world!";
    printf("Enter the width of the art (1-%d): ", MAX_WIDTH);
    scanf("%d", &width);
    printf("Enter the height of the art (1-%d): ", MAX_HEIGHT);
    scanf("%d", &height);

    int x = (MAX_WIDTH - width) / 2;
    int y = (MAX_HEIGHT - height) / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            art[i * MAX_WIDTH + j].ch = text[i * width + j];
            art[i * MAX_WIDTH + j].fg_color = 0;
            art[i * MAX_WIDTH + j].bg_color = 0;
        }
    }

    print_art(art, height, width);

    free(art);

    return 0;
}