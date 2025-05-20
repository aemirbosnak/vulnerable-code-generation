//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double num1, num2, result;
    int choice;

    printf("Welcome to the Math Exercise Program!\n\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    printf("Please enter the first number:\n");
    scanf("%lf", &num1);

    switch (choice) {
        case 1:
            printf("Please enter the second number:\n");
            scanf("%lf", &num2);
            result = num1 + num2;
            printf("The result is: %.2lf\n", result);
            break;
        case 2:
            printf("Please enter the second number:\n");
            scanf("%lf", &num2);
            result = num1 - num2;
            printf("The result is: %.2lf\n", result);
            break;
        case 3:
            printf("Please enter the second number:\n");
            scanf("%lf", &num2);
            result = num1 * num2;
            printf("The result is: %.2lf\n", result);
            break;
        case 4:
            printf("Please enter the second number:\n");
            scanf("%lf", &num2);
            if (num2 == 0) {
                printf("Cannot divide by zero.\n");
            } else {
                result = num1 / num2;
                printf("The result is: %.2lf\n", result);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}