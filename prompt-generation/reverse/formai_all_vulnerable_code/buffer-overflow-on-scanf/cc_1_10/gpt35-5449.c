//FormAI DATASET v1.0 Category: Database simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 20
#define MAX_NAME_LENGTH 20

struct Record {
    char name[MAX_NAME_LENGTH];
    int age;
    char address[50];
};

struct Database {
    struct Record records[MAX_RECORDS];
    int num_records;
};

void init_database(struct Database *db) {
    db->num_records = 0;
}

void add_record(struct Database *db, char *name, int age, char *address) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: database is full.\n");
        return;
    }

    struct Record *rec = &db->records[db->num_records];
    strncpy(rec->name, name, MAX_NAME_LENGTH);
    rec->name[MAX_NAME_LENGTH-1] = '\0';
    rec->age = age;
    strncpy(rec->address, address, 50);
    rec->address[49] = '\0';
    db->num_records++;
}

void delete_record(struct Database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            for (int j = i+1; j < db->num_records; j++) {
                db->records[j-1] = db->records[j];
            }
            db->num_records--;
            break;
        }
    }
}

void print_database(struct Database *db) {
    printf("Name\tAge\tAddress\n");
    for (int i = 0; i < db->num_records; i++) {
        struct Record *rec = &db->records[i];
        printf("%s\t%d\t%s\n", rec->name, rec->age, rec->address);
    }
}

void menu() {
    printf("Welcome to Post-Apocalyptic Database System\n");
    printf("1. Add record\n");
    printf("2. Delete record\n");
    printf("3. Print database\n");
    printf("4. Exit\n");
}

int main() {
    struct Database db;
    init_database(&db);

    char name[MAX_NAME_LENGTH];
    int age;
    char address[50];
    int choice;

    do {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter address: ");
                scanf("%s", address);
                add_record(&db, name, age, address);
                break;

            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                delete_record(&db, name);
                break;

            case 3:
                print_database(&db);
                break;

            case 4: // Do nothing
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
        printf("\n");
    } while (choice != 4);

    return EXIT_SUCCESS;
}