//FormAI DATASET v1.0 Category: Database Indexing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing the information for each record
typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Record;

// Structure for storing the index information for each record
typedef struct {
    int key;
    int offset;
} Index;

int main() {
    // Create an array of 10 records
    Record records[10];
    // Fill the records with some fake data
    for (int i = 0; i < 10; i++) {
        records[i].id = i + 1;
        strcpy(records[i].name, "John Doe");
        records[i].age = 30;
        records[i].salary = 50000.0;
    }

    // Create an array of 10 indexes
    Index indexes[10];
    // Fill the indexes with the id of each record and the offset in the file where it can be found
    for (int i = 0; i < 10; i++) {
        indexes[i].key = records[i].id;
        indexes[i].offset = i * sizeof(Record);
    }

    // Open the file where the records will be stored
    FILE* file = fopen("records.dat", "wb");
    // Write the records to the file
    fwrite(records, sizeof(Record), 10, file);
    // Close the file
    fclose(file);

    // Open the index file
    FILE* indexFile = fopen("indexes.dat", "wb");
    // Write the indexes to the index file
    fwrite(indexes, sizeof(Index), 10, indexFile);
    // Close the index file
    fclose(indexFile);

    // Prompt the user to enter an id to search for
    int searchId;
    printf("Enter an id to search for: ");
    scanf("%d", &searchId);

    // Open the index file
    indexFile = fopen("indexes.dat", "rb");
    // Loop through the indexes to find the offset of the record with the specified id
    int offset = -1;
    for (int i = 0; i < 10; i++) {
        Index currentIndex;
        fread(&currentIndex, sizeof(Index), 1, indexFile);
        if (currentIndex.key == searchId) {
            offset = currentIndex.offset;
            break;
        }
    }
    // Close the index file
    fclose(indexFile);

    // If the offset is -1, the record with the specified id was not found
    if (offset == -1) {
        printf("Record not found.\n");
    } else {
        // Open the record file
        file = fopen("records.dat", "rb");
        // Seek to the offset of the record with the specified id
        fseek(file, offset, SEEK_SET);
        // Read the record from the file
        Record record;
        fread(&record, sizeof(Record), 1, file);
        // Close the record file
        fclose(file);
        // Print the record
        printf("Record found:\n");
        printf("ID: %d\n", record.id);
        printf("Name: %s\n", record.name);
        printf("Age: %d\n", record.age);
        printf("Salary: %.2f\n", record.salary);
    }

    return 0;
}