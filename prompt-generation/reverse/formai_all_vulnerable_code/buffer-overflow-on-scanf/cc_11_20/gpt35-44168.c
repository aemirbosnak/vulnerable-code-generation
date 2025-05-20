//FormAI DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

int main() {
    int choice;
    FILE* fptr;
    Employee emp;

    while(1) {
        printf("\nSelect an option:\n");
        printf("1. Add an employee record\n");
        printf("2. Display all employee records\n");
        printf("3. Search for an employee\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                fptr = fopen("employees.txt", "a");
                if(fptr == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                printf("\nEnter the employee's name: ");
                fgets(emp.name, sizeof(emp.name), stdin);
                emp.name[strcspn(emp.name, "\n")] = 0;

                printf("Enter the employee's age: ");
                scanf("%d", &emp.age);
                getchar();

                printf("Enter the employee's salary: ");
                scanf("%f", &emp.salary);
                getchar();

                fprintf(fptr, "%s %d %.2f\n", emp.name, emp.age, emp.salary);
                fclose(fptr);
                break;
            
            case 2:
                fptr = fopen("employees.txt", "r");
                if(fptr == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                printf("\nEmployee Records:\n");
                printf("----------------------------\n");
                printf("Name\t\tAge\tSalary\n");
                printf("----------------------------\n");

                while(fscanf(fptr, "%s %d %f", emp.name, &emp.age, &emp.salary) != EOF) {
                    printf("%-15s%-10d%.2f\n", emp.name, emp.age, emp.salary);
                }
                fclose(fptr);
                break;

            case 3:
                fptr = fopen("employees.txt", "r");
                if(fptr == NULL) {
                    printf("Error opening file!\n");
                    exit(1);
                }

                char search_name[50];
                printf("\nEnter the name of the employee you want to search: ");
                fgets(search_name, sizeof(search_name), stdin);
                search_name[strcspn(search_name, "\n")] = 0;

                int found = 0;

                while(fscanf(fptr, "%s %d %f", emp.name, &emp.age, &emp.salary) != EOF) {
                    if(strcmp(search_name, emp.name) == 0) {
                        printf("\nRecord Found:\n");
                        printf("Name: %s\n", emp.name);
                        printf("Age: %d\n", emp.age);
                        printf("Salary: %.2f\n", emp.salary);
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("\nRecord not found!\n");
                }
                fclose(fptr);
                break;

            case 4:
                printf("\nExiting program...");
                exit(0);
                break;

            default:
                printf("\nPlease enter a valid option!\n");
                break;
        }
    }

    return 0;
}