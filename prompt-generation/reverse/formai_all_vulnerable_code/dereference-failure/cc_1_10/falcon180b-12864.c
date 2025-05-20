//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int value;
} variable_t;

variable_t *create_variable(char *name, int value) {
    variable_t *var = malloc(sizeof(variable_t));
    var->name = strdup(name);
    var->value = value;
    return var;
}

int evaluate_expression(char *expression, variable_t **vars, int vars_count) {
    int result = 0;
    char *token = strtok(expression, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < vars_count; i++) {
            if (strcmp(token, vars[i]->name) == 0) {
                result += vars[i]->value;
                break;
            }
        }
        if (i == vars_count) {
            printf("Invalid variable: %s\n", token);
            return -1;
        }
        token = strtok(NULL, " ");
    }
    return result;
}

int main() {
    variable_t *a = create_variable("a", 1);
    variable_t *b = create_variable("b", 2);
    variable_t *c = create_variable("c", 3);
    variable_t *vars[] = {a, b, c};
    int vars_count = sizeof(vars) / sizeof(vars[0]);

    char input[1024];
    while (fgets(input, 1024, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        int result = evaluate_expression(input, vars, vars_count);
        if (result!= -1) {
            printf("Result: %d\n", result);
        }
    }

    for (int i = 0; i < vars_count; i++) {
        free(vars[i]->name);
        free(vars[i]);
    }

    return 0;
}