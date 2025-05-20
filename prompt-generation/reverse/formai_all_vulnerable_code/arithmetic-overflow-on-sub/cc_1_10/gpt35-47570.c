//FormAI DATASET v1.0 Category: Database simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

void saveRecordsToFile(Record records[], int numRecords, char* filename);

void loadRecordsFromFile(Record records[], int* numRecords, char* filename);

void addRecord(Record records[], int* numRecords);

void deleteRecord(Record records[], int* numRecords, int id);

void updateRecord(Record records[], int* numRecords, int id);

void printRecord(Record record);

void printAllRecords(Record records[], int numRecords);

int main() {
    Record records[MAX_RECORDS];
    int numRecords = 0;
    int option = 0;
    char filename[] = "records.dat";
    loadRecordsFromFile(records, &numRecords, filename);

    do {
        printf("DATABASE SIMULATION PROGRAM\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Update Record\n");
        printf("4. Print a Record\n");
        printf("5. Print All Records\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addRecord(records, &numRecords);
                saveRecordsToFile(records, numRecords, filename);
                break;
            case 2:
                {
                    int id;
                    printf("Enter the ID of the record you want to delete: ");
                    scanf("%d", &id);
                    deleteRecord(records, &numRecords, id);
                    saveRecordsToFile(records, numRecords, filename);
                }
                break;
            case 3:
                {
                    int id;
                    printf("Enter the ID of the record you want to update: ");
                    scanf("%d", &id);
                    updateRecord(records, &numRecords, id);
                    saveRecordsToFile(records, numRecords, filename);
                }
                break;
            case 4:
                {
                    int id;
                    printf("Enter the ID of the record you want to print: ");
                    scanf("%d", &id);
                    Record record = records[id];
                    printRecord(record);
                }
                break;
            case 5:
                printAllRecords(records, numRecords);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n");
    } while (option != 6);

    return 0;
}

void saveRecordsToFile(Record records[], int numRecords, char* filename) {
    FILE* file = fopen(filename, "wb");
    fwrite(records, sizeof(Record), numRecords, file);
    fclose(file);
}

void loadRecordsFromFile(Record records[], int* numRecords, char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file != NULL) {
        fread(records, sizeof(Record), MAX_RECORDS, file);
        *numRecords = MAX_RECORDS; // in this program, we always assume the file has MAX_RECORDS number of records
        fclose(file);
    }
}

void addRecord(Record records[], int* numRecords) {
    if (*numRecords < MAX_RECORDS) {
        Record record;
        record.id = *numRecords;
        printf("Enter name: ");
        scanf("%s", record.name);
        printf("Enter age: ");
        scanf("%d", &record.age);
        records[*numRecords] = record;
        (*numRecords)++;
        printf("Record added successfully.\n");
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void deleteRecord(Record records[], int* numRecords, int id) {
    if (id < *numRecords) {
        for (int i = id; i < (*numRecords - 1); i++) {
            records[i] = records[i + 1];
            records[i].id--; // update the ID of the records after the deleted record
        }
        (*numRecords)--;
        printf("Record deleted successfully.\n");
    } else {
        printf("Invalid record ID.\n");
    }
}

void updateRecord(Record records[], int* numRecords, int id) {
    if (id < *numRecords) {
        Record* record = &records[id];
        printf("Enter name: ");
        scanf("%s", record->name);
        printf("Enter age: ");
        scanf("%d", &record->age);
        printf("Record updated successfully.\n");
    } else {
        printf("Invalid record ID.\n");
    }
}

void printRecord(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
}

void printAllRecords(Record records[], int numRecords) {
    printf("%-5s%-20s%-10s\n", "ID", "NAME", "AGE");
    printf("----------------------------\n");
    for (int i = 0; i < numRecords; i++) {
        Record record = records[i];
        printf("%-5d%-20s%-10d\n", record.id, record.name, record.age);
    }
    printf("----------------------------\n");
}