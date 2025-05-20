//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10

typedef struct record {
    int id;
    char name[20];
    int age;
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Cannot add record, database is full!\n");
        return;
    }
    printf("Enter record ID: ");
    scanf("%d", &database[num_records].id);
    printf("Enter record name: ");
    scanf("%s", database[num_records].name);
    printf("Enter record age: ");
    scanf("%d", &database[num_records].age);
    num_records++;
    printf("Record added successfully!\n");
}

void display_record(int index) {
    printf("Record ID: %d\n", database[index].id);
    printf("Record name: %s\n", database[index].name);
    printf("Record age: %d\n", database[index].age);
}

void view_records() {
    if (num_records == 0) {
        printf("No records found in database!\n");
        return;
    }
    for (int i = 0; i < num_records; i++) {
        display_record(i);
    }
}

void search_record() {
    int record_id;
    printf("Enter record ID to search: ");
    scanf("%d", &record_id);
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == record_id) {
            display_record(i);
            return;
        }
    }
    printf("Record not found in database!\n");
}

void delete_record() {
    int record_id;
    printf("Enter record ID to delete: ");
    scanf("%d", &record_id);
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == record_id) {
            for (int j = i; j < num_records - 1; j++) {
                database[j] = database[j + 1];
            }
            num_records--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    printf("Record not found in database!\n");
}

int main() {
    int choice;
    printf("Welcome to the C database simulation!\n");
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add record\n");
        printf("2. View records\n");
        printf("3. Search record\n");
        printf("4. Delete record\n");
        printf("5. Exit\n");
        printf("Enter your selection: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                view_records();
                break;
            case 3:
                search_record();
                break;
            case 4:
                delete_record();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid selection!\n");
        }
    } while (choice != 5);
    return 0;
}