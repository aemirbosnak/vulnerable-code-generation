//FormAI DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[20];
    char department[20];
    float salary;
};

int main(){

    //creating database and initializing variables
    struct employee emp[10];
    int choice, id, index = 0;
    float salary;
    char name[20], department[20];

    //menu for user to interact with the database
    while(1){
        printf("\nSelect an operation to perform on the employee database\n");
        printf("1. Add Employee\n");
        printf("2. Search Employee by ID\n");
        printf("3. Update Employee Salary by ID\n");
        printf("4. Delete Employee by ID\n");
        printf("5. Display all Employees\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1: //adding an employee to the database
                printf("Enter Employee ID: ");
                scanf("%d", &id);

                printf("Enter Employee Name: ");
                scanf("%s", name);

                printf("Enter Employee Department: ");
                scanf("%s", department);

                printf("Enter Employee Salary: ");
                scanf("%f", &salary);

                emp[index].id = id;
                strcpy(emp[index].name, name);
                strcpy(emp[index].department, department);
                emp[index].salary = salary;

                printf("\nEmployee Added Successfully!\n");
                index++;
                break;

            case 2: //searching for an employee by ID
                printf("Enter Employee ID to Search: ");
                scanf("%d", &id);

                for(int i=0; i<index; i++){
                    if(emp[i].id == id){
                        printf("\nEmployee Found!\n");
                        printf("ID: %d\n", emp[i].id);
                        printf("Name: %s\n", emp[i].name);
                        printf("Department: %s\n", emp[i].department);
                        printf("Salary: %.2f\n", emp[i].salary);
                        break;
                    }
                    if(i == index-1) printf("\nEmployee not found!\n");
                }
                break;

            case 3: //updating an employee's salary by ID
                printf("Enter Employee ID to update Salary: ");
                scanf("%d", &id);

                for(int i=0; i<index; i++){
                    if(emp[i].id == id){
                        printf("Enter New Salary: ");
                        scanf("%f", &salary);
                        emp[i].salary = salary;
                        printf("\nSalary Updated Successfully!\n");
                        break;
                    }
                    if(i == index-1) printf("\nEmployee not found!\n");
                }
                break;

            case 4: //deleting an employee from the database by ID
                printf("Enter Employee ID to Delete: ");
                scanf("%d", &id);

                for(int i=0; i<index; i++){
                    if(emp[i].id == id){
                        for(int j=i; j<index-1; j++){
                            emp[j] = emp[j+1];
                        }
                        index--;
                        printf("\nEmployee Deleted Successfully!\n");
                        break;
                    }
                    if(i == index-1) printf("\nEmployee not found!\n");
                }
                break;

            case 5: //displaying all employees in the database
                printf("\nEmployee Database:\n\n");
                for(int i=0; i<index; i++){
                    printf("ID: %d\n", emp[i].id);
                    printf("Name: %s\n", emp[i].name);
                    printf("Department: %s\n", emp[i].department);
                    printf("Salary: %.2f\n\n", emp[i].salary);
                }
                break;

            case 6: //exiting the program
                exit(0);
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
                break;
        }
    }

    return 0;
}