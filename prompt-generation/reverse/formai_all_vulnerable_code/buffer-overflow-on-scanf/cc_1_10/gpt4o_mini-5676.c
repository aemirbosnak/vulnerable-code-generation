//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DATABASE_FILE "database.txt"

// Structure to represent a record
typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Record;

// Structure to represent an index
typedef struct {
    int id;
    int position;
} IndexEntry;

Record records[MAX_RECORDS];
IndexEntry indexTable[MAX_RECORDS];
int recordCount = 0;
int indexCount = 0;

// Function prototype declarations
void loadDatabase();
void saveDatabase();
void createIndex();
void searchById(int id);
void displayRecords();

int main() {
    int choice, id;

    loadDatabase();

    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Display Records\n");
        printf("2. Create Index\n");
        printf("3. Search by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRecords();
                break;
            case 2:
                createIndex();
                printf("Index created successfully!\n");
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchById(id);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    saveDatabase();
    return 0;
}

// Function to load the database from a file
void loadDatabase() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (!file) {
        printf("Database file not found. Starting fresh...\n");
        return;
    }
    
    while (fscanf(file, "%d %s %f", &records[recordCount].id, records[recordCount].name, &records[recordCount].score) != EOF) {
        recordCount++;
    }
    fclose(file);
}

// Function to save the database to a file
void saveDatabase() {
    FILE *file = fopen(DATABASE_FILE, "w");
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s %.2f\n", records[i].id, records[i].name, records[i].score);
    }
    fclose(file);
}

// Function to display all records
void displayRecords() {
    if (recordCount == 0) {
        printf("No records found in the database.\n");
        return;
    }
    printf("\nAll Records:\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Score: %.2f\n", records[i].id, records[i].name, records[i].score);
    }
}

// Function to create an index for the records
void createIndex() {
    indexCount = 0;
    for (int i = 0; i < recordCount; i++) {
        indexTable[indexCount].id = records[i].id;
        indexTable[indexCount].position = i;
        indexCount++;
    }
}

// Function to search for a record by its ID using the index
void searchById(int id) {
    for (int i = 0; i < indexCount; i++) {
        if (indexTable[i].id == id) {
            int position = indexTable[i].position;
            printf("Record found: ID: %d, Name: %s, Score: %.2f\n", records[position].id, records[position].name, records[position].score);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}