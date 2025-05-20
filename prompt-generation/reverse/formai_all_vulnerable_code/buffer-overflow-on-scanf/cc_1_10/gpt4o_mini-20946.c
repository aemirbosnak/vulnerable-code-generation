//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ID_LENGTH 10

typedef struct {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
} Student;

typedef struct {
    Student records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, const char *id, const char *name) {
    if (db->count < MAX_RECORDS) {
        strcpy(db->records[db->count].id, id);
        strcpy(db->records[db->count].name, name);
        db->count++;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

int searchRecord(Database *db, const char *id) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].id, id) == 0) {
            return i;
        }
    }
    return -1; // Record not found
}

void displayRecords(Database *db) {
    if (db->count == 0) {
        printf("No records found.\n");
    } else {
        printf("Student Records:\n");
        for (int i = 0; i < db->count; i++) {
            printf("ID: %s, Name: %s\n", db->records[i].id, db->records[i].name);
        }
    }
}

void menu() {
    printf("Database Menu:\n");
    printf("1. Add Record\n");
    printf("2. Search Record\n");
    printf("3. Display All Records\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Database db;
    initializeDatabase(&db);

    int choice;
    char id[ID_LENGTH];
    char name[NAME_LENGTH];

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                fgets(id, ID_LENGTH, stdin);
                id[strcspn(id, "\n")] = '\0'; // Remove newline character
                printf("Enter Student Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline character
                addRecord(&db, id, name);
                break;

            case 2:
                printf("Enter Student ID to search: ");
                fgets(id, ID_LENGTH, stdin);
                id[strcspn(id, "\n")] = '\0'; // Remove newline character

                int index = searchRecord(&db, id);
                if (index != -1) {
                    printf("Found Record: ID: %s, Name: %s\n", db.records[index].id, db.records[index].name);
                } else {
                    printf("Record not found.\n");
                }
                break;

            case 3:
                displayRecords(&db);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}