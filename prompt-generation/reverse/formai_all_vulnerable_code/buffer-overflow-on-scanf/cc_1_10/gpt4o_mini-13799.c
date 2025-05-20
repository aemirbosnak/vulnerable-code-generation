//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int id;        // Key Field
    int recordIndex;  // Index of the record in main array
} Index;

Record database[MAX_RECORDS];
Index indexTable[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

void addRecord(int id, const char *name) {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    
    database[recordCount].id = id;
    strncpy(database[recordCount].name, name, NAME_LENGTH - 1);
    database[recordCount].name[NAME_LENGTH - 1] = '\0'; // Safeguard
    recordCount++;
}

void buildIndex() {
    indexCount = recordCount; // Reset index count
    
    for (int i = 0; i < recordCount; i++) {
        indexTable[i].id = database[i].id;
        indexTable[i].recordIndex = i;
    }
    
    // Simple bubble sort to sort the index table based on ID
    for (int i = 0; i < indexCount - 1; i++) {
        for (int j = 0; j < indexCount - i - 1; j++) {
            if (indexTable[j].id > indexTable[j + 1].id) {
                Index temp = indexTable[j];
                indexTable[j] = indexTable[j + 1];
                indexTable[j + 1] = temp;
            }
        }
    }
}

int searchIndex(int id) {
    int left = 0, right = indexCount - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (indexTable[mid].id == id) {
            return indexTable[mid].recordIndex; // Found
        } else if (indexTable[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Not found
}

void displayRecords() {
    printf("\nCurrent Records in the Database:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s\n", database[i].id, database[i].name);
    }
    printf("--------------------------------\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Simple Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Build Index\n");
        printf("3. Search Record by ID\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

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
                buildIndex();
                printf("Index built successfully!\n");
                break;
            case 3: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int resultIndex = searchIndex(id);
                if (resultIndex != -1) {
                    printf("Record Found: ID: %d, Name: %s\n", database[resultIndex].id, database[resultIndex].name);
                } else {
                    printf("Record with ID %d not found!\n", id);
                }
                break;
            }
            case 4:
                displayRecords();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}