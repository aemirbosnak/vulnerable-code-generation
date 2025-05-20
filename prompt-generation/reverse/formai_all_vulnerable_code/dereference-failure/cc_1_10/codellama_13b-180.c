//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to an integer
int string_to_int(char *str) {
    int num = 0;
    for (int i = 0; i < strlen(str); i++) {
        num = num * 10 + str[i] - '0';
    }
    return num;
}

// Function to convert an integer to a string
char *int_to_string(int num) {
    char *str = malloc(sizeof(char) * 10);
    int i = 0;
    while (num > 0) {
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    str[i] = '\0';
    return str;
}

// Function to perform a calculation
int calculate(char *expr) {
    int num1 = 0, num2 = 0, result = 0;
    char op = ' ';
    for (int i = 0; i < strlen(expr); i++) {
        if (isdigit(expr[i])) {
            if (op == ' ') {
                num1 = string_to_int(expr + i);
            } else {
                num2 = string_to_int(expr + i);
            }
        } else {
            op = expr[i];
        }
    }
    switch (op) {
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
    }
    return result;
}

// Main function
int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);
    int result = calculate(expr);
    printf("Result: %s\n", int_to_string(result));
    return 0;
}