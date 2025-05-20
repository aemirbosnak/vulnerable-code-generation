//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initialize_db(Database *db) {
    db->count = 0;
}

int add_record(Database *db, const char *name, const char *email) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full, cannot add more records.\n");
        return -1;
    }
    Record new_record;
    new_record.id = db->count + 1; // ID starts from 1
    strncpy(new_record.name, name, NAME_LENGTH);
    strncpy(new_record.email, email, EMAIL_LENGTH);
    
    db->records[db->count] = new_record;
    db->count++;
    printf("Record added: %d, %s, %s\n", new_record.id, new_record.name, new_record.email);
    return new_record.id;
}

void display_records(const Database *db) {
    if (db->count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("ID\tName\t\tEmail\n");
    printf("------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

int delete_record(Database *db, int id) {
    if (id < 1 || id > db->count) {
        printf("Record with ID %d not found.\n", id);
        return -1;
    }
    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    printf("Record with ID %d deleted.\n", id);
    return 0;
}

void search_record(const Database *db, const char *email) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].email, email) == 0) {
            printf("Record found: %d, %s, %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
            return;
        }
    }
    printf("No record found with email: %s\n", email);
}

int main() {
    Database db;
    initialize_db(&db);
    int choice;
    char name[NAME_LENGTH], email[EMAIL_LENGTH];
    
    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Search Record by Email\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf(" %[^\n]", name);
                printf("Enter email: ");
                scanf(" %[^\n]", email);
                add_record(&db, name, email);
                break;
            case 2:
                display_records(&db);
                break;
            case 3:
                printf("Enter record ID to delete: ");
                int id;
                scanf("%d", &id);
                delete_record(&db, id);
                break;
            case 4:
                printf("Enter email to search: ");
                scanf(" %[^\n]", email);
                search_record(&db, email);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}