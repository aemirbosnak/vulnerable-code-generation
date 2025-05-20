//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for storing parsed C syntax */
typedef struct {
    char* type;
    char* name;
} Variable;

/* Function to parse a C declaration */
Variable parseCDeclaration(char* input) {
    char* type = NULL;
    char* name = NULL;

    /* Tokenize input by whitespace */
    char* token = strtok(input, " ");
    int i = 0;

    /* Loop through tokens until end of string */
    while (token != NULL) {
        if (i == 0) {
            /* First token is the variable type */
            type = token;
        } else if (i == 1) {
            /* Second token is the variable name */
            name = token;
            /* Remove any trailing semicolons or commas from variable name */
            if (name[strlen(name)-1] == ';' || name[strlen(name)-1] == ',') {
                name[strlen(name)-1] = '\0';
            }
        }
        token = strtok(NULL, " ");
        i++;
    }

    /* Create new Variable struct and copy type and name */
    Variable var;
    var.type = malloc(strlen(type)+1);
    strcpy(var.type, type);
    var.name = malloc(strlen(name)+1);
    strcpy(var.name, name);

    return var;
}

int main() {
    char input[100];
    printf("Enter a C declaration:\n");
    fgets(input, 100, stdin);
    /* Remove newline character from input string */
    input[strlen(input)-1] = '\0';

    /* Call parseCDeclaration function and print results */
    Variable var = parseCDeclaration(input);
    printf("Type: %s\nName: %s\n", var.type, var.name);

    /* Free allocated memory */
    free(var.type);
    free(var.name);

    return 0;
}