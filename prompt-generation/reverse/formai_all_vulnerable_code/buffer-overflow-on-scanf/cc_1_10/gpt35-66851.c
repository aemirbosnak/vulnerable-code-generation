//FormAI DATASET v1.0 Category: Database simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

// Define the Employee struct
typedef struct {
    int id;
    char name[20];
    char position[20];
    int age;
    double salary;
} Employee;

// Function declarations
int menu();
void createDatabase(Employee[]);
void displayDatabase(Employee[]);
void addEmployee(Employee[]);
void editEmployee(Employee[]);
void deleteEmployee(Employee[]);
void searchEmployee(Employee[]);
void sortByName(Employee[]);

// Main function
int main() {
    int choice;
    Employee database[MAX_SIZE];
    
    while(1) {
        choice = menu();
    
        switch(choice) {
            case 1:
                createDatabase(database);
                break;
            case 2:
                displayDatabase(database);
                break;
            case 3:
                addEmployee(database);
                break;
            case 4:
                editEmployee(database);
                break;
            case 5:
                deleteEmployee(database);
                break;
            case 6:
                searchEmployee(database);
                break;
            case 7:
                sortByName(database);
                break;
            case 8:
                printf("Exiting program...");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}

// Function to display the menu and get user's choice
int menu() {
    int choice;
    
    printf("\n***************************************\n");
    printf("           EMPLOYEE DATABASE\n");
    printf("***************************************\n");
    printf("1. Create Database\n");
    printf("2. Display Database\n");
    printf("3. Add Employee\n");
    printf("4. Edit Employee\n");
    printf("5. Delete Employee\n");
    printf("6. Search Employee\n");
    printf("7. Sort by Name\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    return choice;
}

// Function to create the database
void createDatabase(Employee database[]) {
    int i;
    
    for(i=0; i<MAX_SIZE; i++) {
        database[i].id = 0;
        strcpy(database[i].name, "");
        strcpy(database[i].position, "");
        database[i].age = 0;
        database[i].salary = 0.0;
    }
    
    printf("Database created successfully.\n");
}

// Function to display the database
void displayDatabase(Employee database[]) {
    int i;
    int count = 0;
    
    printf("\n***************************************\n");
    printf("                DATABASE\n");
    printf("***************************************\n");
    printf("ID\tNAME\t\tPOSITION\tAGE\tSALARY\n");
    
    for(i=0; i<MAX_SIZE; i++) {
        if(database[i].id != 0) {
            printf("%d\t%s\t\t%s\t%d\t%.2f\n", 
                database[i].id, 
                database[i].name, 
                database[i].position, 
                database[i].age, 
                database[i].salary
            );
            count++;
        }
    }
    
    if(count == 0) {
        printf("There are no employees in the database.\n");
    }
}

// Function to add a new employee
void addEmployee(Employee database[]) {
    int i;
    int id;
    char name[20];
    char position[20];
    int age;
    double salary;
    int found = 0;
    
    printf("Enter the employee's id: ");
    scanf("%d", &id);
    
    for(i=0; i<MAX_SIZE; i++) {
        if(database[i].id == id) {
            found = 1;
            break;
        }
    }
    
    if(found == 1) {
        printf("An employee with that id already exists.\n");
    } else {
        printf("Enter the employee's name: ");
        scanf("%s", &name);
        printf("Enter the employee's position: ");
        scanf("%s", &position);
        printf("Enter the employee's age: ");
        scanf("%d", &age);
        printf("Enter the employee's salary: ");
        scanf("%lf", &salary);
        
        for(i=0; i<MAX_SIZE; i++) {
            if(database[i].id == 0) {
                database[i].id = id;
                strcpy(database[i].name, name);
                strcpy(database[i].position, position);
                database[i].age = age;
                database[i].salary = salary;
                printf("Employee added successfully.\n");
                break;
            }
        }
    }
}

// Function to edit an existing employee
void editEmployee(Employee database[]) {
    int i;
    int id;
    int found = 0;
    char choice;
    
    printf("Enter the id of the employee to edit: ");
    scanf("%d", &id);
    
    for(i=0; i<MAX_SIZE; i++) {
        if(database[i].id == id) {
            found = 1;
            printf("\nEdit Menu\n");
            printf("1. Name\n");
            printf("2. Position\n");
            printf("3. Age\n");
            printf("4. Salary\n");
            printf("Enter your choice: ");
            scanf(" %c", &choice);
            
            switch(choice) {
                case '1':
                    printf("Enter the new name: ");
                    scanf("%s", &database[i].name);
                    break;
                case '2':
                    printf("Enter the new position: ");
                    scanf("%s", &database[i].position);
                    break;
                case '3':
                    printf("Enter the new age: ");
                    scanf("%d", &database[i].age);
                    break;
                case '4':
                    printf("Enter the new salary: ");
                    scanf("%lf", &database[i].salary);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            
            printf("Employee edited successfully.\n");
            break;
        }
    }
    
    if(found == 0) {
        printf("An employee with that id does not exist.\n");
    }
}

// Function to delete an existing employee
void deleteEmployee(Employee database[]) {
    int i;
    int id;
    int found = 0;
    
    printf("Enter the id of the employee to delete: ");
    scanf("%d", &id);
    
    for(i=0; i<MAX_SIZE; i++) {
        if(database[i].id == id) {
            found = 1;
            database[i].id = 0;
            strcpy(database[i].name, "");
            strcpy(database[i].position, "");
            database[i].age = 0;
            database[i].salary = 0.0;
            printf("Employee deleted successfully.\n");
            break;
        }
    }
    
    if(found == 0) {
        printf("An employee with that id does not exist.\n");
    }
}

// Function to search for an existing employee
void searchEmployee(Employee database[]) {
    int i;
    int id;
    int found = 0;
    
    printf("Enter the id of the employee to search for: ");
    scanf("%d", &id);
    
    for(i=0; i<MAX_SIZE; i++) {
        if(database[i].id == id) {
            found = 1;
            printf("\nID\tNAME\t\tPOSITION\tAGE\tSALARY\n");
            printf("%d\t%s\t\t%s\t%d\t%.2f\n", 
                database[i].id, 
                database[i].name, 
                database[i].position, 
                database[i].age, 
                database[i].salary
            );
            break;
        }
    }
    
    if(found == 0) {
        printf("An employee with that id does not exist.\n");
    }
}

// Function to sort the database by name
void sortByName(Employee database[]) {
    int i, j;
    Employee temp;
    
    for(i=0; i<MAX_SIZE; i++) {
        for(j=i+1; j<MAX_SIZE; j++) {
            if(strcmp(database[i].name, database[j].name) > 0) {
                temp = database[i];
                database[i] = database[j];
                database[j] = temp;
            }
        }
    }
    
    printf("Database sorted successfully.\n");
}