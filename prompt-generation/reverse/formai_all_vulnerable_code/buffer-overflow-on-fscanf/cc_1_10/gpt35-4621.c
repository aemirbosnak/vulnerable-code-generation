//FormAI DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20

// Define structure for storing records
struct record {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

// Define structure for storing index entries
struct index_entry {
    char key[MAX_NAME_LEN];
    int record_num;
};

// Function prototypes
void load_records(struct record [], int *);
void create_index(struct index_entry [], struct record [], int);
void search_database(struct index_entry [], struct record [], int);
int compare_strings(const void *, const void *);

int main(void) {
    struct record records[MAX_RECORDS];
    struct index_entry index[MAX_RECORDS];
    int num_records = 0;

    printf("Welcome to the Database Indexing System!\n");

    // Load records from file
    load_records(records, &num_records);

    // Create index
    create_index(index, records, num_records);

    // Search database
    search_database(index, records, num_records);

    printf("Goodbye!\n");
    return 0;
}

void load_records(struct record records[], int *num_records) {
    char filename[MAX_NAME_LEN];
    FILE *fp;

    printf("Enter name of data file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %s", records[*num_records].name, records[*num_records].phone) != EOF) {
        (*num_records)++;
    }

    fclose(fp);

    printf("%d records loaded.\n", *num_records);
}

void create_index(struct index_entry index[], struct record records[], int num_records) {
    int i;

    // Copy names to index and store record numbers
    for (i = 0; i < num_records; i++) {
        strcpy(index[i].key, records[i].name);
        index[i].record_num = i;
    }

    // Sort index by name
    qsort(index, num_records, sizeof(struct index_entry), compare_strings);

    printf("Index created.\n");
}

void search_database(struct index_entry index[], struct record records[], int num_records) {
    char name[MAX_NAME_LEN];
    int i, j;

    while (1) {
        printf("\nEnter name to search for (or 'quit' to exit): ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        // Binary search for record by name
        i = 0;
        j = num_records - 1;

        while (i <= j) {
            int mid = (i + j) / 2;
            int cmp = strcmp(name, index[mid].key);

            if (cmp == 0) {
                printf("Name: %s    Phone: %s\n", records[index[mid].record_num].name, records[index[mid].record_num].phone);
                break;
            } else if (cmp < 0) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        if (i > j) {
            printf("Record not found.\n");
        }
    }
}

int compare_strings(const void *a, const void *b) {
    const struct index_entry *ia = (const struct index_entry *)a;
    const struct index_entry *ib = (const struct index_entry *)b;
    return strcmp(ia->key, ib->key);
}