//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operation;
    char repeat;

    srand(time(NULL));
    num1 = rand() % 100;
    num2 = rand() % 100;

    do {
        printf("Enter operation (+, -, *, /): ");
        scanf("%d", &operation);

        switch(operation) {
            case 1:
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
                break;
            case 4:
                printf("Enter two numbers:\n");
                scanf("%d %d", &num1, &num2);
                if(num2 == 0) {
                    printf("Cannot divide by zero.\n");
                } else {
                    printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
                }
                break;
            default:
                printf("Invalid operation.\n");
        }

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &repeat);
    } while(repeat == 'y' || repeat == 'Y');

    return 0;
}