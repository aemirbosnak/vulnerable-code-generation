//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*The following function takes two integer values and returns their sum.*/
int add(int a, int b) {
    return a + b;
}

/*The following function takes two integer values and returns their difference.*/
int subtract(int a, int b) {
    return a - b;
}

/*The following function takes two integer values and returns their product.*/
int multiply(int a, int b) {
    return a * b;
}

/*The following function takes two integer values and returns the quotient of the division of the first integer by the second integer.*/
int divide(int a, int b) {
    if (b == 0) {
        printf("Error: division by zero.\n");
        return 0;
    }
    else {
        return a / b;
    }
}

/*The following function takes an integer value and returns the factorial of that value.*/
long int factorial(int n) {
    long int result = 1;
    int i;

    for (i = 1; i <= n; i++) {
        result = result * i;
    }

    return result;
}

/*The following function takes a double value and returns the square root of that value.*/
double square_root(double n) {
    if (n < 0) {
        printf("Error: square root of a negative number.\n");
        return -1;
    }
    else {
        return sqrt(n);
    }
}

/*The main function of this program.*/
int main() {
    int choice;
    int a, b;
    double x;

    printf("Welcome to the scientific calculator!\n");

    do {
        printf("\nPlease select an operation to perform:\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Factorial\n");
        printf("6. Square root\n");
        printf("0. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers:\n");
                scanf("%d %d", &a, &b);
                printf("%d + %d = %d\n", a, b, add(a,b));
                break;
            case 2:
                printf("Enter two numbers:\n");
                scanf("%d %d", &a, &b);
                printf("%d - %d = %d\n", a, b, subtract(a,b));
                break;
            case 3:
                printf("Enter two numbers:\n");
                scanf("%d %d", &a, &b);
                printf("%d * %d = %d\n", a, b, multiply(a,b));
                break;
            case 4:
                printf("Enter two numbers:\n");
                scanf("%d %d", &a, &b);
                printf("%d / %d = %d\n", a, b, divide(a,b));
                break;
            case 5:
                printf("Enter a number:\n");
                scanf("%d", &a);
                printf("%d! = %ld\n", a, factorial(a));
                break;
            case 6:
                printf("Enter a number:\n");
                scanf("%lf", &x);
                printf("sqrt(%lf) = %lf\n", x, square_root(x));
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Error: invalid choice.\n");
                break;
        }

    } while (choice != 0);

    return 0;
}