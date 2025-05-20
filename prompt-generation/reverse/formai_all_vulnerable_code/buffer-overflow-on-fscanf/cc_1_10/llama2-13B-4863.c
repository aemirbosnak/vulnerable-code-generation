//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to store a single record
typedef struct {
    char name[50];
    int age;
    float weight;
    double height;
    char gender;
} record_t;

// Function to read records from a file
record_t* read_records(const char* file_name) {
    // Open the file in read mode
    FILE* file = fopen(file_name, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Create an array to store the records
    record_t* records = (record_t*)calloc(MAX_RECORDS, sizeof(record_t));
    if (!records) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the records from the file
    int i = 0;
    while (fscanf(file, "%s%d%f%lf%c", records[i].name, &records[i].age, &records[i].weight, &records[i].height, records[i].gender) == 5) {
        i++;
    }

    // Check if there are any records
    if (i == 0) {
        printf("No records found in file\n");
    }

    // Close the file
    fclose(file);

    return records;
}

// Function to write records to a file
void write_records(const char* file_name, record_t* records, int num_records) {
    // Open the file in write mode
    FILE* file = fopen(file_name, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    // Write the records to the file
    for (int i = 0; i < num_records; i++) {
        fprintf(file, "%s%d%f%lf%c", records[i].name, records[i].age, records[i].weight, records[i].height, records[i].gender);
    }

    // Close the file
    fclose(file);
}

int main() {
    // Read the records from a file
    record_t* records = read_records("records.txt");
    if (!records) {
        printf("Error reading records from file\n");
        return 1;
    }

    // Print the records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%d. %s (%d years old, %f kg, %lf meters tall, %c)\n", i + 1, records[i].name, records[i].age, records[i].weight, records[i].height, records[i].gender);
    }

    // Write the records to a new file
    write_records("output.txt", records, MAX_RECORDS);

    // Free the memory allocated for the records
    free(records);

    return 0;
}