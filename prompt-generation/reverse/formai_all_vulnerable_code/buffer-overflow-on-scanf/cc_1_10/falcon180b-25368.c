//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result;
    char operator;
    int choice;

    printf("Welcome to the Exciting World of Arithmetic!\n\n");

    srand(time(NULL));
    choice = rand() % 4;

    switch(choice) {
        case 0:
            printf("You have chosen Addition!\n\n");
            break;
        case 1:
            printf("You have chosen Subtraction!\n\n");
            break;
        case 2:
            printf("You have chosen Multiplication!\n\n");
            break;
        case 3:
            printf("You have chosen Division!\n\n");
            break;
    }

    printf("Enter two numbers separated by an operator:\n");
    scanf("%d %c %d", &num1, &operator, &num2);

    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0) {
                printf("Error! Division by zero is not allowed.\n");
                exit(0);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error! Invalid operator.\n");
            exit(0);
    }

    printf("The result is: %d\n", result);

    return 0;
}