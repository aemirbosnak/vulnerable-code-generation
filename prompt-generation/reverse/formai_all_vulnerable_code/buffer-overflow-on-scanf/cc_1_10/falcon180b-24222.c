//Falcon-180B DATASET v1.0 Category: System administration ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void addEmployee(Employee* emp, int size) {
    printf("Enter employee name: ");
    scanf("%s", emp->name);
    printf("Enter employee age: ");
    scanf("%d", &emp->age);
    printf("Enter employee salary: ");
    scanf("%f", &emp->salary);
    size++;
}

void displayEmployees(Employee* emp, int size) {
    printf("\nEmployee Details:\n");
    printf("-------------------\n");
    printf("Name\tAge\tSalary\n");
    for(int i=0; i<size; i++) {
        printf("%s\t%d\t%.2f\n", emp[i].name, emp[i].age, emp[i].salary);
    }
}

void sortEmployees(Employee* emp, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(emp[i].age > emp[j].age) {
                Employee temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
}

int main() {
    Employee emp[100];
    int size = 0;
    char choice;
    do {
        printf("\nEmployee Management System\n");
        printf("---------------------------\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Sort employees by age\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch(choice) {
            case '1':
                addEmployee(emp, size);
                break;
            case '2':
                displayEmployees(emp, size);
                break;
            case '3':
                sortEmployees(emp, size);
                displayEmployees(emp, size);
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= '4');
    return 0;
}