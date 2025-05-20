//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 30
#define MAX_EMAIL_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, int id, const char *name, const char *email) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH);
        strncpy(db->records[db->count].email, email, MAX_EMAIL_LENGTH);
        db->count++;
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void searchById(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID=%d, Name=%s, Email=%s\n",
                   db->records[i].id, db->records[i].name, db->records[i].email);
            return;
        }
    }
    printf("No record found with ID=%d\n", id);
}

void searchByName(Database *db, const char *name) {
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->records[i].name, name) == 0) {
            printf("Record found: ID=%d, Name=%s, Email=%s\n",
                   db->records[i].id, db->records[i].name, db->records[i].email);
            return;
        }
    }
    printf("No record found with Name=%s\n", name);
}

void deleteRecord(Database *db, int id) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record with ID=%d deleted successfully.\n", id);
            break;
        }
    }
    if (!found) {
        printf("No record found with ID=%d\n", id);
    }
}

void displayDatabase(Database *db) {
    printf("Displaying Database (%d records):\n", db->count);
    for (int i = 0; i < db->count; i++) {
        printf("ID=%d, Name=%s, Email=%s\n",
               db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

void menu() {
    printf("\n");
    printf("1. Add Record\n");
    printf("2. Search by ID\n");
    printf("3. Search by Name\n");
    printf("4. Delete Record\n");
    printf("5. Display All Records\n");
    printf("6. Exit\n");
}

int main() {
    Database db;
    initDatabase(&db);
    int choice;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int id;
            char name[MAX_NAME_LENGTH];
            char email[MAX_EMAIL_LENGTH];
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Email: ");
            scanf("%s", email);
            addRecord(&db, id, name, email);
        } else if (choice == 2) {
            int id;
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchById(&db, id);
        } else if (choice == 3) {
            char name[MAX_NAME_LENGTH];
            printf("Enter Name to search: ");
            scanf("%s", name);
            searchByName(&db, name);
        } else if (choice == 4) {
            int id;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteRecord(&db, id);
        } else if (choice == 5) {
            displayDatabase(&db);
        } else if (choice == 6) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}