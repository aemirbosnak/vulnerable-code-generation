//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 100
#define MAX_OPERATIONS 10

typedef struct {
    char operation;
    double (*func)(double, double);
} Operation;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero!\n");
        exit(EXIT_FAILURE);
    }
}

double power(double a, double b) {
    return pow(a, b);
}

void init_operations(Operation *operations) {
    operations[0].operation = '+';
    operations[0].func = add;

    operations[1].operation = '-';
    operations[1].func = subtract;

    operations[2].operation = '*';
    operations[2].func = multiply;

    operations[3].operation = '/';
    operations[3].func = divide;

    operations[4].operation = '^';
    operations[4].func = power;
}

void print_operations(Operation *operations, int op_count) {
    printf("Available operations:\n");
    for (int i = 0; i < op_count; i++) {
        printf(" %c ", operations[i].operation);
    }
    printf("\n");
}

int main() {
    Operation operations[MAX_OPERATIONS];
    init_operations(operations);

    char continue_calc;
    do {
        double num1, num2;
        char op;
        
        printf("Enter first number: ");
        if (scanf("%lf", &num1) != 1) {
            printf("Invalid input!\n");
            return EXIT_FAILURE;
        }

        print_operations(operations, 5);

        printf("Enter operation: ");
        scanf(" %c", &op);

        int found = 0;
        for (int i = 0; i < 5; i++) {
            if (operations[i].operation == op) {
                found = 1;

                printf("Enter second number: ");
                if (scanf("%lf", &num2) != 1) {
                    printf("Invalid input!\n");
                    return EXIT_FAILURE;
                }

                double result = operations[i].func(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            }
        }

        if (!found) {
            printf("Invalid operation! Please try again.\n");
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &continue_calc);
    } while (continue_calc == 'y' || continue_calc == 'Y');

    printf("Thank you for using the Scientific Calculator!\n");
    return EXIT_SUCCESS;
}