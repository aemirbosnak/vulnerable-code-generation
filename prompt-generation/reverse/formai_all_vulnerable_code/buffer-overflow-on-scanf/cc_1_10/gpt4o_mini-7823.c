//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DATABASE_FILE "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float score;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int totalRecords;
} Database;

void initializeDatabase(Database *db) {
    db->totalRecords = 0;
}

void addRecord(Database *db, int id, const char *name, float score) {
    if (db->totalRecords < MAX_RECORDS) {
        db->records[db->totalRecords].id = id;
        strncpy(db->records[db->totalRecords].name, name, NAME_LENGTH);
        db->records[db->totalRecords].score = score;
        db->totalRecords++;
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

void saveToDatabase(Database *db) {
    FILE *file = fopen(DATABASE_FILE, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < db->totalRecords; i++) {
        fprintf(file, "%d,%s,%f\n", db->records[i].id, db->records[i].name, db->records[i].score);
    }
    fclose(file);
}

void loadFromDatabase(Database *db) {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        printf("No database file found. Starting fresh.\n");
        return;
    }
    db->totalRecords = 0;
    while (fscanf(file, "%d,%49[^,],%f\n", &db->records[db->totalRecords].id, db->records[db->totalRecords].name, &db->records[db->totalRecords].score) == 3) {
        db->totalRecords++;
    }
    fclose(file);
}

void displayRecords(const Database *db) {
    printf("ID\tName\t\tScore\n");
    printf("----------------------------\n");
    for (int i = 0; i < db->totalRecords; i++) {
        printf("%d\t%-15s\t%f\n", db->records[i].id, db->records[i].name, db->records[i].score);
    }
}

int compareRecords(const void *a, const void *b) {
    return ((Record *)a)->score - ((Record *)b)->score;
}

void sortRecords(Database *db) {
    qsort(db->records, db->totalRecords, sizeof(Record), compareRecords);
}

void searchRecord(const Database *db, int id) {
    for (int i = 0; i < db->totalRecords; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID=%d, Name=%s, Score=%f\n", db->records[i].id, db->records[i].name, db->records[i].score);
            return;
        }
    }
    printf("Record with ID=%d not found.\n", id);
}

int main() {
    Database db;
    initializeDatabase(&db);
    loadFromDatabase(&db);
    
    int choice, id;
    char name[NAME_LENGTH];
    float score;

    do {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Sort Records\n");
        printf("4. Search Record\n");
        printf("5. Save and Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Score: ");
                scanf("%f", &score);
                addRecord(&db, id, name, score);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                sortRecords(&db);
                printf("Records sorted by score.\n");
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecord(&db, id);
                break;
            case 5:
                saveToDatabase(&db);
                printf("Records saved to database.\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}