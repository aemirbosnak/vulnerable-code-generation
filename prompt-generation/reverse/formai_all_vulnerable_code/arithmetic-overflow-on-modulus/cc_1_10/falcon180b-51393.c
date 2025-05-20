//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    int num1, num2, choice, i, j, k, n;
    float result;
    char op;

    srand(time(NULL));
    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Square\n7. Square root\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                result = num1 / num2;
                printf("Result: %f\n", result);
            }
            break;
        case 5:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 % num2;
            printf("Result: %d\n", result);
            break;
        case 6:
            printf("Enter a number:\n");
            scanf("%d", &num1);
            result = num1 * num1;
            printf("Result: %d\n", result);
            break;
        case 7:
            printf("Enter a number:\n");
            scanf("%d", &num1);
            result = sqrt(num1);
            printf("Result: %f\n", result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}