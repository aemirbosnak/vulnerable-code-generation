//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to our CSV Reader program!\n");

    char filename[50];
    printf("Please enter the name of the .csv file you would like to read: ");
    scanf("%s", filename);

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    char line[256];
    int num_lines = 0;
    int num_columns = 0;
    int i, j;

    while (fgets(line, sizeof(line), fp) != NULL) {
        num_lines++;
        if (num_lines == 1) {
            char *token;
            token = strtok(line, ",");
            while (token != NULL) {
                num_columns++;
                token = strtok(NULL, ",");
            }
        }
    }

    rewind(fp);

    char **matrix;
    matrix = (char **)malloc(num_lines * sizeof(char *));
    for (i = 0; i < num_lines; i++) {
        matrix[i] = (char *)malloc(num_columns * sizeof(char));
    }

    i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        j = 0;
        char *token;
        token = strtok(line, ",");
        while (token != NULL) {
            strcpy(matrix[i][j], token);
            token = strtok(NULL, ",");
            j++;
        }
        i++;
    }

    printf("\nHere is the content of the file:\n\n");

    for (i = 0; i < num_lines; i++) {
        for (j = 0; j < num_columns; j++) {
            printf("%s", matrix[i][j]);
            if (j != num_columns-1) {
                printf(",");
            }
        }
        printf("\n");
    }

    fclose(fp);

    for (i = 0; i < num_lines; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("\nThank you for using our CSV Reader program!\n");

    return 0;
}