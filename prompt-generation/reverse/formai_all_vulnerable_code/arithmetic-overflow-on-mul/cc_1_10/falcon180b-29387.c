//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to add two numbers in a funny way
void add_numbers(int num1, int num2) {
    int sum = num1 + num2;
    printf("We took %d, and added %d to it, and got %d!\n", num1, num2, sum);
}

// Function to subtract two numbers in a funny way
void subtract_numbers(int num1, int num2) {
    int diff = num1 - num2;
    printf("We took %d, and subtracted %d from it, and got %d!\n", num1, num2, diff);
}

// Function to multiply two numbers in a funny way
void multiply_numbers(int num1, int num2) {
    int prod = num1 * num2;
    printf("We took %d, and multiplied it by %d, and got %d!\n", num1, num2, prod);
}

// Function to divide two numbers in a funny way
void divide_numbers(int num1, int num2) {
    int quot = num1 / num2;
    int rem = num1 % num2;
    printf("We took %d, and divided it by %d, and got %d with a remainder of %d!\n", num1, num2, quot, rem);
}

// Function to calculate the square of a number in a funny way
void square_number(int num) {
    int sq = num * num;
    printf("We took %d, and squared it, and got %d!\n", num, sq);
}

// Function to calculate the cube of a number in a funny way
void cube_number(int num) {
    int cub = num * num * num;
    printf("We took %d, and cubed it, and got %d!\n", num, cub);
}

// Main function
int main() {
    int num1, num2;

    // Prompt the user to enter two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Perform arithmetic operations on the numbers
    add_numbers(num1, num2);
    subtract_numbers(num1, num2);
    multiply_numbers(num1, num2);
    divide_numbers(num1, num2);
    square_number(num1);
    cube_number(num1);

    return 0;
}