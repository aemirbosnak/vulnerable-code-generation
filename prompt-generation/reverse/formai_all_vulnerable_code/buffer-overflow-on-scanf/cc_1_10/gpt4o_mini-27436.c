//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_PATH_LENGTH 256

typedef struct {
    int id;
    char name[50];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, int id, const char *name, int age) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strcpy(db->records[db->count].name, name);
        db->records[db->count].age = age;
        db->count++;
    } else {
        printf("Database is full!\n");
    }
}

void displayRecords(Database *db) {
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

int compareById(const void *a, const void *b) {
    return ((Record *)a)->id - ((Record *)b)->id;
}

int compareByName(const void *a, const void *b) {
    return strcmp(((Record *)a)->name, ((Record *)b)->name);
}

int compareByAge(const void *a, const void *b) {
    return ((Record *)a)->age - ((Record *)b)->age;
}

void indexRecords(Database *db, int (*compare)(const void*, const void*)) {
    qsort(db->records, db->count, sizeof(Record), compare);
}

void saveToFile(Database *db, const char *filepath) {
    FILE *file = fopen(filepath, "wb");
    if (file) {
        fwrite(db, sizeof(Database), 1, file);
        fclose(file);
        printf("Database saved to %s\n", filepath);
    } else {
        perror("Error opening file for writing");
    }
}

void loadFromFile(Database *db, const char *filepath) {
    FILE *file = fopen(filepath, "rb");
    if (file) {
        fread(db, sizeof(Database), 1, file);
        fclose(file);
        printf("Database loaded from %s\n", filepath);
    } else {
        perror("Error opening file for reading");
    }
}

void menu() {
    printf("\n=== Database Menu ===\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Index By ID\n");
    printf("4. Index By Name\n");
    printf("5. Index By Age\n");
    printf("6. Save to File\n");
    printf("7. Load from File\n");
    printf("8. Exit\n");
    printf("======================\n");
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;
    int id, age;
    char name[50], filepath[MAX_PATH_LENGTH];

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                addRecord(&db, id, name, age);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                indexRecords(&db, compareById);
                printf("Indexed Records by ID:\n");
                displayRecords(&db);
                break;
            case 4:
                indexRecords(&db, compareByName);
                printf("Indexed Records by Name:\n");
                displayRecords(&db);
                break;
            case 5:
                indexRecords(&db, compareByAge);
                printf("Indexed Records by Age:\n");
                displayRecords(&db);
                break;
            case 6:
                printf("Enter filepath to save: ");
                scanf("%s", filepath);
                saveToFile(&db, filepath);
                break;
            case 7:
                printf("Enter filepath to load: ");
                scanf("%s", filepath);
                loadFromFile(&db, filepath);
                break;
            case 8:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}