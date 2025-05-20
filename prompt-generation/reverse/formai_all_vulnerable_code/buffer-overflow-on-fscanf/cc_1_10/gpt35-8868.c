//FormAI DATASET v1.0 Category: Database querying ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char name[50];
    char department[50];
    int age;
    float salary;
};

void addEmployee() {
    struct employee emp;
    FILE *fptr;
    fptr = fopen("employees.txt", "a");
    printf("\nEnter Employee Name: ");
    scanf("%s",emp.name);
    printf("\nEnter Department: ");
    scanf("%s", emp.department);
    printf("\nEnter Age: ");
    scanf("%d",&emp.age);
    printf("\nEnter Salary: ");
    scanf("%f", &emp.salary);
    fprintf(fptr,"%s %s %d %.2f\n",emp.name,emp.department,emp.age, emp.salary);
    fclose(fptr);
    printf("Employee details added successfully!\n\n");
}

void viewEmployee() {
    struct employee emp;
    FILE *fptr;
    fptr = fopen("employees.txt","r");
    printf("\n\nName\t\tDepartment\tAge\tSalary\n\n");
    while(fscanf(fptr,"%s %s %d %f\n", emp.name, emp.department, &emp.age, &emp.salary) != EOF) {
        printf("%s\t\t%s\t\t%d\t%.2f\n",emp.name,emp.department,emp.age, emp.salary);
    }
    fclose(fptr);
}

void findEmployee() {
    struct employee emp;
    FILE *fptr;
    char name[50];
    printf("\nEnter Employee Name to search: ");
    scanf("%s", name);
    fptr = fopen("employees.txt", "r");
    while(fscanf(fptr, "%s %s %d %f\n", emp.name, emp.department, &emp.age, &emp.salary) != EOF) {
        if(strcmp(emp.name,name) == 0) {
            printf("\nRecord Found!\n\n");
            printf("Name\t\tDepartment\tAge\tSalary\n\n");
            printf("%s\t\t%s\t\t%d\t%.2f\n\n",emp.name, emp.department, emp.age, emp.salary);
            fclose(fptr);
            return;
        }
    }
    printf("\nRecord not found for %s\n\n",name);
    fclose(fptr);
}

int main() {
    char option;
    while(1) {
        printf("Select an Option:\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Find Employee\n");
        printf("4. Exit\n\n");

        printf("Enter option: ");
        scanf(" %c", &option);

        switch(option) {
            case '1':
                addEmployee();
                break;
            case '2':
                viewEmployee();
                break;
            case '3':
                findEmployee();
                break;
            case '4':
                printf("\nExiting Program...Goodbye!\n");
                exit(0);
            default:
                printf("\nPlease select a valid option...\n\n");
        }
    }
}