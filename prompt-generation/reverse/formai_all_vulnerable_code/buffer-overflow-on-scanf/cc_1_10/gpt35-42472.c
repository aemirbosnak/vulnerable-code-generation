//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RECORDS 100

struct record {
    int id;
    char name[20];
    char address[50];
    float salary;
};

struct database {
    int num_records;
    struct record records[MAX_RECORDS];
};

void add_record(struct database *db) {
    if (db->num_records == MAX_RECORDS) {
        printf("Error: database is full.\n");
        return;
    }
    struct record *new_record = &db->records[db->num_records];
    printf("Enter the following information:\n");
    printf("ID: ");
    scanf("%d", &new_record->id);
    printf("Name: ");
    scanf("%s", new_record->name);
    printf("Address: ");
    scanf("%s", new_record->address);
    printf("Salary: ");
    scanf("%f", &new_record->salary);
    db->num_records++;
}

void print_record(struct record *record) {
    printf("ID: %d\tName: %s\tAddress: %s\tSalary: %.2f\n",
           record->id, record->name, record->address, record->salary);
}

void print_database(struct database *db) {
    printf("Printing all records in the database:\n");
    for (int i = 0; i < db->num_records; i++) {
        print_record(&db->records[i]);
    }
}

int main() {
    struct database db = {0};
    char input[10];
    while (1) {
        printf("Enter a command: (add/print/quit)\n");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            add_record(&db);
        } else if (strcmp(input, "print") == 0) {
            print_database(&db);
        } else if (strcmp(input, "quit") == 0) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Error: unrecognized command.\n");
        }
    }
    return 0;
}