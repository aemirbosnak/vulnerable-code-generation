//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
    int age;
    float salary;
} Employee;

int main() {
    Employee db[MAX_SIZE];  // create an array to hold a maximum of MAX_SIZE employees
    int numEmployees = 0;   // initialize number of employees to zero
    int choice;

    while (1) {
        printf("\n---- Database ----\n");
        printf("1 - Add Employee\n");
        printf("2 - Remove Employee\n");
        printf("3 - Search for Employee\n");
        printf("4 - Display All Employees\n");
        printf("5 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Employee newEmployee;
                printf("\nEnter Employee Details:\n");
                printf("ID: ");
                scanf("%d", &newEmployee.id);
                printf("Name: ");
                scanf("%s", newEmployee.name);
                printf("Age: ");
                scanf("%d", &newEmployee.age);
                printf("Salary: ");
                scanf("%f", &newEmployee.salary);

                db[numEmployees] = newEmployee; // add new employee to the database
                numEmployees++; // increase the number of employees in the database

                printf("\nEmployee Added!\n");
                break;
            }

            case 2: {
                int idToRemove;
                printf("\nEnter Employee ID to Remove: ");
                scanf("%d", &idToRemove);

                int found = 0;
                for (int i = 0; i < numEmployees; i++) {
                    if (db[i].id == idToRemove) {
                        found = 1;
                        for (int j = i; j < numEmployees - 1; j++) {
                            db[j] = db[j+1];
                        }
                        numEmployees--;
                        printf("\nEmployee Removed!\n");
                    }
                }

                if (!found) {
                    printf("\nEmployee ID not found.\n");
                }

                break;
            }

            case 3: {
                int idToSearch;
                printf("\nEnter Employee ID to Search for: ");
                scanf("%d", &idToSearch);

                int found = 0;
                for (int i = 0; i < numEmployees; i++) {
                    if (db[i].id == idToSearch) {
                        found = 1;
                        printf("\nEmployee Details:\n");
                        printf("ID: %d\n", db[i].id);
                        printf("Name: %s\n", db[i].name);
                        printf("Age: %d\n", db[i].age);
                        printf("Salary: %.2f\n", db[i].salary);
                    }
                }

                if (!found) {
                    printf("\nEmployee ID not found.\n");
                }

                break;
            }

            case 4: {
                if (numEmployees == 0) {
                    printf("\nNo Employees Found!\n");
                } else {
                    printf("\nAll Employees:\n");
                    for (int i = 0; i < numEmployees; i++) {
                        printf("ID: %d\n", db[i].id);
                        printf("Name: %s\n", db[i].name);
                        printf("Age: %d\n", db[i].age);
                        printf("Salary: %.2f\n", db[i].salary);
                        printf("\n");
                    }
                }

                break;
            }

            case 5: {
                printf("\nExiting Program.\n");
                exit(0);
            }

            default:
                printf("\nInvalid Choice. Try Again.\n");
        }
    }

    return 0;
}