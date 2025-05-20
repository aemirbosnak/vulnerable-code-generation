//FormAI DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    float salary;
} Employee;

Employee employees[MAX_RECORDS];
int num_records = 0;

void add_employee() {
    int id;
    char name[20];
    float salary;

    printf("Enter employee ID: ");
    scanf("%d", &id);

    printf("Enter employee name: ");
    scanf("%s", &name);

    printf("Enter employee salary: ");
    scanf("%f", &salary);

    employees[num_records].id = id;
    strcpy(employees[num_records].name, name);
    employees[num_records].salary = salary;

    num_records++;
    printf("Employee added successfully!\n");
}

void print_employees() {
    printf("ID\tName\tSalary\n");

    for (int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

void menu() {
    printf("------------------------\n");
    printf("MENU\n");
    printf("------------------------\n");
    printf("1. Add employee\n");
    printf("2. Print employees\n");
    printf("3. Quit\n");
    printf("------------------------\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_employee();
                break;
            case 2:
                print_employees();
                break;
            case 3:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}