//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 30
#define MAX_INDEX_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char city[MAX_NAME_LENGTH];
} Record;

typedef struct {
    char indexValue[MAX_INDEX_LENGTH];
    int recordIndex;
} Index;

Record records[MAX_RECORDS];
Index indexTable[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

void addRecord(const char *name, int age, const char *city) {
    if (recordCount >= MAX_RECORDS) {
        printf("Record limit reached. Cannot add more records.\n");
        return;
    }

    strcpy(records[recordCount].name, name);
    records[recordCount].age = age;
    strcpy(records[recordCount].city, city);

    // Index by name
    strcpy(indexTable[indexCount].indexValue, name);
    indexTable[indexCount].recordIndex = recordCount;
    indexCount++;
    recordCount++;
}

void createIndex() {
    for (int i = 0; i < recordCount; i++) {
        strcpy(indexTable[i].indexValue, records[i].name);
        indexTable[i].recordIndex = i;
    }

    // Sort index table based on indexValue
    for (int i = 0; i < indexCount - 1; i++) {
        for (int j = 0; j < indexCount - i - 1; j++) {
            if (strcmp(indexTable[j].indexValue, indexTable[j + 1].indexValue) > 0) {
                // Swap
                Index temp = indexTable[j];
                indexTable[j] = indexTable[j + 1];
                indexTable[j + 1] = temp;
            }
        }
    }
}

void searchByIndex(const char *query) {
    int low = 0, high = indexCount - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = strcmp(indexTable[mid].indexValue, query);
        
        if (cmp == 0) {
            printf("Record found: Name: %s, Age: %d, City: %s\n",
                   records[indexTable[mid].recordIndex].name,
                   records[indexTable[mid].recordIndex].age,
                   records[indexTable[mid].recordIndex].city);
            return;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Record not found!\n");
}

void displayRecords() {
    printf("Current Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("Record %d: Name: %s, Age: %d, City: %s\n", i + 1,
               records[i].name, records[i].age, records[i].city);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int age;
    char city[MAX_NAME_LENGTH];

    while (1) {
        printf("1. Add Record\n");
        printf("2. Create Index\n");
        printf("3. Search by Name\n");
        printf("4. Display All Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                printf("Enter age: ");
                scanf("%d", &age);
                getchar(); // Consume newline
                printf("Enter city: ");
                fgets(city, MAX_NAME_LENGTH, stdin);
                city[strcspn(city, "\n")] = 0;  // Remove newline
                addRecord(name, age, city);
                break;
            case 2:
                createIndex();
                printf("Index created successfully!\n");
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                searchByIndex(name);
                break;
            case 4:
                displayRecords();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}