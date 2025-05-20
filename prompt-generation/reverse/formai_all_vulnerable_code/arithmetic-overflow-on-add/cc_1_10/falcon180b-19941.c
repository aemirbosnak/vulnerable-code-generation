//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2;
    int operation;
    int result;
    int choice;
    int i;

    srand(time(NULL));

    printf("Welcome to the Exciting Arithmetic Program!\n\n");

    do {
        printf("Please enter the number of operations you want to perform: ");
        scanf("%d", &i);
    } while (i <= 0);

    for (int j = 0; j < i; j++) {
        printf("Please enter the first number: ");
        scanf("%d", &num1);
        printf("Please enter the second number: ");
        scanf("%d", &num2);
        printf("Please enter the operation you want to perform (+, -, *, /): ");
        scanf("%d", &operation);

        switch (operation) {
            case 1:
                result = num1 + num2;
                break;
            case 2:
                result = num1 - num2;
                break;
            case 3:
                result = num1 * num2;
                break;
            case 4:
                if (num2 == 0) {
                    printf("Cannot divide by zero!\n");
                    break;
                }
                result = num1 / num2;
                break;
            default:
                printf("Invalid operation!\n");
                break;
        }

        printf("The result is: %d\n\n", result);
    }

    printf("Thank you for using the Exciting Arithmetic Program!\n");

    return 0;
}