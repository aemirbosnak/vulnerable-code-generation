//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>
#include <string.h>
#define WIDTH 30
#define HEIGHT 5

void print_pattern(int row) {
    int i, j;
    char pattern[WIDTH];

    memset(pattern, ' ', WIDTH);

    // Print left half
    for (i = 0; i <= row; i++) {
        pattern[i] = '*';
        pattern[WIDTH - i - 1] = '*';
    }

    // Print top and bottom halves
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                putchar(pattern[j]);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    // Print right half
    for (i = row; i >= 0; i--) {
        pattern[WIDTH - i - 1] = ' ';
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                putchar(pattern[j]);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

int main() {
    int i, row;

    printf("Enter the row number: ");
    scanf("%d", &row);

    if (row < 0 || row >= HEIGHT) {
        printf("Invalid row number.\n");
        return 1;
    }

    print_pattern(row);

    return 0;
}