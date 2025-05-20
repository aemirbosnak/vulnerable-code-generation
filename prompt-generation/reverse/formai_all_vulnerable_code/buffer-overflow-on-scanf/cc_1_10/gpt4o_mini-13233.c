//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DB_FILENAME "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Record;

void addRecord(Record* db, int* count) {
    if (*count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    Record new_record;
    new_record.id = *count + 1; // Simple ID generation based on record count

    printf("Enter name for Record %d: ", new_record.id);
    fgets(new_record.name, NAME_LENGTH, stdin);
    new_record.name[strcspn(new_record.name, "\n")] = 0; // Remove newline char

    printf("Enter age for Record %d: ", new_record.id);
    scanf("%d", &new_record.age);
    getchar(); // Clear newline character from buffer

    db[*count] = new_record;
    (*count)++;
    printf("Record added successfully!\n");
}

void displayRecords(Record* db, int count) {
    if (count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- Database Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db[i].id, db[i].name, db[i].age);
    }
}

void saveRecords(Record* db, int count) {
    FILE* file = fopen(DB_FILENAME, "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%d\n", db[i].id, db[i].name, db[i].age);
    }

    fclose(file);
    printf("Records saved to %s successfully!\n", DB_FILENAME);
}

void loadRecords(Record* db, int* count) {
    FILE* file = fopen(DB_FILENAME, "r");
    if (!file) {
        printf("Error opening file for reading! Database might be empty.\n");
        return;
    }

    while (fscanf(file, "%d,%49[^,],%d\n", &db[*count].id, db[*count].name, &db[*count].age) != EOF) {
        (*count)++;
    }

    fclose(file);
    printf("Records loaded successfully! Total records: %d\n", *count);
}

int main() {
    Record db[MAX_RECORDS];
    int count = 0;
    int choice;

    loadRecords(db, &count);

    do {
        printf("\n--- Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Save Records\n");
        printf("4. Load Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                addRecord(db, &count);
                break;
            case 2:
                displayRecords(db, count);
                break;
            case 3:
                saveRecords(db, count);
                break;
            case 4:
                loadRecords(db, &count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}