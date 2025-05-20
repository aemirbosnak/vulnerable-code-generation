//LLAMA2-13B DATASET v1.0 Category: Syntax parsing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define SYMBOL_COUNT 16

typedef struct {
    char name[20];
    int value;
} symbol_t;

static symbol_t symbols[SYMBOL_COUNT] = {
    {"+", 1},
    {"-", -1},
    {"*", 2},
    {"/", 2},
    {"(", 3},
    {")", -3},
    {"&&", 4},
    {"||", 5},
    {"==", 6},
    {"!=", -6},
    {"<", 7},
    {">", -7},
    {"==", 8},
    {"!=", -8}
};

int parse(char *input) {
    int length = strlen(input);
    int i = 0;
    int symbol = 0;
    int value = 0;

    while (i < length) {
        symbol = input[i];
        if (symbol == '(' || symbol == ')' || symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/') {
            value = symbols[symbol].value;
            if (value == 3 || value == -3) {
                i += value;
            } else {
                symbol = 0;
            }
        } else if (symbol == '{' || symbol == '}') {
            symbol = 0;
        } else if (symbol == ' ' || symbol == '\t') {
            continue;
        } else {
            return -1;
        }
        i++;
    }

    return symbol;
}

int main() {
    char input[MAX_LENGTH];
    int result;

    printf("Enter a C expression:\n");
    fgets(input, MAX_LENGTH, stdin);

    result = parse(input);
    if (result != 0) {
        printf("Invalid expression\n");
    } else {
        printf("Expression parsed successfully\n");
    }

    return 0;
}