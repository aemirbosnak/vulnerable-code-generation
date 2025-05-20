//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define INDEX_FILE "index.txt"
#define DATA_FILE "data.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int id;
    long offset;
} IndexEntry;

IndexEntry indexTable[MAX_RECORDS];
int indexCount = 0;

void addRecord(int id, const char* name) {
    FILE* dataFile = fopen(DATA_FILE, "a");
    if (!dataFile) {
        perror("Unable to open data file");
        exit(EXIT_FAILURE);
    }

    Record record = {id, ""};
    strncpy(record.name, name, NAME_LENGTH);
    long offset = ftell(dataFile);
    
    fwrite(&record, sizeof(Record), 1, dataFile);
    fclose(dataFile);

    // Update index
    indexTable[indexCount].id = id;
    indexTable[indexCount].offset = offset;
    indexCount++;
}

void createIndexFile() {
    FILE* indexFile = fopen(INDEX_FILE, "w");
    if (!indexFile) {
        perror("Unable to open index file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < indexCount; i++) {
        fprintf(indexFile, "%d %ld\n", indexTable[i].id, indexTable[i].offset);
    }

    fclose(indexFile);
}

void loadIndex() {
    FILE* indexFile = fopen(INDEX_FILE, "r");
    if (!indexFile) {
        perror("Index file does not exist, creating a new one");
        return;
    }

    while (fscanf(indexFile, "%d %ld", &indexTable[indexCount].id, &indexTable[indexCount].offset) == 2) {
        indexCount++;
    }

    fclose(indexFile);
}

Record* getRecordById(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i].id == id) {
            FILE* dataFile = fopen(DATA_FILE, "r");
            if (!dataFile) {
                perror("Unable to open data file");
                exit(EXIT_FAILURE);
            }

            fseek(dataFile, indexTable[i].offset, SEEK_SET);
            static Record record;
            fread(&record, sizeof(Record), 1, dataFile);
            fclose(dataFile);
            return &record;
        }
    }
    return NULL;
}

void displayRecord(const Record* record) {
    if (record) {
        printf("Record ID: %d, Name: %s\n", record->id, record->name);
    } else {
        printf("Record not found.\n");
    }
}

void displayAllRecords() {
    FILE* dataFile = fopen(DATA_FILE, "r");
    if (!dataFile) {
        perror("Unable to open data file");
        exit(EXIT_FAILURE);
    }

    Record record;
    while (fread(&record, sizeof(Record), 1, dataFile)) {
        printf("Record ID: %d, Name: %s\n", record.id, record.name);
    }

    fclose(dataFile);
}

int main() {
    loadIndex();
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Get Record by ID\n");
        printf("3. Display All Records\n");
        printf("4. Create Index File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addRecord(id, name);
                printf("Record added successfully!\n");
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                displayRecord(getRecordById(id));
                break;
            case 3:
                displayAllRecords();
                break;
            case 4:
                createIndexFile();
                printf("Index file created successfully!\n");
                break;
            case 5:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}