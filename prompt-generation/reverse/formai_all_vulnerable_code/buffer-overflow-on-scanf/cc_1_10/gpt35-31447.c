//FormAI DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    int key;
    char data[20];
} Record;

typedef struct Index {
    int key;
    int offset;
} Index;

void insert_into_database(FILE *fp, Record record, int *num_of_records, Index *indices) {
    fseek(fp, 0, SEEK_END); // Move the file pointer to the end of file
    fwrite(&record, sizeof(Record), 1, fp); // Write the record into the file
    indices[*num_of_records].key = record.key; // Create new index for the new record
    indices[*num_of_records].offset = ftell(fp) - sizeof(Record); // Save the offset of the record in the file
    (*num_of_records)++; // Increase the record count
}

int search_database(FILE *fp, int key, Index *indices, int num_of_records) {
    int low = 0, high = num_of_records - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == indices[mid].key) { // If the key is found
            fseek(fp, indices[mid].offset, SEEK_SET); // Move the file pointer to the location of the record
            Record record;
            fread(&record, sizeof(Record), 1, fp); // Read the record from the file
            printf("Found record: (%d, %s)\n", record.key, record.data);
            return mid;
        } else if (key < indices[mid].key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("Record not found.\n");
    return -1;
}

int main() {
    FILE *fp = fopen("database.bin", "r+b"); // Open the binary file
    if (fp == NULL) { // If the file does not exist
        fp = fopen("database.bin", "w+b"); // Create the file
        if (fp == NULL) {
            printf("Failed to create the file.\n");
            return 1;
        }
    }

    int num_of_records = 0;
    Index indices[100];

    // Main menu loop
    while (1) {
        printf("\n1. Insert record\n2. Search record\n3. Exit\n\nYour choice: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) { // Insert record
            Record record;
            printf("Enter key: ");
            scanf("%d", &record.key);
            printf("Enter data: ");
            scanf("%s", record.data);
            insert_into_database(fp, record, &num_of_records, indices);
            printf("Record inserted.\n");
        } else if (choice == 2) { // Search record
            int key;
            printf("Enter key: ");
            scanf("%d", &key);
            search_database(fp, key, indices, num_of_records);
        } else if (choice == 3) { // Exit
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    fclose(fp); // Close the file
    return 0;
}