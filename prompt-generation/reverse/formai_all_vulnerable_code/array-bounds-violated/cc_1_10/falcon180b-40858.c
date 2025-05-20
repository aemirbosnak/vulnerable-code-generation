//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAX_HISTORY 100
#define MAX_RESULT 100

struct history {
    char *input;
    double result;
};

struct history history[MAX_HISTORY];
int history_index = 0;

void push_history(char *input, double result) {
    if (history_index >= MAX_HISTORY) {
        printf("History buffer is full.\n");
        return;
    }
    history[history_index].input = strdup(input);
    history[history_index].result = result;
    history_index++;
}

void print_history() {
    for (int i = 0; i < history_index; i++) {
        printf("%s = %lf\n", history[i].input, history[i].result);
    }
}

double evaluate_expression(char *expression) {
    char *token = strtok(expression, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            push_history(expression, atof(token));
        } else {
            double operand1, operand2;
            char *operand1_str, *operand2_str;
            operand1_str = strdup(history[history_index - 1].input);
            operand2_str = strdup(history[history_index - 2].input);
            operand1 = atof(operand1_str);
            operand2 = atof(operand2_str);
            if (strcmp(token, "+") == 0) {
                push_history(expression, operand1 + operand2);
            } else if (strcmp(token, "-") == 0) {
                push_history(expression, operand1 - operand2);
            } else if (strcmp(token, "*") == 0) {
                push_history(expression, operand1 * operand2);
            } else if (strcmp(token, "/") == 0) {
                push_history(expression, operand1 / operand2);
            }
        }
        token = strtok(NULL, " ");
    }
    return atof(history[history_index - 1].input);
}

int main() {
    char input[MAX_RESULT];
    printf("Welcome to the Scientific Calculator!\n");
    while (1) {
        printf("Enter an expression: ");
        fgets(input, MAX_RESULT, stdin);
        input[strcspn(input, "\n")] = '\0';
        double result = evaluate_expression(input);
        printf("Result: %lf\n", result);
    }
    return 0;
}