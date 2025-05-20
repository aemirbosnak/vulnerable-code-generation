#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char expression[100];
    printf("Enter a mathematical expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    int num1 = 0, num2 = 0;
    char operator;
    sscanf(expression, "%d %c %d", &num1, &operator, &num2);
    
    switch (operator) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;
        case '-':
            printf("Result: %d\n", num1 - num2);
            break;
        case '*':
            printf("Result: %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Result: %.2f\n", (float)num1 / num2);
            else
                printf("Error: Division by zero\n");
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }
    
    return 0;
}
