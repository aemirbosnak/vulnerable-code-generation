//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_COLUMNS 5
#define MAX_LENGTH 50

typedef struct {
    char name[MAX_LENGTH];
    float value[MAX_COLUMNS];
} Record;

void read_data(Record data[], char filename[]) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_RECORDS; i++) {
        fgets(data[i].name, MAX_LENGTH, fp);
        data[i].name[strcspn(data[i].name, "\n")] = '\0';

        for (j = 0; j < MAX_COLUMNS; j++) {
            fscanf(fp, "%f", &data[i].value[j]);
        }
    }

    fclose(fp);
}

void average(Record data[]) {
    int i, j;
    float sum[MAX_COLUMNS] = {0};

    for (i = 0; i < MAX_RECORDS; i++) {
        for (j = 0; j < MAX_COLUMNS; j++) {
            sum[j] += data[i].value[j];
        }
    }

    printf("\nAverage values:\n");
    for (j = 0; j < MAX_COLUMNS; j++) {
        printf("Column %d: %.2f\n", j, sum[j] / MAX_RECORDS);
    }
}

int main() {
    Record data[MAX_RECORDS];
    char filename[] = "data.csv";

    read_data(data, filename);
    average(data);

    return 0;
}