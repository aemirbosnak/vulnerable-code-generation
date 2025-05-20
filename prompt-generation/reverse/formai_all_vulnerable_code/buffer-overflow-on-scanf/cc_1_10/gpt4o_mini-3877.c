//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function prototypes
void initialize_database(Database *db);
void add_record(Database *db);
void display_records(Database *db);
void delete_record(Database *db);
int find_record(Database *db, int id);
void display_menu();
void clear_input_buffer();

int main() {
    Database db;
    initialize_database(&db);
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch (choice) {
            case 1:
                add_record(&db);
                break;
            case 2:
                display_records(&db);
                break;
            case 3:
                delete_record(&db);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void initialize_database(Database *db) {
    db->count = 0;
}

void add_record(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    Record new_record;
    new_record.id = db->count + 1; // Assigning a unique ID
    printf("Enter name: ");
    fgets(new_record.name, NAME_LENGTH, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = 0; // Remove newline
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    clear_input_buffer();

    db->records[db->count++] = new_record;
    printf("Record added successfully!\n");
}

void display_records(Database *db) {
    if (db->count == 0) {
        printf("No records found in the database.\n");
        return;
    }
    printf("\n--- Records in Database ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    printf("---------------------------\n");
}

void delete_record(Database *db) {
    int id;
    printf("Enter ID of the record to delete: ");
    scanf("%d", &id);
    clear_input_buffer();

    int index = find_record(db, id);
    if (index == -1) {
        printf("Record not found.\n");
        return;
    }

    for (int i = index; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    printf("Record deleted successfully!\n");
}

int find_record(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

void display_menu() {
    printf("\n--- Database Menu ---\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Exit\n");
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}