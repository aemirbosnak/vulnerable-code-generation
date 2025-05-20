//FormAI DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Record;

int read_choice();
void handle_choice(int choice, Record* db);
void add_record(Record* db, int* num_records);
void delete_record(Record* db, int* num_records);
void search_record(Record* db, int num_records);
void print_all_records(Record* db, int num_records);

int main() {
    Record database[MAX_RECORDS];
    int num_records = 0;
    int choice;

    do {
        printf("\n1. Add record\n2. Delete record\n3. Search record\n4. Print all records\n5. Exit\n");
        choice = read_choice();
        handle_choice(choice, database);
    } while (choice != 5);

    return 0;
}

int read_choice() {
    char input[10];

    printf("Enter your choice: ");
    fgets(input, 10, stdin);
    return atoi(input);
}

void handle_choice(int choice, Record* db) {
    int num_records = 0;

    switch (choice) {
        case 1:
            add_record(db, &num_records);
            break;
        case 2:
            delete_record(db, &num_records);
            break;
        case 3:
            search_record(db, num_records);
            break;
        case 4:
            print_all_records(db, num_records);
            break;
        case 5:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
}

void add_record(Record* db, int* num_records) {
    if (*num_records >= MAX_RECORDS) {
        printf("Database full!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &(db[*num_records].id));

    printf("Enter name: ");
    scanf("%s", db[*num_records].name);

    (*num_records)++;
}

void delete_record(Record* db, int* num_records) {
    int id, i;

    printf("Enter ID of record to delete: ");
    scanf("%d", &id);

    for (i = 0; i < *num_records; i++) {
        if (db[i].id == id) {
            memmove(&db[i], &db[i+1], (*num_records-i-1)*sizeof(Record));
            (*num_records)--;
            printf("Record deleted successfully.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

void search_record(Record* db, int num_records) {
    int id, i;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < num_records; i++) {
        if (db[i].id == id) {
            printf("Record found:\nID: %d\nName: %s\n", db[i].id, db[i].name);
            return;
        }
    }

    printf("Record not found.\n");
}

void print_all_records(Record* db, int num_records) {
    int i;

    printf("ID\tName\n");
    for (i = 0; i < num_records; i++) {
        printf("%d\t%s\n", db[i].id, db[i].name);
    }
}