//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 // Maximum number of records that can be stored in the database

struct employee {
    char name[20];
    int id;
    char dept[10];
    float salary;
};

struct employee database[MAX_SIZE]; // Declare an array of employees to store the records in the database
int num_records = 0; // Keep track of the number of records in the database

// Function to add a new record to the database
void add_record() {
    struct employee emp;
    printf("Enter name: ");
    scanf("%s", emp.name);
    printf("Enter ID: ");
    scanf("%d", &emp.id);
    printf("Enter department: ");
    scanf("%s", emp.dept);
    printf("Enter salary: ");
    scanf("%f", &emp.salary);

    database[num_records++] = emp;
    printf("Record added successfully!\n\n");
}

// Function to display all the records in the database
void display_records() {
    if(num_records == 0) {
        printf("No records found in the database.\n\n");
    }
    else {
        for(int i=0; i<num_records; i++) {
            printf("Record %d:\n", i+1);
            printf("Name: %s\n", database[i].name);
            printf("ID: %d\n", database[i].id);
            printf("Department: %s\n", database[i].dept);
            printf("Salary: %.2f\n", database[i].salary);
            printf("\n");
        }
    }
}

int main() {
    int choice = 0;
    do {
        printf("Welcome to the Employee Database Simulation!\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_record();
                break;
            case 2:
                display_records();
                break;
            case 3:
                printf("Thank you for using the program!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while(choice != 3);

    return 0;
}