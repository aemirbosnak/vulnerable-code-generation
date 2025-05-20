//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function prototypes
void init_database(Database* db);
void add_record(Database* db, int id, const char* name, const char* email);
void display_records(Database* db);
void save_to_file(Database* db, const char* filename);
void load_from_file(Database* db, const char* filename);
void search_by_id(Database* db, int id);
void delete_record(Database* db, int id);
void clear_screen();

int main() {
    Database db;
    init_database(&db);

    int choice;
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];

    do {
        printf("\n--- Database Management System ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Search by ID\n");
        printf("6. Delete Record\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Email: ");
                scanf("%s", email);
                add_record(&db, id, name, email);
                break;
            case 2:
                display_records(&db);
                break;
            case 3:
                save_to_file(&db, "database.txt");
                break;
            case 4:
                load_from_file(&db, "database.txt");
                break;
            case 5:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_by_id(&db, id);
                break;
            case 6:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_record(&db, id);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice. Please select again.\n");
                break;
        }

        clear_screen();
    } while (choice != 0);

    return 0;
}

void init_database(Database* db) {
    db->count = 0;
}

void add_record(Database* db, int id, const char* name, const char* email) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strcpy(db->records[db->count].name, name);
        strcpy(db->records[db->count].email, email);
        db->count++;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void display_records(Database* db) {
    if (db->count == 0) {
        printf("No records to display!\n");
        return;
    }

    printf("\n--- Records in Database ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

void save_to_file(Database* db, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }
    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Records saved to %s successfully!\n", filename);
}

void load_from_file(Database* db, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }
    fread(db, sizeof(Database), 1, file);
    fclose(file);
    printf("Records loaded from %s successfully!\n", filename);
}

void search_by_id(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found! ID: %d, Name: %s, Email: %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
            return;
        }
    }
    printf("No record found with ID: %d\n", id);
}

void delete_record(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            // Shift records to the left
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record with ID: %d deleted successfully!\n", id);
            return;
        }
    }
    printf("No record found with ID: %d\n", id);
}

void clear_screen() {
    printf("\033[H\033[J");
}