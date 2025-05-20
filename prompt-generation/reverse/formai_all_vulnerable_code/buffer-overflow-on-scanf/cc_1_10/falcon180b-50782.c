//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float salary;
} Employee;

void write_to_file(Employee *employee) {
    FILE *fp;
    fp = fopen("employee.txt", "a");
    if (fp == NULL) {
        printf("Error in file opening\n");
        exit(1);
    }
    fprintf(fp, "Name: %s\nAge: %d\nSalary: %.2f\n", employee->name, employee->age, employee->salary);
    fclose(fp);
}

void read_from_file(Employee *employee) {
    FILE *fp;
    fp = fopen("employee.txt", "r");
    if (fp == NULL) {
        printf("Error in file opening\n");
        exit(1);
    }
    fscanf(fp, "Name: %s\nAge: %d\nSalary: %.2f", employee->name, &employee->age, &employee->salary);
    fclose(fp);
}

int main() {
    Employee emp1, emp2;
    int choice, i;
    char file_name[50];

    do {
        printf("\nEmployee Management System\n");
        printf("1. Create Employee Record\n2. Read Employee Record\n3. Update Employee Record\n4. Delete Employee Record\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter name (max 50 characters): ");
            scanf("%s", emp1.name);
            printf("Enter age: ");
            scanf("%d", &emp1.age);
            printf("Enter salary: ");
            scanf("%f", &emp1.salary);
            write_to_file(&emp1);
            break;

        case 2:
            printf("Enter file name: ");
            scanf("%s", file_name);
            read_from_file(&emp1);
            printf("\nName: %s\nAge: %d\nSalary: %.2f\n", emp1.name, emp1.age, emp1.salary);
            break;

        case 3:
            printf("Enter name to update: ");
            scanf("%s", emp1.name);
            printf("Enter new age: ");
            scanf("%d", &emp1.age);
            printf("Enter new salary: ");
            scanf("%f", &emp1.salary);
            write_to_file(&emp1);
            break;

        case 4:
            printf("Enter name to delete: ");
            scanf("%s", emp1.name);
            remove("employee.txt");
            write_to_file(&emp1);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    } while (1);
}