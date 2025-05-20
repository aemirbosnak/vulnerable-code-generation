//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char name[MAX_STRING_LENGTH];
    int age;
    float height;
    float weight;
} Person;

void loadData(const char *filename, Person records[], int *count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (*count < MAX_RECORDS && fscanf(file, "%[^,],%d,%f,%f\n", 
                     records[*count].name, &records[*count].age, 
                     &records[*count].height, &records[*count].weight) == 4) {
        (*count)++;
    }
    
    fclose(file);
}

void displayRecords(const Person records[], int count) {
    printf("Name\t\tAge\tHeight\tWeight\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-15s%-8d%-8.2f%-8.2f\n", records[i].name, records[i].age, records[i].height, records[i].weight);
    }
}

float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

void findHealthiestPerson(const Person records[], int count) {
    float maxBMI = 0.0;
    int healthiestIndex = -1;
    
    for (int i = 0; i < count; i++) {
        float bmi = calculateBMI(records[i].weight, records[i].height);
        if (bmi > maxBMI) {
            maxBMI = bmi;
            healthiestIndex = i;
        }
    }
    
    if (healthiestIndex != -1) {
        printf("\nHealthiest Person: %s with BMI: %.2f\n", records[healthiestIndex].name, calculateBMI(records[healthiestIndex].weight, records[healthiestIndex].height));
    }
}

void sortRecordsByName(Person records[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(records[j].name, records[j + 1].name) > 0) {
                Person temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

void saveSortedData(const char *filename, const Person records[], int count) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Could not open file for writing");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%.2f,%.2f\n", records[i].name, records[i].age, records[i].height, records[i].weight);
    }

    fclose(file);
}

int main() {
    Person records[MAX_RECORDS];
    int count = 0;

    loadData("data.txt", records, &count);
    displayRecords(records, count);
    findHealthiestPerson(records, count);
    
    printf("\nSorting records by name...\n");
    sortRecordsByName(records, count);
    displayRecords(records, count);
    
    saveSortedData("sorted_data.txt", records, count);
    printf("\nSorted data has been saved to sorted_data.txt\n");

    return 0;
}