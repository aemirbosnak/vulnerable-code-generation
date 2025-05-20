//Falcon2-11B DATASET v1.0 Category: Syntax parsing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* op;
    double num1;
    double num2;
} Syntax;

Syntax* parse(char* str) {
    Syntax* syntax = (Syntax*) malloc(sizeof(Syntax));
    int op_len = 0;
    int num1_len = 0;
    int num2_len = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '+') {
            syntax->op = (char*) malloc(sizeof(char) * (i + 1));
            syntax->op[op_len] = '\0';
            op_len = i + 1;
        } else if (str[i] == '-') {
            syntax->op = (char*) malloc(sizeof(char) * (i + 1));
            syntax->op[op_len] = '\0';
            op_len = i + 1;
        } else if (str[i] == '/') {
            syntax->op = (char*) malloc(sizeof(char) * (i + 1));
            syntax->op[op_len] = '\0';
            op_len = i + 1;
        } else if (str[i] == '*') {
            syntax->op = (char*) malloc(sizeof(char) * (i + 1));
            syntax->op[op_len] = '\0';
            op_len = i + 1;
        } else if (str[i] == '(') {
            syntax->num1 = strtod(str, &i);
            num1_len = i;
        } else if (str[i] == ')') {
            syntax->num2 = strtod(str + num1_len + 1, &i);
            num2_len = i;
        }
    }

    syntax->num1 *= -1.0;
    syntax->num2 *= -1.0;

    if (op_len > 0) {
        syntax->op = (char*) realloc(syntax->op, sizeof(char) * (op_len - 1));
        syntax->op[op_len - 1] = '\0';
    }

    return syntax;
}

int main() {
    char str[] = "5 + 7 * 8 - 4";
    Syntax* syntax = parse(str);
    if (syntax == NULL) {
        printf("Error parsing syntax.\n");
        return 1;
    }

    double result = 0.0;
    switch (strcmp(syntax->op, "+")) {
        case 0:
            result = syntax->num1 + syntax->num2;
            break;
        case 1:
            result = syntax->num1 - syntax->num2;
            break;
        case 2:
            result = syntax->num1 / syntax->num2;
            break;
        case 3:
            result = syntax->num1 * syntax->num2;
            break;
    }

    printf("Result: %.2lf\n", result);
    free(syntax);
    return 0;
}