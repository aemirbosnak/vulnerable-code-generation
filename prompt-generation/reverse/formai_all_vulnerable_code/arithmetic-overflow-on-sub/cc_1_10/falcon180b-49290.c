//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation, result;
    char operator;
    int choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two numbers and operator for addition:\n");
                scanf("%d %c %d", &num1, &operator, &num2);
                result = num1 + num2;
                printf("Result: %d\n", result);
                break;
            case 2:
                printf("Enter two numbers and operator for subtraction:\n");
                scanf("%d %c %d", &num1, &operator, &num2);
                result = num1 - num2;
                printf("Result: %d\n", result);
                break;
            case 3:
                printf("Enter two numbers and operator for multiplication:\n");
                scanf("%d %c %d", &num1, &operator, &num2);
                result = num1 * num2;
                printf("Result: %d\n", result);
                break;
            case 4:
                printf("Enter two numbers and operator for division:\n");
                scanf("%d %c %d", &num1, &operator, &num2);
                if (num2 == 0) {
                    printf("Error! Division by zero\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %d\n", result);
                }
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}