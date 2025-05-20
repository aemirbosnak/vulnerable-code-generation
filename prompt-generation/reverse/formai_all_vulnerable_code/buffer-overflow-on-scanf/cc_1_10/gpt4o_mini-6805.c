//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define INDEX_TYPE_HASH 1
#define INDEX_TYPE_BINARY 2

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

typedef struct {
    int id;
    int index;
} HashIndex;

typedef struct {
    int id;
    int left;
    int right;
} BinaryIndexNode;

typedef struct {
    BinaryIndexNode nodes[MAX_RECORDS];
    int count;
} BinaryIndex;

Database db;
HashIndex hashIndex[MAX_RECORDS];
BinaryIndex binaryIndex;

void initDatabase() {
    db.count = 0;
    binaryIndex.count = 0;
}

void addRecord(int id, const char* name) {
    if (db.count < MAX_RECORDS) {
        db.records[db.count].id = id;
        strncpy(db.records[db.count].name, name, NAME_LENGTH);
        db.count++;
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

int hashFunction(int id) {
    return id % MAX_RECORDS;
}

void createHashIndex() {
    for (int i = 0; i < db.count; i++) {
        int index = hashFunction(db.records[i].id);
        hashIndex[index] = (HashIndex){.id = db.records[i].id, .index = i};
    }
}

void binaryTreeInsert(int id, int leftIndex, int rightIndex) {
    if (binaryIndex.count < MAX_RECORDS) {
        int pos = binaryIndex.count;
        binaryIndex.nodes[pos] = (BinaryIndexNode){.id = id, .left = leftIndex, .right = rightIndex};
        binaryIndex.count++;
    }
}

int binaryTreeSearch(int id) {
    for (int i = 0; i < binaryIndex.count; i++) {
        if (binaryIndex.nodes[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

void createBinaryIndex() {
    for (int i = 0; i < db.count; i++) {
        int left = (i > 0) ? i - 1 : -1;
        int right = (i < db.count - 1) ? i + 1 : -1;
        binaryTreeInsert(db.records[i].id, left, right);
    }
}

Record* findRecordWithHashIndex(int id) {
    int index = hashFunction(id);
    if (hashIndex[index].id == id) {
        return &db.records[hashIndex[index].index];
    }
    return NULL;
}

Record* findRecordWithBinaryIndex(int id) {
    int index = binaryTreeSearch(id);
    if (index != -1) {
        return &db.records[index];
    }
    return NULL;
}

void displayRecords() {
    printf("Displaying Records:\n");
    for (int i = 0; i < db.count; i++) {
        printf("ID: %d, Name: %s\n", db.records[i].id, db.records[i].name);
    }
}

void menu() {
    int choice;
    while (1) {
        printf("\nDatabase Indexing System Menu:\n");
        printf("1. Add Record\n");
        printf("2. Create Hash Index\n");
        printf("3. Create Binary Index\n");
        printf("4. Find Record by Hash Index\n");
        printf("5. Find Record by Binary Index\n");
        printf("6. Display All Records\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 7) break;

        switch (choice) {
            case 1: {
                int id;
                char name[NAME_LENGTH];
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addRecord(id, name);
                break;
            }
            case 2:
                createHashIndex();
                printf("Hash Index Created.\n");
                break;
            case 3:
                createBinaryIndex();
                printf("Binary Index Created.\n");
                break;
            case 4: {
                int id;
                printf("Enter ID to find: ");
                scanf("%d", &id);
                Record* record = findRecordWithHashIndex(id);
                if (record) {
                    printf("Record found: ID: %d, Name: %s\n", record->id, record->name);
                } else {
                    printf("Record not found.\n");
                }
                break;
            }
            case 5: {
                int id;
                printf("Enter ID to find: ");
                scanf("%d", &id);
                Record* record = findRecordWithBinaryIndex(id);
                if (record) {
                    printf("Record found: ID: %d, Name: %s\n", record->id, record->name);
                } else {
                    printf("Record not found.\n");
                }
                break;
            }
            case 6:
                displayRecords();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    initDatabase();
    menu();
    return 0;
}