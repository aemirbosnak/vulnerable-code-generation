//Falcon-180B DATASET v1.0 Category: Data mining ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VALUES 1000
#define MAX_ATTRIBUTES 10

typedef struct {
    char name[20];
    int value;
} Record;

void loadData(Record data[], int numRecords) {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error loading data\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%s %d\n", data[i].name, &data[i].value)!= EOF) {
        i++;
    }

    fclose(fp);
}

void printData(Record data[], int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        printf("%s %d\n", data[i].name, data[i].value);
    }
}

int main() {
    Record data[MAX_VALUES];
    int numRecords;

    loadData(data, MAX_VALUES);
    numRecords = MAX_VALUES;

    int numAttributes = 0;
    while (numAttributes < MAX_ATTRIBUTES && numRecords > 1) {
        int maxCorrelation = 0;
        int maxAttribute = -1;

        for (int i = 0; i < numRecords - 1; i++) {
            for (int j = i + 1; j < numRecords; j++) {
                double correlation = 0;
                int k = 0;

                while (data[i].name[k]!= '\0' && data[j].name[k]!= '\0' && data[i].name[k] == data[j].name[k]) {
                    correlation += data[i].value * data[j].value;
                    k++;
                }

                if (correlation > maxCorrelation) {
                    maxCorrelation = correlation;
                    maxAttribute = k;
                }
            }
        }

        if (maxCorrelation > 0) {
            char attribute[20];
            strncpy(attribute, data[0].name, maxAttribute);
            attribute[maxAttribute] = '\0';

            printf("Attribute: %s\n", attribute);
            printf("Correlation: %f\n", maxCorrelation);

            numAttributes++;
            numRecords--;

            for (int l = 0; l < numRecords; l++) {
                if (strcmp(data[l].name, attribute) == 0) {
                    data[l].value = 0;
                }
            }
        } else {
            break;
        }
    }

    printData(data, numRecords);

    return 0;
}