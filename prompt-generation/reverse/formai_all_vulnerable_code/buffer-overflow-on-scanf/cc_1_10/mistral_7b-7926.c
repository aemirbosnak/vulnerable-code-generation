//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct Complex {
    double real;
    double imag;
} Complex;

typedef struct Cell {
    Complex value;
    struct Cell *down;
    struct Cell *right;
} Cell;

void print_complex(Complex c) {
    char str[50];
    if (c.imag >= 0) {
        sprintf(str, "%.2f + %.2fi", c.real, c.imag);
    } else {
        sprintf(str, "%.2f - %.2fi", c.real, -c.imag);
    }
    puts(str);
}

void visualize(Cell *root, int x, int y) {
    if (root == NULL) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                printf("\033[%d;%dH ");
                printf("%s", j % 10 > 0 ? " " : "");
            }
            puts("\033[H");
        }
        return;
    }

    int rx = x * 2 + 1, ry = y * 2 + 1;

    if (rx < 0 || rx >= WIDTH || ry < 0 || ry >= HEIGHT) {
        visualize(root->down, x, y + 1);
        return;
    }

    printf("\033[%d;%dH", ry, rx);
    print_complex(root->value);

    visualize(root->right, x + 1, y);
    visualize(root->down, x, y + 1);
}

int main() {
    int n;
    printf("Enter the number of complex numbers to store: ");
    scanf("%d", &n);

    Cell **grid = malloc(n * sizeof(Cell*));
    for (int i = 0; i < n; i++) {
        grid[i] = malloc(sizeof(Cell));
        printf("Enter the real and imaginary parts of complex number %d: ", i + 1);
        scanf("%lf %lf", &grid[i]->value.real, &grid[i]->value.imag);
        grid[i]->down = NULL;
        grid[i]->right = NULL;
    }

    Cell *root = grid[0];
    visualize(root, 0, 0);

    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}