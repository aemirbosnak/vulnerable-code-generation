//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator;
    char repeat;

    srand(time(NULL));
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    do {
        printf("Enter an operator (+, -, *, /): ");
        scanf("%d", &operator);

        switch(operator) {
            case 0:
                printf("Invalid operator.\n");
                break;
            case 1:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Result: %d + %d = %d\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Result: %d - %d = %d\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                printf("Result: %d * %d = %d\n", num1, num2, num1 * num2);
                break;
            case 4:
                printf("Enter first number: ");
                scanf("%d", &num1);
                printf("Enter second number: ");
                scanf("%d", &num2);
                if(num2 == 0) {
                    printf("Cannot divide by zero.\n");
                } else {
                    printf("Result: %d / %d = %d\n", num1, num2, num1 / num2);
                }
                break;
            default:
                printf("Invalid operator.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &repeat);
    } while(repeat == 'y' || repeat == 'Y');

    return 0;
}