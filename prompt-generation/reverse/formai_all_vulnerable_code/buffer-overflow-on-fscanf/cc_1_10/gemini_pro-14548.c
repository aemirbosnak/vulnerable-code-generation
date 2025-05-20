//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RECORDS 100

typedef struct {
    char name[32];
    char address[64];
    char phone[16];
    int age;
} record_t;

record_t records[MAX_RECORDS];

// Load records from a file
int load_records(char *filename) {
    FILE *fp;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    while (fscanf(fp, "%s %s %s %d", records[i].name, records[i].address, records[i].phone, &records[i].age) != EOF) {
        i++;
    }

    fclose(fp);

    return i;
}

// Print a record
void print_record(record_t *record) {
    printf("%s %s %s %d\n", record->name, record->address, record->phone, record->age);
}

// Search for a record by name
record_t *search_by_name(char *name) {
    int i;

    for (i = 0; i < MAX_RECORDS; i++) {
        if (strcmp(records[i].name, name) == 0) {
            return &records[i];
        }
    }

    return NULL;
}

// Search for records by age range
int search_by_age_range(int min_age, int max_age, record_t **results) {
    int i;
    int count = 0;

    for (i = 0; i < MAX_RECORDS; i++) {
        if (records[i].age >= min_age && records[i].age <= max_age) {
            results[count] = &records[i];
            count++;
        }
    }

    return count;
}

// Print a list of records
void print_records(record_t **records, int count) {
    int i;

    for (i = 0; i < count; i++) {
        print_record(records[i]);
    }
}

// Main function
int main() {
    char input[256];
    char *filename = "records.txt";
    int num_records;
    record_t *record;
    record_t *results[MAX_RECORDS];
    int count;

    // Load records from a file
    num_records = load_records(filename);
    if (num_records < 0) {
        printf("Error loading records.\n");
        return -1;
    }

    // Print a welcome message
    printf("Welcome to the database!\n");

    // Get user input
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Parse user input
        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  quit: Quit the program.\n");
            printf("  help: Print this help message.\n");
            printf("  search name <name>: Search for a record by name.\n");
            printf("  search age <min_age> <max_age>: Search for records by age range.\n");
            printf("  list: Print a list of all records.\n");
        } else if (strncmp(input, "search name", 11) == 0) {
            char *name = input + 12;

            record = search_by_name(name);
            if (record != NULL) {
                printf("Found record:\n");
                print_record(record);
            } else {
                printf("Record not found.\n");
            }
        } else if (strncmp(input, "search age", 10) == 0) {
            char *min_age = input + 11;
            char *max_age = strchr(min_age, ' ');
            if (max_age == NULL) {
                printf("Invalid input.\n");
                continue;
            }

            *max_age = 0;
            max_age++;

            count = search_by_age_range(atoi(min_age), atoi(max_age), results);
            if (count > 0) {
                printf("Found %d records:\n", count);
                print_records(results, count);
            } else {
                printf("No records found.\n");
            }
        } else if (strcmp(input, "list") == 0) {
            printf("Records:\n");
            print_records(records, num_records);
        } else {
            printf("Invalid command.\n");
        }
    }

    // Print a goodbye message
    printf("Goodbye!\n");

    return 0;
}