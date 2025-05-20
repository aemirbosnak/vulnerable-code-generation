//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Enter an expression: ");
    scanf("%s", input);

    char *token;
    token = strtok(input, " ");

    int result = 0;
    while (token!= NULL) {
        if (isdigit(*token)) {
            result = result * 10 + (*token - '0');
            token = strtok(NULL, " ");
        } else if (*token == '-' || *token == '+') {
            token = strtok(NULL, " ");
            continue;
        } else if (*token == '(') {
            token = strtok(NULL, " ");
            result += calculate(token);
            token = strtok(NULL, " ");
        } else if (*token == ')') {
            break;
        } else {
            result += atof(token);
            token = strtok(NULL, " ");
        }
    }

    printf("Result: %d\n", result);
    return 0;
}

int calculate(char *token) {
    int result = 0;
    char *op = strtok(token, " ");
    while (op!= NULL) {
        if (op[0] == '+' || op[0] == '-') {
            result += atoi(strtok(NULL, " "));
            op = strtok(NULL, " ");
        } else if (op[0] == '*' || op[0] == '/') {
            int num1 = atoi(strtok(NULL, " "));
            int num2 = atoi(strtok(NULL, " "));
            if (op[0] == '*') {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            op = strtok(NULL, " ");
        }
    }
    return result;
}