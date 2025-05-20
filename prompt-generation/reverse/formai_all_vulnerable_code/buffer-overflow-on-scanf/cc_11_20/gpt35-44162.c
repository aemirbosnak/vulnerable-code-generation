//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// defines the structure of our record
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

int main() {
    Record records[MAX_RECORDS]; // our database of records
    int numRecords = 0; // current number of records in our database

    // menu options
    const char *options[] = {"Add Record", "Delete Record", "View Records", "Exit"};

    // loop until user chooses to exit
    while(1) {
        // print menu options
        printf("\nMenu Options:\n");
        for(int i = 0; i < 4; i++) {
            printf("%d. %s\n", i+1, options[i]);
        }

        int selection;
        printf("\nPlease select an option (1-4): ");
        scanf("%d", &selection);

        // add record option
        if(selection == 1) {
            if(numRecords == MAX_RECORDS) {
                printf("\nDatabase is full. Cannot add more records.\n");
                continue;
            }

            Record newRecord;

            // receive input for new record
            printf("\nEnter record ID: ");
            scanf("%d", &newRecord.id);
            printf("Enter record name: ");
            scanf(" %[^\n]", newRecord.name);
            printf("Enter record age: ");
            scanf("%d", &newRecord.age);

            // add new record to database
            records[numRecords] = newRecord;
            numRecords++;
            printf("\nRecord added successfully.\n");
        }

        // delete record option
        else if(selection == 2) {
            if(numRecords == 0) {
                printf("\nDatabase is empty. Cannot delete records.\n");
                continue;
            }

            int deleteID;
            int found = 0;

            // receive input for record ID to delete
            printf("\nEnter ID of record to delete: ");
            scanf("%d", &deleteID);

            // find and delete record with matching ID
            for(int i = 0; i < numRecords; i++) {
                if(records[i].id == deleteID) {
                    for(int j = i; j < numRecords-1; j++) {
                        records[j] = records[j+1];
                    }
                    numRecords--;
                    printf("\nRecord deleted successfully.\n");
                    found = 1;
                    break;
                }
            }

            if(!found) {
                printf("\nRecord with ID %d not found.\n", deleteID);
            }
        }

        // view records option
        else if(selection == 3) {
            if(numRecords == 0) {
                printf("\nDatabase is empty. No records to view.\n");
                continue;
            }

            // print database of records
            printf("\nID\tName\t\tAge\n");
            for(int i = 0; i < numRecords; i++) {
                printf("%d\t%s\t\t%d\n", records[i].id, records[i].name, records[i].age);
            }
        }

        // exit program option
        else if(selection == 4) {
            printf("\nExiting program. Goodbye.\n");
            break;
        }

        // invalid input
        else {
            printf("\nInvalid selection. Please choose from options 1-4.\n");
        }
    }

    return 0;
}