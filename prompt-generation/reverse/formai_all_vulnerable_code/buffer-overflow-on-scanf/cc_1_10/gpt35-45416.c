//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 20
#define MAX_PHONE_LENGTH 10

typedef struct Record {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

typedef struct Database {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

void insert_record(Database* db, char* name, char* phone) {
    if(db->num_records >= MAX_RECORDS) {
        printf("Database is already full. Cannot insert record.\n");
    }
    else {
        strcpy(db->records[db->num_records].name, name);
        strcpy(db->records[db->num_records].phone, phone);
        db->num_records++;
    }
}

void delete_record(Database* db, char* name) {
    int i, j;
    for(i = 0; i < db->num_records; i++) {
        if(strcmp(db->records[i].name, name) == 0) {
            for(j = i; j < db->num_records-1; j++) {
                db->records[j] = db->records[j+1];
            }
            db->num_records--;
            printf("Record for %s has been deleted.\n", name);
            return;
        }
    }
    printf("Record for %s not found.\n", name);
}

void display_database(Database* db) {
    int i;
    printf("%-20s %-10s\n", "Name", "Phone");
    for(i = 0; i < db->num_records; i++) {
        printf("%-20s %-10s\n", db->records[i].name, db->records[i].phone);
    }
}

int main() {
    Database db;
    db.num_records = 0;
    int choice;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];

    do {
        printf("Menu\n");
        printf("1. Insert Record\n");
        printf("2. Delete Record\n");
        printf("3. Display Database\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                insert_record(&db, name, phone);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                delete_record(&db, name);
                break;
            case 3:
                display_database(&db);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while(choice != 4);

    return 0;
}