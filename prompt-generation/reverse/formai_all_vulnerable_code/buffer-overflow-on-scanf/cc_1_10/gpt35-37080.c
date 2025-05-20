//FormAI DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for data entries
typedef struct {
    int id;             // ID of data entry
    char name[50];      // Name of data entry
    float value;        // Value of data entry
} Record;

// Struct definition for index entries
typedef struct {
    int id;             // ID of corresponding data entry
    long offset;        // Byte offset of data entry in file
} Index;

// Function declarations
void addRecord(FILE *data, FILE *index);
void searchRecord(FILE *data, FILE *index);

int main() {
    // File pointers for data and index files
    FILE *data;
    FILE *index;

    // Attempt to open data file
    if ((data = fopen("data.dat", "ab+")) == NULL) {
        printf("Error: Unable to open data file.\n");
        exit(1);
    }

    // Attempt to open index file
    if ((index = fopen("index.dat", "ab+")) == NULL) {
        printf("Error: Unable to open index file.\n");
        exit(1);
    }

    // Menu loop
    int choice;
    do {
        printf("\n1. Add record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(data, index);
                break;
            case 2:
                searchRecord(data, index);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    // Close files
    fclose(data);
    fclose(index);

    return 0;
}

// Function to add a record to the database
void addRecord(FILE *data, FILE *index) {
    // Create new record
    Record newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    printf("Enter name: ");
    scanf("%s", newRecord.name);
    printf("Enter value: ");
    scanf("%f", &newRecord.value);

    // Write record to data file
    fseek(data, 0, SEEK_END);
    long offset = ftell(data);
    fwrite(&newRecord, sizeof(Record), 1, data);

    // Add index entry
    Index newIndex;
    newIndex.id = newRecord.id;
    newIndex.offset = offset;
    fseek(index, 0, SEEK_END);
    fwrite(&newIndex, sizeof(Index), 1, index);

    printf("Record added.\n");
}

// Function to search for a record in the database
void searchRecord(FILE *data, FILE *index) {
    // Get ID to search for
    int searchID;
    printf("Enter ID to search for: ");
    scanf("%d", &searchID);

    // Find corresponding index entry
    Index currentIndex;
    int found = 0;
    rewind(index);
    while (fread(&currentIndex, sizeof(Index), 1, index) == 1) {
        if (currentIndex.id == searchID) {
            found = 1;
            break;
        }
    }

    // Print record if found
    if (found) {
        Record currentRecord;
        fseek(data, currentIndex.offset, SEEK_SET);
        fread(&currentRecord, sizeof(Record), 1, data);
        printf("ID: %d\nName: %s\nValue: %.2f\n", currentRecord.id, currentRecord.name, currentRecord.value);
    }
    else {
        printf("Record not found.\n");
    }
}