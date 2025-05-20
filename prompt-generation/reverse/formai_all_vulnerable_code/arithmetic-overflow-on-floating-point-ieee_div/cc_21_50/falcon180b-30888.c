//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: satisfied
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    char token[MAX_LEN];
    double num1, num2, result;
    int count;
    char operator;
    char *ptr;

    printf("Enter expression: ");
    fgets(input, MAX_LEN, stdin);

    count = 0;
    ptr = strtok(input, " ");
    while (ptr!= NULL) {
        strcpy(token, ptr);
        if (isdigit(token[0])) {
            num1 = atof(token);
        } else if (token[0] == '(') {
            count++;
        } else if (token[0] == ')') {
            count--;
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            operator = token[0];
        }
        ptr = strtok(NULL, " ");
    }

    if (count!= 0) {
        printf("Error: Mismatched parentheses\n");
        return 1;
    }

    ptr = strtok(input, " ");
    while (ptr!= NULL) {
        strcpy(token, ptr);
        if (isdigit(token[0])) {
            num1 = atof(token);
        } else if (token[0] == '(') {
            count++;
        } else if (token[0] == ')') {
            count--;
        } else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
            operator = token[0];
            if (count == 0) {
                num2 = num1;
                num1 = 0;
            }
        }
        ptr = strtok(NULL, " ");
    }

    switch (operator) {
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
            if (num2 == 0) {
                printf("Error: Division by zero\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operator\n");
            return 1;
    }

    printf("Result: %.2f\n", result);

    return 0;
}