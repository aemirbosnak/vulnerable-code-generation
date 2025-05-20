//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char filename[BUFFER_SIZE];
    printf("Enter name of CSV file to read: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file %s.\n", filename);
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int rows = 0, cols = -1;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        rows++;

        char *token = strtok(buffer, ",");
        int count = 0;
        while (token) {
            count++;
            token = strtok(NULL, ",");
        }

        if (cols == -1) {
            cols = count;
        } else if (cols != count) {
            printf("Error: Row %d has %d columns instead of %d.\n", rows, count, cols);
            exit(1);
        }
    }

    rewind(file);

    char ***data = malloc(rows * sizeof(char **));
    for (int i = 0; i < rows; i++) {
        data[i] = malloc(cols * sizeof(char *));
        for (int j = 0; j < cols; j++) {
            data[i][j] = malloc(BUFFER_SIZE * sizeof(char));
        }
    }

    int row = 0, col = 0;
    while (fgets(buffer, BUFFER_SIZE, file)) {
        col = 0;

        char *token = strtok(buffer, ",");
        while (token) {
            strcpy(data[row][col], token);
            col++;
            token = strtok(NULL, ",");
        }

        row++;
    }

    printf("Successfully read %d rows and %d columns from file %s.\n", rows, cols, filename);
    printf("Data:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);

    fclose(file);

    return 0;
}