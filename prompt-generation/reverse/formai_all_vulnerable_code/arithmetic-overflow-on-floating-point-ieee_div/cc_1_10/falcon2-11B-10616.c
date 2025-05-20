//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Global variables
float operand1, operand2;
int operation, result;
char buffer[100];

void input_operand(void) {
    printf("Enter the first operand: ");
    scanf("%f", &operand1);
}

void input_operation(void) {
    printf("Enter the operation (+, -, *, /): ");
    scanf(" %c", &operation);
}

void input_operand2(void) {
    printf("Enter the second operand: ");
    scanf("%f", &operand2);
}

void perform_operation(void) {
    switch (operation) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            printf("Invalid operation\n");
            exit(1);
    }
    printf("Result: %.2f\n", result);
}

int main(void) {
    srand(time(0));
    char random_string[20];
    while (1) {
        sprintf(random_string, "Enter the first operand: %f", random() / 10.0);
        printf("%s\n", random_string);
        input_operand();

        sprintf(random_string, "Enter the operation (+, -, *, /): %c", rand() % 4);
        printf("%s\n", random_string);
        input_operation();

        sprintf(random_string, "Enter the second operand: %f", random() / 10.0);
        printf("%s\n", random_string);
        input_operand2();

        perform_operation();
    }
    return 0;
}