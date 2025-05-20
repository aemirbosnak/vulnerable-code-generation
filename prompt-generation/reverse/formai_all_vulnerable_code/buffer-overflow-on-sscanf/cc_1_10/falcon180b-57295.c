//Falcon-180B DATASET v1.0 Category: File handling ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_NUM_VARIABLES 100

typedef struct {
    char name[MAX_LINE_SIZE];
    int value;
} Variable;

int main() {
    FILE *input_file;
    FILE *output_file;
    char input_filename[MAX_LINE_SIZE];
    char output_filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char delimiter[MAX_LINE_SIZE];
    int num_variables = 0;
    Variable variables[MAX_NUM_VARIABLES];

    // Prompt user for input and output filenames
    printf("Enter input filename: ");
    scanf("%s", input_filename);
    printf("Enter output filename: ");
    scanf("%s", output_filename);

    // Open input and output files
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Read first line of input file to determine delimiter
    fgets(line, MAX_LINE_SIZE, input_file);
    if (line[0] == '#') {
        sscanf(line, "# Delimiter: %s", delimiter);
    } else {
        strcpy(delimiter, ",");
    }

    // Read variables from input file
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        if (line[0] == '#') {
            continue;
        }
        char *token = strtok(line, delimiter);
        while (token!= NULL) {
            if (num_variables >= MAX_NUM_VARIABLES) {
                printf("Error: Too many variables.\n");
                exit(1);
            }
            strcpy(variables[num_variables].name, token);
            variables[num_variables].value = 0;
            num_variables++;
            token = strtok(NULL, delimiter);
        }
    }

    // Write variables to output file
    fprintf(output_file, "Variables:\n");
    for (int i = 0; i < num_variables; i++) {
        fprintf(output_file, "%s = %d\n", variables[i].name, variables[i].value);
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}