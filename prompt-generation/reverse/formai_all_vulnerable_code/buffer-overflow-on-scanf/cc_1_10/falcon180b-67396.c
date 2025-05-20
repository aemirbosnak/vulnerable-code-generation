//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VARIABLES 100
#define MAX_VARIABLE_NAME_LEN 100

typedef struct {
    char name[MAX_VARIABLE_NAME_LEN];
    int type;
    int length;
    void *value;
} Variable;

int main() {
    FILE *fp;
    char filename[MAX_VARIABLE_NAME_LEN];
    int i, j;
    Variable variables[MAX_VARIABLES];

    // Prompt user for filename
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read in variables
    i = 0;
    while (fscanf(fp, "%s %d %d", variables[i].name, &variables[i].type, &variables[i].length)!= EOF) {
        variables[i].value = malloc(variables[i].length);
        fread(variables[i].value, variables[i].length, 1, fp);
        i++;
    }
    fclose(fp);

    // Print out variables
    printf("Variables:\n");
    for (i = 0; i < i; i++) {
        printf("Name: %s\nType: %d\nLength: %d\nValue: ", variables[i].name, variables[i].type, variables[i].length);
        switch (variables[i].type) {
            case 1: // int
                printf("%d\n", *(int *)variables[i].value);
                break;
            case 2: // float
                printf("%f\n", *(float *)variables[i].value);
                break;
            case 3: // double
                printf("%lf\n", *(double *)variables[i].value);
                break;
            case 4: // char *
                printf("%s\n", (char *)variables[i].value);
                break;
            default:
                printf("Unknown type\n");
        }
    }

    return 0;
}