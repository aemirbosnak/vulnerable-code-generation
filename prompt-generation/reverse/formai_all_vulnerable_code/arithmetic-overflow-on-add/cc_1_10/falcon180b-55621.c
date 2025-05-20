//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char choice;

    printf("Welcome to the Arithmetic Calculator!\n");
    printf("Select an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &operator);

    printf("Enter two integers:\n");
    scanf("%d %d", &num1, &num2);

    switch(operator) {
        case 1:
            result = num1 + num2;
            printf("The result is %d.\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("The result is %d.\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("The result is %d.\n", result);
            break;
        case 4:
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is %d.\n", result);
            }
            break;
        default:
            printf("Invalid operator selected.\n");
            break;
    }

    printf("Do you want to perform another calculation? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Thank you for using the Arithmetic Calculator.\n");
        return 0;
    }
}