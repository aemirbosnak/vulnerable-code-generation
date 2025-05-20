//FormAI DATASET v1.0 Category: Arithmetic ; Style: scalable
#include <stdio.h>

// Function to compute the nth power of a number
double power(double base, int exponent) {
    double result = 1.0;
    int i;
    for (i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int choice;
    double a, b, result;
    printf("Choose an operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Power\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter two numbers to add:\n");
            scanf("%lf %lf", &a, &b);
            result = a + b;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            printf("Enter two numbers to subtract:\n");
            scanf("%lf %lf", &a, &b);
            result = a - b;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            printf("Enter two numbers to multiply:\n");
            scanf("%lf %lf", &a, &b);
            result = a * b;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            printf("Enter two numbers to divide:\n");
            scanf("%lf %lf", &a, &b);
            if (b == 0) {
                printf("Error: Cannot divide by zero\n");
            } else {
                result = a / b;
                printf("Result: %.2lf\n", result);
            }
            break;
        case 5:
            printf("Enter a number and its exponent:\n");
            scanf("%lf %d", &a, &choice);
            result = power(a, choice);
            printf("Result: %lf\n", result);
            break;
        default:
            printf("Error: Invalid choice\n");
    }
    return 0;
}