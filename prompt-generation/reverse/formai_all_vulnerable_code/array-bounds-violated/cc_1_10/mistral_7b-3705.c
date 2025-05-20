//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_SIZE 1024
#define NUM_OPERANDS 10
#define NUM_OPERATORS 4

char input[MAX_INPUT_SIZE];
char operands[NUM_OPERANDS][32];
char operators[NUM_OPERATORS][3] = {"+", "-", "*", "/"};
double operands_values[NUM_OPERANDS];
int operators_positions[NUM_OPERANDS];

void parse_input(void);
void perform_calculation(void);

int main() {
    while (1) {
        printf("Calculator > ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0';
        parse_input();
        perform_calculation();
    }

    return 0;
}

void parse_input(void) {
    char *token;
    int i = 0, j = 0;

    token = strtok(input, " ");
    while (token != NULL) {
        if (i < NUM_OPERANDS) {
            strcpy(operands[i], token);
            operands_values[i] = strtod(token, NULL);
            i++;
        } else {
            for (j = 0; j < NUM_OPERATORS; j++) {
                if (strcmp(token, operators[j]) == 0) {
                    operators_positions[i - 1] = j;
                    break;
                }
            }
        }

        token = strtok(NULL, " ");
    }
}

void perform_calculation(void) {
    int i, j;
    double result;

    for (i = 0; i < NUM_OPERANDS - 1; i++) {
        for (j = 0; j < NUM_OPERATORS; j++) {
            if (operators_positions[i] == j) {
                switch (j) {
                    case 0:
                        operands_values[i + 1] += operands_values[i];
                        break;
                    case 1:
                        operands_values[i + 1] -= operands_values[i];
                        break;
                    case 2:
                        operands_values[i + 1] *= operands_values[i];
                        break;
                    case 3:
                        if (operands_values[i] == 0) {
                            printf("Error: Division by zero is not allowed.\n");
                            return;
                        }
                        operands_values[i + 1] /= operands_values[i];
                        break;
                }

                i++;
                break;
            }
        }
    }

    result = operands_values[NUM_OPERANDS - 1];

    printf("Result: %.16lf\n", result);
}