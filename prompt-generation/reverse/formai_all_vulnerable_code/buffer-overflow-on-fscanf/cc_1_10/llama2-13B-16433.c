//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 255

// Structure to store a single record
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} record_t;

// Function to read records from a file
record_t *read_records(const char *filename) {
    // Open the file in read mode
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Create an array to store the records
    record_t *records = (record_t *)calloc(MAX_RECORDS, sizeof(record_t));
    if (!records) {
        printf("Error: Unable to allocate memory for records\n");
        fclose(file);
        return NULL;
    }

    // Read the records from the file
    int i = 0;
    while (fscanf(file, "%s %d", records[i].name, &records[i].age) == 2) {
        i++;
    }

    // Check if there are any records
    if (i == 0) {
        printf("Error: No records found in file %s\n", filename);
        free(records);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Return the array of records
    return records;
}

// Function to write records to a file
void write_records(const char *filename, record_t *records) {
    // Open the file in write mode
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Write the records to the file
    int i = 0;
    for (; i < MAX_RECORDS; i++) {
        if (records[i].name[0] != '\0') {
            fprintf(file, "%s %d\n", records[i].name, records[i].age);
        }
    }

    // Close the file
    fclose(file);
}

// Function to display the records
void display_records(record_t *records) {
    int i = 0;
    for (; i < MAX_RECORDS; i++) {
        if (records[i].name[0] != '\0') {
            printf("%d. %s %d\n", i + 1, records[i].name, records[i].age);
        }
    }
}

int main() {
    // Load the records from a file
    record_t *records = read_records("records.txt");
    if (!records) {
        printf("Error: Unable to read records from file\n");
        return 1;
    }

    // Display the records
    display_records(records);

    // Write the records to a new file
    write_records("new_records.txt", records);

    // Free the memory
    free(records);

    return 0;
}