//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_OPERANDS 10
#define MAX_OPERATORS 5

typedef enum { ADD, SUBTRACT, MULTIPLY, DIVIDE, UNDEFINED } Operator;

typedef struct {
    double value;
    Operator op;
} Operand;

void parse_input(char* input, Operand operands[MAX_OPERANDS], Operator* operator, double* operand_value) {
    char token[10];
    int i = 0;

    sscanf(input, "%s %s %s %s %n", token, token + 1, token + 3, token + 5, input + *input);

    if (*input) {
        operands[i].value = atof(token);
        operands[i].op = UNDEFINED;
        i++;
        parse_input(input, operands, operator, operand_value);
        return;
    }

    if (strlen(token) > 0) {
        if (strcmp(token, "+") == 0)
            *operator = ADD;
        else if (strcmp(token, "-") == 0)
            *operator = SUBTRACT;
        else if (strcmp(token, "*") == 0)
            *operator = MULTIPLY;
        else if (strcmp(token, "/") == 0)
            *operator = DIVIDE;
        else {
            fprintf(stderr, "Invalid operator: %s\n", token);
            exit(EXIT_FAILURE);
        }
    } else {
        *operand_value = operands[--i].value;
    }
}

int main() {
    Operand operands[MAX_OPERANDS];
    Operator operator;
    double operand_value1, operand_value2;

    printf("Enter expression in the format: number operator number operator number ...\n");
    printf("Example: 5 + 3 * 2.5\n");
    printf("Press Ctrl+D to exit\n");

    while (1) {
        Operand current_operand;
        char input[1024];

        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (feof(stdin))
            break;

        parse_input(input, operands, &operator, &operand_value1);
        parse_input(input, operands, NULL, &operand_value2);

        switch (operator) {
            case ADD:
                current_operand.value = operands[0].value + operands[1].value;
                break;
            case SUBTRACT:
                current_operand.value = operands[0].value - operands[1].value;
                break;
            case MULTIPLY:
                current_operand.value = operands[0].value * operands[1].value;
                break;
            case DIVIDE:
                if (operands[1].value == 0) {
                    fprintf(stderr, "Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
                current_operand.value = operands[0].value / operands[1].value;
                break;
            default:
                fprintf(stderr, "Error: Unknown operator\n");
                exit(EXIT_FAILURE);
        }

        operands[0] = current_operand;

        for (int i = 1; i < MAX_OPERANDS; i++) {
            operands[i].value = 0;
            operands[i].op = UNDEFINED;
        }
    }

    printf("Result: %.2f\n", operands[0].value);
    return 0;
}