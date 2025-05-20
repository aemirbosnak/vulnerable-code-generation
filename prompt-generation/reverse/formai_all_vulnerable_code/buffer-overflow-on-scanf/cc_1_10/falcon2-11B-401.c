//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Struct for representing a record in the database
typedef struct record {
    char name[100];
    int age;
    float salary;
} Record;

// Function to add a new record to the database
void add_record(Record *records, int *size) {
    // Check if the database is full
    if (*size >= 10) {
        printf("Database is full, cannot add new record\n");
        return;
    }
    
    // Create a new record
    Record new_record;
    printf("Enter name: ");
    fgets(new_record.name, sizeof(new_record.name), stdin);
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    printf("Enter salary: ");
    scanf("%f", &new_record.salary);
    
    // Add the new record to the database
    (*size)++;
    records[*size-1] = new_record;
}

// Function to remove a record from the database
void remove_record(Record *records, int *size, char *name) {
    // Check if the record exists
    int i;
    for (i = 0; i < *size; i++) {
        if (strcmp(records[i].name, name) == 0) {
            // Remove the record from the database
            (*size)--;
            for (int j = i; j < *size-1; j++) {
                records[j] = records[j+1];
            }
            return;
        }
    }
    
    // Record not found
    printf("Record not found\n");
}

// Function to search for a record in the database
void search_record(Record *records, int size, char *name) {
    // Check if the record exists
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(records[i].name, name) == 0) {
            printf("Name: %s, Age: %d, Salary: %f\n", records[i].name, records[i].age, records[i].salary);
            return;
        }
    }
    
    // Record not found
    printf("Record not found\n");
}

int main() {
    Record records[10];
    int size = 0;
    
    // Add records to the database
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    add_record(records, &size);
    
    // Remove a record from the database
    remove_record(records, &size, "John");
    
    // Search for a record in the database
    search_record(records, size, "Jane");
    
    return 0;
}