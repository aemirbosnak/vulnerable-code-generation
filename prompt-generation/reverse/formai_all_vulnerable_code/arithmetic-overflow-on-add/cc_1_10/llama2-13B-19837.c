//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBER 1000000
#define MAGIC_NUMBER 42

int main() {
    int num1, num2, sum, product, square, square_root;
    char magic_number[20];

    printf("Welcome to the Arithmetic Adventure! \n");

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    product = 1;
    square = 0;
    square_root = 0;

    // Get the first number from the user
    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Check if the number is negative
    if (num1 < 0) {
        printf("Invalid number! Please enter a positive number.\n");
        return 1;
    }

    // Get the second number from the user
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Check if the number is negative
    if (num2 < 0) {
        printf("Invalid number! Please enter a positive number.\n");
        return 1;
    }

    // Calculate the sum
    sum = num1 + num2;

    // Calculate the product
    product = num1 * num2;

    // Calculate the square
    square = num1 * num1;

    // Calculate the square root
    square_root = sqrt(square);

    // Print the results
    printf("The sum of %d and %d is %d.\n", num1, num2, sum);
    printf("The product of %d and %d is %d.\n", num1, num2, product);
    printf("The square of %d is %d.\n", num1, square);
    printf("The square root of %d is %d.\n", square, square_root);

    // Check if the result is magical
    sprintf(magic_number, "%d", MAGIC_NUMBER);
    if (sum == magic_number[0] && product == magic_number[1] && square == magic_number[2] && square_root == magic_number[3]) {
        printf("Congratulations! You have found the magical result!\n");
    } else {
        printf("Too bad, the result is not magical.\n");
    }

    return 0;
}