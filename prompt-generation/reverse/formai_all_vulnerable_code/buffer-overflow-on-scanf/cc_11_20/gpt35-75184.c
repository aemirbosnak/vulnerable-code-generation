//FormAI DATASET v1.0 Category: Database simulation ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defining structure for the Employee records
struct Employee {
    int emp_id;
    char name[20];
    int age;
    float salary;
};

int main() {
    int choice, num_of_employees = 0, i;
    char filename[20], answer[3];
    FILE *fp;
    struct Employee emp;

    printf("Welcome to Employee Database Simulation Program\n");
    printf("Please choose from the following options:\n");
    printf("1. Add Employee Record\n");
    printf("2. Display All Employee Records\n");
    printf("3. Search Employee Record by ID\n");
    printf("4. Exit Program\n");

    while(1) {
        printf("\nEnter your choice (1-4): ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice) {
            case 1: // Adding new employee record
                printf("\nEnter the employee ID: ");
                scanf("%d", &emp.emp_id);
                fflush(stdin);

                printf("Enter the employee name: ");
                gets(emp.name);
                fflush(stdin);

                printf("Enter the employee age: ");
                scanf("%d", &emp.age);
                fflush(stdin);

                printf("Enter the employee salary: ");
                scanf("%f", &emp.salary);
                fflush(stdin);

                // Writing the record to the file
                fp = fopen("employee_records.txt", "a");
                if(fp == NULL) {
                    printf("Error in opening file!\n");
                    exit(1);
                }
                fwrite(&emp, sizeof(emp), 1, fp);
                fclose(fp);
                num_of_employees++;
                break;

            case 2: // Displaying all employee records
                fp = fopen("employee_records.txt", "r");
                if(fp == NULL) {
                    printf("Error in opening file!\n");
                    exit(1);
                }
                printf("\nTotal number of employees: %d\n", num_of_employees);
                printf("------------------------------------------------\n");
                printf("ID\tName\tAge\tSalary\n");
                printf("------------------------------------------------\n");
                while(fread(&emp, sizeof(emp), 1, fp) == 1) {
                    printf("%d\t%s\t%d\t%.2f\n", emp.emp_id, emp.name, emp.age, emp.salary);
                }
                fclose(fp);
                break;

            case 3: // Searching employee record by ID
                fp = fopen("employee_records.txt", "r");
                if(fp == NULL) {
                    printf("Error in opening file!\n");
                    exit(1);
                }
                printf("\nEnter the employee ID to search: ");
                scanf("%d", &i);
                fflush(stdin);
                while(fread(&emp, sizeof(emp), 1, fp) == 1) {
                    if(emp.emp_id == i) {
                        printf("------------------------------------------------\n");
                        printf("ID\tName\tAge\tSalary\n");
                        printf("------------------------------------------------\n");
                        printf("%d\t%s\t%d\t%.2f\n", emp.emp_id, emp.name, emp.age, emp.salary);
                        break;
                    }
                }
                fclose(fp);
                break;

            case 4: // Exiting the program
                printf("\nDo you want to exit the program? (Yes/No): ");
                gets(answer);
                if(strcmp(answer, "Yes") == 0 || strcmp(answer, "yes") == 0) {
                    printf("Exiting the program......\n");
                    exit(0);
                }
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}