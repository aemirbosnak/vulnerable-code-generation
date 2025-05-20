//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float score;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, int id, const char *name, float score) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH);
        db->records[db->count].score = score;
        db->count++;
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

Record* searchById(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;  // Record not found
}

void displayRecords(Database *db) {
    if (db->count == 0) {
        printf("No records in the database.\n");
        return;
    }

    printf("\nAll Records:\n");
    printf("ID\tName\t\tScore\n");
    printf("------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%-15s%.2f\n", db->records[i].id, db->records[i].name, db->records[i].score);
    }
}

void printStatistics(Database *db) {
    if (db->count == 0) {
        printf("No records to compute statistics.\n");
        return;
    }

    float totalScore = 0;
    float maxScore = db->records[0].score;
    float minScore = db->records[0].score;

    for (int i = 0; i < db->count; i++) {
        totalScore += db->records[i].score;
        if (db->records[i].score > maxScore) {
            maxScore = db->records[i].score;
        }
        if (db->records[i].score < minScore) {
            minScore = db->records[i].score;
        }
    }

    float averageScore = totalScore / db->count;

    printf("\nStatistics:\n");
    printf("Total Records: %d\n", db->count);
    printf("Average Score: %.2f\n", averageScore);
    printf("Max Score: %.2f\n", maxScore);
    printf("Min Score: %.2f\n", minScore);
}

int main() {
    Database db;
    initDatabase(&db);
    int choice, id;
    char name[MAX_NAME_LENGTH];
    float score;

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Search by ID\n");
        printf("3. Display All Records\n");
        printf("4. Show Statistics\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record *record = searchById(&db, id);
                if (record) {
                    printf("Record Found: ID=%d, Name=%s, Score=%.2f\n", record->id, record->name, record->score);
                } else {
                    printf("Record with ID %d not found.\n", id);
                }
                break;
            case 3:
                displayRecords(&db);
                break;
            case 4:
                printStatistics(&db);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    
    return 0;
}