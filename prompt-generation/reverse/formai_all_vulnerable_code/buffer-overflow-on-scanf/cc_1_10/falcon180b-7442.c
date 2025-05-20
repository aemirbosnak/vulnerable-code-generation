//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLUMNS 100
#define MAX_NUMBERS 1000

// Function to generate a random Fibonacci number
int generateFibonacciNumber(int max) {
    int num1 = 0, num2 = 1, nextTerm;
    int randomIndex = rand() % max; // Generate a random index within the range of max
    
    for (int i = 0; i < randomIndex; i++) {
        nextTerm = num1 + num2;
        num1 = num2;
        num2 = nextTerm;
    }
    
    return num1;
}

// Function to print the Fibonacci sequence in a spiral pattern
void printFibonacciSpiral(int rows, int columns, int numbers) {
    int top = 0, left = 0, bottom = rows - 1, right = columns - 1;
    int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up
    int count = 0;

    while (count < numbers) {
        for (int i = 0; i < 4; i++) {
            switch (direction) {
                case 0:
                    printf("%d ", generateFibonacciNumber(MAX_NUMBERS));
                    top++;
                    break;
                case 1:
                    printf("%d ", generateFibonacciNumber(MAX_NUMBERS));
                    bottom--;
                    break;
                case 2:
                    printf("%d ", generateFibonacciNumber(MAX_NUMBERS));
                    left--;
                    break;
                case 3:
                    printf("%d ", generateFibonacciNumber(MAX_NUMBERS));
                    right++;
                    break;
            }
        }

        if (++direction > 3)
            direction = 0;

        count++;
    }
}

int main() {
    int rows, columns, numbers;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &numbers);

    if (rows <= 0 || columns <= 0 || numbers <= 0 || numbers > MAX_NUMBERS) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Generating Fibonacci sequence...\n");
    printFibonacciSpiral(rows, columns, numbers);

    return 0;
}