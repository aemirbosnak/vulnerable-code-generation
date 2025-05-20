//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* Bitwise operators */
unsigned int and(unsigned int a, unsigned int b)
{
    return a & b;
}

unsigned int or(unsigned int a, unsigned int b)
{
    return a | b;
}

unsigned int xor(unsigned int a, unsigned int b)
{
    return a ^ b;
}

unsigned int not(unsigned int a)
{
    return ~a;
}

unsigned int shift_left(unsigned int a, int b)
{
    return a << b;
}

unsigned int shift_right(unsigned int a, int b)
{
    return a >> b;
}

/* Function to print binary representation of a number */
void print_binary(unsigned int num)
{
    int i;
    char str[33];
    str[32] = '\0';
    for (i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            str[i] = '1';
        } else {
            str[i] = '0';
        }
    }
    printf("%s\n", str);
}

/* Function to perform bitwise operations on two numbers */
void perform_operation(unsigned int a, unsigned int b, int operation)
{
    switch (operation) {
        case 1:
            printf("AND: ");
            print_binary(and(a, b));
            break;
        case 2:
            printf("OR: ");
            print_binary(or(a, b));
            break;
        case 3:
            printf("XOR: ");
            print_binary(xor(a, b));
            break;
        case 4:
            printf("NOT: ");
            print_binary(not(a));
            break;
        case 5:
            printf("Shift left by: ");
            printf("%d\n", b);
            print_binary(shift_left(a, b));
            break;
        case 6:
            printf("Shift right by: ");
            printf("%d\n", b);
            print_binary(shift_right(a, b));
            break;
        default:
            printf("Invalid operation.\n");
            break;
    }
}

/* Main function */
int main()
{
    int operation, i;
    unsigned int num1, num2;

    /* Get input from user */
    printf("Enter two unsigned integers: ");
    scanf("%u %u", &num1, &num2);
    printf("Enter the operation you want to perform (1 = AND, 2 = OR, 3 = XOR, 4 = NOT, 5 = Shift left, 6 = Shift right): ");
    scanf("%d", &operation);

    /* Perform the selected operation */
    perform_operation(num1, num2, operation);

    return 0;
}