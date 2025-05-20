//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char expression[100];
    double num1, num2, result;
    int operator;

    printf("Enter an expression (e.g. 3+4*5): ");
    scanf("%s", expression);

    for(int i=0; expression[i]!='\0'; i++) {
        if(expression[i]==' ') {
            expression[i] = '\0';
        }
    }

    num1 = atof(expression);
    result = num1;

    if(expression[0]!= '\0') {
        operator = expression[0];
        scanf("%s", expression);
        num2 = atof(expression);

        switch(operator) {
            case '+':
                result += num2;
                break;
            case '-':
                result -= num2;
                break;
            case '*':
                result *= num2;
                break;
            case '/':
                if(num2 == 0) {
                    printf("Error: Division by zero\n");
                    exit(1);
                }
                result /= num2;
                break;
            case '^':
                result = pow(result, num2);
                break;
            default:
                printf("Error: Invalid operator\n");
                exit(1);
        }
    }

    printf("Result: %.2lf\n", result);

    return 0;
}