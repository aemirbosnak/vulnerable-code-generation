//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLUMNS 100
#define DELIMITER ','

typedef struct {
    char **data;
    int rows;
    int columns;
} CSVData;

CSVData *readCSVFile(FILE *file) {
    CSVData *csvData = NULL;
    char line[MAX_LINE_SIZE];
    char *token = NULL;
    int rows = 0;
    int columns = 0;

    csvData = (CSVData *) malloc(sizeof(CSVData));
    csvData->data = (char **) malloc(MAX_COLUMNS * sizeof(char *));
    csvData->rows = 0;
    csvData->columns = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        rows++;
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            columns++;
            csvData->data[columns - 1] = malloc((strlen(token) + 1) * sizeof(char));
            strcpy(csvData->data[columns - 1], token);
            token = strtok(NULL, DELIMITER);
        }
        csvData->columns = columns;
    }

    csvData->rows = rows;
    return csvData;
}

void printCSVData(CSVData *csvData) {
    int i, j;

    for (i = 0; i < csvData->rows; i++) {
        for (j = 0; j < csvData->columns; j++) {
            printf("%s\t", csvData->data[j]);
        }
        printf("\n");
    }
}

void freeCSVData(CSVData *csvData) {
    int i;

    for (i = 0; i < csvData->columns; i++) {
        free(csvData->data[i]);
    }
    free(csvData->data);
    free(csvData);
}

int main() {
    FILE *file;
    CSVData *csvData;

    file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    csvData = readCSVFile(file);
    printCSVData(csvData);

    freeCSVData(csvData);
    fclose(file);

    return 0;
}