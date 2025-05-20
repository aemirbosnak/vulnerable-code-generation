//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, operator, result;
    char choice;

    srand(time(NULL));
    printf("Welcome to the C Arithmetic Example Program!\n");

    // Generate random numbers
    num1 = rand() % 100;
    num2 = rand() % 100;

    // Get operator from user
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);

    // Perform arithmetic operation
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
                printf("Error: Division by zero!\n");
                return 0;
            } else {
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid operator!\n");
            return 0;
    }

    // Print result
    printf("Result: %d\n", result);

    // Ask user if they want to try again
    printf("Do you want to try again? (y/n): ");
    scanf("%c", &choice);

    if(choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Exiting program...\n");
        return 0;
    }
}