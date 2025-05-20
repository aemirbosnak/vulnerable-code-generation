//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max lengths for the parsing example
#define MAX_LINE_LENGTH 256
#define MAX_VARIABLES 50
#define MAX_VAR_NAME_LENGTH 20

// Structure to hold variable name and value
typedef struct {
    char name[MAX_VAR_NAME_LENGTH];
    int value;
} Variable;

// Global array to hold variables
Variable variables[MAX_VARIABLES];
int variable_count = 0;

// Function to add variable to the list
void add_variable(const char *name, int value) {
    if (variable_count < MAX_VARIABLES) {
        strncpy(variables[variable_count].name, name, MAX_VAR_NAME_LENGTH);
        variables[variable_count].value = value;
        variable_count++;
    } else {
        printf("Error: Maximum variable limit reached!\n");
    }
}

// Function to get the value of a variable by name
int get_variable_value(const char *name) {
    for (int i = 0; i < variable_count; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    printf("Error: Variable '%s' not found!\n", name);
    return 0; // Return 0 if variable not found
}

// Function to parse a line of input
void parse_line(const char *line) {
    char command[10];
    char var_name[MAX_VAR_NAME_LENGTH];
    int result;

    // Check for assignment
    if (sscanf(line, "%s %s = %d", command, var_name, &result) == 3 && strcmp(command, "let") == 0) {
        add_variable(var_name, result);
        printf("Assigned: %s = %d\n", var_name, result);
    } 
    // Check for addition
    else if (sscanf(line, "print %s + %s", var_name, command) == 2) {
        int v1 = get_variable_value(var_name);
        int v2 = get_variable_value(command);
        printf("Result: %d + %d = %d\n", v1, v2, v1 + v2);
    } 
    // Check for subtraction
    else if (sscanf(line, "print %s - %s", var_name, command) == 2) {
        int v1 = get_variable_value(var_name);
        int v2 = get_variable_value(command);
        printf("Result: %d - %d = %d\n", v1, v2, v1 - v2);
    } 
    // Invalid input
    else {
        printf("Error: Invalid command.\n");
    }
}

// Function to read lines and parse
void interactive_prompt() {
    char line[MAX_LINE_LENGTH];

    printf("Simple Variable Assignment Parser\n");
    printf("Type 'exit' to quit the program.\n");

    while (1) {
        printf("> ");
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0; // Remove trailing newline

        if (strcmp(line, "exit") == 0) {
            break;
        }

        parse_line(line);
    }
}

int main() {
    interactive_prompt();
    return 0;
}