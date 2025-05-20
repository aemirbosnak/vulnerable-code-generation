//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define TABLE_SIZE 20

typedef struct Record {
    int key;
    char value[100];
} Record;

typedef struct Node {
    Record record;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];
Record records[MAX_RECORDS];
int recordCount = 0;

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

void insertIndex(Record record) {
    unsigned int index = hash(record.key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->record = record;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

Record* searchIndex(int key) {
    unsigned int index = hash(key);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (current->record.key == key) {
            return &current->record;
        }
        current = current->next;
    }
    return NULL;
}

void insertRecord(int key, const char* value) {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full, cannot insert new record.\n");
        return;
    }
    Record record;
    record.key = key;
    strncpy(record.value, value, sizeof(record.value));
    records[recordCount++] = record;
    insertIndex(record);
}

void displayRecords() {
    printf("All Records in Database:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Key: %d, Value: %s\n", records[i].key, records[i].value);
    }
}

void searchRecord(int key) {
    Record* record = searchIndex(key);
    if (record) {
        printf("Record Found: Key: %d, Value: %s\n", record->key, record->value);
    } else {
        printf("Record with Key: %d not found.\n", key);
    }
}

void freeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main() {
    int choice, key;
    char value[100];

    do {
        printf("\n--- Simple Database Indexing System ---\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Key (Integer): ");
                scanf("%d", &key);
                printf("Enter Value (String): ");
                scanf("%s", value);
                insertRecord(key, value);
                break;
            case 2:
                printf("Enter Key to Search: ");
                scanf("%d", &key);
                searchRecord(key);
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                printf("Exiting...\n");
                freeHashTable();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}