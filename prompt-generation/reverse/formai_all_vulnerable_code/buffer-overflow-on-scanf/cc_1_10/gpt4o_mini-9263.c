//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Record;

typedef struct {
    char key[MAX_KEY_LENGTH];
    int index;  // index in records array
} IndexEntry;

Record records[MAX_ENTRIES];
IndexEntry indexTable[MAX_ENTRIES];
int recordCount = 0;
int indexCount = 0;

// Function to add a record
void addRecord(const char* key, const char* value) {
    if (recordCount >= MAX_ENTRIES) {
        printf("Database is full. Cannot add new record.\n");
        return;
    }
    
    strcpy(records[recordCount].key, key);
    strcpy(records[recordCount].value, value);

    // Update the index
    strcpy(indexTable[indexCount].key, key);
    indexTable[indexCount].index = recordCount;
    indexCount++;

    recordCount++;
}

// Function to search for a record by key
Record* searchRecord(const char* key) {
    for (int i = 0; i < indexCount; i++) {
        if (strcmp(indexTable[i].key, key) == 0) {
            return &records[indexTable[i].index];
        }
    }
    return NULL;  // Not found
}

// Function to display all records
void displayRecords() {
    printf("Current Records in Database:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Key: %s, Value: %s\n", records[i].key, records[i].value);
    }
}

// Function to display all indexed keys
void displayIndex() {
    printf("Current Index:\n");
    for (int i = 0; i < indexCount; i++) {
        printf("Index: %d, Key: %s\n", i, indexTable[i].key);
    }
}

// Main function
int main() {
    int choice;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Display All Records\n");
        printf("4. Display Index\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character left in the buffer

        switch (choice) {
            case 1:
                printf("Enter key: ");
                fgets(key, sizeof(key), stdin);
                strtok(key, "\n");  // Remove newline character
                printf("Enter value: ");
                fgets(value, sizeof(value), stdin);
                strtok(value, "\n");  // Remove newline character
                addRecord(key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                fgets(key, sizeof(key), stdin);
                strtok(key, "\n");  // Remove newline character
                Record* record = searchRecord(key);
                if (record) {
                    printf("Found Record: Key: %s, Value: %s\n", record->key, record->value);
                } else {
                    printf("Record not found.\n");
                }
                break;

            case 3:
                displayRecords();
                break;

            case 4:
                displayIndex();
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}