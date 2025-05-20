//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LEN 30
#define DESC_LEN 100

typedef struct {
    int id;
    char name[NAME_LEN];
    char description[DESC_LEN];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void init_database(Database *db) {
    db->count = 0;
}

void add_record(Database *db, const char *name, const char *description) {
    if (db->count >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }
    Record *rec = &db->records[db->count];
    rec->id = db->count + 1;
    strncpy(rec->name, name, NAME_LEN);
    strncpy(rec->description, description, DESC_LEN);
    db->count++;
    printf("Added Record ID %d: %s\n", rec->id, rec->name);
}

void display_records(const Database *db) {
    printf("\nDisplaying Records:\n");
    printf("ID\tName\t\tDescription\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%-15s\t%s\n", db->records[i].id, db->records[i].name, db->records[i].description);
    }
}

void delete_record(Database *db, int id) {
    if (id < 1 || id > db->count) {
        printf("Error: Record ID %d does not exist.\n", id);
        return;
    }
    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    printf("Deleted Record ID %d.\n", id);
}

void search_record(const Database *db, const char *name) {
    printf("\nSearching for records with name '%s':\n", name);
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->records[i].name, name) == 0) {
            found = 1;
            printf("Found Record ID %d: %s\n", db->records[i].id, db->records[i].description);
        }
    }
    if (!found) {
        printf("No records found matching '%s'.\n", name);
    }
}

void menu() {
    printf("\nDatabase Menu:\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Search Record by Name\n");
    printf("5. Exit\n");
}

int main() {
    Database db;
    init_database(&db);
    
    int choice;
    char name[NAME_LEN], description[DESC_LEN];
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter description: ");
                getchar(); // Consume newline left by previous scanf
                fgets(description, DESC_LEN, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                add_record(&db, name, description);
                break;
            case 2:
                display_records(&db);
                break;
            case 3:
                printf("Enter Record ID to delete: ");
                int id;
                scanf("%d", &id);
                delete_record(&db, id);
                break;
            case 4:
                printf("Enter name to search: ");
                scanf("%s", name);
                search_record(&db, name);
                break;
            case 5:
                printf("Exiting the database program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}