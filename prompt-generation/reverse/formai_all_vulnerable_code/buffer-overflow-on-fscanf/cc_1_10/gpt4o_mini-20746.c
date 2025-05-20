//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char phone[PHONE_LENGTH];
} Record;

typedef struct {
    Record *records;
    int count;
} Database;

Database* createDatabase() {
    Database *db = (Database *)malloc(sizeof(Database));
    db->records = (Record *)malloc(MAX_RECORDS * sizeof(Record));
    db->count = 0;
    return db;
}

void freeDatabase(Database *db) {
    free(db->records);
    free(db);
}

void addRecord(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }
    
    printf("Enter name: ");
    scanf("%s", db->records[db->count].name);
    
    printf("Enter email: ");
    scanf("%s", db->records[db->count].email);
    
    printf("Enter phone: ");
    scanf("%s", db->records[db->count].phone);
    
    db->count++;
    printf("Record added successfully!\n");
}

void displayRecords(Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\nRecords in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s\n", db->records[i].name);
        printf("Email: %s\n", db->records[i].email);
        printf("Phone: %s\n", db->records[i].phone);
    }
}

void deleteRecord(Database *db) {
    if (db->count == 0) {
        printf("No records to delete.\n");
        return;
    }
    
    int index;
    printf("Enter the record number to delete (1 to %d): ", db->count);
    scanf("%d", &index);
    
    if (index < 1 || index > db->count) {
        printf("Invalid record number.\n");
        return;
    }

    for (int i = index - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->count--;
    printf("Record deleted successfully!\n");
}

void saveDatabase(Database *db) {
    FILE *file = fopen("database.txt", "w");
    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return;
    }
    
    fprintf(file, "%d\n", db->count);
    for (int i = 0; i < db->count; i++) {
        fprintf(file, "%s,%s,%s\n", db->records[i].name, db->records[i].email, db->records[i].phone);
    }
    fclose(file);
    printf("Database saved successfully!\n");
}

void loadDatabase(Database *db) {
    FILE *file = fopen("database.txt", "r");
    if (file == NULL) {
        printf("No database file found, starting fresh.\n");
        return;
    }
    
    fscanf(file, "%d\n", &db->count);
    for (int i = 0; i < db->count; i++) {
        fscanf(file, "%[^,],%[^,],%s\n", db->records[i].name, db->records[i].email, db->records[i].phone);
    }
    fclose(file);
    printf("Database loaded successfully!\n");
}

int main() {
    Database *db = createDatabase();
    loadDatabase(db);
    
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Save Database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(db);
                break;
            case 2:
                displayRecords(db);
                break;
            case 3:
                deleteRecord(db);
                break;
            case 4:
                saveDatabase(db);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    freeDatabase(db);
    printf("Exited successfully.\n");
    return 0;
}