//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

// Function to split a string using delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **result;
    char *token;

    result = (char **)malloc(sizeof(char *));
    if (result == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    token = strtok(str, delimiter);
    while (token!= NULL) {
        count++;
        result = (char **)realloc(result, sizeof(char *) * count);
        if (result == NULL) {
            printf("Memory error\n");
            exit(1);
        }
        result[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    return result;
}

// Function to read CSV file
void read_csv(char *filename) {
    FILE *fp;
    char line[MAX_ROW];
    char delimiter;
    int rows = 0;
    int cols = 0;
    char **data;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Read first line to determine number of columns
    fgets(line, MAX_ROW, fp);
    cols = split(line, ',')[0];

    // Allocate memory for data
    data = (char **)malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        data[i] = (char *)malloc(sizeof(char) * cols);
    }

    // Read remaining lines and store in data
    while (fgets(line, MAX_ROW, fp)!= NULL) {
        rows++;
        data[rows - 1] = split(line, ',');
        if (data[rows - 1][0] == NULL) {
            printf("Error reading line\n");
            exit(1);
        }
    }

    fclose(fp);

    // Print data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
}

int main() {
    char filename[MAX_ROW];

    printf("Enter CSV filename: ");
    scanf("%s", filename);

    read_csv(filename);

    return 0;
}