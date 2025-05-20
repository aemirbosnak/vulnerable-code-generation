//FormAI DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Data structure to hold the information of each record
struct Record {
    int key;
    char name[50];
    int age;
};

// Function to check if a file exists
int checkFileExists(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}

// Function to search for a record by key in a file
struct Record searchRecordByKey(char* filename, int key) {
    FILE* fp = fopen(filename, "rb");
    struct Record record;
    while (fread(&record, sizeof(struct Record), 1, fp)) {
        if (record.key == key) {
            fclose(fp);
            return record;
        }
    }
    fclose(fp);
    record.key = -1;
    return record;
}

int main() {
    char filename[] = "records.dat";
    int numRecords = 0;

    // Check if file exists. If it does, read the number of records from the file
    if (checkFileExists(filename)) {
        FILE* fp = fopen(filename, "rb");
        fread(&numRecords, sizeof(int), 1, fp);
        fclose(fp);
    }

    int choice;
    do {
        // Display menu
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Record record;
                printf("Enter key: ");
                scanf("%d", &record.key);
                printf("Enter name: ");
                scanf("%s", record.name);
                printf("Enter age: ");
                scanf("%d", &record.age);

                // Write record to file
                FILE* fp = fopen(filename, "ab");
                fwrite(&record, sizeof(struct Record), 1, fp);
                fclose(fp);

                numRecords++;
                // Update number of records in file
                fp = fopen(filename, "rb+");
                fwrite(&numRecords, sizeof(int), 1, fp);
                fclose(fp);
                break;
            }
            case 2: {
                int key;
                printf("Enter key to search: ");
                scanf("%d", &key);

                // Search for record by key and print the record
                struct Record record = searchRecordByKey(filename, key);
                if (record.key != -1) {
                    printf("Key: %d\nName: %s\nAge: %d\n", record.key, record.name, record.age);
                } else {
                    printf("Record not found.\n");
                }
                break;
            }
            case 3:
                // Exit program
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 3);

    return 0;
}