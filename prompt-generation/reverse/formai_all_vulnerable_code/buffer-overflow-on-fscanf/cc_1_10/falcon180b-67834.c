//Falcon-180B DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_AGE 120

// Define the structure of a record
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} Record;

// Function to read records from a file into an array
void readRecords(Record* records, FILE* fp) {
    int i = 0;
    while (fscanf(fp, "%s %d", records[i].name, &records[i].age)!= EOF) {
        i++;
    }
}

// Function to write records to a file from an array
void writeRecords(Record* records, FILE* fp) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].age!= 0) {
            fprintf(fp, "%s %d\n", records[i].name, records[i].age);
        }
    }
}

// Function to sort records by age in ascending order
void sortRecords(Record* records) {
    int i, j;
    for (i = 0; i < MAX_RECORDS - 1; i++) {
        for (j = i + 1; j < MAX_RECORDS; j++) {
            if (records[i].age > records[j].age) {
                Record temp = records[i];
                records[i] = records[j];
                records[j] = temp;
            }
        }
    }
}

// Function to filter records by age range
void filterRecords(Record* records, int minAge, int maxAge) {
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].age >= minAge && records[i].age <= maxAge) {
            records[i].age = 0;
        }
    }
}

// Main function to demonstrate querying capabilities
int main() {
    Record records[MAX_RECORDS];
    FILE* fp;

    // Read records from a file
    fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    readRecords(records, fp);
    fclose(fp);

    // Sort records by age in ascending order
    sortRecords(records);

    // Filter records by age range (20-30)
    filterRecords(records, 20, 30);

    // Write filtered and sorted records to a new file
    fp = fopen("filtered_records.txt", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    writeRecords(records, fp);
    fclose(fp);

    return 0;
}