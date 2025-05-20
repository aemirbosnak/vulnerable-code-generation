//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define INDEX_FILENAME "index.dat"
#define DATA_FILENAME "data.dat"

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int id;
    long offset;
} Index;

Index indexArray[MAX_RECORDS];
int indexCount = 0;

void addRecord() {
    Record record;
    FILE *dataFile = fopen(DATA_FILENAME, "ab");
    if (!dataFile) {
        perror("Unable to open data file");
        return;
    }
    
    printf("Enter record ID: ");
    scanf("%d", &record.id);
    printf("Enter name: ");
    scanf(" %[^\n]s", record.name);
    
    long offset = ftell(dataFile);
    fwrite(&record, sizeof(Record), 1, dataFile);

    Index newIndex;
    newIndex.id = record.id;
    newIndex.offset = offset;
    indexArray[indexCount++] = newIndex;

    fclose(dataFile);
}

void createIndexFile() {
    FILE *indexFile = fopen(INDEX_FILENAME, "wb");
    if (!indexFile) {
        perror("Unable to open index file");
        return;
    }

    fwrite(indexArray, sizeof(Index), indexCount, indexFile);
    fclose(indexFile);
}

void searchRecord() {
    int id;
    printf("Enter record ID to search: ");
    scanf("%d", &id);

    // Linear search through the index
    for (int i = 0; i < indexCount; i++) {
        if (indexArray[i].id == id) {
            // Found the index, now read the record
            FILE *dataFile = fopen(DATA_FILENAME, "rb");
            if (!dataFile) {
                perror("Unable to open data file");
                return;
            }
            Record record;
            fseek(dataFile, indexArray[i].offset, SEEK_SET);
            fread(&record, sizeof(Record), 1, dataFile);
            printf("Record found: ID = %d, Name = %s\n", record.id, record.name);
            fclose(dataFile);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void displayRecords() {
    FILE *dataFile = fopen(DATA_FILENAME, "rb");
    if (!dataFile) {
        perror("Unable to open data file");
        return;
    }

    Record record;
    printf("All Records:\n");
    while (fread(&record, sizeof(Record), 1, dataFile)) {
        printf("ID = %d, Name = %s\n", record.id, record.name);
    }
    fclose(dataFile);
}

void loadIndexFile() {
    FILE *indexFile = fopen(INDEX_FILENAME, "rb");
    if (!indexFile) {
        perror("Unable to open index file");
        return;
    }

    indexCount = fread(indexArray, sizeof(Index), MAX_RECORDS, indexFile);
    fclose(indexFile);
}

int main() {
    int choice;

    // Load existing index at startup
    loadIndexFile();

    do {
        printf("\n*** Simple Database Indexing System ***\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                createIndexFile();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}