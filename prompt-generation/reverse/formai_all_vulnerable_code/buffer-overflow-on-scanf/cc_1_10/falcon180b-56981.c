//Falcon-180B DATASET v1.0 Category: Data mining ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_WORDS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} DataSet;

DataSet load_data(char *filename) {
    FILE *fp;
    char line[1024];
    char delim = ',';
    DataSet dataset = {NULL, 0, 0};
    int i = 0, j = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, &delim);
        while (token!= NULL) {
            if (i == MAX_ROWS) {
                printf("Error: Maximum number of rows exceeded\n");
                exit(1);
            }
            if (j == MAX_COLS) {
                printf("Error: Maximum number of columns exceeded\n");
                exit(1);
            }
            dataset.data[i][j] = token;
            j++;
            token = strtok(NULL, &delim);
        }
        i++;
        j = 0;
    }

    dataset.rows = i;
    dataset.cols = j;

    return dataset;
}

void print_data(DataSet dataset) {
    int i, j;

    for (i = 0; i < dataset.rows; i++) {
        for (j = 0; j < dataset.cols; j++) {
            printf("%s ", dataset.data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    DataSet dataset;
    char filename[100];
    int choice;

    srand(time(NULL));
    printf("Enter the name of the dataset file: ");
    scanf("%s", filename);

    dataset = load_data(filename);

    do {
        printf("\n");
        printf("1. Print dataset\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_data(dataset);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}