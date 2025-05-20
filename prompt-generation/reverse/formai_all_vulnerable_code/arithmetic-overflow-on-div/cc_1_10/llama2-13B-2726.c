//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 100
#define MAX_NUMBERS 20

// Global variables
int num1, num2, result;
char operation[20];

void menu();
void perform_operation();
void show_result();

int main() {
    srand(time(NULL));

    while (1) {
        menu();
        perform_operation();
        show_result();
    }

    return 0;
}

void menu() {
    printf("Welcome to the Arithmetic Game!\n");
    printf("Please select an operation (+, -, *, /, or ^): ");
    fgets(operation, 20, stdin);

    if (strcmp(operation, "+") == 0) {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        perform_operation();
    } else if (strcmp(operation, "-") == 0) {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        perform_operation();
    } else if (strcmp(operation, "*") == 0) {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        perform_operation();
    } else if (strcmp(operation, "/") == 0) {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        perform_operation();
    } else if (strcmp(operation, "^") == 0) {
        printf("Enter two numbers: ");
        scanf("%d%d", &num1, &num2);
        perform_operation();
    } else {
        printf("Invalid operation. Try again.\n");
    }
}

void perform_operation() {
    if (strcmp(operation, "+") == 0) {
        result = num1 + num2;
    } else if (strcmp(operation, "-") == 0) {
        result = num1 - num2;
    } else if (strcmp(operation, "*") == 0) {
        result = num1 * num2;
    } else if (strcmp(operation, "/") == 0) {
        result = num1 / num2;
    } else if (strcmp(operation, "^") == 0) {
        result = num1 ^ num2;
    }

    printf("Result: %d\n", result);
}

void show_result() {
    printf("Your current balance is %d\n", num1);
    printf("You have performed the following operations: ");
    printf(" + ");
    printf("%d", num2);
    printf("\n");
    printf("Your new balance is %d\n", result);
}