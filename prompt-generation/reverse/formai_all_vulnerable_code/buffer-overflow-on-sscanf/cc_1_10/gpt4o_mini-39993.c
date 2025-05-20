//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_RECORDS 100
#define MAX_FIELD_LENGTH 256

typedef struct {
    char name[MAX_FIELD_LENGTH];
    int age;
    char city[MAX_FIELD_LENGTH];
    float salary;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} DataSet;

void initDataSet(DataSet *dataSet) {
    dataSet->count = 0;
}

int readCSV(const char *filename, DataSet *dataSet) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) && dataSet->count < MAX_RECORDS) {
        Record record;
        sscanf(line, "%[^,],%d,%[^,],%f", record.name, &record.age, record.city, &record.salary);
        dataSet->records[dataSet->count++] = record;
    }

    fclose(file);
    return 0;
}

void displayDataSet(const DataSet *dataSet) {
    printf("Name\tAge\tCity\tSalary\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < dataSet->count; i++) {
        printf("%s\t%d\t%s\t%.2f\n", dataSet->records[i].name,
               dataSet->records[i].age,
               dataSet->records[i].city,
               dataSet->records[i].salary);
    }
}

void filterByCity(const DataSet *dataSet, const char *city) {
    printf("Filtered records for city: %s\n", city);
    printf("Name\tAge\tCity\tSalary\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < dataSet->count; i++) {
        if (strcmp(dataSet->records[i].city, city) == 0) {
            printf("%s\t%d\t%s\t%.2f\n", dataSet->records[i].name,
                   dataSet->records[i].age,
                   dataSet->records[i].city,
                   dataSet->records[i].salary);
        }
    }
}

void calculateAverageSalary(const DataSet *dataSet) {
    float totalSalary = 0.0;
    for (int i = 0; i < dataSet->count; i++) {
        totalSalary += dataSet->records[i].salary;
    }
    float averageSalary = (dataSet->count > 0) ? totalSalary / dataSet->count : 0;
    printf("Average Salary: %.2f\n", averageSalary);
}

int compareRecords(const void *a, const void *b) {
    return ((Record *)a)->salary > ((Record *)b)->salary ? -1 : 1; // Descending order
}

void sortRecordsBySalary(DataSet *dataSet) {
    qsort(dataSet->records, dataSet->count, sizeof(Record), compareRecords);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DataSet dataSet;
    initDataSet(&dataSet);
    
    if (readCSV(argv[1], &dataSet) != 0) {
        return EXIT_FAILURE;
    }

    displayDataSet(&dataSet);
    
    char cityFilter[MAX_FIELD_LENGTH];
    printf("Enter city to filter records: ");
    scanf("%s", cityFilter);
    filterByCity(&dataSet, cityFilter);
    
    calculateAverageSalary(&dataSet);
    
    sortRecordsBySalary(&dataSet);
    printf("Records sorted by salary:\n");
    displayDataSet(&dataSet);

    return EXIT_SUCCESS;
}