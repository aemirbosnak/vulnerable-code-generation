//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

/* Function to perform bitwise AND operation */
unsigned int bitwise_and(unsigned int a, unsigned int b)
{
    return a & b;
}

/* Function to perform bitwise OR operation */
unsigned int bitwise_or(unsigned int a, unsigned int b)
{
    return a | b;
}

/* Function to perform bitwise XOR operation */
unsigned int bitwise_xor(unsigned int a, unsigned int b)
{
    return a ^ b;
}

/* Function to perform bitwise NOT operation */
unsigned int bitwise_not(unsigned int a)
{
    return ~a;
}

/* Function to perform bitwise left shift operation */
unsigned int bitwise_left_shift(unsigned int a, int n)
{
    return a << n;
}

/* Function to perform bitwise right shift operation */
unsigned int bitwise_right_shift(unsigned int a, int n)
{
    return a >> n;
}

int main()
{
    unsigned int num1, num2;
    int choice;

    /* Prompt the user to enter the first number */
    printf("Enter the first number: ");
    scanf("%u", &num1);

    /* Prompt the user to enter the second number */
    printf("Enter the second number: ");
    scanf("%u", &num2);

    /* Prompt the user to choose the operation */
    printf("Choose the operation:\n");
    printf("1. Bitwise AND\n");
    printf("2. Bitwise OR\n");
    printf("3. Bitwise XOR\n");
    printf("4. Bitwise NOT\n");
    printf("5. Bitwise left shift\n");
    printf("6. Bitwise right shift\n");
    scanf("%d", &choice);

    /* Perform the chosen operation and display the result */
    switch(choice)
    {
        case 1:
            printf("Result of bitwise AND operation: %u\n", bitwise_and(num1, num2));
            break;
        case 2:
            printf("Result of bitwise OR operation: %u\n", bitwise_or(num1, num2));
            break;
        case 3:
            printf("Result of bitwise XOR operation: %u\n", bitwise_xor(num1, num2));
            break;
        case 4:
            printf("Result of bitwise NOT operation: %u\n", bitwise_not(num1));
            break;
        case 5:
            printf("Result of bitwise left shift operation: %u\n", bitwise_left_shift(num1, num2));
            break;
        case 6:
            printf("Result of bitwise right shift operation: %u\n", bitwise_right_shift(num1, num2));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}