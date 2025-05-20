//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int num1, num2, operator;
    char choice;

    do {
        printf("Enter your choice:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                printf("The sum is %d\n", num1 + num2);
                break;
            case '2':
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                printf("The difference is %d\n", num1 - num2);
                break;
            case '3':
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                printf("The product is %d\n", num1 * num2);
                break;
            case '4':
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0) {
                    printf("Division by zero is not allowed.\n");
                } else {
                    printf("The quotient is %d\n", num1 / num2);
                }
                break;
            case '5':
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '5');

    return 0;
}