//FormAI DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure of the Database
struct Database {
    int id;
    char name[MAX_SIZE];
    int age;
    float salary;
};

int main() {
    struct Database employee[MAX_SIZE];
    int n, choice, id;
    int i = 0, flag = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    // Inputting the Employee Data
    for(i=0; i<n; i++) {
        printf("Enter the details of Employee %d:\n", i+1);
        printf("\tEmployee ID: ");
        scanf("%d", &employee[i].id);
        printf("\tName: ");
        scanf("%s", employee[i].name);
        printf("\tAge: ");
        scanf("%d", &employee[i].age);
        printf("\tSalary: ");
        scanf("%f", &employee[i].salary);
    }

    // Menu to Perform Operations on the Data
    do {
        printf("\n---------------MENU---------------\n");
        printf("1.Search by ID\n2.Display all\n3.Exit\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nEnter the ID to search: ");
                scanf("%d", &id);

                // Searching the Employee by ID
                for(i=0; i<n; i++) {
                    if(employee[i].id == id) {
                        printf("\nEmployee Found!\n");
                        printf("ID: %d\n", employee[i].id);
                        printf("Name: %s\n", employee[i].name);
                        printf("Age: %d\n", employee[i].age);
                        printf("Salary: %.2f\n", employee[i].salary);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nEmployee not found!\n");
                }
                break;

            case 2:
                printf("\n---------------All Employees---------------\n");
                printf("ID | Name        | Age | Salary\n");
                printf("--------------------------------------------\n");

                // Displaying All the Employees
                for(i=0; i<n; i++) {
                    printf("%d  | %-12s | %d  | %.2f\n", employee[i].id, employee[i].name, employee[i].age, employee[i].salary);
                }
                break;
            case 3:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid Choice!\nPlease try again.\n");
                break;
        }
    } while(choice != 3 );

    return 0;
}