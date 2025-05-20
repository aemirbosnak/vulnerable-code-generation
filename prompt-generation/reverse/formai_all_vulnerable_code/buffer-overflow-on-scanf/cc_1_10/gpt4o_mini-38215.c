//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    int id;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function prototypes
void addRecord(Database* db);
void displayRecords(Database* db);
int searchByName(Database* db, const char* name);
void displaySearchResult(Database* db, int index);

int main() {
    Database db;
    db.count = 0;
    int choice;

    printf("🌟 Welcome to the Cheerful Database Indexing System! 🌟\n");

    do {
        printf("\nChoose an option:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline character from the input buffer

        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3: {
                char name[NAME_LENGTH];
                printf("Enter the name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character
                int index = searchByName(&db, name);
                displaySearchResult(&db, index);
                break;
            }
            case 4:
                printf("🎉 Thank you for using the system! Have a sunny day! ☀️\n");
                break;
            default:
                printf("🚫 Invalid choice! Please try again. 🚫\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

void addRecord(Database* db) {
    if (db->count >= MAX_RECORDS) {
        printf("🌈 The database is full! Cannot add more records. 🌈\n");
        return;
    }

    Record newRecord;
    printf("🎈 Enter name: ");
    fgets(newRecord.name, NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0;  // Remove newline character

    printf("🎊 Enter age: ");
    scanf("%d", &newRecord.age);
    getchar();  // Clear newline character

    newRecord.id = db->count;
    db->records[db->count] = newRecord;
    db->count++;

    printf("🌟 Record added successfully! 🌟\n");
}

void displayRecords(Database* db) {
    printf("\n📚 Current Records in Database 📚\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d | Name: %s | Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    if (db->count == 0) {
        printf("✨ No records to display! ✨\n");
    }
}

int searchByName(Database* db, const char* name) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return i;  // Found
        }
    }
    return -1;  // Not found
}

void displaySearchResult(Database* db, int index) {
    if (index == -1) {
        printf("👀 Record not found! Try searching for a different name. 👀\n");
    } else {
        printf("🎉 Record Found! 🎉\n");
        printf("ID: %d | Name: %s | Age: %d\n", db->records[index].id, db->records[index].name, db->records[index].age);
    }
}