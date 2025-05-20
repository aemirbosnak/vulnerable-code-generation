//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

// Structure to represent a record
typedef struct {
    char name[50];
    int age;
    float salary;
} record_t;

// Function to read records from a file
record_t *read_records(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    record_t *records = calloc(MAX_RECORDS, sizeof(record_t));
    if (!records) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    char line[100];
    while (fgets(line, 100, file)) {
        // Parse the line and fill the record structure
        sscanf(line, "%49s %d %f", records->name, &records->age, &records->salary);
        records++;
    }

    fclose(file);
    return records;
}

// Function to write records to a file
void write_records(const char *filename, record_t *records) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < MAX_RECORDS; i++) {
        fprintf(file, "%s %d %f\n", records[i].name, records[i].age, records[i].salary);
    }

    fclose(file);
}

int main() {
    record_t *records = read_records("records.txt");
    if (!records) {
        printf("Error reading records from file\n");
        return 1;
    }

    // Print the records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%s (%d) - %f\n", records[i].name, records[i].age, records[i].salary);
    }

    // Modify a record
    records[1].age = 30;

    // Write the modified records to a new file
    write_records("modified_records.txt", records);

    // Free the memory allocated for the records
    free(records);

    return 0;
}