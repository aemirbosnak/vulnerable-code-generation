//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT_SIZE 256
#define MAX_OUTPUT_SIZE 1024
#define MAX_OPERATION_SIZE 256

char input[MAX_INPUT_SIZE];
char output[MAX_OUTPUT_SIZE];
char operation[MAX_OPERATION_SIZE];

int main() {
    double num1, num2, result;
    char op;
    int i;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &op);

    switch(op) {
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
                printf("Error: Division by zero\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operation\n");
            exit(1);
    }

    sprintf(output, "Result: %lf", result);
    printf("%s\n", output);

    return 0;
}