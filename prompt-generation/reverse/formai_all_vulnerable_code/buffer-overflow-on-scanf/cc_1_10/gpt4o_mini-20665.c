//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3

typedef struct {
    char name[NAME_LENGTH];
    char age[AGE_LENGTH];
} Person;

typedef struct {
    Person records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addEntry(Database *db, const char *name, const char *age) {
    if (db->count < MAX_RECORDS) {
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        strncpy(db->records[db->count].age, age, AGE_LENGTH);
        db->count++;
        printf("Added: %s, Age: %s\n", name, age);
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void displayEntries(const Database *db) {
    if (db->count == 0) {
        printf("No records in the database yet! Let's add some happy faces!\n");
    } else {
        printf("\n--- Database Records ---\n");
        for (int i = 0; i < db->count; i++) {
            printf("Entry %d: Name: %s, Age: %s\n", i + 1, db->records[i].name, db->records[i].age);
        }
        printf("------------------------\n");
    }
}

void searchEntry(const Database *db, const char *name) {
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->records[i].name, name) == 0) {
            printf("Found: Name: %s, Age: %s\n", db->records[i].name, db->records[i].age);
            return;
        }
    }
    printf("No record found for %s.\n", name);
}

void deleteEntry(Database *db, const char *name) {
    int i;
    for (i = 0; i < db->count; i++) {
        if (strcasecmp(db->records[i].name, name) == 0) {
            break;
        }
    }
    if (i < db->count) {
        for (int j = i; j < db->count - 1; j++) {
            db->records[j] = db->records[j + 1];
        }
        db->count--;
        printf("Deleted record for %s. Goodbye and good vibes!\n", name);
    } else {
        printf("No record found for %s to delete.\n", name);
    }
}

void clearDatabase(Database *db) {
    db->count = 0;
    printf("All records cleared! The database is now a clean slate! 😊\n");
}

int main() {
    Database db;
    initializeDatabase(&db);

    int choice;
    char name[NAME_LENGTH];
    char age[AGE_LENGTH];

    do {
        printf("\n--- Welcome to the Happy Database! ---\n");
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Clear Database\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                printf("Enter Age: ");
                fgets(age, AGE_LENGTH, stdin);
                age[strcspn(age, "\n")] = 0;   // Remove newline
                addEntry(&db, name, age);
                break;
            case 2:
                displayEntries(&db);
                break;
            case 3:
                printf("Enter Name to Search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                searchEntry(&db, name);
                break;
            case 4:
                printf("Enter Name to Delete: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                deleteEntry(&db, name);
                break;
            case 5:
                clearDatabase(&db);
                break;
            case 6:
                printf("Thank you for using the Happy Database! Goodbye! 🌈\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 to 6.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}