//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

typedef struct {
    char *name;
    int age;
    float salary;
} employee;

employee emp_list[MAX_SIZE];
int emp_count = 0;

void add_employee() {
    if (emp_count >= MAX_SIZE) {
        printf("Error: Maximum employee limit reached!\n");
        return;
    }

    employee *new_emp = &emp_list[emp_count];

    printf("Enter employee name: ");
    scanf("%s", new_emp->name);

    printf("Enter employee age: ");
    scanf("%d", &new_emp->age);

    printf("Enter employee salary: ");
    scanf("%f", &new_emp->salary);

    emp_count++;
}

void search_employee() {
    char search_name[50];

    printf("Enter employee name to search: ");
    scanf("%s", search_name);

    int found = 0;

    for (int i = 0; i < emp_count; i++) {
        if (strcmp(emp_list[i].name, search_name) == 0) {
            printf("\nEmployee found:\n");
            printf("Name: %s\n", emp_list[i].name);
            printf("Age: %d\n", emp_list[i].age);
            printf("Salary: %.2f\n", emp_list[i].salary);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee not found!\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nEmployee Management System\n");
        printf("1. Add employee\n");
        printf("2. Search employee\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_employee();
                break;
            case 2:
                search_employee();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice!= 3);

    return 0;
}