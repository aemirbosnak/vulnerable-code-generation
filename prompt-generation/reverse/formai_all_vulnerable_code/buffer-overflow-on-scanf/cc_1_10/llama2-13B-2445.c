//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    int num1, num2, sum, product, square, cube;
    char op[2];

    // Initialize variables
    num1 = 5;
    num2 = 10;
    sum = 0;
    product = 0;
    square = 0;
    cube = 0;

    // Get the first operator from the user
    printf("Enter the first operator (+, -, x, /): ");
    scanf(" %c", &op[0]);

    // Perform the operation
    if (op[0] == '+') {
        sum = num1 + num2;
    } else if (op[0] == '-') {
        sum = num1 - num2;
    } else if (op[0] == 'x') {
        product = num1 * num2;
    } else if (op[0] == '/') {
        cube = num1 / num2;
    }

    // Get the second operator from the user
    printf("Enter the second operator (+, -, x, /): ");
    scanf(" %c", &op[1]);

    // Perform the operation
    if (op[1] == '+') {
        square = sum * sum;
    } else if (op[1] == '-') {
        square = sum - num2;
    } else if (op[1] == 'x') {
        product = product * num2;
    } else if (op[1] == '/') {
        cube = cube * num2;
    }

    // Print the results
    printf("Result of the first operation: %d\n", sum);
    printf("Result of the second operation: %d\n", square);
    printf("Result of the third operation: %d\n", product);
    printf("Result of the fourth operation: %d\n", cube);

    return 0;
}