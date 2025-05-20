//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

// Structure to hold a single record
typedef struct {
    char name[20];
    int age;
    float salary;
} record_t;

// Array to store all records
record_t records[MAX_RECORDS];

// Function to read records from a file
void read_records(const char* filename) {
    // Open the file in read mode
    FILE* file = fopen(filename, "r");

    // Check if the file is valid
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Read the records from the file
    int record_count = 0;
    char line[100];
    while (fgets(line, 100, file) != NULL) {
        // Parse the line and extract the fields
        record_t* new_record = &records[record_count];
        sscanf(line, "%19s %d %f", new_record->name, &new_record->age, &new_record->salary);

        // Increment the record count
        record_count++;
    }

    // Close the file
    fclose(file);
}

// Function to write records to a file
void write_records(const char* filename) {
    // Open the file in write mode
    FILE* file = fopen(filename, "w");

    // Check if the file is valid
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Write the records to the file
    for (int i = 0; i < MAX_RECORDS; i++) {
        // Print the record fields
        fprintf(file, "%19s %d %f\n", records[i].name, records[i].age, records[i].salary);
    }

    // Close the file
    fclose(file);
}

int main() {
    // Read the records from a file
    read_records("records.txt");

    // Print the records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%d. %s (%d years old, %f salary)\n", i + 1, records[i].name, records[i].age, records[i].salary);
    }

    // Write the records to a new file
    write_records("new_records.txt");

    return 0;
}