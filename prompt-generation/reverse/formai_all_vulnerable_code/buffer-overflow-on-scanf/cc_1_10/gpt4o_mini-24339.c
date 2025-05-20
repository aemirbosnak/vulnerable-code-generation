//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database* db) {
    db->count = 0;
    printf("🎉 Database Initialized! Ready to store records! 🎉\n");
}

void addRecord(Database* db, int id, const char* name) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        db->count++;
        printf("✨ Record Added: [ID: %d, Name: %s] ✨\n", id, name);
    } else {
        printf("🚫 Database is full! Can't add more records. 🚫\n");
    }
}

void viewRecords(const Database* db) {
    printf("📜 Current Records:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
}

void updateRecord(Database* db, int id, const char* newName) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            strncpy(db->records[i].name, newName, NAME_LENGTH);
            printf("🎈 Record Updated: [ID: %d, New Name: %s] 🎈\n", id, newName);
            return;
        }
    }
    printf("❌ Record with ID %d not found! ❌\n", id);
}

void deleteRecord(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("🗑️ Record Deleted: [ID: %d, Name: %s] 🗑️\n", db->records[i].id, db->records[i].name);
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            return;
        }
    }
    printf("❌ Record with ID %d not found! ❌\n", id);
}

void searchRecord(const Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("🔍 Record Found: [ID: %d, Name: %s] 🔍\n", id, db->records[i].name);
            return;
        }
    }
    printf("❌ Record with ID %d not found! ❌\n", id);
}

int main() {
    Database db;

    initializeDatabase(&db);

    while (1) {
        printf("\n✨ Select an option:\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Search Record\n");
        printf("6. Exit\n");
        
        int choice;
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the integer input

        switch (choice) {
            case 1: {
                int id;
                char name[NAME_LENGTH];
                printf("Enter Record ID: ");
                scanf("%d", &id);
                getchar(); // Consume newline
                printf("Enter Record Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                addRecord(&db, id, name);
                break;
            }
            case 2:
                viewRecords(&db);
                break;
            case 3: {
                int id;
                char newName[NAME_LENGTH];
                printf("Enter Record ID to Update: ");
                scanf("%d", &id);
                getchar(); // Consume newline
                printf("Enter New Name: ");
                fgets(newName, NAME_LENGTH, stdin);
                newName[strcspn(newName, "\n")] = 0; // Remove newline
                updateRecord(&db, id, newName);
                break;
            }
            case 4: {
                int id;
                printf("Enter Record ID to Delete: ");
                scanf("%d", &id);
                deleteRecord(&db, id);
                break;
            }
            case 5: {
                int id;
                printf("Enter Record ID to Search: ");
                scanf("%d", &id);
                searchRecord(&db, id);
                break;
            }
            case 6:
                printf("🌈 Exiting... Have a wonderful day! 🌈\n");
                exit(0);
            default:
                printf("🤔 Invalid choice! Please select a valid option! 🤔\n");
        }
    }

    return 0;
}