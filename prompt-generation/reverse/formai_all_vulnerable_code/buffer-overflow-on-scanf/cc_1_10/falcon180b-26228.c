//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to perform basic arithmetic operations
int perform_operation(int num1, int num2, char operation) {
    int result = 0;
    switch(operation) {
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
                exit(0);
            }
            result = num1 / num2;
            break;
        default:
            printf("Invalid operation\n");
            exit(0);
    }
    return result;
}

// Function to check if a string is a valid number
int is_number(char* str) {
    int i = 0;
    while(str[i]!= '\0') {
        if(str[i] < '0' || str[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert a string to an integer
int string_to_int(char* str) {
    int num = 0;
    int i = 0;
    while(str[i]!= '\0') {
        num = num * 10 + str[i] - '0';
        i++;
    }
    return num;
}

// Function to evaluate an expression
int evaluate_expression(char* expression) {
    char* token = strtok(expression, " ");
    int num1 = 0;
    int num2 = 0;
    char operation = '\0';
    while(token!= NULL) {
        if(is_number(token)) {
            num1 = string_to_int(token);
        } else {
            operation = *token;
        }
        token = strtok(NULL, " ");
        if(is_number(token)) {
            num2 = string_to_int(token);
            int result = perform_operation(num1, num2, operation);
            num1 = result;
            num2 = 0;
        } else if(operation!= '\0') {
            int result = perform_operation(num1, num2, operation);
            num1 = result;
            num2 = 0;
        }
    }
    return num1;
}

// Main function
int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);
    int result = evaluate_expression(expression);
    printf("Result: %d\n", result);
    return 0;
}