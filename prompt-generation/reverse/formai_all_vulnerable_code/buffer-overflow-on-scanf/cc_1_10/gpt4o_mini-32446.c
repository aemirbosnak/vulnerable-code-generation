//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_SIZE 50
#define CITY_SIZE 50

typedef struct {
    int id;
    char name[NAME_SIZE];
    char city[CITY_SIZE];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initialize_database(Database *db) {
    db->count = 0;
}

void add_record(Database *db, const char *name, const char *city) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    
    Record new_record;
    new_record.id = db->count + 1;  // Assigning a unique ID
    strncpy(new_record.name, name, NAME_SIZE);
    strncpy(new_record.city, city, CITY_SIZE);
    
    db->records[db->count] = new_record;
    db->count++;
    printf("Record added: ID=%d, Name=%s, City=%s\n", new_record.id, new_record.name, new_record.city);
}

void display_records(Database *db) {
    printf("\n--- Database Records ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, City: %s\n", db->records[i].id, db->records[i].name, db->records[i].city);
    }
    printf("------------------------\n");
}

void delete_record(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record with ID=%d deleted.\n", id);
            return;
        }
    }
    printf("Record with ID=%d not found.\n", id);
}

void find_record(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID=%d, Name=%s, City=%s\n", db->records[i].id, db->records[i].name, db->records[i].city);
            return;
        }
    }
    printf("Record with ID=%d not found.\n", id);
}

void save_database(Database *db) {
    FILE *file = fopen("database.txt", "w");
    if (!file) {
        perror("Failed to open file for saving");
        return;
    }
    fwrite(db->records, sizeof(Record), db->count, file);
    fclose(file);
    printf("Database saved to database.txt\n");
}

void load_database(Database *db) {
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        perror("Failed to open file for loading");
        return;
    }
    db->count = fread(db->records, sizeof(Record), MAX_RECORDS, file);
    fclose(file);
    printf("Database loaded from database.txt\n");
}

int main() {
    Database db;
    initialize_database(&db);

    int choice;
    char name[NAME_SIZE], city[CITY_SIZE];
    int id;

    do {
        printf("\n--- Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Find Record\n");
        printf("5. Save Database\n");
        printf("6. Load Database\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // consume newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_SIZE, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                printf("Enter city: ");
                fgets(city, CITY_SIZE, stdin);
                city[strcspn(city, "\n")] = 0;  // Remove newline
                add_record(&db, name, city);
                break;
            case 2:
                display_records(&db);
                break;
            case 3:
                printf("Enter ID of record to delete: ");
                scanf("%d", &id);
                delete_record(&db, id);
                break;
            case 4:
                printf("Enter ID of record to find: ");
                scanf("%d", &id);
                find_record(&db, id);
                break;
            case 5:
                save_database(&db);
                break;
            case 6:
                load_database(&db);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}