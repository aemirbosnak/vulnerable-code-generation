//FormAI DATASET v1.0 Category: Database simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct {
  int id;
  char name[50];
  char address[100];
  float salary;
} Employee;

void add_employee(Employee* employees, int* count);
void delete_employee(Employee* employees, int* count);
void update_employee(Employee* employees, int count);
void display_records(Employee* employees, int count);
int find_employee(Employee* employees, int count, int id);

int main(void) {
  Employee employees[MAX_RECORDS];
  int count = 0;
  int choice;

  do {
    printf("1. Add Employee\n");
    printf("2. Delete Employee\n");
    printf("3. Update Employee\n");
    printf("4. Display Records\n");
    printf("0. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_employee(employees, &count);
        break;

      case 2:
        delete_employee(employees, &count);
        break;

      case 3:
        update_employee(employees, count);
        break;

      case 4:
        display_records(employees, count);
        break;

      case 0:
        break;

      default:
        printf("Invalid choice!\n");
        break;
    }
  } while(choice != 0);

  return 0;
}

void add_employee(Employee* employees, int* count) {
  if(*count == MAX_RECORDS) {
    printf("Maximum records reached!\n");
    return;
  }

  Employee new_employee;

  printf("Enter Employee ID: ");
  scanf("%d", &new_employee.id);

  if(find_employee(employees, *count, new_employee.id) != -1) {
    printf("Employee with ID %d already exists!\n", new_employee.id);
    return;
  }

  printf("Enter Employee Name: ");
  scanf(" %[^\n]s", new_employee.name);

  printf("Enter Employee Address: ");
  scanf(" %[^\n]s", new_employee.address);

  printf("Enter Employee Salary: ");
  scanf("%f", &new_employee.salary);

  employees[*count] = new_employee;
  (*count)++;

  printf("Employee added successfully!\n");
}

void delete_employee(Employee* employees, int* count) {
  int id;

  printf("Enter Employee ID: ");
  scanf("%d", &id);

  int pos = find_employee(employees, *count, id);

  if(pos == -1) {
    printf("Employee with ID %d does not exist!\n", id);
    return;
  }

  for(int i = pos; i < (*count) - 1; i++) {
    employees[i] = employees[i + 1];
  }

  (*count)--;
  printf("Employee deleted successfully!\n");
}

void update_employee(Employee* employees, int count) {
  int id;

  printf("Enter Employee ID: ");
  scanf("%d", &id);

  int pos = find_employee(employees, count, id);

  if(pos == -1) {
    printf("Employee with ID %d does not exist!\n", id);
    return;
  }

  printf("Enter Employee Name: ");
  scanf(" %[^\n]s", employees[pos].name);

  printf("Enter Employee Address: ");
  scanf(" %[^\n]s", employees[pos].address);

  printf("Enter Employee Salary: ");
  scanf("%f", &employees[pos].salary);

  printf("Employee updated successfully!\n");
}

void display_records(Employee* employees, int count) {
  if(count == 0) {
    printf("No records to display!\n");
    return;
  }

  for(int i = 0; i < count; i++) {
    printf("ID: %d\n", employees[i].id);
    printf("Name: %s\n", employees[i].name);
    printf("Address: %s\n", employees[i].address);
    printf("Salary: %.2f\n", employees[i].salary);
    printf("\n");
  }
}

int find_employee(Employee* employees, int count, int id) {
  for(int i = 0; i < count; i++) {
    if(employees[i].id == id) {
      return i;
    }
  }

  return -1;
}