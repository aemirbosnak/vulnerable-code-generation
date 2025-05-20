//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define AGE_LENGTH 3

typedef struct {
    char name[NAME_LENGTH];
    int age;
} Person;

typedef struct {
    Person records[MAX_RECORDS];
    int count;
} Database;

void initDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    Person newPerson;
    printf("Enter name: ");
    fgets(newPerson.name, NAME_LENGTH, stdin);
    newPerson.name[strcspn(newPerson.name, "\n")] = '\0';  // Remove newline character

    printf("Enter age: ");
    scanf("%d", &newPerson.age);
    getchar();  // Remove newline after scanf

    db->records[db->count++] = newPerson;
    printf("Record added successfully.\n");
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\n--- Records ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("Record %d: Name: %s, Age: %d\n", i + 1, db->records[i].name, db->records[i].age);
    }
}

void searchRecord(const Database *db) {
    char searchName[NAME_LENGTH];
    printf("Enter name to search: ");
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Remove newline character

    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].name, searchName) == 0) {
            printf("Record found: Name: %s, Age: %d\n", db->records[i].name, db->records[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found with the name %s.\n", searchName);
    }
}

void deleteRecord(Database *db) {
    char deleteName[NAME_LENGTH];
    printf("Enter name to delete: ");
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';  // Remove newline character

    int index = -1;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].name, deleteName) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < db->count - 1; i++) {
            db->records[i] = db->records[i + 1];
        }
        db->count--;
        printf("Record deleted successfully.\n");
    } else {
        printf("No record found with the name %s.\n", deleteName);
    }
}

void menu() {
    printf("\n--- Database Menu ---\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
}

int main() {
    Database db;
    initDatabase(&db);
    int choice;

    do {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar();  // Remove newline after scanf
        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                searchRecord(&db);
                break;
            case 4:
                deleteRecord(&db);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}