//FormAI DATASET v1.0 Category: Syntax parsing ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* This program will parse an input string and check if it is a valid C function declaration */

int main() {
    char input[100];
    printf("Please enter a C function declaration:");
    fgets(input, 100, stdin); //fgets reads one line of input from the user

    bool valid_declaration = true; //boolean to track if the declaration is valid or not

    //parsing starts here
    char *return_type = strtok(input, " "); //the first token is the return type of the function
    if (strcmp(return_type, "int") != 0 && strcmp(return_type, "char") != 0 && strcmp(return_type, "float") != 0 && strcmp(return_type, "double") != 0 && strcmp(return_type, "void") != 0) {
        valid_declaration = false; //if the return type is not valid, the declaration is invalid
    }

    char *function_name = strtok(NULL, "("); //the next token should be the function name
    if (function_name == NULL) {
        valid_declaration = false; //if there is no function name, the declaration is invalid
    }

    char *parameter_list = strtok(NULL, ")"); //the parameter list should be enclosed in parentheses
    if (parameter_list == NULL || parameter_list[strlen(parameter_list)-1] != '(') {
        valid_declaration = false; //if the parameter list is missing or malformed, the declaration is invalid
    }

    //check each parameter: they should be of the form "<type> <name>"
    char *parameter = strtok(parameter_list, ",");
    while (parameter != NULL) {
        char *type = strtok(parameter, " ");
        if (strcmp(type, "int") != 0 && strcmp(type, "char") != 0 && strcmp(type, "float") != 0 && strcmp(type, "double") != 0 && strcmp(type, "void") != 0) {
            valid_declaration = false; //if the parameter type is not valid, the declaration is invalid
        }
        char *name = strtok(NULL, " ");
        if (name == NULL) {
            valid_declaration = false; //if the parameter name is missing, the declaration is invalid
        }
        parameter = strtok(NULL, ",");
    }

    if (valid_declaration) {
        printf("The input string is a valid C function declaration.\n");
    } else {
        printf("The input string is not a valid C function declaration.\n");
    }

    return 0;
}