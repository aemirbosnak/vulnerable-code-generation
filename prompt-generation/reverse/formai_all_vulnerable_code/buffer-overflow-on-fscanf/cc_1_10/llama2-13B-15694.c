//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to represent a record
struct record {
    char name[50];
    int age;
    float salary;
};

// Function to create a new record
struct record *new_record(char *name, int age, float salary) {
    struct record *record = malloc(sizeof(struct record));
    strcpy(record->name, name);
    record->age = age;
    record->salary = salary;
    return record;
}

// Function to read records from a file
struct record *read_records(const char *file_name) {
    struct record *records = malloc(MAX_RECORDS * sizeof(struct record));
    int i = 0;

    // Open the file in read mode
    FILE *file = fopen(file_name, "r");

    // Read records from the file
    while (i < MAX_RECORDS && fscanf(file, "%s %d %f", records[i].name, &records[i].age, &records[i].salary) == 3) {
        i++;
    }

    // Close the file
    fclose(file);

    return records;
}

// Function to write records to a file
void write_records(const char *file_name, struct record *records) {
    int i = 0;

    // Open the file in write mode
    FILE *file = fopen(file_name, "w");

    // Write records to the file
    while (i < MAX_RECORDS) {
        fprintf(file, "%s %d %f\n", records[i].name, records[i].age, records[i].salary);
        i++;
    }

    // Close the file
    fclose(file);
}

int main() {
    // Create a list of records
    struct record *records = malloc(MAX_RECORDS * sizeof(struct record));

    // Read records from a file
    records = read_records("employees.dat");

    // Filter the records based on age
    struct record *filtered_records = malloc(MAX_RECORDS * sizeof(struct record));
    int j = 0;

    for (int i = 0; i < MAX_RECORDS; i++) {
        if (records[i].age >= 25 && records[i].age <= 50) {
            filtered_records[j] = records[i];
            j++;
        }
    }

    // Write the filtered records to a new file
    write_records("filtered_employees.dat", filtered_records);

    // Free memory
    free(records);
    free(filtered_records);

    return 0;
}