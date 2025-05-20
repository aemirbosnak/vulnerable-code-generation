//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int modulo(int a, int b);
int power(int base, int exponent);
int factorial(int n);

int main() {

    int option, a, b;

    do {
        printf("\nWelcome to the Scavenger Scientific Calculator\n");
        printf("Choose an option:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulo\n");
        printf("6. Power\n");
        printf("7. Factorial\n");
        printf("8. Exit\n");

        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("%d + %d = %d\n", a, b, add(a, b));
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("%d - %d = %d\n", a, b, subtract(a, b));
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("%d * %d = %d\n", a, b, multiply(a, b));
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("%d / %d = %d\n", a, b, divide(a, b));
                break;
            case 5:
                printf("Enter two numbers: ");
                scanf("%d %d", &a, &b);
                printf("%d %% %d = %d\n", a, b, modulo(a, b));
                break;
            case 6:
                printf("Enter base and exponent: ");
                scanf("%d %d", &a, &b);
                printf("%d ^ %d = %d\n", a, b, power(a, b));
                break;
            case 7:
                printf("Enter a number: ");
                scanf("%d", &a);
                printf("%d! = %d\n", a, factorial(a));
                break;
            case 8:
                printf("Thank you for using the Scavenger Scientific Calculator!\n");
                break;
            default:
                printf("Error: Invalid option! Please try again.\n");
        }
    } while(option != 8);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if(b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int modulo(int a, int b) {
    return a % b;
}

int power(int base, int exponent) {
    int result = 1;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int factorial(int n) {
    int result = 1;
    for(int i = n; i >= 1; i--) {
        result *= i;
    }
    return result;
}