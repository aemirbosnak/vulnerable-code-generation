//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_INPUT_SIZE 100

void get_input(char *input);
void display_menu();
void calculate(int *num1, int *num2, int operator);

int main() {
    int num1, num2, operator;
    char input[MAX_INPUT_SIZE];

    while (1) {
        display_menu();
        get_input(input);
        calculate(&num1, &num2, atoi(input));
    }

    return 0;
}

void get_input(char *input) {
    printf("Enter your expression: ");
    scanf("%s", input);
}

void display_menu() {
    printf("\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exponentiation\n6. Square Root\n7. Exit\n");
}

void calculate(int *num1, int *num2, int operator) {
    switch (operator) {
        case 1:
            *num1 += *num2;
            break;
        case 2:
            *num1 -= *num2;
            break;
        case 3:
            *num1 *= *num2;
            break;
        case 4:
            if (*num2 == 0) {
                printf("Error: Division by zero.\n");
            } else {
                *num1 /= *num2;
            }
            break;
        case 5:
            *num1 = pow(*num1, *num2);
            break;
        case 6:
            *num1 = sqrt(*num1);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Error: Invalid operator.\n");
    }

    printf("Result: %d\n", *num1);
}