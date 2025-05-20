//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000
#define MAX_ROWS 100
#define MAX_COLS 100

// Function to generate a random color
void getRandomColor(int *r, int *g, int *b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

// Function to print a number with leading zeros
void printNumber(int num, int width) {
    if (num == 0) {
        printf("0");
    } else {
        int i = 0;
        while (i < width - 1) {
            printf("0");
            i++;
        }
        printf("%d", num);
    }
}

// Function to print the Fibonacci sequence in a grid
void printFibonacciGrid(int numbers[], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", numbers[i * cols + j]);
        }
        printf("\n");
    }
}

// Function to generate the Fibonacci sequence
void generateFibonacci(int numbers[], int num) {
    numbers[0] = 0;
    numbers[1] = 1;
    int i;
    for (i = 2; i < num; i++) {
        numbers[i] = numbers[i - 1] + numbers[i - 2];
    }
}

int main() {
    srand(time(NULL));

    int numbers[MAX_NUMBERS];
    int num, rows, cols;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &num);

    printf("Enter the number of rows for the grid: ");
    scanf("%d", &rows);

    printf("Enter the number of columns for the grid: ");
    scanf("%d", &cols);

    generateFibonacci(numbers, num);

    printf("Fibonacci sequence:\n");
    for (int i = 0; i < num; i++) {
        printNumber(numbers[i], 5);
        printf("\n");
    }

    printf("Grid of Fibonacci numbers:\n");
    printFibonacciGrid(numbers, rows, cols);

    return 0;
}