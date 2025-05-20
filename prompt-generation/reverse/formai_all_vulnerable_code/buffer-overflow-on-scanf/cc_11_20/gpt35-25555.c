//FormAI DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    int id;
    char name[20];
    char address[50];
    float salary;
}Employee;

int main()
{
    Employee employees[MAX];
    int choice, count = 0, id = 0;

    while(1){
        printf("1. Add Employee\n");
        printf("2. Show Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch(choice){
            case 1:{
                if(count < MAX){
                    Employee employee;
                    id++;
                    employee.id = id;

                    printf("Enter employee name: ");
                    scanf("%s", employee.name);

                    printf("Enter employee address: ");
                    scanf("%s", employee.address);

                    printf("Enter employee salary: ");
                    scanf("%f", &employee.salary);

                    employees[count] = employee;
                    count++;
                }
                else{
                    printf("Database is full!\n");
                }
                break;
            }

            case 2:{
                for(int i = 0; i < count; i++){
                    printf("ID: %d, Name: %s, Address: %s, Salary: %f\n", 
                    employees[i].id, employees[i].name, employees[i].address, employees[i].salary);
                }
                break;
            }

            case 3:{
                int id;
                int employeeIndex = -1;

                printf("Enter employee id: ");
                scanf("%d", &id);

                for(int i = 0; i < count; i++){
                    if(employees[i].id == id){
                        employeeIndex = i;
                        break;
                    }
                }

                if(employeeIndex == -1){
                    printf("Employee not found!\n");
                }
                else{
                    printf("ID: %d, Name: %s, Address: %s, Salary: %f\n", 
                    employees[employeeIndex].id, employees[employeeIndex].name, 
                    employees[employeeIndex].address, employees[employeeIndex].salary);
                }
                break;
            }

            case 4:{
                int id;
                int employeeIndex = -1;

                printf("Enter employee id: ");
                scanf("%d", &id);

                for(int i = 0; i < count; i++){
                    if(employees[i].id == id){
                        employeeIndex = i;
                        break;
                    }
                }

                if(employeeIndex == -1){
                    printf("Employee not found!\n");
                }
                else{
                    printf("Enter employee name: ");
                    scanf("%s", employees[employeeIndex].name);

                    printf("Enter employee address: ");
                    scanf("%s", employees[employeeIndex].address);

                    printf("Enter employee salary: ");
                    scanf("%f", &employees[employeeIndex].salary);

                    printf("Employee updated successfully!\n");
                }
                break;
            }

            case 5:{
                int id;
                int employeeIndex = -1;

                printf("Enter employee id: ");
                scanf("%d", &id);

                for(int i = 0; i < count; i++){
                    if(employees[i].id == id){
                        employeeIndex = i;
                        break;
                    }
                }

                if(employeeIndex == -1){
                    printf("Employee not found!\n");
                }
                else{
                    for(int i = employeeIndex; i < count-1; i++){
                        employees[i] = employees[i+1];
                    }

                    count--;

                    printf("Employee deleted successfully!\n");
                }
                break;
            }

            case 6:{
                exit(0);
                break;
            }

            default:{
                printf("Invalid choice!\n");
                break;
            }
        }
    }

    return 0;
}