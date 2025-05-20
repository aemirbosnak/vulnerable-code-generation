//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int size;
} Database;

void initialize_database(Database *db) {
    db->size = 0;
}

void add_record(Database *db, int id, const char *name, int age) {
    if (db->size >= MAX_RECORDS) {
        printf("Database full. Cannot add more records.\n");
        return;
    }
    db->records[db->size].id = id;
    strncpy(db->records[db->size].name, name, MAX_NAME_LENGTH);
    db->records[db->size].age = age;
    db->size++;
    printf("Record added: ID=%d, Name=%s, Age=%d\n", id, name, age);
}

void delete_record(Database *db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->size - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->size--;
            printf("Record with ID=%d deleted successfully.\n", id);
            return;
        }
    }
    printf("Record with ID=%d not found.\n", id);
}

void display_database(const Database *db) {
    if (db->size == 0) {
        printf("Database is empty.\n");
        return;
    }
    printf("\nDisplaying Database Records:\n");
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id,
               db->records[i].name, db->records[i].age);
    }
}

void search_record(const Database *db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID=%d, Name=%s, Age=%d\n", id,
                   db->records[i].name, db->records[i].age);
            return;
        }
    }
    printf("Record with ID=%d not found.\n", id);
}

int main() {
    Database db;
    initialize_database(&db);
    
    int choice, id, age;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Delete Record\n");
        printf("3. Display All Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                add_record(&db, id, name, age);
                break;

            case 2:
                printf("Enter ID of record to delete: ");
                scanf("%d", &id);
                delete_record(&db, id);
                break;

            case 3:
                display_database(&db);
                break;

            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_record(&db, id);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}