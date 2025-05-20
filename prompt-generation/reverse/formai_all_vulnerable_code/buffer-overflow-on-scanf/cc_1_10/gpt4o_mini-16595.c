//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define FIELD_SIZE 50

typedef struct {
    int id;
    char name[FIELD_SIZE];
    char email[FIELD_SIZE];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initDatabase(Database* db) {
    db->count = 0;
}

void addRecord(Database* db, int id, const char* name, const char* email) {
    if (db->count < MAX_RECORDS) {
        Record* newRecord = &db->records[db->count];
        newRecord->id = id;
        strncpy(newRecord->name, name, FIELD_SIZE - 1);
        newRecord->name[FIELD_SIZE - 1] = '\0';
        strncpy(newRecord->email, email, FIELD_SIZE - 1);
        newRecord->email[FIELD_SIZE - 1] = '\0';
        db->count++;
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

void displayRecords(Database* db) {
    if (db->count == 0) {
        printf("No records found.\n");
        return;
    }
    printf("ID\tName\t\tEmail\n");
    printf("===============================\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%s\n",
               db->records[i].id,
               db->records[i].name,
               db->records[i].email);
    }
}

void searchRecord(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found:\nID: %d\nName: %s\nEmail: %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void updateRecord(Database* db, int id, const char* name, const char* email) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            strncpy(db->records[i].name, name, FIELD_SIZE - 1);
            db->records[i].name[FIELD_SIZE - 1] = '\0';
            strncpy(db->records[i].email, email, FIELD_SIZE - 1);
            db->records[i].email[FIELD_SIZE - 1] = '\0';
            printf("Record with ID %d updated.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void deleteRecord(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            // Shift records left to fill the gap
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

int main() {
    Database db;
    initDatabase(&db);
    
    int choice, id;
    char name[FIELD_SIZE], email[FIELD_SIZE];

    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
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
                addRecord(&db, id, name, email);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecord(&db, id);
                break;
            case 4:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Name: ");
                scanf("%s", name);
                printf("Enter new Email: ");
                scanf("%s", email);
                updateRecord(&db, id, name, email);
                break;
            case 5:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(&db, id);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}