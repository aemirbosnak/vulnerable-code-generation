//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void addRecord(Database *db, int id, const char *name) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        db->count++;
        printf("Record added: %d, %s\n", id, name);
    } else {
        printf("Database is full - we ran out of space faster than an elephant in a tutu!\n");
    }
}

void listRecords(Database *db) {
    printf("\nListing Records - Get ready for a wild ride:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Record %d: [id: %d, name: %s]\n", i + 1, db->records[i].id, db->records[i].name);
    }
}

void findRecord(Database *db, int id) {
    printf("\nSearching for ID %d. Fingers crossed!\n", id);
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Found Record: [id: %d, name: %s] - It's a match made in database heaven!\n", id, db->records[i].name);
            return;
        }
    }
    printf("Record with ID %d not found. It's gone like a sock in the dryer!\n", id);
}

void deleteRecord(Database *db, int id) {
    printf("\nAttempting to delete Record with ID %d... A sad, yet necessary task!\n", id);
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Deleting Record: [id: %d, name: %s] - Bye bye, buddy!\n", id, db->records[i].name);
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            return;
        }
    }
    printf("Can't delete. Record with ID %d not found. It's like trying to delete that last slice of pizza when no one is looking!\n", id);
}

void sillyMenu() {
    printf("Welcome to the Silly Database Indexing System!\n");
    printf("Options:\n");
    printf("1. Add Record\n");
    printf("2. List Records\n");
    printf("3. Find Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit (Because all good things must come to an end!)\n");
}

int main() {
    Database db = {.count = 0};
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        sillyMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID and Name (separated by space): ");
                scanf("%d %s", &id, name);
                addRecord(&db, id, name);
                break;
            case 2:
                listRecords(&db);
                break;
            case 3:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                findRecord(&db, id);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(&db, id);
                break;
            case 5:
                printf("Exiting the Silly Database. May your data be forever safe!\n");
                exit(0);
            default:
                printf("Oops! Invalid option. Try again and maybe consult a magic eight ball!\n");
        }
    }
    return 0;
}