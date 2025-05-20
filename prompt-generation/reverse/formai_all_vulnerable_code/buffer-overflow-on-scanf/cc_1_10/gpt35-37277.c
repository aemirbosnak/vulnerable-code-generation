//FormAI DATASET v1.0 Category: Database simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELDS 10

typedef struct record {
    int id;
    char fields[MAX_FIELDS][50];
} Record;

typedef struct database {
    int num_records;
    Record records[MAX_RECORDS];
} Database;

void print_record(Record* record) {
    printf("%d\t", record->id);
    for (int i = 0; i < MAX_FIELDS; i++) {
        printf("%s\t", record->fields[i]);
    }
    printf("\n");
}

void print_database(Database* database) {
    printf("ID\tFIELD1\tFIELD2\tFIELD3\tFIELD4\tFIELD5\tFIELD6\tFIELD7\tFIELD8\tFIELD9\tFIELD10\n");
    for (int i = 0; i < database->num_records; i++) {
        print_record(&database->records[i]);
    }
}

void insert_record(Database* database) {
    if (database->num_records == MAX_RECORDS) {
        printf("Error: maximum number of records reached\n");
        return;
    }

    Record* new_record = &database->records[database->num_records];
    new_record->id = database->num_records + 1;

    printf("Enter field 1: ");
    scanf("%s", new_record->fields[0]);

    printf("Enter field 2: ");
    scanf("%s", new_record->fields[1]);

    printf("Enter field 3: ");
    scanf("%s", new_record->fields[2]);

    printf("Enter field 4: ");
    scanf("%s", new_record->fields[3]);

    printf("Enter field 5: ");
    scanf("%s", new_record->fields[4]);

    printf("Enter field 6: ");
    scanf("%s", new_record->fields[5]);

    printf("Enter field 7: ");
    scanf("%s", new_record->fields[6]);

    printf("Enter field 8: ");
    scanf("%s", new_record->fields[7]);

    printf("Enter field 9: ");
    scanf("%s", new_record->fields[8]);

    printf("Enter field 10: ");
    scanf("%s", new_record->fields[9]);

    database->num_records++;
}

void search_records(Database* database) {
    char field[50];
    printf("Enter field to search: ");
    scanf("%s", field);

    for (int i = 0; i < database->num_records; i++) {
        Record* record = &database->records[i];
        for (int j = 0; j < MAX_FIELDS; j++) {
            if (strcmp(record->fields[j], field) == 0) {
                print_record(record);
                break;
            }
        }
    }
}

int main() {
    int choice;
    Database database = {0};

    while (1) {
        printf("1. Insert record\n");
        printf("2. Search records\n");
        printf("3. Print database\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_record(&database);
                break;
            case 2:
                search_records(&database);
                break;
            case 3:
                print_database(&database);
                break;
            case 4:
                return 0;
            default:
                printf("Error: invalid choice\n");
                break;
        }
    }
}