//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

int addRecord(Database *db, const char *name, int age) {
    if (db->count >= MAX_RECORDS) {
        return -1; // Database full
    }

    Record newRecord;
    newRecord.id = db->count + 1; // Simple ID generation
    strncpy(newRecord.name, name, NAME_LENGTH - 1);
    newRecord.name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    newRecord.age = age;

    db->records[db->count] = newRecord;
    db->count++;
    return newRecord.id;
}

void displayRecords(const Database *db) {
    printf("ID\tName\t\tAge\n");
    printf("--------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

int deleteRecord(Database *db, int id) {
    if (id <= 0 || id > db->count) {
        return -1; // Invalid ID
    }

    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->count--;
    return 0;
}

void saveDatabase(const Database *db, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing.\n");
        return;
    }
    
    fwrite(db, sizeof(Database), 1, file);
    fclose(file);
}

void loadDatabase(Database *db, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file for reading.\n");
        return;
    }

    fread(db, sizeof(Database), 1, file);
    fclose(file);
}

void displayMenu() {
    printf("Database Menu\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Save Database\n");
    printf("5. Load Database\n");
    printf("6. Exit\n");
}

int main() {
    Database db;
    int choice, age;
    char name[NAME_LENGTH];
    char filename[100];

    initializeDatabase(&db);

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Add Record
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                if (addRecord(&db, name, age) != -1) {
                    printf("Record added successfully!\n");
                } else {
                    printf("Database is full!\n");
                }
                break;

            case 2: // Display Records
                displayRecords(&db);
                break;

            case 3: // Delete Record
                printf("Enter ID to delete: ");
                scanf("%d", &age);
                if (deleteRecord(&db, age) == -1) {
                    printf("Record not found!\n");
                } else {
                    printf("Record deleted successfully!\n");
                }
                break;

            case 4: // Save Database
                printf("Enter filename: ");
                scanf("%s", filename);
                saveDatabase(&db, filename);
                printf("Database saved successfully!\n");
                break;

            case 5: // Load Database
                printf("Enter filename: ");
                scanf("%s", filename);
                loadDatabase(&db, filename);
                printf("Database loaded successfully!\n");
                break;

            case 6: // Exit
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}