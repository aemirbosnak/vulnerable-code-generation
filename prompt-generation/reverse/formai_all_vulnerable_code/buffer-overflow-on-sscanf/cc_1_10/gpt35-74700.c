//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_RECORDS 100 // maximum number of records the program can handle
#define MAX_NAME_LENGTH 20 // maximum length of name
#define MAX_PHONE_LENGTH 10 // maximum length of phone number

// structure for each record
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

// structure for the database
typedef struct {
    Record records[MAX_NUM_RECORDS];
    int num_records; // current number of records
} Database;

// function to add a record to the database
void add_record(Database* db, char* name, char* phone) {
    if (db->num_records == MAX_NUM_RECORDS) {
        printf("Database is full\n");
        return;
    }
    strncpy(db->records[db->num_records].name, name, MAX_NAME_LENGTH - 1);
    strncpy(db->records[db->num_records].phone, phone, MAX_PHONE_LENGTH - 1);
    db->num_records++;
}

// function to print all records in the database
void print_records(Database* db) {
    printf("Name\tPhone\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%s\t%s\n", db->records[i].name, db->records[i].phone);
    }
}

// function to find a record by name
void find_record(Database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            printf("Record found:\nName\tPhone\n%s\t%s\n", db->records[i].name, db->records[i].phone);
            return;
        }
    }
    printf("Record not found\n");
}

// function to delete a record by name
void delete_record(Database* db, char* name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            // shift all records after the deleted one to fill the gap
            for (int j = i + 1; j < db->num_records; j++) {
                strcpy(db->records[j - 1].name, db->records[j].name);
                strcpy(db->records[j - 1].phone, db->records[j].phone);
            }
            db->num_records--;
            printf("Record deleted\n");
            return;
        }
    }
    printf("Record not found\n");
}

int main() {
    Database db = { {{"John Doe", "1234567890"}, {"Jane Smith", "9876543210"}}, 2 }; // initialize database with some records

    char input[MAX_NAME_LENGTH + MAX_PHONE_LENGTH + 2]; // buffer for user input
    char action[MAX_NAME_LENGTH]; // action to perform
    char name[MAX_NAME_LENGTH]; // name of record
    char phone[MAX_PHONE_LENGTH]; // phone number of record

    while (1) {
        printf("Enter action (add, print, find, delete, quit): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%s", action); // extract action from input

        if (strcmp(action, "add") == 0) {
            sscanf(input + strlen(action) + 1, "%s %s", name, phone); // extract name and phone from input
            add_record(&db, name, phone);
        } else if (strcmp(action, "print") == 0) {
            print_records(&db);
        } else if (strcmp(action, "find") == 0) {
            sscanf(input + strlen(action) + 1, "%s", name); // extract name from input
            find_record(&db, name);
        } else if (strcmp(action, "delete") == 0) {
            sscanf(input + strlen(action) + 1, "%s", name); // extract name from input
            delete_record(&db, name);
        } else if (strcmp(action, "quit") == 0) {
            break;
        } else {
            printf("Invalid action\n");
        }
    }

    return 0;
}