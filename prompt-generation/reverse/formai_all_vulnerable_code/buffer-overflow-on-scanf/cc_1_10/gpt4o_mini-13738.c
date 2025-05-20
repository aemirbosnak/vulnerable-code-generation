//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define INDEX_FILE "index.dat"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    int id;
    long offset; // Offset in the data file
} Index;

Record records[MAX_RECORDS];
Index indexArray[MAX_RECORDS];
int recordCount = 0;

void addRecord(int id, const char *name) {
    if (recordCount >= MAX_RECORDS) {
        printf("Maximum record limit reached.\n");
        return;
    }
    records[recordCount].id = id;
    strncpy(records[recordCount].name, name, MAX_NAME_LENGTH);
    recordCount++;
}

void saveData() {
    FILE *dataFile = fopen("data.dat", "wb");
    if (!dataFile) {
        perror("Error opening data file");
        return;
    }
    for (int i = 0; i < recordCount; i++) {
        fwrite(&records[i], sizeof(Record), 1, dataFile);
    }
    fclose(dataFile);
}

void createIndex() {
    FILE *dataFile = fopen("data.dat", "rb");
    if (!dataFile) {
        perror("Error opening data file");
        return;
    }

    FILE *indexFile = fopen(INDEX_FILE, "wb");
    if (!indexFile) {
        perror("Error opening index file");
        fclose(dataFile);
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        indexArray[i].id = records[i].id;
        indexArray[i].offset = ftell(dataFile);
        fwrite(&records[i], sizeof(Record), 1, dataFile);
    }

    for (int i = 0; i < recordCount; i++) {
        fwrite(&indexArray[i], sizeof(Index), 1, indexFile);
    }

    fclose(dataFile);
    fclose(indexFile);
}

Index* loadIndex(int *indexCount) {
    FILE *indexFile = fopen(INDEX_FILE, "rb");
    if (!indexFile) {
        perror("Error opening index file");
        return NULL;
    }

    fread(indexCount, sizeof(int), 1, indexFile);
    Index *indexArray = malloc((*indexCount) * sizeof(Index));
    fread(indexArray, sizeof(Index), *indexCount, indexFile);
    fclose(indexFile);
    
    return indexArray;
}

Record* findRecordById(int id) {
    for (int i = 0; i < recordCount; i++) {
        if (records[i].id == id) {
            return &records[i];
        }
    }
    return NULL;
}

void searchRecordById(int id) {
    Record *record = findRecordById(id);
    if (record) {
        printf("Record found: ID=%d, Name=%s\n", record->id, record->name);
    } else {
        printf("Record with ID=%d not found.\n", id);
    }
}

void freeResources(Index *indexArray) {
    free(indexArray);
}

int main() {
    int choice, id;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Save Data\n");
        printf("3. Create Index\n");
        printf("4. Search Record by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter record ID: ");
                scanf("%d", &id);
                printf("Enter record name: ");
                scanf("%s", name);
                addRecord(id, name);
                break;
            case 2:
                saveData();
                break;
            case 3:
                createIndex();
                break;
            case 4:
                printf("Enter record ID to search: ");
                scanf("%d", &id);
                searchRecordById(id);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}