//FormAI DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an entry in the database
typedef struct {
    int id;
    char name[20];
    int age;
    float salary;
} Employee;

// Function to display the menu and return the user's choice
int displayMenu() {
    int choice;
    printf("\n\n============ Employee Database ============\n");
    printf("1. Add new employee\n");
    printf("2. View all employees\n");
    printf("3. Update employee details\n");
    printf("4. Search employee by ID\n");
    printf("5. Delete employee by ID\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to add a new employee to the database
void addEmployee(Employee *database, int *numEmployees) {
    printf("\n\n============ Add New Employee ============\n");
    printf("Enter employee name: ");
    scanf("%s", database[*numEmployees].name);
    printf("Enter employee age: ");
    scanf("%d", &database[*numEmployees].age);
    printf("Enter employee salary: ");
    scanf("%f", &database[*numEmployees].salary);
    database[*numEmployees].id = *numEmployees + 1;
    (*numEmployees)++;
    printf("Employee added successfully!\n");
}

// Function to view all employees in the database
void viewEmployees(Employee *database, int numEmployees) {
    printf("\n\n============ Employee List ============\n");
    printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Salary");
    for (int i = 0; i < numEmployees; i++) {
        printf("%-10d %-20s %-10d %-10.2f\n", database[i].id, database[i].name, database[i].age, database[i].salary);
    }
}

// Function to update an employee's details in the database
void updateEmployee(Employee *database, int numEmployees) {
    int id;
    printf("\n\n============ Update Employee ============\n");
    printf("Enter employee ID: ");
    scanf("%d", &id);

    // Check if the ID is valid
    if (id > 0 && id <= numEmployees) {
        printf("Current details:\n");
        printf("Name: %s\n", database[id-1].name);
        printf("Age: %d\n", database[id-1].age);
        printf("Salary: %.2f\n", database[id-1].salary);
        printf("\nEnter new details:\n");
        printf("New name (press enter to keep current name): ");
        char newName[20];
        fgets(newName, 20, stdin);
        fgets(newName, 20, stdin);
        if (strlen(newName) > 1) {
            strcpy(database[id-1].name, newName);
        }
        printf("New age (press enter to keep current age): ");
        char newAge[5];
        fgets(newAge, 5, stdin);
        if (strlen(newAge) > 1) {
            sscanf(newAge, "%d", &database[id-1].age);
        }
        printf("New salary (press enter to keep current salary): ");
        char newSalary[10];
        fgets(newSalary, 10, stdin);
        if (strlen(newSalary) > 1) {
            sscanf(newSalary, "%f", &database[id-1].salary);
        }
        printf("Employee details updated successfully!\n");
    } else {
        printf("Invalid ID. Please try again.\n");
    }
}

// Function to search for an employee by ID
void searchEmployee(Employee *database, int numEmployees) {
    int id;
    printf("\n\n============ Search Employee ============\n");
    printf("Enter employee ID: ");
    scanf("%d", &id);

    // Check if the ID is valid
    if (id > 0 && id <= numEmployees) {
        printf("%-10s %-20s %-10s %-10s\n", "ID", "Name", "Age", "Salary");
        printf("%-10d %-20s %-10d %-10.2f\n", database[id-1].id, database[id-1].name, database[id-1].age, database[id-1].salary);
    } else {
        printf("Invalid ID. Please try again.\n");
    }
}

// Function to delete an employee by ID
void deleteEmployee(Employee *database, int *numEmployees) {
    int id;
    printf("\n\n============ Delete Employee ============\n");
    printf("Enter employee ID: ");
    scanf("%d", &id);

    // Check if the ID is valid
    if (id > 0 && id <= *numEmployees) {
        // Remove the employee by shifting all elements after it back
        for (int i = id; i < *numEmployees; i++) {
            database[i-1] = database[i];
        }
        (*numEmployees)--;
        printf("Employee deleted successfully!\n");
    } else {
        printf("Invalid ID. Please try again.\n");
    }
}

int main() {
    Employee database[100]; // Initialize database with maximum capacity of 100 employees
    int numEmployees = 0;   // Counter for number of employees currently in database

    int choice;
    do {
        choice = displayMenu();

        switch(choice) {
            case 1:
                addEmployee(database, &numEmployees);
                break;
            case 2:
                viewEmployees(database, numEmployees);
                break;
            case 3:
                updateEmployee(database, numEmployees);
                break;
            case 4:
                searchEmployee(database, numEmployees);
                break;
            case 5:
                deleteEmployee(database, &numEmployees);
                break;
            case 6:
                printf("Exiting... \n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 6);

    return 0;
}