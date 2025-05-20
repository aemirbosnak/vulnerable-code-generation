//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 20
#define MAX_AGE 100

// Structure to store a person's record
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
} person_record_t;

// Function to read a person's record from the database
person_record_t *read_record(int index) {
    // simulate reading from a file
    FILE *file = fopen("database.txt", "r");
    char line[100];
    int i = 0;

    if (file == NULL) {
        printf("Error: unable to open database file\n");
        return NULL;
    }

    // read the record from the file
    while (fgets(line, 100, file)) {
        if (i == index) {
            // found the record, return it
            person_record_t *record = malloc(sizeof(person_record_t));
            sscanf(line, "%s %d", record->name, &record->age);
            return record;
        }
        i++;
    }

    // not found, return NULL
    return NULL;
}

// Function to write a person's record to the database
void write_record(int index, person_record_t *record) {
    // simulate writing to a file
    FILE *file = fopen("database.txt", "w");
    char line[100];

    if (file == NULL) {
        printf("Error: unable to open database file\n");
        return;
    }

    // format the record for writing
    sprintf(line, "%s %d\n", record->name, record->age);
    fputs(line, file);

    // close the file
    fclose(file);
}

int main() {
    // initialize the database with some records
    person_record_t records[MAX_RECORDS] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35},
    };

    // simulate a search function
    int found = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        person_record_t *record = read_record(i);
        if (record != NULL) {
            // found a match, print the record
            printf("Found record: %s, %d\n", record->name, record->age);
            found = 1;
            break;
        }
    }

    // simulate an update function
    records[0].age = 30;
    write_record(0, &records[0]);

    // simulate a query function
    person_record_t *record = read_record(1);
    if (record != NULL) {
        printf("Record found: %s, %d\n", record->name, record->age);
    } else {
        printf("Record not found\n");
    }

    return 0;
}