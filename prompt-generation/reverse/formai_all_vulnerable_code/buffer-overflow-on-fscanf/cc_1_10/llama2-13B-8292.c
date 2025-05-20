//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 5

// Structure to store a single record
typedef struct {
    char name[20];
    int age;
    char gender;
    int address[3];
} record_t;

// Function to read a record from the database
record_t *read_record(FILE *file) {
    record_t r;
    int i;

    // Read name
    fscanf(file, "%19s", r.name);

    // Read age
    fscanf(file, "%d", &r.age);

    // Read gender
    fscanf(file, "%c", &r.gender);

    // Read address
    for (i = 0; i < 3; i++) {
        fscanf(file, "%d", &r.address[i]);
    }

    return &r;
}

// Function to write a record to the database
void write_record(FILE *file, record_t *r) {
    int i;

    // Write name
    fprintf(file, "%19s", r->name);

    // Write age
    fprintf(file, "%d", r->age);

    // Write gender
    fprintf(file, "%c", r->gender);

    // Write address
    for (i = 0; i < 3; i++) {
        fprintf(file, "%d", r->address[i]);
    }
}

// Function to display the contents of the database
void display_records(FILE *file) {
    record_t *r;

    // Read the first record
    r = read_record(file);

    // Display the record
    printf("Record 1: %s (%d years old, %c, %d, %d, %d)\n", r->name, r->age, r->gender, r->address[0], r->address[1], r->address[2]);

    // Read the next record
    r = read_record(file);

    // Display the record
    printf("Record 2: %s (%d years old, %c, %d, %d, %d)\n", r->name, r->age, r->gender, r->address[0], r->address[1], r->address[2]);

    // Repeat until there are no more records
}

int main() {
    FILE *file = fopen("database.dat", "r");

    // Check if the file exists
    if (file == NULL) {
        printf("Error: File not found\n");
        return 1;
    }

    // Display the contents of the database
    display_records(file);

    // Close the file
    fclose(file);

    return 0;
}