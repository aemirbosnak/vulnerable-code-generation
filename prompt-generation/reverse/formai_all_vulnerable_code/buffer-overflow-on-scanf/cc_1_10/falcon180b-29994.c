//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result;
    char operator;
    int choice;

    printf("Welcome to the Shocking Arithmetic Program!\n\n");
    printf("Please select an operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You chose addition.\n");
            printf("Enter two numbers separated by an operator (+): ");
            scanf("%d%c%d", &num1, &operator, &num2);
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;
        case 2:
            printf("You chose subtraction.\n");
            printf("Enter two numbers separated by an operator (-): ");
            scanf("%d%c%d", &num1, &operator, &num2);
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;
        case 3:
            printf("You chose multiplication.\n");
            printf("Enter two numbers separated by an operator (*): ");
            scanf("%d%c%d", &num1, &operator, &num2);
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;
        case 4:
            printf("You chose division.\n");
            printf("Enter two numbers separated by an operator (/): ");
            scanf("%d%c%d", &num1, &operator, &num2);
            if(num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("The result is: %d\n", result);
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}