//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_OPERATORS 1000
#define MAX_OPERANDS 1000
#define MAX_RESULT_DIGITS 1000
#define MAX_RESULT_LEN 1000

char *operators[MAX_OPERATORS];
int num_operators;

char *operands[MAX_OPERANDS];
int num_operands;

char result[MAX_RESULT_DIGITS];
int result_len;

void add_operator(char *op) {
    if (num_operators >= MAX_OPERATORS) {
        printf("Error: Too many operators.\n");
        exit(1);
    }
    operators[num_operators] = op;
    num_operators++;
}

void add_operand(char *op) {
    if (num_operands >= MAX_OPERANDS) {
        printf("Error: Too many operands.\n");
        exit(1);
    }
    operands[num_operands] = op;
    num_operands++;
}

void evaluate() {
    char *op1, *op2, *result_str;
    int op1_len, op2_len, result_len;

    op1 = operands[--num_operands];
    op1_len = strlen(op1);

    op2 = operands[--num_operands];
    op2_len = strlen(op2);

    result_str = malloc(op1_len + op2_len + 1);
    strcpy(result_str, op1);
    strcat(result_str, op2);

    result_len = sprintf(result, "%f", atof(result_str));

    if (result_len == 0) {
        printf("Error: Invalid result.\n");
        exit(1);
    }

    printf("Result: ");
    for (int i = 0; i < result_len; i++) {
        printf("%c", result[i]);
    }
    printf("\n");
}

int main() {
    char input[100];
    int len;

    printf("Enter an expression:\n");
    fgets(input, 100, stdin);
    len = strlen(input);

    char *token = strtok(input, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            add_operand(token);
        } else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            add_operator(token);
        } else {
            printf("Error: Invalid token.\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }

    if (num_operands == 0) {
        printf("Error: No operands.\n");
        exit(1);
    }

    evaluate();

    return 0;
}