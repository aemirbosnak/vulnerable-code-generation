//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure to hold record data
struct Record {
    int id;
    char name[20];
    int age;
};

// Define the structure to hold the index
struct Index {
    int key;
    int offset;
};

// Function to add a new record to the database
void addRecord(FILE* dataFile, FILE* indexFile, struct Record* record) {
    // Calculate the offset of the record in the data file
    fseek(dataFile, 0, SEEK_END);
    int offset = ftell(dataFile);

    // Write the record to the data file
    fwrite(record, sizeof(struct Record), 1, dataFile);

    // Write the index to the index file
    struct Index index;
    index.key = record->id;
    index.offset = offset;
    fwrite(&index, sizeof(struct Index), 1, indexFile);
}

// Function to search for a record by ID
void searchRecord(FILE* dataFile, FILE* indexFile, int id) {
    // Read the index file and find the matching record
    struct Index index;
    int found = 0;
    rewind(indexFile);
    while (fread(&index, sizeof(struct Index), 1, indexFile) == 1) {
        if (index.key == id) {
            found = 1;
            break;
        }
    }

    // Print the record if found
    if (found) {
        struct Record record;
        fseek(dataFile, index.offset, SEEK_SET);
        fread(&record, sizeof(struct Record), 1, dataFile);
        printf("ID: %d\nName: %s\nAge: %d\n", record.id, record.name, record.age);
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    // Open the data file and index file
    FILE* dataFile = fopen("data.db", "a+b");
    FILE* indexFile = fopen("index.db", "a+b");

    // Display the menu options
    printf("1. Add record\n");
    printf("2. Search record\n");
    printf("3. Quit\n");

    // Process user input
    int choice;
    do {
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                // Ask user for record data
                struct Record record;
                printf("Enter ID: ");
                scanf("%d", &record.id);
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter age: ");
                scanf("%d", &record.age);

                // Add the record to the database
                addRecord(dataFile, indexFile, &record);
                printf("Record added.\n");
                break;
            }
            case 2: {
                // Ask user for ID to search for
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);

                // Search for the record in the database
                searchRecord(dataFile, indexFile, id);
                break;
            }
            case 3: {
                // Quit the program
                printf("Quitting...\n");
                break;
            }
            default: {
                printf("Invalid choice. Try again.\n");
                break;
            }
        }
    } while (choice != 3);

    // Close the data file and index file
    fclose(dataFile);
    fclose(indexFile);

    return 0;
}