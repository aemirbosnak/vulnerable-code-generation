//FormAI DATASET v1.0 Category: Database simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

int main() {
    int numEmployees = 0;
    Employee *database = NULL;
    int choice = 0;
    
    do {
        printf("DATABASE\n");
        printf("------------------\n");
        printf("1. Add employee\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Delete employee by ID\n");
        printf("5. Exit\n");
        printf("------------------\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Add employee
                numEmployees++;
                database = realloc(database, numEmployees * sizeof(Employee));
                
                printf("Enter ID: ");
                scanf("%d", &database[numEmployees-1].id);
                
                printf("Enter name: ");
                scanf("%s", database[numEmployees-1].name);
                
                printf("Enter salary: ");
                scanf("%f", &database[numEmployees-1].salary);
                
                printf("Employee added successfully!\n");
                break;
                
            case 2: // Display all employees
                printf("EMPLOYEES\n");
                printf("------------------\n");
                for (int i = 0; i < numEmployees; i++) {
                    printf("ID: %d\n", database[i].id);
                    printf("Name: %s\n", database[i].name);
                    printf("Salary: $%.2f\n", database[i].salary);
                    printf("------------------\n");
                }
                break;
                
            case 3: // Search employee by ID
                printf("Enter employee ID to search: ");
                int searchID;
                scanf("%d", &searchID);
                
                for (int i = 0; i < numEmployees; i++) {
                    if (database[i].id == searchID) {
                        printf("Employee found!\n");
                        printf("ID: %d\n", database[i].id);
                        printf("Name: %s\n", database[i].name);
                        printf("Salary: $%.2f\n", database[i].salary);
                        break;
                    }
                    else if (i == numEmployees-1) {
                        printf("Employee not found.\n");
                    }
                }
                break;
                
            case 4: // Delete employee by ID
                printf("Enter employee ID to delete: ");
                int deleteID;
                scanf("%d", &deleteID);
                
                for (int i = 0; i < numEmployees; i++) {
                    if (database[i].id == deleteID) {
                        for (int j = i; j < numEmployees-1; j++) {
                            database[j] = database[j+1];
                        }
                        numEmployees--;
                        database = realloc(database, numEmployees * sizeof(Employee));
                        printf("Employee deleted successfully!\n");
                        break;
                    }
                    else if (i == numEmployees-1) {
                        printf("Employee not found.\n");
                    }
                }
                break;
                
            case 5: // Exit
                printf("Exiting program...\n");
                free(database);
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        printf("\n");
    } while (choice != 5);
    
    return 0;
}