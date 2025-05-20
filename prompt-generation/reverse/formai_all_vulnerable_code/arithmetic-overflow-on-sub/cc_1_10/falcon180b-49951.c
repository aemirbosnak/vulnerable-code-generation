//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char choice;
    float decimal1, decimal2;
    int count = 0;

    srand(time(NULL));
    printf("Welcome to the Happy Arithmetic Program!\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &operator);

    while (count < 10) {
        if (operator == 1) {
            printf("Enter two numbers for addition:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            printf("The result is %d.\n", result);
            count++;
        } else if (operator == 2) {
            printf("Enter two numbers for subtraction:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            printf("The result is %d.\n", result);
            count++;
        } else if (operator == 3) {
            printf("Enter two numbers for multiplication:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            printf("The result is %d.\n", result);
            count++;
        } else if (operator == 4) {
            printf("Enter two numbers for division:\n");
            scanf("%d %d", &num1, &num2);
            if (num2 == 0) {
                printf("Division by zero is not allowed!\n");
            } else {
                result = num1 / num2;
                printf("The result is %d.\n", result);
                count++;
            }
        } else {
            printf("Invalid operation!\n");
        }
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    return 0;
}