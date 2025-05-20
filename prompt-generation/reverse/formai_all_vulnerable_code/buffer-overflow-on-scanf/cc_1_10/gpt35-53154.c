//FormAI DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

typedef struct Record {
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

void add_record() {
    if (num_records >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    Record new_record;
    printf("Enter ID: ");
    scanf("%d", &new_record.id);
    printf("Enter name: ");
    scanf("%s", new_record.name);
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    printf("Enter address: ");
    scanf("%s", new_record.address);

    database[num_records] = new_record;
    num_records++;

    printf("Record added successfully.\n");
}

void print_record(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Age: %d\n", record.age);
    printf("Address: %s\n", record.address);
}

void search_record() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            print_record(database[i]);
            return;
        }
    }

    printf("Record not found.\n");
}

void delete_record() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    int i;
    for (i = 0; i < num_records; i++) {
        if (database[i].id == id) {
            int j;
            for (j = i; j < num_records - 1; j++) {
                database[j] = database[j + 1];
            }
            num_records--;
            printf("Record deleted successfully.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

void print_all_records() {
    int i;
    for (i = 0; i < num_records; i++) {
        print_record(database[i]);
        printf("\n");
    }
}

int main() {
    while (1) {
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Delete record\n");
        printf("4. Print all records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                print_all_records();
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\n");
    }

    return 0;
}