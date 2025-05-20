//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num1, num2, operation;

    // Prompt user for input
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Prompt user for bitwise operation
    printf("Enter bitwise operation (+, -, *, /, &, |, ^, <<, >>): ");
    scanf("%c", &operation);

    // Perform bitwise operation
    switch (operation) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;
        case '-':
            printf("Result: %d\n", num1 - num2);
            break;
        case '*':
            printf("Result: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero\n");
            } else {
                printf("Result: %d\n", num1 / num2);
            }
            break;
        case '&':
            printf("Result: %d\n", num1 & num2);
            break;
        case '|':
            printf("Result: %d\n", num1 | num2);
            break;
        case '^':
            printf("Result: %d\n", num1 ^ num2);
            break;
        case '<':
            printf("Result: %d\n", num1 << num2);
            break;
        case '>':
            printf("Result: %d\n", num1 >> num2);
            break;
        default:
            printf("Error: Invalid operation\n");
            break;
    }

    return 0;
}