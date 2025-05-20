//FormAI DATASET v1.0 Category: Database simulation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10 // maximum number of records the database can store

// struct to hold information about a record
typedef struct {
    int id;
    char name[20];
    int age;
    float salary;
} Record;

// array to store all the records in the database
Record database[MAX_RECORDS];

// function to add a new record to the database
void addRecord(int id, char name[], int age, float salary) {
    Record newRecord = {id, "", age, salary};
    strcpy(newRecord.name, name);
    
    // check if the database is full
    for(int i=0; i<MAX_RECORDS; i++) {
        if(database[i].id == 0) { // empty space found
            database[i] = newRecord;
            printf("Record added successfully.\n");
            return;
        }
    }
    
    // all the records are full
    printf("The database is full. Cannot add new record.\n");
}

// function to delete a record from the database
void deleteRecord(int id) {
    for(int i=0; i<MAX_RECORDS; i++) {
        if(database[i].id == id) { // record found
            database[i].id = 0;
            database[i].name[0] = '\0';
            database[i].age = 0;
            database[i].salary = 0.0;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    
    // record not found
    printf("Record not found.\n");
}

// function to print all the records in the database
void printRecords() {
    printf("| %-3s | %-20s | %-3s | %-10s |\n", "ID", "Name", "Age", "Salary");
    printf("|----|----------------------|-----|------------|\n");
    for(int i=0; i<MAX_RECORDS; i++) {
        if(database[i].id != 0) { // record found
            printf("| %-3d | %-20s | %-3d | %-10.2f |\n", database[i].id, database[i].name, database[i].age, database[i].salary);
        }
    }
    printf("\n");
}

int main() {
    // initialize the database
    for(int i=0; i<MAX_RECORDS; i++) {
        database[i].id = 0;
        database[i].name[0] = '\0';
        database[i].age = 0;
        database[i].salary = 0.0;
    }
    
    // menu-driven system to interact with the user
    printf("Welcome to the Database Simulation program.\n");
    printf("Please select an option from the menu below:\n");
    while(1) {
        printf("1. Add a new record.\n");
        printf("2. Delete an existing record.\n");
        printf("3. Print all the records.\n");
        printf("4. Exit.\n");
        
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                // add a new record
                int id, age;
                char name[20];
                float salary;
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter salary: ");
                scanf("%f", &salary);
                addRecord(id, name, age, salary);
                break;
            }
            case 2: {
                // delete an existing record
                int id;
                printf("Enter ID: ");
                scanf("%d", &id);
                deleteRecord(id);
                break;
            }
            case 3: {
                // print all the records
                printRecords();
                break;
            }
            case 4: {
                // exit the program
                printf("Exiting the program.\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }
    
    return 0;
}