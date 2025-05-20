//FormAI DATASET v1.0 Category: Arithmetic ; Style: thoughtful
#include <stdio.h>

/*This program demonstrates the use of arithmetic operators in C language.*/

int main() {

    int num1, num2;
    float result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    /*Let's perform some arithmetic operations*/

    /*Addition*/
    result = num1 + num2;
    printf("Addition: %d + %d = %.2f\n", num1, num2, result);

    /*Subtraction*/
    result = num1 - num2;
    printf("Subtraction: %d - %d = %.2f\n", num1, num2, result);

    /*Multiplication*/
    result = num1 * num2;
    printf("Multiplication: %d * %d = %.2f\n", num1, num2, result);

    /*Division*/
    if(num2 != 0) {
        result = (float)num1 / num2;
        printf("Division: %d / %d = %.2f\n", num1, num2, result);
    } else {
        printf("Cannot perform division as denominator is zero.\n");
    }

    /*Modulus*/
    result = num1 % num2;
    printf("Modulus: %d %% %d = %.2f\n", num1, num2, result);

    /*Increment*/
    printf("Before increment, num1 = %d\n", num1);
    num1++;
    printf("After increment, num1 = %d\n", num1);

    /*Decrement*/
    printf("Before decrement, num2 = %d\n", num2);
    num2--;
    printf("After decrement, num2 = %d\n", num2);

    return 0;
}