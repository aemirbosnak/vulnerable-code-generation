//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define INDEX_FILE "database.index"
#define RECORDS_FILE "database.records"

#define MAX_STRING_LENGTH 100
#define MAX_RECORDS 100

struct Record {
    int id;
    char name[MAX_STRING_LENGTH];
    char address[MAX_STRING_LENGTH];
    char phone[MAX_STRING_LENGTH];
};

int main() {
    FILE* index_file = fopen(INDEX_FILE, "w");
    FILE* records_file = fopen(RECORDS_FILE, "w");

    if (!index_file || !records_file) {
        printf("Error opening files.\n");
        return 1;
    }

    int record_count = 0;
    struct Record records[MAX_RECORDS];

    // Prompt user to enter records
    printf("Enter records (up to %d, type \"exit\" when done):\n", MAX_RECORDS);
    char input[MAX_STRING_LENGTH];
    while (record_count < MAX_RECORDS) {
        printf("Record %d:\nID: ", record_count + 1);
        fgets(input, MAX_STRING_LENGTH, stdin);
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        records[record_count].id = atoi(input);
        printf("Name: ");
        fgets(records[record_count].name, MAX_STRING_LENGTH, stdin);
        printf("Address: ");
        fgets(records[record_count].address, MAX_STRING_LENGTH, stdin);
        printf("Phone: ");
        fgets(records[record_count].phone, MAX_STRING_LENGTH, stdin);
        fprintf(records_file, "%d;%s;%s;%s", records[record_count].id, records[record_count].name, records[record_count].address, records[record_count].phone);
        record_count++;
    }

    // Write index to file
    for (int i = 0; i < record_count; i++) {
        fprintf(index_file, "%d;%d\n", records[i].id, i);
    }

    // Close files
    fclose(index_file);
    fclose(records_file);

    // Prompt user to search records
    printf("Enter an ID to search for:\n");
    fgets(input, MAX_STRING_LENGTH, stdin);
    int search_id = atoi(input);

    // Read index and find matching record
    FILE* index_file_read = fopen(INDEX_FILE, "r");
    if (!index_file_read) {
        printf("Error opening index file.\n");
        return 1;
    }

    int found = 0;
    int record_index;
    while (!feof(index_file_read)) {
        int id;
        fscanf(index_file_read, "%d;%d\n", &id, &record_index);
        if (id == search_id) {
            found = 1;
            break;
        }
    }

    // Print matching record
    if (found) {
        FILE* records_file_read = fopen(RECORDS_FILE, "r");
        if (!records_file_read) {
            printf("Error opening records file.\n");
            return 1;
        }

        struct Record record;
        fseek(records_file_read, record_index * sizeof(struct Record), SEEK_SET);
        fread(&record, sizeof(struct Record), 1, records_file_read);

        printf("%d;%s;%s;%s", record.id, record.name, record.address, record.phone);

        fclose(records_file_read);
    } else {
        printf("Record not found.\n");
    }

    fclose(index_file_read);

    return 0;
}