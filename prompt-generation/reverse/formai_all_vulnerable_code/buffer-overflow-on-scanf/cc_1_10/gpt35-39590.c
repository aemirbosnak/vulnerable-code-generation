//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void clear_matrix(char matrix[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void print_matrix(char matrix[HEIGHT][WIDTH]) {
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            putchar(matrix[i][j]);
        }
        putchar('\n');
    }
}

void set_pixel(char matrix[HEIGHT][WIDTH], int x, int y, char c) {
    if(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        matrix[y][x] = c;
    }
}

void draw_square(char matrix[HEIGHT][WIDTH], int x, int y, int size, char c) {
    for(int i = y; i < y + size && i < HEIGHT; i++) {
        for(int j = x; j < x + size && j < WIDTH; j++) {
            set_pixel(matrix, j, i, c);
        }
    }
}

void draw_triangle(char matrix[HEIGHT][WIDTH], int x, int y, int base, char c) {
    for(int i = 0; i < base && y + i < HEIGHT; i++) {
        for(int j = x + i; j <= x + base - i - 1 && j < WIDTH; j++) {
            set_pixel(matrix, j, y + i, c);
        }
    }
}

void draw_pixel_art(char matrix[HEIGHT][WIDTH], int choice) {
    if(choice == 1) {
        draw_square(matrix, 0, 0, 5, 'X');
    } else if(choice == 2) {
        draw_triangle(matrix, 0, 0, 5, 'O');
    } else if(choice == 3) {
        draw_square(matrix, 2, 2, 6, 'T');
    } else if(choice == 4) {
        draw_triangle(matrix, 5, 5, 4, '@');
    } else if(choice == 5) {
        draw_square(matrix, 1, 1, 8, '%');
        draw_triangle(matrix, 0, 3, 6, '#');
        draw_triangle(matrix, 1, 6, 4, '&');
    }
}

int main() {
    char matrix[HEIGHT][WIDTH];
    int choice;
    clear_matrix(matrix);
    printf("Enter your choice of pixel art (1-5):\n");
    scanf("%d", &choice);
    draw_pixel_art(matrix, choice);
    print_matrix(matrix);
    return 0;
}