//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
    float salary;
} Employee;

Employee employees[MAX_RECORDS];
int num_records = 0;

void addNewRecord()
{
    Employee emp;
    printf("Enter employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee age: ");
    scanf("%d", &emp.age);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);

    employees[num_records] = emp;
    num_records++;
}

void displayRecords()
{
    printf("ID\tName\tAge\tSalary\n");
    for(int i=0; i<num_records; i++) {
        printf("%d\t%s\t%d\t%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

void searchById()
{
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);

    for(int i=0; i<num_records; i++) {
        if(employees[i].id == id) {
            printf("ID\tName\tAge\tSalary\n");
            printf("%d\t%s\t%d\t%.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
            return;
        }
    }

    printf("No employee found with ID %d\n", id);
}

int main()
{
    int choice;
    while(1) {
        printf("\n****** MENU ******\n");
        printf("1. Add new record\n");
        printf("2. Display all records\n");
        printf("3. Search record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNewRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchById();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}