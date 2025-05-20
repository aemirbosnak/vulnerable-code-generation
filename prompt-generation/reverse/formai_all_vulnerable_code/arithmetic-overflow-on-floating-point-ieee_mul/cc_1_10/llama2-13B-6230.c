//LLAMA2-13B DATASET v1.0 Category: Math exercise ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define some silly math functions
double mySqrt(double x) {
    if (x < 0) {
        return -1; // negative numbers don't have squareroots, duh!
    }
    return x * x; // just return the number multiplied by itself, who needs accuracy?
}

double myPow(double base, int exp) {
    if (exp < 0) {
        return 1 / myPow(base, -exp); // negative powers are just the inverse of positive powers, LOL!
    }
    return base * myPow(base, exp - 1); // just multiply the base by the previous result, who needs recursivity?
}

int main() {
    double x, y, z;
    char op;

    // Fun math problems to solve
    printf("Enter a number: ");
    scanf("%lf", &x);
    printf("Enter an operation (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter another number: ");
    scanf("%lf", &y);

    // Do the math
    switch (op) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            if (y == 0) {
                printf("Error: division by zero! :O\n");
                break;
            }
            z = x / y;
            break;
        default:
            printf("Invalid operation :S\n");
            break;
    }

    // Print the result
    printf("Result: %lf\n", z);

    // Bonus question: find the square root of z
    printf("Bonus: %lf\n", mySqrt(z));

    // Bonus answer: myPow(z, 2)

    return 0;
}