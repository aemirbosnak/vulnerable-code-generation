//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum number of records that can be stored */
#define MAX_RECORDS 100

/* Define the length of each field */
#define FIELD1_LEN 20
#define FIELD2_LEN 20
#define FIELD3_LEN 20

/* Define the record structure */
typedef struct record {
    int id;
    char field1[FIELD1_LEN+1];
    char field2[FIELD2_LEN+1];
    char field3[FIELD3_LEN+1];
} Record;

/* Declare the functions */
void add_record(Record records[MAX_RECORDS], int *n_records);
void print_records(Record records[MAX_RECORDS], int n_records);
void write_to_file(Record records[MAX_RECORDS], int n_records);
void read_from_file(Record records[MAX_RECORDS], int *n_records);

/* Declare the global variable to keep track of the number of records */
int n_records = 0;

int main() {
    Record records[MAX_RECORDS];

    /* Read records from file if it exists */
    read_from_file(records, &n_records);

    /* Display the menu and handle user input */
    while (1) {
        printf("\n1. Add Record\n");
        printf("2. Print Records\n");
        printf("3. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record(records, &n_records);
                break;
            case 2:
                print_records(records, n_records);
                break;
            case 3:
                /* Write records to file and exit */
                write_to_file(records, n_records);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}

void add_record(Record records[MAX_RECORDS], int *n_records) {
    /* Check if the maximum number of records has been reached */
    if (*n_records == MAX_RECORDS) {
        printf("Maximum number of records reached.\n");
        return;
    }

    /* Add a new record */
    Record new_record;

    printf("\nEnter the ID: ");
    scanf("%d", &new_record.id);

    printf("Enter Field 1: ");
    scanf("%s", new_record.field1);

    printf("Enter Field 2: ");
    scanf("%s", new_record.field2);

    printf("Enter Field 3: ");
    scanf("%s", new_record.field3);

    records[*n_records] = new_record;
    (*n_records)++;

    printf("Record added successfully.\n");
}

void print_records(Record records[MAX_RECORDS], int n_records) {
    /* Check if any records exist */
    if (n_records == 0) {
        printf("No records found.\n");
        return;
    }

    /* Display all records */
    printf("\nID\tFIELD 1\t\tFIELD 2\t\tFIELD 3\n");
    for (int i = 0; i < n_records; i++) {
        printf("%d\t%-20s\t%-20s\t%-20s\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }
}

void write_to_file(Record records[MAX_RECORDS], int n_records) {
    FILE *fp = fopen("records.txt", "w");
    if (fp == NULL) {
        printf("Error writing to file.\n");
        return;
    }

    /* Write each record to file */
    for (int i = 0; i < n_records; i++) {
        fprintf(fp, "%d %s %s %s\n", records[i].id, records[i].field1, records[i].field2, records[i].field3);
    }

    fclose(fp);
    printf("Records written to file successfully.\n");
}

void read_from_file(Record records[MAX_RECORDS], int *n_records) {
    FILE *fp = fopen("records.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    /* Read each record from file */
    while (!feof(fp)) {
        Record new_record;

        fscanf(fp, "%d %s %s %s\n", &new_record.id, new_record.field1, new_record.field2, new_record.field3);

        records[*n_records] = new_record;
        (*n_records)++;
    }

    fclose(fp);
    printf("Records read from file successfully.\n");
}