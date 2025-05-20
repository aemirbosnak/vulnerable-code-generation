//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN];
    double num1, num2, result;
    char operator;

    printf("Welcome to the Ada Lovelace Scientific Calculator!\n");
    printf("Enter your expression (up to %d characters): ", MAX_LEN - 1);
    fgets(input, MAX_LEN, stdin);

    int len = strlen(input);
    int i = 0;
    while (i < len) {
        if (isdigit(input[i])) {
            num1 = atof(input);
            break;
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            operator = input[i];
            i++;
        } else if (isalpha(input[i])) {
            printf("Invalid character found: %c\n", input[i]);
            return 1;
        }
        i++;
    }

    if (operator == '+') {
        printf("Enter second number: ");
        scanf("%lf", &num2);
        result = num1 + num2;
        printf("Result: %lf\n", result);
    } else if (operator == '-') {
        printf("Enter second number: ");
        scanf("%lf", &num2);
        result = num1 - num2;
        printf("Result: %lf\n", result);
    } else if (operator == '*') {
        printf("Enter second number: ");
        scanf("%lf", &num2);
        result = num1 * num2;
        printf("Result: %lf\n", result);
    } else if (operator == '/') {
        printf("Enter second number: ");
        scanf("%lf", &num2);
        if (num2 == 0) {
            printf("Error: Division by zero\n");
        } else {
            result = num1 / num2;
            printf("Result: %lf\n", result);
        }
    }

    return 0;
}