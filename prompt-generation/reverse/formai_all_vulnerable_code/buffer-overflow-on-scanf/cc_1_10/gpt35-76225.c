//FormAI DATASET v1.0 Category: Database querying ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Define a struct to represent the data in the database
typedef struct {
    char name[MAX];
    int age;
    float salary;
} Employee;

// Define a struct to represent the database
typedef struct {
    Employee employees[MAX];
    int size;
} Database;

// Function prototypes
void displayMenu();
void addEmployee(Database *db);
void displayEmployees(Database db);
void queryDatabase(Database db);

int main() {
    Database db;
    db.size = 0;
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee(&db);
                break;
            case 2:
                displayEmployees(db);
                break;
            case 3:
                queryDatabase(db);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
        }
    } while (1);
    
    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("---- Employee Database ----\n");
    printf("1. Add employee\n");
    printf("2. Display all employees\n");
    printf("3. Query database\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to add an employee to the database
void addEmployee(Database *db) {
    Employee employee;
    
    printf("Enter name: ");
    scanf("%s", employee.name);
    printf("Enter age: ");
    scanf("%d", &employee.age);
    printf("Enter salary: ");
    scanf("%f", &employee.salary);
    
    db->employees[db->size] = employee;
    db->size++;
    
    printf("Employee added successfully.\n");
}

// Function to display all employees in the database
void displayEmployees(Database db) {
    if (db.size == 0) {
        printf("There are no employees in the database.\n");
    } else {
        printf("%-20s %-10s %-10s\n", "Name", "Age", "Salary");
        for (int i = 0; i < db.size; i++) {
            printf("%-20s %-10d %-10.2f\n", db.employees[i].name, db.employees[i].age, db.employees[i].salary);
        }
    }
}

// Function to query the database based on a user-entered search term
void queryDatabase(Database db) {
    char searchTerm[MAX];
    printf("Enter search term: ");
    scanf("%s", searchTerm);
    
    int results = 0;
    for (int i = 0; i < db.size; i++) {
        if (strstr(db.employees[i].name, searchTerm) != NULL) {
            printf("%-20s %-10d %-10.2f\n", db.employees[i].name, db.employees[i].age, db.employees[i].salary);
            results++;
        }
    }
    
    if (results == 0) {
        printf("No results found.\n");
    } else {
        printf("%d result(s) found.\n", results);
    }
}