//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store employee information
struct Employee {
  char name[50];
  int age;
  double salary;
  struct Employee* next;
};

// Function to insert a new employee at the end
void insertEmployee(struct Employee** head) {
  struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
  printf("Enter employee name: ");
  scanf("%s", newEmployee->name);
  printf("Enter employee age: ");
  scanf("%d", &newEmployee->age);
  printf("Enter employee salary: ");
  scanf("%lf", &newEmployee->salary);

  if (*head == NULL) {
    *head = newEmployee;
  } else {
    (*head)->next = newEmployee;
  }
  *head = newEmployee;
}

// Function to print all employees
void printEmployees(struct Employee* head) {
  while (head) {
    printf("Name: %s, Age: %d, Salary: %.2lf\n", head->name, head->age, head->salary);
    head = head->next;
  }
}

int main() {
  struct Employee* head = NULL;

  // Insert employees
  insertEmployee(&head);
  insertEmployee(&head);
  insertEmployee(&head);

  // Print employees
  printEmployees(head);

  return 0;
}