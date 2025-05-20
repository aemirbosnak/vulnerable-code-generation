//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: protected
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct {
        char *input;
        double result;
    } calculator_t;

    void parse_input(char *input, calculator_t *calc) {
        // Parse the input string and set the result
        char *token = strtok(input, " ");
        if (token == NULL) {
            return;
        }

        double num1 = atof(token);
        token = strtok(NULL, " ");
        if (token == NULL) {
            return;
        }

        double num2 = atof(token);
        switch (*token) {
            case '+':
                calc->result = num1 + num2;
                break;
            case '-':
                calc->result = num1 - num2;
                break;
            case '*':
                calc->result = num1 * num2;
                break;
            case '/':
                calc->result = num1 / num2;
                break;
            default:
                break;
        }
    }

    int main(void) {
        char input[1024];
        calculator_t calc = {0};

        while (1) {
            printf("Enter an expression: ");
            scanf("%s", input);
            parse_input(input, &calc);
            printf("Result: %f\n", calc.result);
        }

        return 0;
    }