//Falcon-180B DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1000
#define MAX_NUM_DATA 100
#define MAX_NUM_ATTRIBUTES 20

typedef struct {
    char name[50];
    int age;
    double income;
} Data;

typedef struct {
    char name[50];
    int numData;
    Data *data;
} DataSet;

void readData(DataSet *dataSet) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error reading data file.\n");
        exit(1);
    }

    char line[100];
    while (fscanf(file, "%s", line)!= EOF) {
        if (dataSet->numData >= MAX_NUM_DATA) {
            printf("Maximum number of data exceeded.\n");
            exit(1);
        }

        Data *data = (Data *)malloc(sizeof(Data));
        strcpy(data->name, line);
        dataSet->data = (Data *)realloc(dataSet->data, sizeof(Data) * (dataSet->numData + 1));
        dataSet->data[dataSet->numData] = *data;
        dataSet->numData++;
    }

    fclose(file);
}

void printData(DataSet *dataSet) {
    printf("Name\tAge\tIncome\n");
    for (int i = 0; i < dataSet->numData; i++) {
        printf("%s\t%d\t%.2f\n", dataSet->data[i].name, dataSet->data[i].age, dataSet->data[i].income);
    }
}

int main() {
    DataSet dataSet;
    dataSet.numData = 0;
    dataSet.data = NULL;

    readData(&dataSet);
    printData(&dataSet);

    return 0;
}