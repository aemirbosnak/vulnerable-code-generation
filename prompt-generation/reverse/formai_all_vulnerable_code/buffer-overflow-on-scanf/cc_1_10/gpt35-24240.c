//FormAI DATASET v1.0 Category: Database simulation ; Style: Sherlock Holmes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// defining constant values
#define MAX_CHAR 100
#define MAX_RECORDS 10

// defining a structure to store record details
typedef struct record {
    int id;
    char name[MAX_CHAR];
    char occupation[MAX_CHAR];
    int salary;
} Record;

// function to add a new record into the database
void add_new_record(Record database[], int *num_of_records){
    
    // checking if database has the space to store new record
    if (*num_of_records == MAX_RECORDS){
        printf("Sorry! The database is full and cannot store more records.\n");
        return;
    }
    
    int id, salary;
    char name[MAX_CHAR], occupation[MAX_CHAR];
    
    // getting details of new record from user
    printf("Enter the id: ");
    scanf("%d", &id);
    
    // checking if entered id already exists
    for (int i=0; i<*num_of_records; i++){
        if (database[i].id == id){
            printf("Sorry! This id already exists in the database.\n");
            return;
        }
    }
    
    printf("Enter the name: ");
    scanf("%s", name);
    printf("Enter the occupation: ");
    scanf("%s", occupation);
    printf("Enter the salary: ");
    scanf("%d", &salary);
    
    // adding the new record in the next available space in database
    database[*num_of_records].id = id;
    strcpy(database[*num_of_records].name, name);
    strcpy(database[*num_of_records].occupation, occupation);
    database[*num_of_records].salary = salary;
    *num_of_records += 1;
    
    printf("The record has been added to the database successfully.\n");
}

// function to search a record in the database
void search_record(Record database[], int num_of_records){
    int choice;
    
    printf("Please select an option for searching:\n");
    printf("1. Search by id\n");
    printf("2. Search by name\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1){
        int id;
        printf("Enter the id to search for: ");
        scanf("%d", &id);
        
        // searching for record with entered id
        for (int i=0; i<num_of_records; i++){
            if (database[i].id == id){
                // displaying details of matched record
                printf("Record Found!\n");
                printf("Id: %d\n", database[i].id);
                printf("Name: %s\n", database[i].name);
                printf("Occupation: %s\n", database[i].occupation);
                printf("Salary: %d\n", database[i].salary);
                return;
            }
        }
        
        printf("Sorry! No record found with the entered id.\n");
        
    } else if (choice == 2){
        char name[MAX_CHAR];
        printf("Enter the name to search for: ");
        scanf("%s", name);
        
        // converting entered name to upper case for case-insensitive searching
        for (int i=0; name[i]; i++){
            name[i] = toupper(name[i]);
        }
        
        // searching for record with entered name
        for (int i=0; i<num_of_records; i++){
            char record_name_upper[MAX_CHAR];
            strcpy(record_name_upper, database[i].name);
            for (int j=0; record_name_upper[j]; j++){
                record_name_upper[j] = toupper(record_name_upper[j]);
            }
            if (strcmp(record_name_upper, name) == 0){
                // displaying details of matched record
                printf("Record Found!\n");
                printf("Id: %d\n", database[i].id);
                printf("Name: %s\n", database[i].name);
                printf("Occupation: %s\n", database[i].occupation);
                printf("Salary: %d\n", database[i].salary);
                return;
            }
        }
        
        printf("Sorry! No record found with the entered name.\n");
        
    } else {
        printf("Invalid choice!\n");
    }
}

// function to display all records in the database
void display_all_records(Record database[], int num_of_records){
    if (num_of_records == 0){
        printf("The database is empty.\n");
    } else {
        printf("Details of all records in the database:\n");
        for (int i=0; i<num_of_records; i++){
            printf("Id: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Occupation: %s\n", database[i].occupation);
            printf("Salary: %d\n", database[i].salary);
            printf("\n");
        }
    }
}

int main(){
    
    // initializing the database
    Record database[MAX_RECORDS];
    int num_of_records = 0;
    
    printf("Welcome to the Sherlock Holmes Database Simulation!\n");
    printf("How may I assist you? You can use the following commands:\n");
    printf("1. Add a new record\n");
    printf("2. Search a record\n");
    printf("3. Display all records\n");
    printf("4. Quit\n");
    int choice;
    
    // running a loop to take commands from user and perform actions accordingly
    while (1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                add_new_record(database, &num_of_records);
                break;
            
            case 2:
                search_record(database, num_of_records);
                break;
            
            case 3:
                display_all_records(database, num_of_records);
                break;
            
            case 4:
                printf("Thank you for using the Sherlock Holmes Database Simulation! Goodbye.\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please enter a valid command.\n");
        }
    }
    
    return 0;
}