//FormAI DATASET v1.0 Category: Database simulation ; Style: invasive
#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[20];
    int age;
    float salary;
};

void printAllEmployees(struct Employee *employees, int size) {
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%d\t%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

int main() {
    struct Employee employees[50]; // database can hold up to 50 employees
    int numEmployees = 0;
    int choice;

    do {
        printf("\n1. Add Employee\n");
        printf("2. Delete Employee\n");
        printf("3. Print All Employees\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (numEmployees == 50) {
                    printf("Database is full. Cannot add new employee.\n");
                    break;
                }

                printf("Enter ID: ");
                scanf("%d", &employees[numEmployees].id);

                // check if ID already exists
                for (int i = 0; i < numEmployees; i++) {
                    if (employees[i].id == employees[numEmployees].id) {
                        printf("Employee with ID %d already exists.\n", employees[numEmployees].id);
                        break;
                    }
                }

                printf("Enter Name: ");
                scanf("%s", employees[numEmployees].name);

                printf("Enter Age: ");
                scanf("%d", &employees[numEmployees].age);

                printf("Enter Salary: ");
                scanf("%f", &employees[numEmployees].salary);

                numEmployees++;
                printf("Employee Added Successfully.\n");
                break;

            case 2:
                if (numEmployees == 0) {
                    printf("Database is empty. Cannot delete employee.\n");
                    break;
                }
                printf("Enter ID of employee to delete: ");
                int idToDelete;
                scanf("%d", &idToDelete);

                int indexToDelete = -1;
                for (int i = 0; i < numEmployees; i++) {
                    if (employees[i].id == idToDelete) {
                        indexToDelete = i;
                        break;
                    }
                }

                if (indexToDelete == -1) {
                    printf("Employee with ID %d not found.\n", idToDelete);
                    break;
                }

                // shift all employees after indexToDelete, one index back
                for (int i = indexToDelete; i < numEmployees-1; i++) {
                    employees[i] = employees[i+1];
                }

                numEmployees--;
                printf("Employee with ID %d deleted successfully.\n", idToDelete);
                break;

            case 3:
                if (numEmployees == 0) {
                    printf("Database is empty. No employees to display.\n");
                } else {
                    printAllEmployees(employees, numEmployees);
                }
                break;

            case 4:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}