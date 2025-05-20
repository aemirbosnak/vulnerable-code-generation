//FormAI DATASET v1.0 Category: Database simulation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 1000 // maximum number of records in the database
#define MAX_NAME_LENGTH 100 // maximum length of record's name field

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

int main() {

    Record* database[MAX_RECORDS] = { 0 }; // initialize the database to NULL
    int database_size = 0; // variable to keep track of the number of records in the database
    int option = 0; // variable to store the user's menu choice
    char name[MAX_NAME_LENGTH]; // temporary variable to hold a name input by the user
    int age; // temporary variable to hold an age input by the user

    while (1) {
        // print the main menu
        printf("\nPlease select an option:\n");
        printf("1. Add a record\n");
        printf("2. Search for a record\n");
        printf("3. Delete a record\n");
        printf("4. Display all records\n");
        printf("5. Exit program\n");
        printf("Option: ");

        scanf("%d", &option);

        if (option == 1) { // add a record
            if (database_size == MAX_RECORDS) { // check if the database is full
                printf("Database is full. Cannot add record.\n");
            }
            else {
                // get input from the user
                printf("\nEnter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);

                // create a new record in memory
                Record* new_record = (Record*)malloc(sizeof(Record));
                strcpy(new_record->name, name);
                new_record->age = age;

                // add the new record to the end of the database
                database[database_size] = new_record;
                database_size++;

                printf("\nRecord added.\n");
            }
        }
        else if (option == 2) { // search for a record
            // get input from the user
            printf("\nEnter name: ");
            scanf("%s", name);

            int i;
            for (i = 0; i < database_size; i++) { // search through database for a record with matching name
                if (strcmp(database[i]->name, name) == 0) { // found a match
                    printf("\nRecord found:\n");
                    printf("Name: %s\n", database[i]->name);
                    printf("Age: %d\n", database[i]->age);
                    break;
                }
            }

            if (i == database_size) { // loop completed without finding a match
                printf("\nRecord not found.\n");
            }
        }
        else if (option == 3) { // delete a record
            // get input from the user
            printf("\nEnter name: ");
            scanf("%s", name);

            int i;
            for (i = 0; i < database_size; i++) { // search through database for a record with matching name
                if (strcmp(database[i]->name, name) == 0) { // found a match
                    free(database[i]); // free the memory used by the record
                    database[i] = NULL; // set the array element to NULL
                    database_size--;
                    printf("\nRecord deleted.\n");
                    break;
                }
            }

            if (i == database_size) { // loop completed without finding a match
                printf("\nRecord not found.\n");
            }
        }
        else if (option == 4) { // display all records
            printf("\nRecords in database:\n");

            int i;
            for (i = 0; i < database_size; i++) { // loop through all records in the database
                printf("Name: %s\n", database[i]->name);
                printf("Age: %d\n", database[i]->age);
                printf("\n");
            }
        }
        else if (option == 5) { // exit program
            printf("\nExiting program...\n");
            break;
        }
        else { // invalid option
            printf("\nInvalid option. Please try again.\n");
        }
    }

    // free all memory used by the records in the database
    int i;
    for (i = 0; i < database_size; i++) {
        free(database[i]);
    }

    return 0;
}