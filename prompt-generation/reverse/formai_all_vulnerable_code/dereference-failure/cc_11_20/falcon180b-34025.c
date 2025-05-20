//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_VARIABLES 100
#define MAX_LINE_LENGTH 1000

int num_variables;
char *variable_names[MAX_VARIABLES];
double variable_values[MAX_VARIABLES];

int main() {
    char line[MAX_LINE_LENGTH];
    char *token;
    int i;

    num_variables = 0;

    printf("Enter variable names (up to %d):\n", MAX_VARIABLES - 1);
    while (num_variables < MAX_VARIABLES - 1 && fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        token = strtok(line, " ");
        while (token!= NULL) {
            for (i = 0; i < num_variables; i++) {
                if (strcmp(token, variable_names[i]) == 0) {
                    printf("Error: variable name already exists.\n");
                    return 1;
                }
            }
            strcpy(variable_names[num_variables], token);
            num_variables++;
            token = strtok(NULL, " ");
        }
    }

    printf("Enter variable values (up to %d):\n", num_variables);
    for (i = 0; i < num_variables; i++) {
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
            printf("Error: unexpected end of input.\n");
            return 1;
        }
        variable_values[i] = atof(line);
    }

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (line[0] == '\n') {
            printf("\n");
        } else {
            token = strtok(line, " ");
            while (token!= NULL) {
                for (i = 0; i < num_variables; i++) {
                    if (strcmp(token, variable_names[i]) == 0) {
                        printf("%s = %.3f\n", token, variable_values[i]);
                        break;
                    }
                }
                if (i == num_variables) {
                    printf("Error: variable name not found.\n");
                }
                token = strtok(NULL, " ");
            }
        }
    }

    return 0;
}