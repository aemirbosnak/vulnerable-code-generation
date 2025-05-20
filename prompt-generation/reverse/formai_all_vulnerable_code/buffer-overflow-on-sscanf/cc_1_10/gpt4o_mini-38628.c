//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char var_name;
    double value;
} Variable;

Variable variables[MAX_SIZE];
int var_count = 0;

void add_variable(char name, double value) {
    variables[var_count].var_name = name;
    variables[var_count].value = value;
    var_count++;
}

double get_variable_value(char name) {
    for (int i = 0; i < var_count; i++) {
        if (variables[i].var_name == name) {
            return variables[i].value;
        }
    }
    printf("Error: Variable '%c' not found\n", name);
    exit(EXIT_FAILURE);
}

double parse_expression(const char *expr);
double parse_term(const char **expr);
double parse_factor(const char **expr);
double parse_number(const char **expr);
double parse_variable(const char **expr);

double parse_expression(const char *expr) {
    double result = parse_term(&expr);
    while (*expr == '+' || *expr == '-') {
        char op = *expr;
        expr++;
        double term = parse_term(&expr);
        if (op == '+') {
            result += term;
        } else {
            result -= term;
        }
    }
    return result;
}

double parse_term(const char **expr) {
    double result = parse_factor(expr);
    while (**expr == '*' || **expr == '/') {
        char op = **expr;
        (*expr)++;
        double factor = parse_factor(expr);
        if (op == '*') {
            result *= factor;
        } else {
            result /= factor;
        }
    }
    return result;
}

double parse_factor(const char **expr) {
    if (isdigit(**expr)) {
        return parse_number(expr);
    } else if (isalpha(**expr)) {
        return parse_variable(expr);
    } else if (**expr == '(') {
        (*expr)++;
        double value = parse_expression(*expr);
        while (**expr != ')') {
            (*expr)++;
        }
        (*expr)++;
        return value;
    } else {
        printf("Error: Unexpected character '%c'\n", **expr);
        exit(EXIT_FAILURE);
    }
}

double parse_number(const char **expr) {
    double value = 0.0;
    while (isdigit(**expr)) {
        value = value * 10 + (**expr - '0');
        (*expr)++;
    }
    if (**expr == '.') {
        (*expr)++;
        double decimal_place = 0.1;
        while (isdigit(**expr)) {
            value += (**expr - '0') * decimal_place;
            decimal_place *= 0.1;
            (*expr)++;
        }
    }
    return value;
}

double parse_variable(const char **expr) {
    char var_name = **expr;
    (*expr)++;
    return get_variable_value(var_name);
}

void assign_variable(char name, double value) {
    add_variable(name, value);
    printf("Assigned: %c = %f\n", name, value);
}

int main() {
    char input[MAX_SIZE];
    char variable_name;
    double variable_value;

    printf("Enter variable assignment (e.g., a = 5): ");
    fgets(input, MAX_SIZE, stdin);
    sscanf(input, "%c = %lf", &variable_name, &variable_value);
    assign_variable(variable_name, variable_value);

    while (1) {
        printf("Enter an expression (or 'exit' to quit): ");
        fgets(input, MAX_SIZE, stdin);
        if (strncmp(input, "exit", 4) == 0) break;
        
        double result = parse_expression(input);
        printf("Result: %f\n", result);
    }
    
    return 0;
}