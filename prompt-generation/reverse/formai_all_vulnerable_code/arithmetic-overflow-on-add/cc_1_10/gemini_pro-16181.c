//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// An array for storing Fibonacci numbers
int fib_nums[100] = {0, 1, 1};

// A 2D array for storing Fibonacci spirals
int fib_spirals[100][100] = {0};

// Function to generate Fibonacci numbers
void generate_fib_nums() {
    for (int i = 3; i < 100; i++) {
        fib_nums[i] = fib_nums[i - 1] + fib_nums[i - 2];
    }
}

// Function to generate Fibonacci spirals
void generate_fib_spirals() {
    int n = 1;
    int x = 0, y = 0;
    int dir = 0; // 0 = right, 1 = down, 2 = left, 3 = up

    while (n <= 100) {
        fib_spirals[y][x] = n;

        if (dir == 0) {
            if (x + 1 < 100 && fib_spirals[y][x + 1] == 0) {
                x++;
            } else {
                dir = 1;
                y++;
            }
        } else if (dir == 1) {
            if (y + 1 < 100 && fib_spirals[y + 1][x] == 0) {
                y++;
            } else {
                dir = 2;
                x--;
            }
        } else if (dir == 2) {
            if (x - 1 >= 0 && fib_spirals[y][x - 1] == 0) {
                x--;
            } else {
                dir = 3;
                y--;
            }
        } else if (dir == 3) {
            if (y - 1 >= 0 && fib_spirals[y - 1][x] == 0) {
                y--;
            } else {
                dir = 0;
                x++;
            }
        }

        n++;
    }
}

// Function to print Fibonacci numbers
void print_fib_nums() {
    printf("Fibonacci numbers: ");
    for (int i = 0; i < 100; i++) {
        printf("%d ", fib_nums[i]);
    }
    printf("\n");
}

// Function to print Fibonacci spirals
void print_fib_spirals() {
    printf("Fibonacci spirals:\n");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            printf("%d ", fib_spirals[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generate_fib_nums();
    generate_fib_spirals();
    print_fib_nums();
    print_fib_spirals();
    return 0;
}