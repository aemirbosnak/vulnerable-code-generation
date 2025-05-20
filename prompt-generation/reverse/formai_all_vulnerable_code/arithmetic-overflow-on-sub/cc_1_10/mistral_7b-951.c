//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num, a, b, c, result;
    char op;

    srand(time(NULL));
    num = rand() % 10 + 1;
    printf("Random number: %d\n", num);

    while (1) {
        printf("Enter an operator (+, -, *, /): ");
        scanf(" %c", &op);

        printf("Enter two numbers for the operation: ");
        scanf("%d %d", &a, &b);

        switch (op) {
            case '+':
                result = num + a + b;
                break;
            case '-':
                result = num - a - b;
                break;
            case '*':
                result = num * a * b;
                break;
            case '/':
                if (b == 0) {
                    printf("Error: Division by zero.\n");
                    continue;
                }
                result = num / a / b;
                break;
            default:
                printf("Error: Invalid operator.\n");
                continue;
        }

        printf("Result: %d\n", result);

        printf("Do you want to continue? (y/n): ");
        char answer;
        scanf("%c", &answer);

        if (answer != 'y') {
            break;
        }

        num = rand() % 10 + 1;
        printf("New random number: %d\n", num);
    }

    return 0;
}