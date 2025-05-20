//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define INDEX_FILE "index.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char address[100];
} Record;

typedef struct {
    int id;
    long offset; // Offset of the record in the data file
} IndexEntry;

IndexEntry indexTable[MAX_RECORDS];
int indexCount = 0;

// Function declarations
void addRecord(FILE *dataFile);
void createIndex(FILE *dataFile);
void displayRecords(FILE *dataFile);
void displayIndex();

int main() {
    FILE *dataFile = fopen("data.txt", "a+");
    if (dataFile == NULL) {
        perror("Failed to open data file");
        return EXIT_FAILURE;
    }

    int choice;
    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Create Index\n");
        printf("4. Display Index\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                addRecord(dataFile);
                break;
            case 2:
                displayRecords(dataFile);
                break;
            case 3:
                createIndex(dataFile);
                break;
            case 4:
                displayIndex();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    fclose(dataFile);
    return EXIT_SUCCESS;
}

void addRecord(FILE *dataFile) {
    Record newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    getchar(); // consume the newline
    printf("Enter Name: ");
    fgets(newRecord.name, NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // Remove newline character
    printf("Enter Address: ");
    fgets(newRecord.address, sizeof(newRecord.address), stdin);
    newRecord.address[strcspn(newRecord.address, "\n")] = 0; // Remove newline character

    fseek(dataFile, 0, SEEK_END);
    long offset = ftell(dataFile);
    fwrite(&newRecord, sizeof(Record), 1, dataFile);
    printf("Record added successfully!\n");

    // Create an index entry
    indexTable[indexCount].id = newRecord.id;
    indexTable[indexCount].offset = offset;
    indexCount++;
}

void createIndex(FILE *dataFile) {
    // Clear previous index
    indexCount = 0;

    fseek(dataFile, 0, SEEK_SET);
    Record tempRecord;
    long offset;
    int readCount = 0;

    while (fread(&tempRecord, sizeof(Record), 1, dataFile) == 1) {
        offset = ftell(dataFile) - sizeof(Record); // Get the current record's offset
        indexTable[indexCount].id = tempRecord.id;
        indexTable[indexCount].offset = offset;
        indexCount++;
        readCount++;
    }
    
    printf("Index created successfully! %d records indexed.\n", readCount);
}

void displayRecords(FILE *dataFile) {
    fseek(dataFile, 0, SEEK_SET);
    Record tempRecord;
    int recordCount = 0;

    printf("\nRecords in the database:\n");
    while (fread(&tempRecord, sizeof(Record), 1, dataFile) == 1) {
        printf("ID: %d, Name: %s, Address: %s\n", tempRecord.id, tempRecord.name, tempRecord.address);
        recordCount++;
    }

    if (recordCount == 0) {
        printf("No records found.\n");
    }
}

void displayIndex() {
    printf("\nIndex Table:\n");
    for (int i = 0; i < indexCount; i++) {
        printf("ID: %d, Offset: %ld\n", indexTable[i].id, indexTable[i].offset);
    }

    if (indexCount == 0) {
        printf("Index is empty.\n");
    }
}