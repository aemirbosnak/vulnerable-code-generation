//FormAI DATASET v1.0 Category: Arithmetic ; Style: peaceful
#include <stdio.h>

int main() {
    int num1, num2, sum = 0, prod = 1;

    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    printf("\nYou entered %d and %d\n", num1, num2);

    // Sum of two integers
    sum = num1 + num2;
    printf("\nThe sum of %d and %d is %d\n", num1, num2, sum);

    // Product of two integers
    prod = num1 * num2;
    printf("The product of %d and %d is %d\n", num1, num2, prod);

    // Check if even or odd, and positive or negative
    if (num1 % 2 == 0)
        printf("%d is an even number\n", num1);
    else
        printf("%d is an odd number\n", num1);

    if (num2 % 2 == 0)
        printf("%d is an even number\n", num2);
    else
        printf("%d is an odd number\n", num2);

    if (num1 > 0)
        printf("%d is a positive number\n", num1);
    else if (num1 < 0)
        printf("%d is a negative number\n", num1);
    else
        printf("%d is neither positive nor negative\n", num1);

    if (num2 > 0)
        printf("%d is a positive number\n", num2);
    else if (num2 < 0)
        printf("%d is a negative number\n", num2);
    else
        printf("%d is neither positive nor negative\n", num2);

    // Square and cube of the first integer
    printf("The square of %d is %d\n", num1, num1 * num1);
    printf("The cube of %d is %d\n", num1, num1 * num1 * num1);

    return 0;
}