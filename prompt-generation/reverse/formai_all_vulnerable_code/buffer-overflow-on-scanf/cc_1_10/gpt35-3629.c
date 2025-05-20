//FormAI DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

void initialize_database(struct database *db) {
    db->num_records = 0;
}

bool add_record(struct database *db, struct record r) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records++] = r;
        return true;
    }
    return false;
}

void print_record(struct record r) {
    printf("ID: %d\nName: %s\nAge: %d\n", r.id, r.name, r.age);
}

void print_database(struct database db) {
    for (int i = 0; i < db.num_records; i++) {
        printf("Record %d:\n", i+1);
        print_record(db.records[i]);
        printf("\n");
    }
}

struct record get_record_from_input() {
    struct record r;
    printf("Enter ID: ");
    scanf("%d", &r.id);
    printf("Enter name: ");
    scanf("%s", r.name);
    printf("Enter age: ");
    scanf("%d", &r.age);
    return r;
}

void menu() {
    printf("1. Add record\n");
    printf("2. View database\n");
    printf("3. Exit\n");
}

int main() {
    struct database db;
    initialize_database(&db);
    
    int choice;
    bool exit = false;
    while (!exit) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Enter the record details:\n");
                struct record r = get_record_from_input();
                if (add_record(&db, r)) {
                    printf("Record added successfully!\n\n");
                }
                else {
                    printf("Database is full. Cannot add record.\n\n");
                }
                break;
            }
            case 2: {
                printf("Database contents:\n");
                print_database(db);
                printf("\n");
                break;
            }
            case 3: {
                printf("Goodbye!\n");
                exit = true;
                break;
            }
            default: {
                printf("Invalid choice. Please try again.\n\n");
                break;
            }
        }
    }
    
    return 0;
}