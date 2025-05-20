//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define MAX_OPERATORS 100

int num_operators = 0;
char operators[MAX_OPERATORS][MAX_SIZE];

char *pop_operator() {
    if (num_operators > 0) {
        num_operators--;
        return operators[num_operators];
    } else {
        return NULL;
    }
}

void push_operator(char *op) {
    strcpy(operators[num_operators], op);
    num_operators++;
}

int main() {
    char input[MAX_SIZE];
    char *token;
    double num1, num2;
    int i;

    printf("Enter an expression in infix notation:\n");
    fgets(input, MAX_SIZE, stdin);

    token = strtok(input, " ");
    while (token!= NULL) {
        if (isdigit(token[0])) {
            num1 = atof(token);
            printf("%.0f ", num1);
        } else if (token[0] == '(') {
            push_operator(token);
        } else if (token[0] == ')') {
            while ((operators[num_operators - 1][0]!= '(') && (num_operators > 0)) {
                printf("%.0f ", pop_operator()[0]);
            }
            pop_operator();
        } else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            push_operator(token);
        }
        token = strtok(NULL, " ");
    }

    while (num_operators > 0) {
        printf("%.0f ", pop_operator()[0]);
    }

    return 0;
}