//Falcon-180B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA 1000
#define MAX_ATTRIBUTES 10

typedef struct {
    int *data;
    char **attributes;
    int num_attributes;
    int num_data;
} DataSet;

void generateRandomDataSet(DataSet *dataset, int num_data, int num_attributes) {
    int i, j;
    dataset->num_attributes = num_attributes;
    dataset->num_data = num_data;
    dataset->data = (int *) malloc(num_data * sizeof(int));
    dataset->attributes = (char **) malloc(num_attributes * sizeof(char *));
    for (i = 0; i < num_attributes; i++) {
        dataset->attributes[i] = (char *) malloc(MAX_ATTRIBUTES * sizeof(char));
        sprintf(dataset->attributes[i], "Attribute_%d", i);
    }
    srand(time(NULL));
    for (i = 0; i < num_data; i++) {
        dataset->data[i] = rand() % 100;
    }
}

void printDataSet(DataSet *dataset) {
    int i, j;
    for (i = 0; i < dataset->num_data; i++) {
        for (j = 0; j < dataset->num_attributes; j++) {
            printf("%d ", dataset->data[i]);
        }
        printf("\n");
    }
}

void freeDataSet(DataSet *dataset) {
    int i;
    for (i = 0; i < dataset->num_attributes; i++) {
        free(dataset->attributes[i]);
    }
    free(dataset->attributes);
    free(dataset->data);
}

int main() {
    DataSet dataset;
    int num_data, num_attributes;
    printf("Enter the number of data points: ");
    scanf("%d", &num_data);
    printf("Enter the number of attributes: ");
    scanf("%d", &num_attributes);
    generateRandomDataSet(&dataset, num_data, num_attributes);
    printf("Data Set:\n");
    printDataSet(&dataset);
    freeDataSet(&dataset);
    return 0;
}