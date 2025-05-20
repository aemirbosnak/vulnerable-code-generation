//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100

// Structure to store student records
typedef struct {
    char name[50];
    int age;
    char address[100];
} student_record;

// Function to read student records from a file
student_record* read_records(const char* file_name) {
    // Open the file in read mode
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return NULL;
    }

    // Create an array to store the records
    student_record* records = calloc(MAX_RECORDS, sizeof(student_record));
    if (records == NULL) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // Read the records from the file
    int i = 0;
    while (fscanf(file, "%s %d %s", records[i].name, &records[i].age, records[i].address) == 3) {
        i++;
    }

    // Check if any records were read
    if (i == 0) {
        printf("Error: No records found in file %s\n", file_name);
    }

    // Return the array of records
    return records;
}

// Function to write student records to a file
void write_records(const char* file_name, student_record* records, int num_records) {
    // Open the file in write mode
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        return;
    }

    // Write the records to the file
    for (int i = 0; i < num_records; i++) {
        fprintf(file, "%s %d %s\n", records[i].name, records[i].age, records[i].address);
    }

    // Close the file
    fclose(file);
}

int main() {
    // Read the records from a file
    student_record* records = read_records("students.dat");
    if (records == NULL) {
        return 1;
    }

    // Print the records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%d. %s %d %s\n", i + 1, records[i].name, records[i].age, records[i].address);
    }

    // Free the memory
    free(records);

    // Write the records to a new file
    write_records("new_students.dat", records, MAX_RECORDS);

    return 0;
}