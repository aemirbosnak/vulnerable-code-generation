//FormAI DATASET v1.0 Category: Database simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    int num_records;
    Record records[MAX_RECORDS];
} Database;

void print_menu() {
    printf("\nChoose an option:\n");
    printf("1 - Add a record\n");
    printf("2 - Remove a record\n");
    printf("3 - Display all records\n");
    printf("4 - Search for a record\n");
    printf("5 - Exit\n\n");
}

void add_record(Database* db) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    Record record;
    printf("Enter record ID: ");
    scanf("%d", &(record.id));

    printf("Enter record name: ");
    scanf("%s", record.name);

    db->records[db->num_records++] = record;
    printf("Record added.\n");
}

void remove_record(Database* db, int id) {
    int index = -1;
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Record not found.\n");
        return;
    }

    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->num_records--;
    printf("Record removed.\n");
}

void display_records(Database* db) {
    if (db->num_records == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("\nRecords:\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
}

void search_record(Database* db, char* name) {
    int found = 0;
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            printf("Record found: ID = %d\n", db->records[i].id);
            found = 1;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

int main() {
    Database db;
    db.num_records = 0;

    int option;
    do {
        print_menu();
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_record(&db);
                break;
            case 2:
                printf("Enter record ID to remove: ");
                int id;
                scanf("%d", &id);
                remove_record(&db, id);
                break;
            case 3:
                display_records(&db);
                break;
            case 4:
                printf("Enter name to search for: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                search_record(&db, name);
                break;
            case 5:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (option != 5);

    return 0;
}