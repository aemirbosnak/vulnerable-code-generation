//GEMINI-pro DATASET v1.0 Category: File handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to represent a record in the file
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Function to read records from a file and store them in an array
void readRecords(FILE *fp, Record *records, int *numRecords) {
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d %s %d", &records[i].id, records[i].name, &records[i].age);
        i++;
    }
    *numRecords = i;
}

// Function to write records from an array to a file
void writeRecords(FILE *fp, Record *records, int numRecords) {
    for (int i = 0; i < numRecords; i++) {
        fprintf(fp, "%d %s %d\n", records[i].id, records[i].name, records[i].age);
    }
}

// Function to search for a record in an array by ID
int searchRecord(Record *records, int numRecords, int id) {
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Function to delete a record from an array by ID
void deleteRecord(Record *records, int *numRecords, int id) {
    int index = searchRecord(records, *numRecords, id);
    if (index != -1) {
        for (int i = index; i < *numRecords - 1; i++) {
            records[i] = records[i + 1];
        }
        (*numRecords)--;
    }
}

// Function to add a record to an array
void addRecord(Record *records, int *numRecords, Record newRecord) {
    records[*numRecords] = newRecord;
    (*numRecords)++;
}

// Main function
int main() {
    // Open the file for reading and writing
    FILE *fp = fopen("records.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read the records from the file into an array
    Record records[100];
    int numRecords;
    readRecords(fp, records, &numRecords);

    // Get the user's choice
    int choice;
    do {
        printf("1. Search for a record\n");
        printf("2. Delete a record\n");
        printf("3. Add a record\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        int id;
        Record newRecord;
        switch (choice) {
            case 1:
                printf("Enter the ID of the record to search for: ");
                scanf("%d", &id);
                int index = searchRecord(records, numRecords, id);
                if (index != -1) {
                    printf("Record found:\n");
                    printf("ID: %d\n", records[index].id);
                    printf("Name: %s\n", records[index].name);
                    printf("Age: %d\n", records[index].age);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 2:
                printf("Enter the ID of the record to delete: ");
                scanf("%d", &id);
                deleteRecord(records, &numRecords, id);
                printf("Record deleted!\n");
                break;
            case 3:
                printf("Enter the ID of the new record: ");
                scanf("%d", &newRecord.id);
                printf("Enter the name of the new record: ");
                scanf("%s", newRecord.name);
                printf("Enter the age of the new record: ");
                scanf("%d", &newRecord.age);
                addRecord(records, &numRecords, newRecord);
                printf("Record added!\n");
                break;
            case 4:
                printf("All records:\n");
                for (int i = 0; i < numRecords; i++) {
                    printf("ID: %d\n", records[i].id);
                    printf("Name: %s\n", records[i].name);
                    printf("Age: %d\n", records[i].age);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);

    // Write the records back to the file
    rewind(fp);
    writeRecords(fp, records, numRecords);

    // Close the file
    fclose(fp);

    return 0;
}