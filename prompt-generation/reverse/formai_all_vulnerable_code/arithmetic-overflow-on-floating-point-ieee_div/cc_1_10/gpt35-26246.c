//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function declarations
void addition();
void subtraction();
void multiplication();
void division();
void power();
void square_root();
void factorial();
void logarithm();

int main() {
    int choice;
    printf("Welcome to the C Scientific Calculator\n");
    printf("-------------------------------------\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Factorial\n");
    printf("8. Logarithm\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        case 5:
            power();
            break;
        case 6:
            square_root();
            break;
        case 7:
            factorial();
            break;
        case 8:
            logarithm();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    return 0;
}

void addition() {
    int i, n;
    float num, sum = 0;
    printf("Enter the number of elements you want to add: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (i = 1; i <= n; i++) {
        scanf("%f", &num);
        sum += num;
    }
    printf("Sum = %.2f\n", sum);
}

void subtraction() {
    float num1, num2, diff;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    diff = num1 - num2;
    printf("Difference = %.2f\n", diff);
}

void multiplication() {
    int i, n;
    float num, product = 1;
    printf("Enter the number of elements you want to multiply: ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (i = 1; i <= n; i++) {
        scanf("%f", &num);
        product *= num;
    }
    printf("Product = %.2f\n", product);
}

void division() {
    float num1, num2, quotient;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    if (num2 == 0) {
        printf("Error! Division by zero.\n");
    }
    else {
        quotient = num1 / num2;
        printf("Quotient = %.2f\n", quotient);
    }
}

void power() {
    float base, exponent, pow;
    printf("Enter the base number: ");
    scanf("%f", &base);
    printf("Enter the exponent number: ");
    scanf("%f", &exponent);
    pow = powf(base, exponent);
    printf("Result = %.2f\n", pow);
}

void square_root() {
    float num, result;
    printf("Enter a number: ");
    scanf("%f", &num);
    if (num < 0) {
        printf("Error! Negative numbers don't have a real square root.\n");
    }
    else {
        result = sqrtf(num);
        printf("Square root of %.2f = %.2f\n", num, result);
    }
}

void factorial() {
    int i, num;
    long long int fact = 1;
    printf("Enter a number (positive integer): ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Error! Invalid input.\n");
    }
    else {
        for (i = 1; i <= num; i++) {
            fact *= i;
        }
        printf("Factorial of %d = %lld\n", num, fact);
    }
}

void logarithm() {
    float num, result;
    printf("Enter a number: ");
    scanf("%f", &num);
    if (num <= 0) {
        printf("Error! Invalid input.\n");
    }
    else {
        result = logf(num);
        printf("Natural Logarithm of %.2f = %.2f\n", num, result);
    }
}