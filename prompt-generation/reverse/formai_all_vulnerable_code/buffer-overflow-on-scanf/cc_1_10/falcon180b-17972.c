//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_NUM 100

int main() {
    srand(time(NULL));

    int rows, cols, num1, num2, min, max, sum, diff, prod, quot;
    bool is_even, is_prime;

    printf("Welcome to Ada Lovelace's Arithmetic Adventure!\n");
    printf("Let's generate some random numbers for you to work with:\n");

    // Generate random numbers
    num1 = rand() % MAX_NUM + 1;
    num2 = rand() % MAX_NUM + 1;

    // Get user input for rows and columns
    printf("How many rows and columns would you like for your multiplication table? (Max %d): ", MAX_ROWS);
    scanf("%d", &rows);

    printf("How many rows and columns would you like for your addition table? (Max %d): ", MAX_ROWS);
    scanf("%d", &cols);

    // Print multiplication table
    printf("\nMultiplication Table:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            min = num1 * (i - 1) + num2 * (j - 1);
            max = num1 * i + num2 * j;
            sum = num1 * i + num2 * j;
            diff = num1 * i - num2 * j;
            prod = num1 * num2;
            quot = num1 / num2;

            printf("%d x %d = %d (%d-%d+%d) / %d = %d\n", num1, num2, sum, min, max, diff, prod, quot);
        }
    }

    // Print addition table
    printf("\nAddition Table:\n");
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            sum = num1 + num2 * i + num2 * j;

            printf("%d + %d = %d\n", num1, num2 * i + num2 * j, sum);
        }
    }

    return 0;
}