//Falcon-180B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int value;
} variable_t;

variable_t variables[MAX_SIZE];
int num_variables = 0;

void add_variable(char *name, int value) {
    if (num_variables >= MAX_SIZE) {
        printf("Error: too many variables.\n");
        exit(1);
    }

    variables[num_variables].name = strdup(name);
    variables[num_variables].value = value;

    num_variables++;
}

int get_variable_index(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void evaluate_expression(char *expression) {
    char *token = strtok(expression, " ");

    while (token!= NULL) {
        int index = get_variable_index(token);

        if (index == -1) {
            printf("Error: undefined variable '%s'.\n", token);
            exit(1);
        }

        if (strcmp(token, "+") == 0) {
            int value = variables[index].value;
            variables[index].value += get_variable_index(strtok(NULL, " "));
        } else if (strcmp(token, "-") == 0) {
            int value = variables[index].value;
            variables[index].value -= get_variable_index(strtok(NULL, " "));
        } else if (strcmp(token, "*") == 0) {
            int value = variables[index].value;
            variables[index].value *= get_variable_index(strtok(NULL, " "));
        } else if (strcmp(token, "/") == 0) {
            int value = variables[index].value;
            variables[index].value /= get_variable_index(strtok(NULL, " "));
        } else if (strcmp(token, "=") == 0) {
            int value = get_variable_index(strtok(NULL, " "));
            variables[index].value = value;
        }

        token = strtok(NULL, " ");
    }
}

int main() {
    add_variable("x", 5);
    add_variable("y", 10);

    char *expression = "x + y = y * 2";
    evaluate_expression(expression);

    printf("x = %d\n", variables[0].value);
    printf("y = %d\n", variables[1].value);

    return 0;
}