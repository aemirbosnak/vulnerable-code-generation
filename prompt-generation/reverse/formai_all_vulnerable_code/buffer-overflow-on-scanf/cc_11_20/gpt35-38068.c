//FormAI DATASET v1.0 Category: Database querying ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
  int id;
  char name[50];
  int age;
  float salary;
};

int main() {
  int n;
  printf("Enter the number of employees: ");
  scanf("%d", &n);
  struct Employee *employees = malloc(n * sizeof(struct Employee));
  
  for (int i=0; i<n; i++) {
    printf("Enter details of employee %d:\n", i+1);
    printf("ID: ");
    scanf("%d", &employees[i].id);
    printf("Name: ");
    scanf("%s", employees[i].name);
    printf("Age: ");
    scanf("%d", &employees[i].age);
    printf("Salary: ");
    scanf("%f", &employees[i].salary);
  }

  int option, id;
  float salary;
  char name[50];
  while (1) {
    printf("\n1. Search by ID\n2. Search by Name\n3. Search by Salary\n4. Quit\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        printf("Enter the ID to search: ");
        scanf("%d", &id);
        for (int i=0; i<n; i++) {
          if (employees[i].id == id) {
            printf("\nID: %d\nName: %s\nAge: %d\nSalary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
            break;
          }
        }
        break;
      case 2:
        printf("Enter the Name to search: ");
        scanf("%s", name);
        for (int i=0; i<n; i++) {
          if (strcmp(employees[i].name, name) == 0) {
            printf("\nID: %d\nName: %s\nAge: %d\nSalary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
          }
        }
        break;
      case 3:
        printf("Enter the Salary to search: ");
        scanf("%f", &salary);
        for (int i=0; i<n; i++) {
          if (employees[i].salary == salary) {
            printf("\nID: %d\nName: %s\nAge: %d\nSalary: %.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
          }
        }
        break;
      case 4:
        free(employees);
        exit(0);
      default:
        printf("Invalid option!\n");
    }
  }
  return 0;
}