//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_VARIABLES 100

typedef struct {
    char *name;
    int type;
    int line_number;
} Variable;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int line_number = 1;
    int num_variables = 0;
    Variable *variables = malloc(MAX_NUM_VARIABLES * sizeof(Variable));

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " \t\r\n");
        while (token!= NULL) {
            if (isalpha(token[0])) {
                if (num_variables >= MAX_NUM_VARIABLES) {
                    printf("Error: Too many variables.\n");
                    return 1;
                }
                variables[num_variables].name = strdup(token);
                variables[num_variables].type = 0;
                variables[num_variables].line_number = line_number;
                num_variables++;
            }
            token = strtok(NULL, " \t\r\n");
        }
        line_number++;
    }

    fclose(fp);

    for (int i = 0; i < num_variables; i++) {
        printf("Variable %d: %s\n", i+1, variables[i].name);
    }

    free(variables);
    return 0;
}