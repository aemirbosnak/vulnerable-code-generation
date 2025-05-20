//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1, num2, sum, diff, prod, quot, rem;
    char choice;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                sum = num1 + num2;
                printf("The sum is: %d\n", sum);
                break;
            case '2':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                diff = num1 - num2;
                printf("The difference is: %d\n", diff);
                break;
            case '3':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                prod = num1 * num2;
                printf("The product is: %d\n", prod);
                break;
            case '4':
                printf("Enter two numbers: ");
                scanf("%d %d", &num1, &num2);
                if (num2 == 0) {
                    printf("Division by zero error!\n");
                } else {
                    quot = num1 / num2;
                    rem = num1 % num2;
                    printf("The quotient is: %d\n", quot);
                    printf("The remainder is: %d\n", rem);
                }
                break;
            case '5':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}