//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

typedef struct {
    char* buffer;
    int buffer_size;
    int buffer_index;
} Calculator;

Calculator* calculator_create() {
    Calculator* calc = malloc(sizeof(Calculator));
    calc->buffer = malloc(MAX_BUFFER_SIZE);
    calc->buffer_size = MAX_BUFFER_SIZE;
    calc->buffer_index = 0;
    return calc;
}

void calculator_destroy(Calculator* calc) {
    free(calc->buffer);
    free(calc);
}

void calculator_clear(Calculator* calc) {
    calc->buffer_index = 0;
    memset(calc->buffer, 0, calc->buffer_size);
}

void calculator_append(Calculator* calc, char c) {
    if (calc->buffer_index >= calc->buffer_size) {
        calc->buffer_size *= 2;
        calc->buffer = realloc(calc->buffer, calc->buffer_size);
    }
    calc->buffer[calc->buffer_index++] = c;
    calc->buffer[calc->buffer_index] = '\0';
}

int calculator_parse(Calculator* calc) {
    char* endptr = NULL;
    double result = strtod(calc->buffer, &endptr);
    if (endptr == calc->buffer) {
        return 0;
    }
    calc->buffer_index = (int) (endptr - calc->buffer);
    return 1;
}

void calculator_print(Calculator* calc) {
    printf("%s\n", calc->buffer);
}

int main() {
    Calculator* calc = calculator_create();
    char input[MAX_BUFFER_SIZE];
    while (1) {
        printf("Enter an expression: ");
        fgets(input, MAX_BUFFER_SIZE, stdin);
        strcat(calc->buffer, input);
        int parsed = calculator_parse(calc);
        if (!parsed) {
            printf("Invalid expression.\n");
            calculator_clear(calc);
        } else {
            double result = atof(calc->buffer);
            printf("Result: %f\n", result);
            calculator_clear(calc);
        }
    }
    calculator_destroy(calc);
    return 0;
}