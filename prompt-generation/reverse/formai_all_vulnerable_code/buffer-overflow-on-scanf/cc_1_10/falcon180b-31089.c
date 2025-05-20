//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int is_numeric(char *str);
int is_operator(char *str);
int is_parentheses(char *str);
char *evaluate_expression(char *expression);

int main() {
    char input[200];
    printf("Enter a mathematical expression: ");
    scanf("%[^\n]", input);

    char *expression = strdup(input);
    char *result = evaluate_expression(expression);

    if (result!= NULL) {
        printf("Result: %s\n", result);
    } else {
        printf("Invalid expression.\n");
    }

    free(expression);
    free(result);

    return 0;
}

int is_numeric(char *str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_operator(char *str) {
    if (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0) {
        return 1;
    }
    return 0;
}

int is_parentheses(char *str) {
    if (strcmp(str, "(") == 0 || strcmp(str, ")") == 0) {
        return 1;
    }
    return 0;
}

char *evaluate_expression(char *expression) {
    char *result = malloc(200 * sizeof(char));
    char *temp = strdup(expression);
    int i = 0;
    while (temp[i]!= '\0') {
        if (is_numeric(temp)) {
            sprintf(result, "%s%s ", result, temp);
        } else if (is_operator(temp)) {
            char *token = strtok(temp, " ");
            while (token!= NULL) {
                sprintf(result, "%s%s ", result, token);
                token = strtok(NULL, " ");
            }
        } else if (is_parentheses(temp)) {
            char *token = strtok(temp, " ");
            while (token!= NULL) {
                sprintf(result, "%s%s ", result, token);
                token = strtok(NULL, " ");
            }
        }
        i++;
    }
    free(temp);
    return result;
}