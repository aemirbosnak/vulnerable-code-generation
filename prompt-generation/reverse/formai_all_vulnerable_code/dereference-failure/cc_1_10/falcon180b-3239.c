//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string by a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, delimiter);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count - 1] = NULL;
    return tokens;
}

// Function to read a CSV file and return its contents as a 2D array
int **read_csv(FILE *fp) {
    char line[1024];
    int rows = 0, cols = 0;
    int **data = NULL;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char **tokens = split(line, ',');
        int col_count = 0;
        while (tokens[col_count]!= NULL) {
            col_count++;
        }
        if (rows == 0) {
            rows = col_count;
        } else if (col_count!= rows) {
            printf("Error: Invalid number of columns\n");
            exit(1);
        }
        cols++;
        data = realloc(data, sizeof(int *) * rows);
        for (int i = 0; i < rows; i++) {
            data[i] = realloc(data[i], sizeof(int) * cols);
            data[i][cols - 1] = atoi(tokens[i]);
        }
        for (int i = 0; i < col_count; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }
    return data;
}

// Function to print a 2D array
void print_array(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    int **data = read_csv(fp);
    fclose(fp);
    print_array(data, data[0][0], data[0][data[0][0]-1]);
    for (int i = 0; i < data[0][0]; i++) {
        free(data[0][i]);
    }
    free(data[0]);
    free(data);
    return 0;
}