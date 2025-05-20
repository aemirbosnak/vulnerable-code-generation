//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int search(char **data, int rows, int cols, char *target) {
    int i = 0;
    int j = 0;
    while (i < rows && j < cols) {
        if (strcmp(data[i][j], target) == 0) {
            return 1;
        }
        if (strcmp(data[i][j], target) > 0) {
            j++;
        } else {
            i++;
        }
    }
    return 0;
}

void print_data(char **data, int rows, int cols) {
    int i = 0;
    int j = 0;
    while (i < rows && j < cols) {
        printf("%s ", data[i][j]);
        j++;
        if (j == cols) {
            printf("\n");
            j = 0;
            i++;
        }
    }
}

int main() {
    char **data;
    int rows, cols;
    char target[MAX_ROWS][MAX_COLS];

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        data[i] = (char *)malloc(cols * sizeof(char));
    }

    printf("Enter data:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%c", &data[i][j]);
        }
    }

    printf("Enter target:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%c", &target[i][j]);
        }
    }

    int found = search(data, rows, cols, target);

    if (found) {
        printf("Target found!\n");
    } else {
        printf("Target not found.\n");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", data[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", target[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}