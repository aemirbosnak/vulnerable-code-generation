//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    double num;
    char op;
} Token;

int main() {
    char input[1024];
    Token tokens[1024];
    int numTokens = 0;

    printf("Enter an expression: ");
    gets(input);

    char *ptr = strtok(input, " ");
    while (ptr != NULL) {
        if (strlen(ptr) == 1 && strchr("+-*/", *ptr)) {
            tokens[numTokens].op = *ptr;
        } else {
            tokens[numTokens].num = atof(ptr);
        }
        numTokens++;
        ptr = strtok(NULL, " ");
    }

    double result = tokens[0].num;
    for (int i = 1; i < numTokens; i++) {
        switch (tokens[i].op) {
            case '+':
                result += tokens[i].num;
                break;
            case '-':
                result -= tokens[i].num;
                break;
            case '*':
                result *= tokens[i].num;
                break;
            case '/':
                result /= tokens[i].num;
                break;
        }
    }

    printf("Result: %f\n", result);

    return 0;
}