//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 100
#define MAX_VARIABLE_NAME_LENGTH 50

typedef struct {
    char name[MAX_VARIABLE_NAME_LENGTH];
    char value[MAX_VARIABLE_NAME_LENGTH];
} Variable;

int main(int argc, char **argv) {
    int num_variables = 0;
    Variable *variables = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    // Read in the metadata file
    FILE *metadata_file = fopen("metadata.txt", "r");
    if (metadata_file == NULL) {
        fprintf(stderr, "Error: Could not open metadata file.\n");
        exit(EXIT_FAILURE);
    }

    // Count the number of variables in the metadata file
    while ((read = getline(&line, &len, metadata_file))!= -1) {
        if (strncmp(line, "Variable: ", 9) == 0) {
            num_variables++;
        }
    }

    // Allocate memory for the variables
    variables = malloc(num_variables * sizeof(Variable));
    if (variables == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for variables.\n");
        exit(EXIT_FAILURE);
    }

    // Read in the metadata file again and extract the variables
    rewind(metadata_file);
    while ((read = getline(&line, &len, metadata_file))!= -1) {
        if (strncmp(line, "Variable: ", 9) == 0) {
            strncpy(variables[num_variables - 1].name, line + 9, MAX_VARIABLE_NAME_LENGTH - 1);
            variables[num_variables - 1].name[MAX_VARIABLE_NAME_LENGTH - 1] = '\0';
            strncpy(variables[num_variables - 1].value, line + 9 + strlen("Variable: "), MAX_VARIABLE_NAME_LENGTH - 1);
            variables[num_variables - 1].value[MAX_VARIABLE_NAME_LENGTH - 1] = '\0';
        }
    }

    // Print out the variables
    for (int i = 0; i < num_variables; i++) {
        printf("Variable %d:\n", i + 1);
        printf("Name: %s\n", variables[i].name);
        printf("Value: %s\n", variables[i].value);
    }

    // Free memory
    free(line);
    free(variables);

    return 0;
}