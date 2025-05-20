//FormAI DATASET v1.0 Category: Database querying ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    int emp_id;
    char emp_name[50];
    int emp_age;
    float emp_salary;
};

int main() {
    // Create an array of employee structure
    struct employee employees[5];
    int i, j, choice;
    float salary;
    char name[50];
    int id, age;

    // Add sample records to the database
    employees[0].emp_id = 1001;
    strcpy(employees[0].emp_name, "John Doe");
    employees[0].emp_age = 40;
    employees[0].emp_salary = 50000.00;

    employees[1].emp_id = 1002;
    strcpy(employees[1].emp_name, "Jane Smith");
    employees[1].emp_age = 35;
    employees[1].emp_salary = 60000.00;

    employees[2].emp_id = 1003;
    strcpy(employees[2].emp_name, "James Anderson");
    employees[2].emp_age = 45;
    employees[2].emp_salary = 70000.00;

    employees[3].emp_id = 1004;
    strcpy(employees[3].emp_name, "Mary Johnson");
    employees[3].emp_age = 30;
    employees[3].emp_salary = 40000.00;

    employees[4].emp_id = 1005;
    strcpy(employees[4].emp_name, "David Lee");
    employees[4].emp_age = 50;
    employees[4].emp_salary = 80000.00;

    printf("Welcome to Employee Database!\n");
    printf("Choose a search option:\n");
    printf("1. Search by Employee ID\n");
    printf("2. Search by Employee Name\n");
    printf("3. Search by Employee Age\n");
    printf("4. Search by Employee Salary\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter employee ID: ");
            scanf("%d", &id);
            for(i=0; i<5; i++) {
                if(employees[i].emp_id == id) {
                    printf("Employee ID: %d\n", employees[i].emp_id);
                    printf("Employee Name: %s\n", employees[i].emp_name);
                    printf("Employee Age: %d\n", employees[i].emp_age);
                    printf("Employee Salary: %.2f\n", employees[i].emp_salary);
                    break;
                }
            }
            if(i >= 5) printf("Employee ID not found in database!\n");
            break;

        case 2:
            printf("Enter employee name: ");
            scanf("%s", name);
            for(i=0; i<5; i++) {
                if(strcmp(employees[i].emp_name, name) == 0) {
                    printf("Employee ID: %d\n", employees[i].emp_id);
                    printf("Employee Name: %s\n", employees[i].emp_name);
                    printf("Employee Age: %d\n", employees[i].emp_age);
                    printf("Employee Salary: %.2f\n", employees[i].emp_salary);
                    break;
                }
            }
            if(i >= 5) printf("Employee name not found in database!\n");
            break;

        case 3:
            printf("Enter employee age: ");
            scanf("%d", &age);
            for(i=0; i<5; i++) {
                if(employees[i].emp_age == age) {
                    printf("Employee ID: %d\n", employees[i].emp_id);
                    printf("Employee Name: %s\n", employees[i].emp_name);
                    printf("Employee Age: %d\n", employees[i].emp_age);
                    printf("Employee Salary: %.2f\n", employees[i].emp_salary);
                }
            }
            break;

        case 4:
            printf("Enter employee salary: ");
            scanf("%f", &salary);
            for(i=0; i<5; i++) {
                if(employees[i].emp_salary == salary) {
                    printf("Employee ID: %d\n", employees[i].emp_id);
                    printf("Employee Name: %s\n", employees[i].emp_name);
                    printf("Employee Age: %d\n", employees[i].emp_age);
                    printf("Employee Salary: %.2f\n", employees[i].emp_salary);
                }
            }
            break;

        default:
            printf("Invalid choice! Please try again!\n");
            break;
    }

    return 0;
}