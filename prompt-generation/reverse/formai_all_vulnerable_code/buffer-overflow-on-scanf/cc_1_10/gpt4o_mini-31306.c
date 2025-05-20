//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    int key;
    char *value;
    struct Record *next;
} Record;

typedef struct Index {
    Record *head;
} Index;

// Function prototypes
Index* createIndex();
void addRecord(Index *index, int key, const char *value);
Record* searchRecord(Index *index, int key);
void listRecords(Index *index);
void freeIndex(Index *index);

int main() {
    Index *index = createIndex();
    int choice, key;
    char value[100];

    while (1) {
        printf("\n--- Database Indexing System ---\n");
        printf("1. Add Record\n2. Search Record\n3. List Records\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key (integer): ");
                scanf("%d", &key);
                printf("Enter value (string): ");
                scanf("%s", value);
                addRecord(index, key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                Record *record = searchRecord(index, key);
                if (record) {
                    printf("Record found: Key: %d, Value: %s\n", record->key, record->value);
                } else {
                    printf("Record not found.\n");
                }
                break;

            case 3:
                printf("Listing all records:\n");
                listRecords(index);
                break;

            case 4:
                freeIndex(index);
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

Index* createIndex() {
    Index *index = (Index *)malloc(sizeof(Index));
    index->head = NULL;
    return index;
}

void addRecord(Index *index, int key, const char *value) {
    Record *newRecord = (Record *)malloc(sizeof(Record));
    newRecord->key = key;
    newRecord->value = (char *)malloc(strlen(value) + 1);
    strcpy(newRecord->value, value);
    newRecord->next = index->head;
    index->head = newRecord;
    printf("Record added: Key: %d, Value: %s\n", key, value);
}

Record* searchRecord(Index *index, int key) {
    Record *current = index->head;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void listRecords(Index *index) {
    Record *current = index->head;
    if (current == NULL) {
        printf("No records to list.\n");
        return;
    }
    while (current != NULL) {
        printf("Key: %d, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

void freeIndex(Index *index) {
    Record *current = index->head;
    Record *next;
    while (current != NULL) {
        next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(index);
}