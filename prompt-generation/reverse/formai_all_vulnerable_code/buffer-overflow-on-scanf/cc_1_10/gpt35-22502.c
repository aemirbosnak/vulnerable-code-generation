//FormAI DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define INDEX_FILE_NAME "index.dat"

// Structure for storing record data.
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    float salary;
} Record;

// Structure for storing index data.
typedef struct {
    int id;
    long offset;
} Index;

// Function to create index file based on record data.
void create_index_file(FILE *data_file) {
    FILE *index_file;
    Record record;
    Index index[MAX_RECORDS];
    int i, count = 0;

    // Open index file for writing.
    index_file = fopen(INDEX_FILE_NAME, "wb");
    if (index_file == NULL) {
        printf("Error creating index file.\n");
        return;
    }

    // Read records from data file and store index data.
    while (fread(&record, sizeof(record), 1, data_file) == 1) {
        index[count].id = record.id;
        index[count].offset = ftell(data_file) - sizeof(record);
        count++;
    }

    // Sort index data by ID.
    for (i = 0; i < count - 1; i++) {
        int j, min = i;
        for (j = i + 1; j < count; j++) {
            if (index[j].id < index[min].id) {
                min = j;
            }
        }
        if (min != i) {
            Index temp = index[i];
            index[i] = index[min];
            index[min] = temp;
        }
    }

    // Write sorted index data to index file.
    fwrite(index, sizeof(Index), count, index_file);

    // Close index file.
    fclose(index_file);
}

// Function to search for records based on ID.
void search_by_id(FILE *data_file, int id) {
    FILE *index_file;
    Index index;
    int found = 0;

    // Open index file for reading.
    index_file = fopen(INDEX_FILE_NAME, "rb");
    if (index_file == NULL) {
        printf("Index file does not exist. Please create it first.\n");
        return;
    }

    // Search for index data for given ID.
    while (fread(&index, sizeof(index), 1, index_file) == 1) {
        if (index.id == id) {
            // Found index data for given ID.
            found = 1;
            fseek(data_file, index.offset, SEEK_SET);
            Record record;
            fread(&record, sizeof(record), 1, data_file);
            printf("Record found: %d %s %.2f\n", record.id, record.name, record.salary);
            break;
        }
    }

    // Close index file.
    fclose(index_file);

    // If index data not found for given ID, print error message.
    if (!found) {
        printf("Record with ID %d not found.\n", id);
    }
}

int main() {
    FILE *data_file;
    int choice, id;
    char name[MAX_NAME_LEN];
    float salary;

    // Open data file for reading/writing.
    data_file = fopen("data.dat", "rb+");
    if (data_file == NULL) {
        printf("Error opening data file.\n");
        return 1;
    }

    // Create index file based on record data.
    create_index_file(data_file);

    // Main program loop.
    do {
        printf("1. Search by ID\n");
        printf("2. Add record\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID to search for: ");
                scanf("%d", &id);
                search_by_id(data_file, id);
                break;
            case 2:
                printf("Enter record data (ID, name, salary): ");
                scanf("%d%s%f", &id, name, &salary);
                Record record = {id, name, salary};
                fseek(data_file, 0, SEEK_END);
                fwrite(&record, sizeof(record), 1, data_file);
                printf("Record added successfully.\n");
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("\n");

    } while (choice != 3);

    // Close data file.
    fclose(data_file);

    return 0;
}