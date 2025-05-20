//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

void print_heart(int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if ((row == 0 && col % 3 != 1) || (row == 1 && col % 3 == 1) || (row - col == 2) || (row + col == size + 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void print_music(int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if ((row < size / 4 && col % 2 == 0) || (row == size / 4 && col >= size / 2) || (row >= size / 4 && row < size / 2 && col % 2 != 0 && col > size / 2 - row) || (row == size / 2 && col % 2 != 0) || (row > size / 2 && col == row - size / 2) || (row > size / 2 && col == size - (row - size / 2) - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void print_ghost(int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if ((row == 0 && col % 2 == 0) || (row == 1 && col % 2 == 0 && col != size - 2) || (row == 2 && col == 2) || (row == 2 && col == size - 3) || (row == 3 && (col == 1 || col == size - 2)) || (row == 4 && (col == 0 || col == size - 1)) || (row > 4 && row < size - 1 && col > 1 && col < size - 2) || (row == size - 1 && col == size / 2))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    int size;
    char shape;

    do {
        printf("Enter the size of the shape (odd number greater than 5): ");
        scanf("%d", &size);
    } while (size <= 5 || size % 2 == 0);

    do {
        printf("Enter the shape you want to print (H for heart, M for music, G for ghost): ");
        scanf(" %c", &shape);
    } while (shape != 'H' && shape != 'M' && shape != 'G');

    switch (shape) {
        case 'H':
            print_heart(size);
            break;
        case 'M':
            print_music(size);
            break;
        case 'G':
            print_ghost(size);
            break;
    }

    return 0;
}