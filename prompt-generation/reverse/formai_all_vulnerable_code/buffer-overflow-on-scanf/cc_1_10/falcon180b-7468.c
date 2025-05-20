//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num1, num2, result, i;
    char operation;

    srand(time(NULL));
    num1 = rand() % 256;
    num2 = rand() % 256;

    printf("Enter the operation to perform (+, -, *, &, |, ^, ~, <<, >>): ");
    scanf("%c", &operation);

    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '&':
            result = num1 & num2;
            printf("Result: %d\n", result);
            break;
        case '|':
            result = num1 | num2;
            printf("Result: %d\n", result);
            break;
        case '^':
            result = num1 ^ num2;
            printf("Result: %d\n", result);
            break;
        case '~':
            result = ~num1;
            printf("Result: %d\n", result);
            break;
        case '<<':
            result = num1 << num2;
            printf("Result: %d\n", result);
            break;
        case '>>':
            result = num1 >> num2;
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid operation!\n");
    }

    return 0;
}