//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_OPERATIONS 10
#define MAX_NUMBERS 10

typedef struct {
    char num[5];
    char operation;
} operation_t;

operation_t operations[MAX_OPERATIONS] = {
    {"+", '+'},
    {"-", '-'},
    {"*", '*'},
    {"/", '/'},
    {"%", '%'},
    {"^", '^'},
    {"~", '~'},
    {"&", '&'},
    {"|", '|'},
    {"(", ')', '('},
    {")", ')'},
};

int main() {
    int num1, num2, result;
    char operation;

    // Initialize the numbers and operation
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the operation (+, -, *, /, %): ");
    scanf(" %c", &operation);

    // Perform the operation
    for (int i = 0; i < MAX_OPERATIONS; i++) {
        if (operations[i].operation == operation) {
            switch (operations[i].num[0]) {
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
                    result = num1 / num2;
                    break;
                case '%':
                    result = num1 % num2;
                    break;
                case '^':
                    result = num1 ^ num2;
                    break;
                case '~':
                    result = num1 ^ num2;
                    break;
                case '&':
                    result = num1 & num2;
                    break;
                case '|':
                    result = num1 | num2;
                    break;
                case '(':
                    result = num1 + num2;
                    break;
                case ')':
                    result = num1 - num2;
                    break;
                default:
                    break;
            }
            printf("Result: %d\n", result);
            return 0;
        }
    }

    // Handle invalid input
    printf("Invalid operation. Please try again.\n");
    return 0;
}