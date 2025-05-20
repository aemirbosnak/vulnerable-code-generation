//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100

// Function to split a string using a delimiter
char *split(char *str, char delimiter) {
    char *token;
    char *result = strdup(str);

    // Replace delimiter with null character
    char *delim_ptr = strchr(result, delimiter);
    while (delim_ptr!= NULL) {
        *delim_ptr = '\0';
        token = strtok(result, ",");
        result = strcat(result, token);
        result = strcat(result, ",");
        delim_ptr = strchr(delim_ptr + 1, delimiter);
    }
    return result;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *filename = argv[1];
    char delimiter = ',';

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // Read header line
    fgets(line, MAX_LINE_SIZE, fp);
    int num_columns = 0;
    char *header = split(line, delimiter);
    char **column_names = malloc(MAX_COLUMNS * sizeof(char *));
    while (header!= NULL) {
        column_names[num_columns] = strdup(header);
        num_columns++;
        header = strtok(NULL, delimiter);
    }

    // Print header
    printf("+");
    for (int i = 0; i < num_columns; i++) {
        printf("-%10s", column_names[i]);
    }
    printf("+\n");

    // Read data lines
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *row = split(line, delimiter);
        for (int i = 0; i < num_columns; i++) {
            printf("%-10s", row[i]);
        }
        printf("\n");
    }

    // Close file
    fclose(fp);
    return 0;
}