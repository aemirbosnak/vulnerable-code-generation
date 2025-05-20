//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 100

int main(void) {
    char input[MAX_INPUT_SIZE];
    char result[MAX_INPUT_SIZE];

    printf("Welcome to the C Scientific Calculator!\n");
    printf("Type 'help' for instructions.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);

        if (strcmp(input, "help") == 0) {
            printf("Available operations: add, subtract, multiply, divide, square, cube, square root, cube root, absolute value.\n");
        } else if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else {
            sscanf(input, "%s", result);

            if (strcmp(result, "add") == 0) {
                double a, b;
                sscanf(input, "%lf %lf", &a, &b);
                printf("%lf\n", a + b);
            } else if (strcmp(result, "subtract") == 0) {
                double a, b;
                sscanf(input, "%lf %lf", &a, &b);
                printf("%lf\n", a - b);
            } else if (strcmp(result, "multiply") == 0) {
                double a, b;
                sscanf(input, "%lf %lf", &a, &b);
                printf("%lf\n", a * b);
            } else if (strcmp(result, "divide") == 0) {
                double a, b;
                sscanf(input, "%lf %lf", &a, &b);
                if (b == 0) {
                    printf("Error: Division by zero\n");
                } else {
                    printf("%lf\n", a / b);
                }
            } else if (strcmp(result, "square") == 0) {
                double a;
                sscanf(input, "%lf", &a);
                printf("%lf\n", pow(a, 2));
            } else if (strcmp(result, "cube") == 0) {
                double a;
                sscanf(input, "%lf", &a);
                printf("%lf\n", pow(a, 3));
            } else if (strcmp(result, "square root") == 0) {
                double a;
                sscanf(input, "%lf", &a);
                printf("%lf\n", sqrt(a));
            } else if (strcmp(result, "cube root") == 0) {
                double a;
                sscanf(input, "%lf", &a);
                printf("%lf\n", cbrt(a));
            } else if (strcmp(result, "abs") == 0) {
                double a;
                sscanf(input, "%lf", &a);
                printf("%lf\n", fabs(a));
            } else {
                printf("Error: Unknown operation\n");
            }
        }
    }

    return 0;
}