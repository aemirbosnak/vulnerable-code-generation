//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Global variables
const int MAX_RECORDS = 100;
const int MAX_FIELDS = 5;
char *db_filename = "shocked_database.dat";

// Structure to hold a record
typedef struct {
    char name[50];
    int age;
    char gender[10];
    int address[5];
} record_t;

// Function to read the database from file
record_t *read_database(void) {
    // Open the database file in read-only mode
    FILE *file = fopen(db_filename, "r");
    assert(file != NULL);

    // Allocate memory for the records
    record_t *records = calloc(MAX_RECORDS, sizeof(record_t));
    assert(records != NULL);

    // Read the records from the file
    int i = 0;
    while (i < MAX_RECORDS && fscanf(file, "%s %d %s %d", records[i].name, &records[i].age, records[i].gender, &records[i].address) == 4) {
        i++;
    }

    // Return the records
    return records;
}

// Function to write the database to file
void write_database(record_t *records) {
    // Open the database file in write-only mode
    FILE *file = fopen(db_filename, "w");
    assert(file != NULL);

    // Write the records to the file
    int i = 0;
    for (; i < MAX_RECORDS; i++) {
        fprintf(file, "%s %d %s %d\n", records[i].name, records[i].age, records[i].gender, records[i].address);
    }

    // Close the file
    fclose(file);
}

int main(void) {
    // Read the database from file
    record_t *records = read_database();

    // Print the records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%d: %s (%d) %s\n", i, records[i].name, records[i].age, records[i].gender);
    }

    // Write the database to file
    write_database(records);

    return 0;
}