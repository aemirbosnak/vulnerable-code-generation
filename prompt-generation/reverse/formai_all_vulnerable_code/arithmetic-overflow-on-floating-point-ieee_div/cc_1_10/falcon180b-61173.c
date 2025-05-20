//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int i, j, n;
    double x, y, z;
    char c;

    // Prompt user to input a number
    printf("Enter a number: ");
    scanf("%lf", &x);

    // Calculate the square root of the input number
    z = sqrt(x);

    // Print the result
    printf("The square root of %lf is %lf\n", x, z);

    // Prompt user to input an arithmetic expression
    printf("Enter an arithmetic expression: ");
    scanf("%s", &c);

    // Evaluate the expression and print the result
    switch(c) {
        case '+':
            scanf("%lf %lf", &x, &y);
            z = x + y;
            printf("The sum of %lf and %lf is %lf\n", x, y, z);
            break;
        case '-':
            scanf("%lf %lf", &x, &y);
            z = x - y;
            printf("The difference between %lf and %lf is %lf\n", x, y, z);
            break;
        case '*':
            scanf("%lf %lf", &x, &y);
            z = x * y;
            printf("The product of %lf and %lf is %lf\n", x, y, z);
            break;
        case '/':
            scanf("%lf %lf", &x, &y);
            if(y == 0) {
                printf("Division by zero is not allowed\n");
            } else {
                z = x / y;
                printf("The quotient of %lf and %lf is %lf\n", x, y, z);
            }
            break;
        default:
            printf("Invalid expression\n");
            break;
    }

    return 0;
}