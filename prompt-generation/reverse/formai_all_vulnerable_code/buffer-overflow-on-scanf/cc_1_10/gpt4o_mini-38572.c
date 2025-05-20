//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DESC_LENGTH 100
#define DB_FILE "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESC_LENGTH];
} Record;

Record db[MAX_RECORDS];
int recordCount = 0;

void loadDatabase() {
    FILE *file = fopen(DB_FILE, "r");
    if (!file) {
        perror("Failed to open database file");
        return;
    }
    while (fscanf(file, "%d %[^\n] %[^\n]", &db[recordCount].id, db[recordCount].name, db[recordCount].description) != EOF) {
        recordCount++;
    }
    fclose(file);
}

void saveDatabase() {
    FILE *file = fopen(DB_FILE, "w");
    if (!file) {
        perror("Failed to open database file for writing");
        return;
    }
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%d %s %s\n", db[i].id, db[i].name, db[i].description);
    }
    fclose(file);
}

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database full!\n");
        return;
    }
    Record newRecord;
    newRecord.id = recordCount + 1; // Simple ID assignment
    printf("Enter name: ");
    fgets(newRecord.name, NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // Remove newline
    printf("Enter description: ");
    fgets(newRecord.description, DESC_LENGTH, stdin);
    newRecord.description[strcspn(newRecord.description, "\n")] = 0; // Remove newline

    db[recordCount++] = newRecord;
    printf("Record added!\n");
}

void displayRecords() {
    printf("\n--- Database Records ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Description: %s\n", db[i].id, db[i].name, db[i].description);
    }
}

void searchRecord() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    getchar(); // Clear newline from buffer
    for (int i = 0; i < recordCount; i++) {
        if (db[i].id == id) {
            printf("Record Found: ID: %d, Name: %s, Description: %s\n", db[i].id, db[i].name, db[i].description);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void deleteRecord() {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    getchar(); // Clear newline from buffer
    for (int i = 0; i < recordCount; i++) {
        if (db[i].id == id) {
            for (int j = i; j < recordCount - 1; j++) {
                db[j] = db[j + 1];
            }
            recordCount--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void menu() {
    int choice;
    do {
        printf("\n--- Database Menu ---\n");
        printf("1. Load Database\n");
        printf("2. Save Database\n");
        printf("3. Add Record\n");
        printf("4. Display Records\n");
        printf("5. Search Record\n");
        printf("6. Delete Record\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1: loadDatabase(); break;
            case 2: saveDatabase(); break;
            case 3: addRecord(); break;
            case 4: displayRecords(); break;
            case 5: searchRecord(); break;
            case 6: deleteRecord(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);
}

int main() {
    printf("Welcome to the Database Simulation!\n");
    menu();
    return 0;
}