//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    char address[100];
    float salary;
} Employee;

int main() {
    Employee employees[5]; // Create an array of 5 Employee structs
    
    printf("Enter the name of employee 1: ");
    scanf("%s", employees[0].name);
    printf("Enter the age of employee 1: ");
    scanf("%d", &employees[0].age);
    printf("Enter the address of employee 1: ");
    scanf("%s", employees[0].address);
    printf("Enter the salary of employee 1: ");
    scanf("%f", &employees[0].salary);
    
    printf("\nEnter the name of employee 2: ");
    scanf("%s", employees[1].name);
    printf("Enter the age of employee 2: ");
    scanf("%d", &employees[1].age);
    printf("Enter the address of employee 2: ");
    scanf("%s", employees[1].address);
    printf("Enter the salary of employee 2: ");
    scanf("%f", &employees[1].salary);
    
    printf("\nEnter the name of employee 3: ");
    scanf("%s", employees[2].name);
    printf("Enter the age of employee 3: ");
    scanf("%d", &employees[2].age);
    printf("Enter the address of employee 3: ");
    scanf("%s", employees[2].address);
    printf("Enter the salary of employee 3: ");
    scanf("%f", &employees[2].salary);
    
    printf("\nEnter the name of employee 4: ");
    scanf("%s", employees[3].name);
    printf("Enter the age of employee 4: ");
    scanf("%d", &employees[3].age);
    printf("Enter the address of employee 4: ");
    scanf("%s", employees[3].address);
    printf("Enter the salary of employee 4: ");
    scanf("%f", &employees[3].salary);
    
    printf("\nEnter the name of employee 5: ");
    scanf("%s", employees[4].name);
    printf("Enter the age of employee 5: ");
    scanf("%d", &employees[4].age);
    printf("Enter the address of employee 5: ");
    scanf("%s", employees[4].address);
    printf("Enter the salary of employee 5: ");
    scanf("%f", &employees[4].salary);
    
    printf("\nEmployee 1:\nName: %s\nAge: %d\nAddress: %s\nSalary: %f\n\n", employees[0].name, employees[0].age, employees[0].address, employees[0].salary);
    printf("Employee 2:\nName: %s\nAge: %d\nAddress: %s\nSalary: %f\n\n", employees[1].name, employees[1].age, employees[1].address, employees[1].salary);
    printf("Employee 3:\nName: %s\nAge: %d\nAddress: %s\nSalary: %f\n\n", employees[2].name, employees[2].age, employees[2].address, employees[2].salary);
    printf("Employee 4:\nName: %s\nAge: %d\nAddress: %s\nSalary: %f\n\n", employees[3].name, employees[3].age, employees[3].address, employees[3].salary);
    printf("Employee 5:\nName: %s\nAge: %d\nAddress: %s\nSalary: %f\n\n", employees[4].name, employees[4].age, employees[4].address, employees[4].salary);
    
    return 0;
}