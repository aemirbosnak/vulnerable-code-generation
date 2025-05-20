//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, c;
    int sum, diff, prod, quot;
    int gcd, lcm;
    float avg;
    char choice;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Please enter your choice of operation:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    scanf("%c", &choice);

    switch(choice) {
        case 'A':
            printf("Enter two numbers to add:\n");
            scanf("%d %d", &a, &b);
            sum = a + b;
            printf("The sum of %d and %d is %d.\n", a, b, sum);
            break;
        case 'S':
            printf("Enter two numbers to subtract:\n");
            scanf("%d %d", &a, &b);
            diff = a - b;
            printf("The difference between %d and %d is %d.\n", a, b, diff);
            break;
        case 'M':
            printf("Enter two numbers to multiply:\n");
            scanf("%d %d", &a, &b);
            prod = a * b;
            printf("The product of %d and %d is %d.\n", a, b, prod);
            break;
        case 'D':
            printf("Enter two numbers to divide:\n");
            scanf("%d %d", &a, &b);
            if(b == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                quot = a / b;
                printf("The quotient of %d and %d is %d.\n", a, b, quot);
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}