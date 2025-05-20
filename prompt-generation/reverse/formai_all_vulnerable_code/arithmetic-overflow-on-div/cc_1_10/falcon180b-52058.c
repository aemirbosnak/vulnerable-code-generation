//Falcon-180B DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char input[100];
    int choice, num1, num2, result;
    time_t t;
    srand(time(&t));

    printf("Welcome to the Paranoid Calculator!\n");
    printf("Please choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 + num2;
            break;
        case 2:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 - num2;
            break;
        case 3:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            result = num1 * num2;
            break;
        case 4:
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("The result is: %d\n", result);
    return 0;
}