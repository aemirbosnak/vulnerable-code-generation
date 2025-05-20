//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to hold a single record
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

    int i = 0;
    char line[100];
    while (fgets(line, 100, file)) {
        // Skip comments and empty lines
        if (strcmp(line, "") == 0 || line[0] == '#') {
            continue;
        }

        // Extract fields from line
        sscanf(line, "%49s %d %f", records[i].name, &records[i].age, &records[i].salary);

        // Increment index
        i++;
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

    int i = 0;
    for (; i < MAX_RECORDS; i++) {
        if (records[i].name[0] != '\0') {
            fprintf(file, "%s %d %f\n", records[i].name, records[i].age, records[i].salary);
        }
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    // Read records from a file
    record_t *records = read_records("records.txt");
    if (!records) {
        perror("Error reading records");
        return 1;
    }

    // Print records
    for (int i = 0; i < MAX_RECORDS; i++) {
        printf("%d. %s %d %f\n", i + 1, records[i].name, records[i].age, records[i].salary);
    }

    // Modify a record
    records[1].salary += 1000;

    // Write modified records to a file
    write_records("modified_records.txt", records);

    // Free memory
    free(records);

    return 0;
}