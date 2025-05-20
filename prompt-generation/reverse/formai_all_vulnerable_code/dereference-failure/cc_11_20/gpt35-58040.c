//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for storing records
typedef struct{
    int id;
    char name[20];
    char address[50];
    float salary;
} Employee;

int main(){
    // declare variables
    Employee employees[5];
    int choice, id, i;
    char name[20], address[50];
    float salary;

    // loop for menu
    while(1){
        // display menu
        printf("\n1. Add Employee\n2. Display All Employees\n3. Search Employee by ID\n4. Update Employee by ID\n5. Delete Employee by ID\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // perform action based on user input
        switch(choice){
            case 1: // add employee
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                fflush(stdin); // clear input buffer
                printf("Enter Employee Name: ");
                gets(name);
                printf("Enter Employee Address: ");
                gets(address);
                printf("Enter Employee Salary: ");
                scanf("%f", &salary);
                employees[i].id = id;
                strcpy(employees[i].name, name);
                strcpy(employees[i].address, address);
                employees[i].salary = salary;
                printf("Employee record added successfully.\n");
                break;
            case 2: // display all employees
                printf("ID\tName\t\tAddress\t\tSalary\n");
                for(i=0;i<5;i++){
                    printf("%d\t%s\t\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].address, employees[i].salary);
                }
                break;
            case 3: // search employee by id
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                for(i=0;i<5;i++){
                    if(employees[i].id == id){
                        printf("ID\tName\t\tAddress\t\tSalary\n");
                        printf("%d\t%s\t\t%s\t\t%.2f\n", employees[i].id, employees[i].name, employees[i].address, employees[i].salary);
                        break;
                    }
                }
                if(i==5)
                    printf("No record found for the ID.\n");
                break;
            case 4: // update employee by id
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                for(i=0;i<5;i++){
                    if(employees[i].id == id){
                        fflush(stdin); // clear input buffer
                        printf("Enter Employee Name: ");
                        gets(name);
                        printf("Enter Employee Address: ");
                        gets(address);
                        printf("Enter Employee Salary: ");
                        scanf("%f", &salary);
                        strcpy(employees[i].name, name);
                        strcpy(employees[i].address, address);
                        employees[i].salary = salary;
                        printf("Employee record updated successfully.\n");
                        break;
                    }
                }
                if(i==5)
                    printf("No record found for the ID.\n");
                break;
            case 5: // delete employee by id
                printf("Enter Employee ID: ");
                scanf("%d", &id);
                for(i=0;i<5;i++){
                    if(employees[i].id == id){
                        employees[i].id = 0;
                        strcpy(employees[i].name, "");
                        strcpy(employees[i].address, "");
                        employees[i].salary = 0.0;
                        printf("Employee record deleted successfully.\n");
                        break;
                    }
                }
                if(i==5)
                    printf("No record found for the ID.\n");
                break;
            case 6: // exit
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}