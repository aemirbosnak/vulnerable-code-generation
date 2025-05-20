//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initialize_database(Database *db) {
    db->count = 0;
}

void add_record(Database *db, int id, const char *name, const char *address) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        strncpy(db->records[db->count].address, address, ADDRESS_LENGTH);
        db->count++;
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

void display_records(const Database *db) {
    printf("\nRecords in Database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Address: %s\n", db->records[i].id, db->records[i].name, db->records[i].address);
    }
}

void search_record(const Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record Found -> ID: %d, Name: %s, Address: %s\n", db->records[i].id, db->records[i].name, db->records[i].address);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void delete_record(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift left
            }
            db->count--;
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found for deletion.\n", id);
}

void update_record(Database *db, int id, const char *name, const char *address) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            strncpy(db->records[i].name, name, NAME_LENGTH);
            strncpy(db->records[i].address, address, ADDRESS_LENGTH);
            printf("Record with ID %d updated successfully.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found for update.\n", id);
}

void sort_records(Database *db) {
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = 0; j < db->count - i - 1; j++) {
            if (db->records[j].id > db->records[j + 1].id) {
                Record temp = db->records[j];
                db->records[j] = db->records[j + 1];
                db->records[j + 1] = temp;
            }
        }
    }
    printf("Records sorted by ID.\n");
}

int main() {
    Database db;
    initialize_database(&db);

    int choice, id;
    char name[NAME_LENGTH], address[ADDRESS_LENGTH];

    while (1) {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Sort Records\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Address: ");
                scanf("%s", address);
                add_record(&db, id, name, address);
                break;
            case 2:
                display_records(&db);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                search_record(&db, id);
                break;
            case 4:
                printf("Enter ID to update: ");
                scanf("%d", &id);
                printf("Enter new Name: ");
                scanf("%s", name);
                printf("Enter new Address: ");
                scanf("%s", address);
                update_record(&db, id, name, address);
                break;
            case 5:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                delete_record(&db, id);
                break;
            case 6:
                sort_records(&db);
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}