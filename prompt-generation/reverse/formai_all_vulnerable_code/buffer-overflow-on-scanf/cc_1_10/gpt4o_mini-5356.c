//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
    printf("🎉 Database initialized! Ready for some fun! 🎉\n");
}

void addRecord(Database *db) {
    if (db->count < MAX_RECORDS) {
        printf("📥 Adding a new record...\n");
        Record newRecord;
        printf("Enter ID: ");
        scanf("%d", &newRecord.id);
        printf("Enter Name: ");
        scanf(" %[^\n]s", newRecord.name); // Read string with spaces

        db->records[db->count++] = newRecord;
        printf("🌟 Record added successfully! 🌟\n");
    } else {
        printf("⚠️ Database is full! Cannot add more records. ⚠️\n");
    }
}

void searchRecord(Database *db) {
    int searchID;
    printf("🔍 Enter ID to search: ");
    scanf("%d", &searchID);
    int found = 0;

    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == searchID) {
            printf("🎊 Record found! ID: %d, Name: %s 🎊\n", db->records[i].id, db->records[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("😢 No record found with ID: %d 😢\n", searchID);
    }
}

void displayRecords(Database *db) {
    if (db->count == 0) {
        printf("📁 No records to display! 📁\n");
    } else {
        printf("📜 Current Records: 📜\n");
        for (int i = 0; i < db->count; i++) {
            printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
        }
    }
}

void menu() {
    printf("\n🎈 Welcome to the Happy Database Indexing System! 🎈\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Display All Records\n");
    printf("4. Exit\n");
    printf("Choose an option (1-4): ");
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                searchRecord(&db);
                break;
            case 3:
                displayRecords(&db);
                break;
            case 4:
                printf("🎉 Thank you for using the Happy Database! Goodbye! 🎉\n");
                break;
            default:
                printf("⚠️ Invalid choice! Please select a valid option. ⚠️\n");
        }
    } while (choice != 4);

    return 0;
}