//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a maximum number of records */
#define MAX_RECORDS 100

/* Define a maximum length of name */
#define MAX_NAME_LENGTH 25

/* Define a maximum length of phone number */
#define MAX_PHONE_LENGTH 15

/* Define a structure for a single record */
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

/* Define a structure for a database */
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

/* Function to add a new record to the database */
void add_record(Database *db, char *name, char *phone) {
    if (db->num_records < MAX_RECORDS) {
        strcpy(db->records[db->num_records].name, name);
        strcpy(db->records[db->num_records].phone, phone);
        db->num_records++;
        printf("Record added successfully!\n");
    } else {
        printf("Cannot add record. Maximum number of records reached.\n");
    }
}

/* Function to print all records in the database */
void print_database(Database *db) {
    int i;
    printf("Name\t\tPhone Number\n");
    for (i = 0; i < db->num_records; i++) {
        printf("%s\t\t%s\n", db->records[i].name, db->records[i].phone);
    }
}

int main(void) {
    /* Declare variables */
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char choice = 'a';
    Database db;
    db.num_records = 0;

    /* Loop to prompt for user input */
    while (choice != 'q') {
        printf("Enter (a) to add a record, (p) to print the database, or (q) to quit: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter a name (max %d characters): ", MAX_NAME_LENGTH);
                scanf("%s", name);
                printf("Enter a phone number (max %d characters): ", MAX_PHONE_LENGTH);
                scanf("%s", phone);
                add_record(&db, name, phone);
                break;

            case 'p':
                print_database(&db);
                break;

            case 'q':
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}