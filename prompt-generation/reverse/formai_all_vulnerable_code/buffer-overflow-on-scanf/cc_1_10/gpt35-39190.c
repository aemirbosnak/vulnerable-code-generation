//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct record {
    int id;
    char name[20];
    int age;
};

struct database {
    struct record records[MAX_RECORDS];
    int num_records;
};

typedef struct database Database;

void add_record(Database* db) {
    if (db->num_records < MAX_RECORDS) {
        struct record new_record;
        printf("Enter ID: ");
        scanf("%d", &new_record.id);
        printf("Enter name : ");
        scanf("%s", new_record.name);
        printf("Enter age: ");
        scanf("%d", &new_record.age);
        db->records[db->num_records++] = new_record;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full!\n");
    }
}

void print_records(Database* db) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    printf("\n");
}

void print_menu() {
    printf("------MENU------\n");
    printf("1. Add record\n");
    printf("2. Print all records\n");
    printf("3. Exit\n");
}

int main() {
    Database my_db = {0};
    int choice = 0;
    while (choice != 3) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_record(&my_db);
                break;
            case 2:
                print_records(&my_db);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}