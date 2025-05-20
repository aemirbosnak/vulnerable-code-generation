//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, result;
    int bitwise_operator;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the bitwise operator (+, -, *, /): ");
    scanf("%d", &bitwise_operator);

    switch(bitwise_operator)
    {
        case 1:
            // Bitwise AND operation
            result = num1 & num2;
            printf("Result of Bitwise AND operation is %d", result);
            break;
        case 2:
            // Bitwise OR operation
            result = num1 | num2;
            printf("Result of Bitwise OR operation is %d", result);
            break;
        case 3:
            // Bitwise XOR operation
            result = num1 ^ num2;
            printf("Result of Bitwise XOR operation is %d", result);
            break;
        case 4:
            // Bitwise NOT operation
            result = ~num1;
            printf("Result of Bitwise NOT operation is %d", result);
            break;
        case 5:
            // Bitwise shift left operation
            result = num1 << num2;
            printf("Result of Bitwise shift left operation is %d", result);
            break;
        case 6:
            // Bitwise shift right operation
            result = num1 >> num2;
            printf("Result of Bitwise shift right operation is %d", result);
            break;
        default:
            printf("Invalid bitwise operator entered!");
    }

    return 0;
}