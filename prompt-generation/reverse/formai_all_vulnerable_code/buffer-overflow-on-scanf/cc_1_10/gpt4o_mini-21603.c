//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initDatabase(Database *db) {
    db->count = 0;
}

int addRecord(Database *db, const char *name, float score) {
    if (db->count >= MAX_RECORDS) {
        return -1; // Database full
    }
    
    db->records[db->count].id = db->count + 1;
    strncpy(db->records[db->count].name, name, NAME_LENGTH - 1);
    db->records[db->count].name[NAME_LENGTH - 1] = '\0'; // Safety
    db->records[db->count].score = score;
    db->count++;
    
    return 0; // Success
}

void displayRecords(const Database *db) {
    printf("ID\tName\t\tScore\n");
    printf("----------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%-15s\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].score);
    }
}

void sortRecords(Database *db) {
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = 0; j < db->count - i - 1; j++) {
            if (db->records[j].score < db->records[j + 1].score) {
                Record temp = db->records[j];
                db->records[j] = db->records[j + 1];
                db->records[j + 1] = temp;
            }
        }
    }
}

int findRecordById(const Database *db, int id, Record *result) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            *result = db->records[i];
            return 0; // Found
        }
    }
    return -1; // Not found
}

void deleteRecordById(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void menu() {
    printf("\n--- Database Management System ---\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Sort Records by Score\n");
    printf("4. Find Record by ID\n");
    printf("5. Delete Record by ID\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Database myDatabase;
    initDatabase(&myDatabase);
    int choice, id;
    char name[NAME_LENGTH];
    float score;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter score: ");
                scanf("%f", &score);
                if (addRecord(&myDatabase, name, score) == 0) {
                    printf("Record added successfully!\n");
                } else {
                    printf("Failed to add record. Database full.\n");
                }
                break;
            case 2:
                displayRecords(&myDatabase);
                break;
            case 3:
                sortRecords(&myDatabase);
                printf("Records sorted by score successfully.\n");
                break;
            case 4:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                Record found;
                if (findRecordById(&myDatabase, id, &found) == 0) {
                    printf("Record Found: ID=%d, Name=%s, Score=%.2f\n", found.id, found.name, found.score);
                } else {
                    printf("Record with ID %d not found.\n", id);
                }
                break;
            case 5:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecordById(&myDatabase, id);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}