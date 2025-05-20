//FormAI DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records supported
#define MAX_NAME_LENGTH 30 // Maximum length of name field
#define MAX_ADDRESS_LENGTH 50 // Maximum length of address field
#define MAX_PHONE_LENGTH 12 // Maximum length of phone number field

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} record;

record database[MAX_RECORDS]; // Database array of records
int num_records = 0; // Counter for number of records in the database

void add_record() {
    if(num_records < MAX_RECORDS) {
        record new_record;

        printf("Enter the following information to add a new record:\n");

        // Prompt user for input
        printf("ID: ");
        scanf("%d", &new_record.id);
        printf("Name: ");
        scanf("%s", new_record.name);
        printf("Address: ");
        scanf("%s", new_record.address);
        printf("Phone: ");
        scanf("%s", new_record.phone);

        // Add new record to the database
        database[num_records] = new_record;
        num_records++;

        printf("Record added successfully!\n");
    } else {
        printf("Error: maximum number of records reached!\n");
    }
}

void search_record() {
    int id;

    printf("Enter the ID of the record to search for: ");
    scanf("%d", &id);

    // Search for record with matching ID
    for(int i = 0; i < num_records; i++) {
        if(database[i].id == id) {
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Address: %s\n", database[i].address);
            printf("Phone: %s\n", database[i].phone);
            
            return;
        }
    }

    // If no matching record is found, print an error message
    printf("Error: record not found!\n");
}

void delete_record() {
    int id;

    printf("Enter the ID of the record to delete: ");
    scanf("%d", &id);

    // Search for record with matching ID and delete it
    for(int i = 0; i < num_records; i++) {
        if(database[i].id == id) {
            for(; i < num_records - 1; i++) {
                // Shift all remaining records one position left to fill the gap left by the deleted record
                database[i] = database[i+1];
            }

            num_records--;

            printf("Record deleted successfully!\n");

            return;
        }
    }

    // If no matching record is found, print an error message
    printf("Error: record not found!\n");
}

void list_records() {
    // Print a table header
    printf("ID\tName\tAddress\tPhone\n");

    // Loop through all records in the database and print them out
    for(int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%s\t%s\n", database[i].id, database[i].name, database[i].address, database[i].phone);
    }
}

int main() {
    char choice;

    do {
        printf("\nEnter your choice:\n");
        printf("a: Add a new record\n");
        printf("s: Search for a record\n");
        printf("d: Delete a record\n");
        printf("l: List all records\n");
        printf("q: Quit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case 'a':
                add_record();
                break;
            case 's':
                search_record();
                break;
            case 'd':
                delete_record();
                break;
            case 'l':
                list_records();
                break;
            case 'q':
                printf("Bye!\n");
                break;
            default:
                printf("Error: invalid choice!\n");
        }
    } while(choice != 'q');

    return 0;
}