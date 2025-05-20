//FormAI DATASET v1.0 Category: File handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

struct employee {
    char name[50];
    int age;
    double salary;
};

void writeToFile() {
    FILE *fp;
    struct employee emp;
    
    fp = fopen("Employee.txt", "a");
    
    if (fp == NULL) {
        printf("Error in opening file!");
        exit(1);
    }
    
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Age: ");
    scanf("%d", &emp.age);
    printf("Enter Employee Salary: ");
    scanf("%lf", &emp.salary);
    
    fprintf(fp, "%s %d %.2lf\n", emp.name, emp.age, emp.salary);
    
    printf("Data written successfully!\n");
    fclose(fp);
}

void readFromFile() {
    FILE *fp;
    struct employee emp;
    
    fp = fopen("Employee.txt", "r");
    
    if (fp == NULL) {
        printf("Error in opening file!");
        exit(1);
    }
    
    printf("\n%-20s %-10s %-10s\n", "Name", "Age", "Salary");
    
    while (fscanf(fp, "%s %d %lf", emp.name, &emp.age, &emp.salary) != EOF) {
        printf("%-20s %-10d %-10.2lf\n", emp.name, emp.age, emp.salary);
    }
    
    fclose(fp);
}

int main() {
    int choice;
    
    do {
        printf("\n------- Employee Management System -------\n");
        printf("1. Add Employee\n");
        printf("2. View Employees\n");
        printf("3. Exit\n");
        printf("-------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                printf("Thank you for using the Employee Management System!");
                break;
            default:
                printf("Invalid choice! Please try again...");
        }
    } while (choice != 3);
    
    return 0;
}