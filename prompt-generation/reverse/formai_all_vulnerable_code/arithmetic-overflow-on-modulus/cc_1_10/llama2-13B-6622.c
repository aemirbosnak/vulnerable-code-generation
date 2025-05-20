//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NUM 100000
#define MIN_NUM 1

int main() {
    int num1, num2, sum, diff, mult, div, mod, pow, root;
    char op;

    printf("Welcome to the Arithmetic Playground! \n");

    do {
        printf("Enter an operation (+, -, *, /, % , ^, or ?): ");
        scanf(" %c", &op);

        switch (op) {
            case '+':
                printf("Enter two numbers: ");
                scanf("%d%d", &num1, &num2);
                sum = num1 + num2;
                printf("Sum: %d\n", sum);
                break;

            case '-':
                printf("Enter two numbers: ");
                scanf("%d%d", &num1, &num2);
                diff = num1 - num2;
                printf("Difference: %d\n", diff);
                break;

            case '*':
                printf("Enter two numbers: ");
                scanf("%d%d", &num1, &num2);
                mult = num1 * num2;
                printf("Product: %d\n", mult);
                break;

            case '/':
                printf("Enter two numbers: ");
                scanf("%d%d", &num1, &num2);
                div = num1 / num2;
                printf("Quotient: %d\n", div);
                break;

            case '%':
                printf("Enter two numbers: ");
                scanf("%d%d", &num1, &num2);
                mod = num1 % num2;
                printf("Modulus: %d\n", mod);
                break;

            case '^':
                printf("Enter two numbers: ");
                scanf("%d%d", &num1, &num2);
                pow = num1 ^ num2;
                printf("Exponentiation: %d\n", pow);
                break;

            case '?':
                printf("Enter a number: ");
                scanf("%d", &num1);
                printf("The number is: %d\n", num1);
                break;

            default:
                printf("Invalid operation. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}