//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char choice;

    srand(time(NULL));
    num1 = rand() % 100 + 1;
    num2 = rand() % 100 + 1;

    printf("Welcome to the Arithmetic Program!\n");
    printf("Please choose an operation:\n");
    printf("A - Addition\n");
    printf("S - Subtraction\n");
    printf("M - Multiplication\n");
    printf("D - Division\n");
    scanf("%c", &choice);

    switch(choice) {
        case 'A':
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;
        case 'S':
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;
        case 'M':
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;
        case 'D':
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("Enter the second number: ");
            scanf("%d", &num2);
            if(num2 == 0) {
                printf("Error! Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice! Please choose a valid operation.\n");
    }

    return 0;
}