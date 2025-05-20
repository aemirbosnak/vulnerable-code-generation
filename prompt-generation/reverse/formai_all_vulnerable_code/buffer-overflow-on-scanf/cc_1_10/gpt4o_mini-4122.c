//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: light-weight
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

typedef struct {
    int ids[MAX_RECORDS];
    int count;
} Index;

void initDatabase(Database* db) {
    db->count = 0;
}

void initIndex(Index* index) {
    index->count = 0;
}

void addRecord(Database* db, Index* index, int id, const char* name) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    db->records[db->count].id = id;
    strncpy(db->records[db->count].name, name, NAME_LENGTH);
    index->ids[index->count] = db->count; // Store index
    index->count++;
    db->count++;
    printf("Record added: %d - %s\n", id, name);
}

void searchRecord(Database* db, Index* index, int id) {
    for (int i = 0; i < index->count; i++) {
        if (db->records[index->ids[i]].id == id) {
            printf("Record found: %d - %s\n", db->records[index->ids[i]].id, db->records[index->ids[i]].name);
            return;
        }
    }
    printf("Record with ID %d does not exist.\n", id);
}

void deleteRecord(Database* db, Index* index, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Deleting Record: %d - %s\n", db->records[i].id, db->records[i].name);
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift records to delete
            }
            db->count--;
            // Update index by removing the deleted record index
            for (int k = 0; k < index->count; k++) {
                if (index->ids[k] == i) {
                    for (int l = k; l < index->count - 1; l++) {
                        index->ids[l] = index->ids[l + 1];
                    }
                    index->count--;
                    break;
                }
            }
            return;
        }
    }
    printf("Record with ID %d does not exist. Nothing deleted.\n", id);
}

void displayRecords(Database* db) {
    printf("Database Records:\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d - %s\n", db->records[i].id, db->records[i].name);
    }
}

int main() {
    Database db;
    Index index;

    initDatabase(&db);
    initIndex(&index);

    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Search Record\n");
        printf("3. Delete Record\n");
        printf("4. Display all Records\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addRecord(&db, &index, id, name);
                break;
            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecord(&db, &index, id);
                break;
            case 3:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecord(&db, &index, id);
                break;
            case 4:
                displayRecords(&db);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}