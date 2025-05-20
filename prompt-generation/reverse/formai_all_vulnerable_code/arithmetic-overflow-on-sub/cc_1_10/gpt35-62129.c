//FormAI DATASET v1.0 Category: Arithmetic ; Style: puzzling
#include <stdio.h>

int main()
{
    int num1, num2, temp;

    printf("Enter first integer: ");
    scanf("%d", &num1);

    printf("Enter second integer: ");
    scanf("%d", &num2);

    // Puzzle 1: Swap the two numbers without using a temporary variable
    num1 = num1 + num2; 
    num2 = num1 - num2;
    num1 = num1 - num2;

    printf("\nAfter swapping, first integer is: %d", num1);
    printf("\nAfter swapping, second integer is: %d", num2);

    // Puzzle 2: Multiply the two numbers without using the * operator
    int product = 0;
    while (num2 != 0)
    {
        if (num2 & 1)
            product += num1;

        num1 <<= 1;
        num2 >>= 1;
    }
    printf("\n\nThe product of the two integers is: %d", product);

    // Puzzle 3: Find the square root of the first integer using only addition and subtraction
    int squareRoot = 0, i, oddNum = 1, num = num1;
    while (num > 0)
    {
        num -= oddNum;
        oddNum += 2;
        squareRoot++;

        if (num < oddNum)
        {
            for (i = oddNum - num; i > 0; i--)
                squareRoot--;

            break;
        }
    }
    printf("\n\nThe square root of the first integer is: %d", squareRoot);

    // Puzzle 4: Determine if the second integer is a power of 2
    int isPowerOfTwo = 0;
    if (num2 != 0 && ((num2 & (num2 - 1)) == 0))
        isPowerOfTwo = 1;

    if (isPowerOfTwo)
        printf("\n\nThe second integer is a power of 2");
    else
        printf("\n\nThe second integer is not a power of 2");

    return 0;
}