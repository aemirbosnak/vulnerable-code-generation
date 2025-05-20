//FormAI DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define INDEX_FILE "index.dat"
#define DATA_FILE "data.dat"

typedef struct {
    int id;
    char name[20];
    char address[50];
} Record;

typedef struct {
    int id;
    int offset;
} IndexRecord;

void addRecord(int *numRecords, Record records[], IndexRecord index[]) {
    // Get user input for new record
    Record newRecord;
    printf("Enter ID, name, and address separated by spaces:\n");
    scanf("%d %s %[^\n]", &newRecord.id, newRecord.name, newRecord.address);

    // Add new record to end of data file
    FILE *dataFile = fopen(DATA_FILE, "ab");
    fwrite(&newRecord, sizeof(Record), 1, dataFile);
    fclose(dataFile);

    // Update index with new record
    int indexPos = *numRecords;
    index[indexPos].id = newRecord.id;
    index[indexPos].offset = ftell(dataFile) - sizeof(Record);

    // Update number of records and save new index to file
    (*numRecords)++;
    FILE *indexFile = fopen(INDEX_FILE, "wb");
    fwrite(index, sizeof(IndexRecord), *numRecords, indexFile);
    fclose(indexFile);
}

void searchRecord(int numRecords, IndexRecord index[]) {
    // Get user input for ID to search for
    int id;
    printf("Enter ID to search for:\n");
    scanf("%d", &id);

    // Use binary search to find index position of matching ID
    int left = 0, right = numRecords - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (index[mid].id == id) {
            break; // found matching ID
        } else if (index[mid].id < id) {
            left = mid + 1; // search right half
        } else {
            right = mid - 1; // search left half
        }
    }
    if (left > right) {
        printf("Record not found.\n");
        return;
    }

    // Read record at found offset in data file
    Record record;
    FILE *dataFile = fopen(DATA_FILE, "rb");
    fseek(dataFile, index[mid].offset, SEEK_SET);
    fread(&record, sizeof(Record), 1, dataFile);
    fclose(dataFile);

    // Print record information
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Address: %s\n", record.address);
}

int main() {
    int numRecords = 0;
    Record records[MAX_RECORDS];
    IndexRecord index[MAX_RECORDS];

    // Read index from file and calculate number of records
    FILE *indexFile = fopen(INDEX_FILE, "rb");
    if (indexFile != NULL) {
        fread(index, sizeof(IndexRecord), MAX_RECORDS, indexFile);
        fclose(indexFile);
        for (int i = 0; i < MAX_RECORDS; i++) {
            if (index[i].id == 0) {
                numRecords = i;
                break;
            }
        }
    }

    // Display menu and process user input
    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        printf("Enter choice (1-3):\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                addRecord(&numRecords, records, index);
                printf("Record added.\n");
                break;
            case '2':
                searchRecord(numRecords, index);
                break;
            case '3':
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != '3');

    // Save index to file before exiting
    indexFile = fopen(INDEX_FILE, "wb");
    fwrite(index, sizeof(IndexRecord), numRecords, indexFile);
    fclose(indexFile);

    return 0;
}