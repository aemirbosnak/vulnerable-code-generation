//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define INDEX_NAME_LENGTH 20

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    int id;
    int index;
} Index;

Record database[MAX_RECORDS];
Index indexTable[MAX_RECORDS];

int recordCount = 0;
int indexCount = 0;

void addRecord(int id, const char *name) {
    if (recordCount < MAX_RECORDS) {
        database[recordCount].id = id;
        strncpy(database[recordCount].name, name, NAME_LENGTH - 1);
        indexTable[indexCount].id = id;
        indexTable[indexCount].index = recordCount;
        indexCount++;
        recordCount++;
        printf("Record added: %d, %s\n", id, name);
    } else {
        printf("Database is full. Cannot add more records!\n");
    }
}

void displayRecords() {
    printf("\n--- Records in Database ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s\n", database[i].id, database[i].name);
    }
    printf("---------------------------\n");
}

int searchRecord(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i].id == id) {
            return indexTable[i].index;
        }
    }
    return -1; // Not found
}

void displayRecord(int id) {
    int index = searchRecord(id);
    if (index != -1) {
        printf("Record Found: ID: %d, Name: %s\n", database[index].id, database[index].name);
    } else {
        printf("Record with ID %d not found.\n", id);
    }
}

void clearDatabase() {
    recordCount = 0;
    indexCount = 0;
    printf("Database cleared!\n");
}

int main() {
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        printf("\n--- Simple Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Clear Database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]s", name); // to read string with spaces
                addRecord(id, name);
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                displayRecord(id);
                break;
            case 4:
                clearDatabase();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}