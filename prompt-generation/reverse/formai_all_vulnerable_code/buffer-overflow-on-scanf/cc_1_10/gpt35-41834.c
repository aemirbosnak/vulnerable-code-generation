//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

// Structure for a record in the database
struct record {
    int id;
    char name[50];
    int age;
};

// Array to store the records in the database
struct record db[MAX_RECORDS];

// Counter variable to keep track of the number of records in the database
int count = 0;

// Function to add a new record to the database
void add_record() {
    printf("Enter name: ");
    scanf("%s", db[count].name);
    
    printf("Enter age: ");
    scanf("%d", &db[count].age);
    
    db[count].id = count + 1;
    
    count++;
    
    printf("Record added successfully!\n");
}

// Function to search for a record in the database by its ID
void search_record() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            printf("%d\t%s\t%d\n", db[i].id, db[i].name, db[i].age);
            return;
        }
    }
    
    printf("No record found with ID %d.\n", id);
}

// Function to delete a record from the database by its ID
void delete_record() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);
    
    for (int i = 0; i < count; i++) {
        if (db[i].id == id) {
            for (int j = i; j < count - 1; j++) {
                db[j] = db[j+1];
            }
            count--;
            printf("Record deleted successfully!\n");
            return;
        }
    }
    
    printf("No record found with ID %d.\n", id);
}

// Function to display all the records in the database
void display_records() {
    printf("ID\tName\tAge\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", db[i].id, db[i].name, db[i].age);
    }
}

int main() {
    int choice;
    
    printf("Welcome to MyDatabase, a C simulation program!\n");
    printf("Please choose an option below:\n\n");
    
    while (1) {
        printf("1. Add record\n");
        printf("2. Search record\n");
        printf("3. Delete record\n");
        printf("4. Display all records\n");
        printf("5. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                search_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                display_records();
                break;
            case 5:
                printf("Thank you for using MyDatabase program!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
    }
    
    return 0;
}