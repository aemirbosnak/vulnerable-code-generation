//FormAI DATASET v1.0 Category: Database simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[20];
    int age;
};

struct Database {
    struct Record records[MAX_RECORDS];
    int count;
};

void initializeDatabase(struct Database* db) {
    db->count = 0;
}

void insertRecord(struct Database* db, struct Record r) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count++] = r;
        printf("Record added successfully.\n");
    } else {
        printf("Database is full.\n");
    }
}

void removeRecord(struct Database* db, int id) {
    int i;
    for (i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            break;
        }
    }
    if (i == db->count) {
        printf("Record not found.\n");
    } else {
        for (; i < db->count - 1; i++) {
            db->records[i] = db->records[i+1];
        }
        db->count--;
        printf("Record removed successfully.\n");
    }
}

void searchRecord(struct Database* db, int id) {
    int i;
    for (i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("ID: %d\n", db->records[i].id);
            printf("Name: %s\n", db->records[i].name);
            printf("Age: %d\n", db->records[i].age);
            break;
        }
    }
    if (i == db->count) {
        printf("Record not found.\n");
    }
}

void printDatabase(struct Database* db) {
    int i;
    for (i = 0; i < db->count; i++) {
        printf("ID: %d\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("------------------------\n");
    }
    if (i == 0) {
        printf("Database is empty.\n");
    }
}

int main() {
    struct Database db;
    initializeDatabase(&db);

    while (1) {
        printf("\n1. Insert record\n");
        printf("2. Remove record\n");
        printf("3. Search record\n");
        printf("4. Print database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Record r;
                printf("Enter ID: ");
                scanf("%d", &r.id);
                printf("Enter name: ");
                scanf("%s", r.name);
                printf("Enter age: ");
                scanf("%d", &r.age);
                insertRecord(&db, r);
                break;
            }
            case 2: {
                int id;
                printf("Enter ID: ");
                scanf("%d", &id);
                removeRecord(&db, id);
                break;
            }
            case 3: {
                int id;
                printf("Enter ID: ");
                scanf("%d", &id);
                searchRecord(&db, id);
                break;
            }
            case 4: {
                printDatabase(&db);
                break;
            }
            case 5: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}