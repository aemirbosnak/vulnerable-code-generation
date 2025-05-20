//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DATABASE_SIZE 100

// Data structure to represent each record in the database
struct Record {
    char name[20];
    int age;
    char address[50];
};

// Global variables
struct Record database[MAX_DATABASE_SIZE];
int num_records = 0;

// Function to add a new record to the database
void add_record() {
    if(num_records >= MAX_DATABASE_SIZE) {
        printf("Error: Database full. Cannot add new record.\n");
        return;
    }
    
    struct Record new_record;
    
    printf("Enter name: ");
    scanf("%s", new_record.name);
    
    printf("Enter age: ");
    scanf("%d", &new_record.age);
    
    printf("Enter address: ");
    scanf("%s", new_record.address);
    
    database[num_records++] = new_record;
}

// Function to search for a record based on name
void search_record() {
    char search_name[20];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    
    int found = 0;
    for(int i=0; i<num_records; i++) {
        if(strcmp(database[i].name, search_name) == 0) {
            printf("Record found - %s %d %s\n", database[i].name, database[i].age, database[i].address);
            found = 1;
            break;
        }
    }
    
    if(!found) {
        printf("Record not found.\n");
    }
}

// Function to display all records in the database
void display_database() {
    printf("Name    Age    Address\n");
    for(int i=0; i<num_records; i++) {
        printf("%s    %d    %s\n", database[i].name, database[i].age, database[i].address);
    }
}

int main() {
    int choice = 0;
    
    // Display menu and get user choice
    do {
        printf("\nSelect an option:\n");
        printf("1. Add a record\n");
        printf("2. Search for a record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                display_database();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);
    
    return 0;
}