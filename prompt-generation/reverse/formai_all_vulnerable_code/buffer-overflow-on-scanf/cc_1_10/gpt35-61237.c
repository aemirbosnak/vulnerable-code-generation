//FormAI DATASET v1.0 Category: Database simulation ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_RECORDS 1000
#define MAX_STRING_SIZE 50

typedef struct {
    int id;
    char name[MAX_STRING_SIZE];
    int age;
    float salary;
} Employee;

Employee records[MAX_RECORDS];
int num_records = 0;

void addRecord() {
    Employee new_employee;
    printf("Enter employee details:\n");
    printf("ID: ");
    scanf("%d", &new_employee.id);
    printf("Name: ");
    scanf("%s", new_employee.name);
    printf("Age: ");
    scanf("%d", &new_employee.age);
    printf("Salary: ");
    scanf("%f", &new_employee.salary);
    records[num_records] = new_employee;
    num_records++;
    printf("Record added successfully.\n");
}

void deleteRecord() {
    int id;
    printf("Enter ID of employee to delete: ");
    scanf("%d", &id);
    bool found = false;
    for (int i = 0; i < num_records; i++) {
        if (records[i].id == id) {
            found = true;
            for (int j = i; j < num_records - 1; j++) {
                records[j] = records[j+1];
            }
            num_records--;
        }
    }
    if (!found) {
        printf("Employee ID not found.\n");
    } else {
        printf("Record deleted successfully.\n");
    }
}

void displayRecords() {
    printf("ID\tName\tAge\tSalary\n");
    for (int i = 0; i < num_records; i++) {
        Employee current_employee = records[i];
        printf("%d\t%s\t%d\t%.2f\n", current_employee.id, current_employee.name, current_employee.age, current_employee.salary);
    }
}

int menu() {
    int choice;
    printf("1. Add new record. \n2. Delete a record. \n3. Display all records. \n4. Exit.\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    printf("Welcome to Employee Database.\n");
    while (true) {
        int choice = menu();
        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                displayRecords();
                break;
            case 4:
                printf("Exiting Employee Database.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}