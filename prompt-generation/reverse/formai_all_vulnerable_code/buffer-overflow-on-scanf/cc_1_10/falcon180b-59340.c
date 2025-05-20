//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, choice;
    char op;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Please enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Square\n");
    printf("6. Cube\n");
    printf("7. Square root\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Cannot divide by zero.\n");
            }
            else {
                result = num1 / num2;
                printf("Result: %d\n", result);
            }
            break;
        case 5:
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = num1 * num1;
            printf("Result: %d\n", result);
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%d", &num1);
            result = num1 * num1 * num1;
            printf("Result: %d\n", result);
            break;
        case 7:
            printf("Enter a number: ");
            scanf("%d", &num1);
            if(num1 < 0) {
                printf("Cannot find square root of negative number.\n");
            }
            else {
                result = sqrt(num1);
                printf("Result: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}