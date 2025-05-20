//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records
#define MAX_RECORDS 100

// Define the structure of a record
typedef struct {
    char name[50];
    int age;
    char occupation[50];
} Record;

// Function to compare two records based on their names
int compare_records(const void *a, const void *b) {
    Record *record_a = (Record *)a;
    Record *record_b = (Record *)b;

    return strcmp(record_a->name, record_b->name);
}

// Function to print a record
void print_record(Record *record) {
    printf("Name: %s\n", record->name);
    printf("Age: %d\n", record->age);
    printf("Occupation: %s\n\n", record->occupation);
}

// Main function
int main() {
    // Initialize the number of records
    int num_records = 0;

    // Initialize an array of records
    Record records[MAX_RECORDS];

    // Prompt the user to enter the number of records
    printf("Enter the number of records (up to %d): ", MAX_RECORDS);
    scanf("%d", &num_records);

    // Loop through each record and prompt the user for input
    for (int i = 0; i < num_records; i++) {
        printf("Enter the name for record %d: ", i + 1);
        scanf("%s", records[i].name);

        printf("Enter the age for record %d: ", i + 1);
        scanf("%d", &records[i].age);

        printf("Enter the occupation for record %d: ", i + 1);
        scanf("%s", records[i].occupation);
    }

    // Sort the records alphabetically by name
    qsort(records, num_records, sizeof(Record), compare_records);

    // Print the sorted records
    printf("Sorted records:\n");
    for (int i = 0; i < num_records; i++) {
        print_record(&records[i]);
    }

    return 0;
}