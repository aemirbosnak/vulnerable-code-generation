//FormAI DATASET v1.0 Category: Math exercise ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {
    int firstNum, secondNum, operation;
    float result;

    printf("Enter first number: ");
    scanf("%d", &firstNum);

    printf("Enter second number: ");
    scanf("%d", &secondNum);

    printf("Select operation: \n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("Enter your choice: ");
    scanf("%d", &operation);

    switch (operation) {
        case 1:
            result = firstNum + secondNum;
            printf("%d + %d = %.2f\n", firstNum, secondNum, result);
            break;

        case 2:
            result = firstNum - secondNum;
            printf("%d - %d = %.2f\n", firstNum, secondNum, result);
            break;

        case 3:
            result = firstNum * secondNum;
            printf("%d * %d = %.2f\n", firstNum, secondNum, result);
            break;

        case 4:
            if (secondNum == 0) {
                printf("Error: Division by zero.\n");
                exit(0);
            }
            result = (float) firstNum / secondNum;
            printf("%d / %d = %.2f\n", firstNum, secondNum, result);
            break;

        default:
            printf("Invalid operation.\n");
            exit(0);
    }

    return 0;
}