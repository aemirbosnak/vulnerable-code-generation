//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
/*
 * The Bitwise Operations Program
 *
 * This program performs various bitwise operations on two numbers.
 * It takes two integers as input and manipulates the bits according
 * to the operation selected by the user. It then prints the result
 * to the console.
 *
 * Written by [Your Name]
 *
 * Based on an idea by Linus Torvalds
 */

#include <stdio.h>

/* Define various bitwise operations */
#define OR      1
#define AND     2
#define XOR     3
#define LEFT    4
#define RIGHT   5
#define NOT     6

/* Main program */
int main()
{
    int num1, num2, result, choice;

    /* Prompt user for input */
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    /* Prompt user for operation */
    printf("Select operation:\n");
    printf("1 - Bitwise OR\n");
    printf("2 - Bitwise AND\n");
    printf("3 - Bitwise XOR\n");
    printf("4 - Shift Left\n");
    printf("5 - Shift Right\n");
    printf("6 - Bitwise NOT\n");
    printf("Enter choice (1-6): ");
    scanf("%d", &choice);

    /* Perform the selected operation */
    switch (choice) {
        case OR:
            result = num1 | num2;
            printf("%d | %d = %d\n", num1, num2, result);
            break;
        case AND:
            result = num1 & num2;
            printf("%d & %d = %d\n", num1, num2, result);
            break;
        case XOR:
            result = num1 ^ num2;
            printf("%d ^ %d = %d\n", num1, num2, result);
            break;
        case LEFT:
            result = num1 << num2;
            printf("%d << %d = %d\n", num1, num2, result);
            break;
        case RIGHT:
            result = num1 >> num2;
            printf("%d >> %d = %d\n", num1, num2, result);
            break;
        case NOT:
            result = ~num1;
            printf("~%d = %d\n", num1, result);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}