//FormAI DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the database array
#define MAX_SIZE 1000

// Define the structure of a single data entry
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Define the structure of a database
typedef struct {
    Record data[MAX_SIZE];
    int count;
} Database;

// Define the structure of an index
typedef struct {
    int key;
    int offset;
} Index;

// Define the structure of an indexing system
typedef struct {
    Index index[MAX_SIZE];
    int count;
} IndexingSystem;

// Function to add a new record to the database
void addRecord(Database *db, IndexingSystem *is)
{
    // Check if the database is full
    if (db->count >= MAX_SIZE) {
        printf("Error: Database is full!\n");
        return;
    }

    // Get the user input for the new record
    Record newRecord;
    printf("Enter the ID of the new record: ");
    scanf("%d", &newRecord.id);
    printf("Enter the name of the new record: ");
    scanf("%s", newRecord.name);
    printf("Enter the age of the new record: ");
    scanf("%d", &newRecord.age);

    // Add the new record to the end of the database
    db->data[db->count] = newRecord;
    db->count++;

    // Add the new index to the index system
    Index newIndex;
    newIndex.key = newRecord.id;
    newIndex.offset = db->count - 1;
    is->index[is->count] = newIndex;
    is->count++;

    // Sort the index system by key
    for (int i = 0; i < is->count - 1; i++) {
        for (int j = 0; j < is->count - i - 1; j++) {
            if (is->index[j].key > is->index[j+1].key) {
                Index temp = is->index[j];
                is->index[j] = is->index[j+1];
                is->index[j+1] = temp;
            }
        }
    }
}

// Function to search for a record by ID
void searchRecord(Database *db, IndexingSystem *is)
{
    // Get the user input for the ID to search for
    int searchID;
    printf("Enter the ID of the record to search for: ");
    scanf("%d", &searchID);

    // Use binary search to find the index of the record
    int low = 0, high = is->count - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (is->index[mid].key == searchID) {
            break;
        }
        else if (is->index[mid].key > searchID) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    // Check if the record was found
    if (low > high) {
        printf("Error: Record not found!\n");
        return;
    }

    // Print the record
    Record record = db->data[is->index[mid].offset];
    printf("ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
}

// Function to print all records in the database
void printDatabase(Database *db)
{
    printf("ID\tName\tAge\n");
    printf("------------------------\n");
    for (int i = 0; i < db->count; i++) {
        Record record = db->data[i];
        printf("%d\t%s\t%d\n", record.id, record.name, record.age);
    }
}

int main()
{
    // Initialize the database and indexing system
    Database db = {0};
    IndexingSystem is = {0};

    // Show the menu and handle user input
    int choice;
    do {
        printf("\n1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Print Database\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(&db, &is);
                break;
            case 2:
                searchRecord(&db, &is);
                break;
            case 3:
                printDatabase(&db);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 4);

    return 0;
}