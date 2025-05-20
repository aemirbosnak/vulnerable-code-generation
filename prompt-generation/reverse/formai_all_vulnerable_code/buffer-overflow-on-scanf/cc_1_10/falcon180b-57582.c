//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int isOperator(char c) {
    switch(c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return 1;
        default:
            return 0;
    }
}

int isNumber(char c) {
    if(isdigit(c)) {
        return 1;
    } else {
        return 0;
    }
}

int isDecimal(char c) {
    if(c == '.') {
        return 1;
    } else {
        return 0;
    }
}

int isValidExpression(char* expression) {
    int i = 0;
    while(expression[i]!= '\0') {
        if(!isNumber(expression[i]) &&!isOperator(expression[i]) &&!isDecimal(expression[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int evaluateExpression(char* expression) {
    int i = 0;
    int operands[100];
    int operators[100];
    int numOperands = 0;
    int numOperators = 0;
    while(expression[i]!= '\0') {
        if(isNumber(expression[i])) {
            char* num = (char*)malloc(100*sizeof(char));
            int j = 0;
            while(isNumber(expression[i])) {
                num[j] = expression[i];
                i++;
                j++;
            }
            num[j] = '\0';
            operands[numOperands] = atoi(num);
            free(num);
            numOperands++;
        } else if(isOperator(expression[i])) {
            operators[numOperators] = expression[i];
            numOperators++;
        }
        i++;
    }
    int result = operands[0];
    for(int j = 0; j < numOperators; j++) {
        switch(operators[j]) {
            case '+':
                result += operands[j+1];
                break;
            case '-':
                result -= operands[j+1];
                break;
            case '*':
                result *= operands[j+1];
                break;
            case '/':
                result /= operands[j+1];
                break;
            case '^':
                result = pow(result, operands[j+1]);
                break;
        }
    }
    return result;
}

int main() {
    char expression[100];
    printf("Enter a valid expression: ");
    scanf("%s", expression);
    if(isValidExpression(expression)) {
        int result = evaluateExpression(expression);
        printf("Result: %d\n", result);
    } else {
        printf("Invalid expression!\n");
    }
    return 0;
}