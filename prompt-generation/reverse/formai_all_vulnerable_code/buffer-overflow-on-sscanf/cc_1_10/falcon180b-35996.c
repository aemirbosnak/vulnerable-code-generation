//Falcon-180B DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_VARIABLES 20
#define MAX_VARIABLE_NAME_LENGTH 50

typedef struct {
    char name[MAX_VARIABLE_NAME_LENGTH];
    char value[MAX_LINE_LENGTH];
} variable_t;

int num_variables = 0;
variable_t variables[MAX_NUM_VARIABLES];

void add_variable(char *name, char *value) {
    if (num_variables >= MAX_NUM_VARIABLES) {
        printf("Error: Maximum number of variables reached.\n");
        exit(1);
    }

    strcpy(variables[num_variables].name, name);
    strcpy(variables[num_variables].value, value);

    num_variables++;
}

void write_variables_to_file(char *filename) {
    FILE *file;
    int i;

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    for (i = 0; i < num_variables; i++) {
        fprintf(file, "%s = %s\n", variables[i].name, variables[i].value);
    }

    fclose(file);
}

void read_variables_from_file(char *filename) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char name[MAX_VARIABLE_NAME_LENGTH];
    char value[MAX_LINE_LENGTH];
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        sscanf(line, "%s = %s", name, value);

        add_variable(name, value);
    }

    fclose(file);
}

int main() {
    char filename[MAX_LINE_LENGTH];
    int i;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    read_variables_from_file(filename);

    printf("\nVariables:\n");
    for (i = 0; i < num_variables; i++) {
        printf("%s = %s\n", variables[i].name, variables[i].value);
    }

    write_variables_to_file(filename);

    printf("\nVariables written to file %s.\n", filename);

    return 0;
}