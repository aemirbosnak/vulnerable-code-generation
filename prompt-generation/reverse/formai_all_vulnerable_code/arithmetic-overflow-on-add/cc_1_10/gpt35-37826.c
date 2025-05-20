//FormAI DATASET v1.0 Category: Educational ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LEN 1000
#define MAX_TOKENS 100

typedef enum token_type {
    INTEGER,
    OPERATOR,
    PARENTHESIS_LEFT,
    PARENTHESIS_RIGHT
} token_type;

typedef struct token {
    token_type type;
    int value;
} token;

typedef enum operator_type {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION
} operator_type;

typedef struct operation {
    operator_type operator;
    int operand1;
    int operand2;
} operation;

int tokenize(char *input, token *tokens) {
    int num_tokens = 0;
    char *token_str = strtok(input, " ");
    while (token_str != NULL) {
        token new_token;
        if (token_str[0] == '(') {
            new_token.type = PARENTHESIS_LEFT;
        } else if (token_str[0] == ')') {
            new_token.type = PARENTHESIS_RIGHT;
        } else if (token_str[0] == '+' || token_str[0] == '-' ||
            token_str[0] == '*' || token_str[0] == '/') {
            new_token.type = OPERATOR;
            switch (token_str[0]) {
                case '+':
                    new_token.value = ADDITION;
                    break;
                case '-':
                    new_token.value = SUBTRACTION;
                    break;
                case '*':
                    new_token.value = MULTIPLICATION;
                    break;
                case '/':
                    new_token.value = DIVISION;
                    break;
            }
        } else {
            new_token.type = INTEGER;
            new_token.value = atoi(token_str);
        }
        tokens[num_tokens] = new_token;
        num_tokens++;
        token_str = strtok(NULL, " ");
    }
    return num_tokens;
}

int parse_expression(int start, int end, token *tokens, operation *output) {
    int num_operations = 0;
    int num_parentheses = 0;
    int last_operator_location = start;
    for (int i = start; i <= end; i++) {
        switch (tokens[i].type) {
            case INTEGER:
                if (num_parentheses == 0) {
                    // We have a complete operand and operator, create a new operation
                    operation new_operation;
                    new_operation.operand1 = tokens[last_operator_location+1].value;
                    new_operation.operand2 = tokens[i].value;
                    new_operation.operator = tokens[last_operator_location].value;
                    output[num_operations] = new_operation;
                    num_operations++;

                    // The next operator location will be one after this integer
                    last_operator_location = i + 1;
                }
                break;
            case OPERATOR:
                num_parentheses = 0;
                break;
            case PARENTHESIS_LEFT:
                num_parentheses++;
                if (num_parentheses == 1 && i != start) {
                    // We have a complete operand and operator, create a new operation
                    operation new_operation;
                    new_operation.operand1 = tokens[last_operator_location+1].value;
                    new_operation.operand2 = parse_expression(i+1, end, tokens, output);
                    new_operation.operator = tokens[last_operator_location].value;
                    output[num_operations] = new_operation;
                    num_operations++;

                    // The next operator location will be one after the end of the sub-expression
                    i = end;
                    last_operator_location = i + 1;
                }
                break;
            case PARENTHESIS_RIGHT:
                num_parentheses--;
                break;
        }
    }

    // We have a last operand and operator that need to be processed
    operation new_operation;
    new_operation.operand1 = tokens[last_operator_location+1].value;
    new_operation.operand2 = tokens[end-1].value;
    new_operation.operator = tokens[end-2].value;
    output[num_operations] = new_operation;
    num_operations++;

    return num_operations == 1 ? num_operations : parse_expression(start, end-2, tokens, output);
}

int evaluate_operation(operation op) {
    switch (op.operator) {
        case ADDITION:
            return op.operand1 + op.operand2;
        case SUBTRACTION:
            return op.operand1 - op.operand2;
        case MULTIPLICATION:
            return op.operand1 * op.operand2;
        case DIVISION:
            return op.operand1 / op.operand2;
    }
}

int evaluate_expression(operation *operations, int num_operations) {
    int result = evaluate_operation(operations[0]);
    for (int i = 1; i < num_operations; i++) {
        result = evaluate_operation(operations[i]);
    }
    return result;
}

int main() {
    char input[MAX_INPUT_LEN];
    fgets(input, MAX_INPUT_LEN, stdin);
    token tokens[MAX_TOKENS];
    int num_tokens = tokenize(input, tokens);
    operation operations[MAX_TOKENS];
    int num_operations = parse_expression(0, num_tokens-1, tokens, operations);
    int result = evaluate_expression(operations, num_operations);
    printf("%d", result);
    return 0;
}