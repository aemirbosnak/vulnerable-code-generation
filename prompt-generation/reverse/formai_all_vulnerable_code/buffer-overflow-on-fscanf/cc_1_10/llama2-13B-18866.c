//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

// Structure to hold a single record
typedef struct {
    char name[20];
    int age;
    float score;
} record_t;

// Function to read records from a file
record_t* read_records(const char* file_name) {
    // Open the file in read mode
    FILE* file = fopen(file_name, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", file_name);
        return NULL;
    }

    // Create an array to store the records
    record_t* records = calloc(MAX_RECORDS, sizeof(record_t));
    if (!records) {
        printf("Error: Unable to allocate memory for records\n");
        fclose(file);
        return NULL;
    }

    // Read the records from the file
    int i = 0;
    while (fscanf(file, "%19s%d%f", records[i].name, &records[i].age, &records[i].score) == 3) {
        i++;
    }

    // Check if there are any errors
    if (feof(file) || ferror(file)) {
        printf("Error: Unable to read file %s\n", file_name);
        free(records);
        fclose(file);
        return NULL;
    }

    // Return the array of records
    return records;
}

// Function to write records to a file
void write_records(const char* file_name, record_t* records, int num_records) {
    // Open the file in write mode
    FILE* file = fopen(file_name, "w");
    if (!file) {
        printf("Error: Unable to open file %s\n", file_name);
        return;
    }

    // Write the records to the file
    for (int i = 0; i < num_records; i++) {
        fprintf(file, "%s %d %f\n", records[i].name, records[i].age, records[i].score);
    }

    // Close the file
    fclose(file);
}

int main() {
    // Read the records from a file
    record_t* records = read_records("records.txt");
    if (!records) {
        printf("Error: Unable to read records from file\n");
        return 1;
    }

    // Print the records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%d. %s (%d, %f)\n", i + 1, records[i].name, records[i].age, records[i].score);
    }

    // Write the records to a new file
    write_records("new_records.txt", records, MAX_RECORDS);

    // Free the memory
    free(records);

    return 0;
}