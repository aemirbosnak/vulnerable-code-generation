//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    int id;
    char name[MAX_STRING_LENGTH];
    float value;
} DataRecord;

void readDataFromFile(const char *filename, DataRecord records[], int *recordCount) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *recordCount = 0;
    while (*recordCount < MAX_RECORDS && fscanf(file, "%d %s %f", &records[*recordCount].id, records[*recordCount].name, &records[*recordCount].value) == 3) {
        (*recordCount)++;
    }

    fclose(file);
}

void calculateStatistics(DataRecord records[], int recordCount, float *mean, float *stddev) {
    float sum = 0.0, sum_squares = 0.0;

    for (int i = 0; i < recordCount; i++) {
        sum += records[i].value;
        sum_squares += records[i].value * records[i].value;
    }

    *mean = sum / recordCount;
    *stddev = sqrt((sum_squares / recordCount) - (*mean * *mean));
}

void filterRecords(DataRecord records[], int recordCount, float threshold, DataRecord filteredRecords[], int *filteredCount) {
    *filteredCount = 0;
    for (int i = 0; i < recordCount; i++) {
        if (records[i].value > threshold) {
            filteredRecords[*filteredCount] = records[i];
            (*filteredCount)++;
        }
    }
}

void writeFilteredDataToFile(const char *filename, DataRecord filteredRecords[], int filteredCount) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < filteredCount; i++) {
        fprintf(file, "%d %s %.2f\n", filteredRecords[i].id, filteredRecords[i].name, filteredRecords[i].value);
    }

    fclose(file);
}

void printRecords(DataRecord records[], int recordCount) {
    printf("ID\tName\tValue\n");
    printf("-------------------------\n");
    for (int i = 0; i < recordCount; i++) {
        printf("%d\t%s\t%.2f\n", records[i].id, records[i].name, records[i].value);
    }
}

int main() {
    DataRecord records[MAX_RECORDS];
    DataRecord filteredRecords[MAX_RECORDS];
    int recordCount = 0;
    int filteredCount = 0;
    float mean, stddev;

    readDataFromFile("data.txt", records, &recordCount);
    calculateStatistics(records, recordCount, &mean, &stddev);

    printf("Statistics:\n");
    printf("Mean: %.2f\n", mean);
    printf("Standard Deviation: %.2f\n", stddev);

    float threshold = mean + stddev;  // Filter threshold as mean + stddev
    filterRecords(records, recordCount, threshold, filteredRecords, &filteredCount);

    printf("\nFiltered Records (Value > %.2f):\n", threshold);
    printRecords(filteredRecords, filteredCount);

    writeFilteredDataToFile("filtered_data.txt", filteredRecords, filteredCount);

    return 0;
}