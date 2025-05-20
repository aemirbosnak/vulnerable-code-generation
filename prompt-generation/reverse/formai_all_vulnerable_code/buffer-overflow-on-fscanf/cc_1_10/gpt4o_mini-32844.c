//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    float value;
} DataPoint;

void readData(DataPoint data[], int *count) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("Error opening data file");
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(file, "%s %f", data[*count].name, &data[*count].value) != EOF) {
        (*count)++;
    }

    fclose(file);
}

void printData(DataPoint data[], int count) {
    printf("\nData Loaded:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Value: %.2f\n", data[i].name, data[i].value);
    }
}

float calculateMean(DataPoint data[], int count) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += data[i].value;
    }
    return sum / count;
}

float calculateStandardDeviation(DataPoint data[], int count, float mean) {
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += pow(data[i].value - mean, 2);
    }
    return sqrt(sum / count);
}

void analyzeData(DataPoint data[], int count) {
    float mean = calculateMean(data, count);
    float stddev = calculateStandardDeviation(data, count, mean);

    printf("\nData Analysis:\n");
    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stddev);
}

void findMinMax(DataPoint data[], int count, DataPoint *min, DataPoint *max) {
    *min = data[0];
    *max = data[0];

    for (int i = 1; i < count; i++) {
        if (data[i].value < min->value) {
            *min = data[i];
        }
        if (data[i].value > max->value) {
            *max = data[i];
        }
    }
}

void printMinMax(DataPoint min, DataPoint max) {
    printf("\nMin Value: %s (%.2f)\n", min.name, min.value);
    printf("Max Value: %s (%.2f)\n", max.name, max.value);
}

void sortData(DataPoint data[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (data[j].value > data[j + 1].value) {
                DataPoint temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void printSortedData(DataPoint data[], int count) {
    printf("\nSorted Data:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Value: %.2f\n", data[i].name, data[i].value);
    }
}

int main() {
    DataPoint data[MAX_LINES];
    int count = 0;

    printf("Welcome to the Exciting Data Mining Program!\n");
    readData(data, &count);
    printData(data, count);
    analyzeData(data, count);

    DataPoint min, max;
    findMinMax(data, count, &min, &max);
    printMinMax(min, max);

    sortData(data, count);
    printSortedData(data, count);

    printf("\nYay! Data mining operations are complete!\n");
    return 0;
}