//Falcon-180B DATASET v1.0 Category: Database querying ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_ROW_LENGTH 1000

typedef struct {
    char *name;
    int age;
    char *address;
} record_t;

int main() {
    char *filename = "data.csv";
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    record_t *records = malloc(MAX_ROWS * sizeof(record_t));
    int num_records = 0;

    char line[MAX_ROW_LENGTH];
    while (fgets(line, MAX_ROW_LENGTH, fptr)!= NULL) {
        char *token = strtok(line, ",");
        if (num_records >= MAX_ROWS) {
            printf("Error: too many records in file\n");
            free(records);
            fclose(fptr);
            return 2;
        }

        record_t *record = &records[num_records++];
        record->name = strdup(token);

        token = strtok(NULL, ",");
        record->age = atoi(token);

        token = strtok(NULL, ",");
        record->address = strdup(token);
    }

    fclose(fptr);

    char *search_name = "John";
    int num_matches = 0;

    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, search_name) == 0) {
            printf("Record %d:\nName: %s\nAge: %d\nAddress: %s\n", i, records[i].name, records[i].age, records[i].address);
            num_matches++;
        }
    }

    if (num_matches == 0) {
        printf("No records found with name %s\n", search_name);
    }

    free(records);
    return 0;
}