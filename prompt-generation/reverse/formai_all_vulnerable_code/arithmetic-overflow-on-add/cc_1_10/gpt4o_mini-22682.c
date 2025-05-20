//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define STRING_SIZE 50

typedef struct {
    int id;
    char name[STRING_SIZE];
    float score;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Dataset;

void addRecord(Dataset *dataset, int id, const char *name, float score) {
    if (dataset->count >= MAX_RECORDS) {
        printf("Dataset is full. Cannot add more records.\n");
        return;
    }
    
    dataset->records[dataset->count].id = id;
    strncpy(dataset->records[dataset->count].name, name, STRING_SIZE);
    dataset->records[dataset->count].score = score;
    dataset->count++;
}

void displayRecords(const Dataset *dataset) {
    printf("ID\tName\t\tScore\n");
    printf("---------------------------\n");
    for (int i = 0; i < dataset->count; i++) {
        printf("%d\t%s\t\t%.2f\n", dataset->records[i].id, dataset->records[i].name, dataset->records[i].score);
    }
}

float calculateAverageScore(const Dataset *dataset) {
    float totalScore = 0.0;
    for (int i = 0; i < dataset->count; i++) {
        totalScore += dataset->records[i].score;
    }
    return (dataset->count > 0) ? totalScore / dataset->count : 0.0;
}

Record* getRecordById(const Dataset *dataset, int id) {
    for (int i = 0; i < dataset->count; i++) {
        if (dataset->records[i].id == id) {
            return &dataset->records[i];
        }
    }
    return NULL;
}

void sortRecordsByScore(Dataset *dataset) {
    for (int i = 0; i < dataset->count - 1; i++) {
        for (int j = 0; j < dataset->count - i - 1; j++) {
            if (dataset->records[j].score < dataset->records[j + 1].score) {
                Record temp = dataset->records[j];
                dataset->records[j] = dataset->records[j + 1];
                dataset->records[j + 1] = temp;
            }
        }
    }
}

void saveDatasetToFile(const Dataset *dataset, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < dataset->count; i++) {
        fprintf(file, "%d,%s,%.2f\n", dataset->records[i].id, dataset->records[i].name, dataset->records[i].score);
    }
    fclose(file);
}

void loadDatasetFromFile(Dataset *dataset, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%f", &dataset->records[dataset->count].id, dataset->records[dataset->count].name, &dataset->records[dataset->count].score) == 3) {
        dataset->count++;
        if (dataset->count >= MAX_RECORDS) {
            break;
        }
    }
    fclose(file);
}

int main() {
    Dataset dataset = {{0}, 0};
    
    // Adding records to the dataset
    addRecord(&dataset, 1, "Alice", 89.5);
    addRecord(&dataset, 2, "Bob", 76.3);
    addRecord(&dataset, 3, "Charlie", 91.2);
    addRecord(&dataset, 4, "David", 84.0);
    addRecord(&dataset, 5, "Eve", 73.5);

    // Displaying records
    printf("Initial Dataset:\n");
    displayRecords(&dataset);

    // Calculating average score
    float average = calculateAverageScore(&dataset);
    printf("Average Score: %.2f\n", average);

    // Sorting records
    sortRecordsByScore(&dataset);
    printf("\nDataset Sorted by Score:\n");
    displayRecords(&dataset);

    // Saving dataset to file
    saveDatasetToFile(&dataset, "dataset.csv");
    
    // Load dataset from file
    Dataset loadedDataset = {{0}, 0};
    loadDatasetFromFile(&loadedDataset, "dataset.csv");
    printf("\nLoaded Dataset from File:\n");
    displayRecords(&loadedDataset);
    
    return 0;
}