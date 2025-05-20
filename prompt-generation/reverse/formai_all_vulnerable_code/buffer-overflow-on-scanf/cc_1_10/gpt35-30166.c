//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100  // maximum number of records the database can hold

typedef struct {
    int id;
    char name[50];
    double salary;
} Record;

// function prototypes
void add_record(Record *db, int *num_records); // adds a new record to the database
void delete_record(Record *db, int *num_records); // deletes a record from the database
void print_records(Record *db, int num_records); // prints all records in the database

int main() {
    Record database[MAX_RECORDS];  // creating an array of Records to hold our database
    int num_records = 0;  // initializing the number of records added to the database to zero
    char choice;  // this variable will hold the user's choice of operation
    
    // printing the menu options
    printf("Welcome to the Database Simulator!\n");
    printf("Please choose an operation:\n");
    printf("a - Add record\n");
    printf("d - Delete record\n");
    printf("p - Print all records\n");
    printf("q - Quit\n\n");
    
    // loop until user chooses to quit
    while (choice != 'q') {
        printf("Enter your choice: ");
        scanf(" %c", &choice);  // read in user's choice
        
        switch (choice) {
            case 'a':
                add_record(database, &num_records);
                break;
            case 'd':
                delete_record(database, &num_records);
                break;
            case 'p':
                print_records(database, num_records);
                break;
            case 'q':
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}

// function to add a new record to the database
void add_record(Record *db, int *num_records) {
    if (*num_records >= MAX_RECORDS) {  // if the database is already full
        printf("The database is full. Cannot add more records.\n");
    } else {
        // read in the new record data
        printf("Enter the ID of the new record: ");
        scanf("%d", &db[*num_records].id);
        printf("Enter the name of the new record: ");
        scanf("%s", db[*num_records].name);
        printf("Enter the salary of the new record: ");
        scanf("%lf", &db[*num_records].salary);
        
        (*num_records)++;  // increase the number of records in the database
        printf("Record added successfully.\n");
    }
}

// function to delete a record from the database
void delete_record(Record *db, int *num_records) {
    int id, i;
    printf("Enter the ID of the record to be deleted: ");
    scanf("%d", &id); // reading in the ID of the record to be deleted
    
    // searching for the record with the given ID and deleting it if found
    for (i = 0; i < *num_records; i++) {
        if (db[i].id == id) {
            // shifting all the records down to fill in the gap left by the deleted record
            memmove(&db[i], &db[i+1], (*num_records - i - 1) * sizeof(Record));
            (*num_records)--; // decrease the number of records in the database
            printf("Record deleted successfully.\n");
            return;
        }
    }
    
    // if control flows here, that means the record was not found
    printf("Record not found.\n");
}

// function to print all records in the database
void print_records(Record *db, int num_records) {
    int i;
    if (num_records == 0) {  // if there are no records in the database
        printf("No records found.\n");
    } else {
        printf("\nID\tName\t\tSalary\n");
        printf("--\t----\t\t------\n");
        
        for (i = 0; i < num_records; i++) {
            printf("%d\t%s\t\t%.2lf\n", db[i].id, db[i].name, db[i].salary);
        }
    }
}