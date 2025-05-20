//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define SQUARE(x) ((x) * (x))

typedef struct {
    int num1;
    int num2;
    char op;
} Arithmetic_Operation;

int main() {
    srand(time(NULL));

    printf("Hello Sunshine!\n");
    printf("Welcome to the Happy Arithmetic Calculator!\n");

    Arithmetic_Operation operation;

    while (1) {
        operation.num1 = rand() % 10 + 1;
        operation.num2 = rand() % 10 + 1;

        printf("Let's do some arithmetic!\n");
        printf("Random numbers: %d and %d\n", operation.num1, operation.num2);

        printf("\nChoose an operation (+, -, *, /): ");
        scanf(" %c", &operation.op);

        switch (operation.op) {
            case '+':
                printf("Result: %d + %d = %d\n", operation.num1, operation.num2, operation.num1 + operation.num2);
                break;
            case '-':
                printf("Result: %d - %d = %d\n", operation.num1, operation.num2, operation.num1 - operation.num2);
                break;
            case '*':
                printf("Result: %d * %d = %d\n", operation.num1, operation.num2, operation.num1 * operation.num2);
                break;
            case '/':
                if (operation.num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    continue;
                }
                printf("Result: %d / %d = %.2f\n", operation.num1, operation.num2, (float) operation.num1 / operation.num2);
                break;
            default:
                printf("Error: Invalid operation.\n");
                continue;
        }

        printf("\nDo you want to continue? (y/n): ");
        char answer;
        scanf(" %c", &answer);

        if (answer != 'y') {
            break;
        }

        printf("\nSmile more! Let's do some more arithmetic!\n");
    }

    printf("Bye Sunshine! Have a great day!\n");

    return 0;
}