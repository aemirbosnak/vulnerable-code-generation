//FormAI DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[50];
  int age;
  float salary;
} Employee;

int main() {
  FILE *fp;
  int choice, id, found, size, i, j, k;
  char name[50];
  float salary;
  Employee emp, temp;

  fp = fopen("employees.dat", "rb+");
  if (fp == NULL) {
    printf("Error opening file");
    exit(1);
  }

  do {
    printf("\n1. Insert an employee record\n2. Search for an employee by ID\n3. Search for an employee by name\n4. Search for an employee by salary range\n5. List all employees\n0. Exit\n\nEnter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
      case 0:
        printf("Program terminated\n");
        break;

      case 1:
        fseek(fp, 0, SEEK_END);
        printf("Enter employee details:\n");
        printf("ID: ");
        scanf("%d", &emp.id);

        found = 0;
        do {
          printf("Name: ");
          scanf("%s", emp.name);
          rewind(fp);

          while (fread(&temp, sizeof(Employee), 1, fp) == 1) {
            if (strcmp(temp.name, emp.name) == 0) {
              printf("\nRecord already exists!\n");
              found = 1;
              break;
            }
          }
        } while (found);

        printf("Age: ");
        scanf("%d", &emp.age);
        printf("Salary: ");
        scanf("%f", &emp.salary);

        fwrite(&emp, sizeof(Employee), 1, fp);
        printf("\nRecord added successfully!\n");
        break;

      case 2:
        printf("Enter employee ID to search: ");
        scanf("%d", &id);

        found = 0;
        rewind(fp);

        while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
          if (emp.id == id) {
            found = 1;
            printf("\nEmployee details:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Age: %d\n", emp.age);
            printf("Salary: %.2f\n", emp.salary);
            break;
          }
        }

        if (!found) {
          printf("\nRecord not found!\n");
        }

        break;

      case 3:
        printf("Enter employee name to search: ");
        scanf("%s", name);

        found = 0;
        rewind(fp);

        while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
          if (strcmp(emp.name, name) == 0) {
            found = 1;
            printf("\nEmployee details:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Age: %d\n", emp.age);
            printf("Salary: %.2f\n", emp.salary);
          }
        }

        if (!found) {
          printf("\nRecord not found!\n");
        }

        break;

      case 4:
        printf("Enter minimum salary: ");
        scanf("%f", &salary);

        found = 0;
        rewind(fp);

        while (fread(&emp, sizeof(Employee), 1, fp) == 1) {
          if (emp.salary >= salary) {
            found = 1;
            printf("\nEmployee details:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Age: %d\n", emp.age);
            printf("Salary: %.2f\n", emp.salary);
          }
        }

        if (!found) {
          printf("\nRecord not found!\n");
        }

        break;

      case 5:
        fseek(fp, 0, SEEK_END);
        size = ftell(fp);
        rewind(fp);
        j = size / sizeof(Employee);

        for (i = 0; i < j; i++) {
          fseek(fp, i*sizeof(Employee), SEEK_SET);
          fread(&emp, sizeof(Employee), 1, fp);

          printf("\nEmployee %d:\n", i+1);
          printf("ID: %d\n", emp.id);
          printf("Name: %s\n", emp.name);
          printf("Age: %d\n", emp.age);
          printf("Salary: %.2f\n", emp.salary);
        }

        break;

      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 0);

  fclose(fp);
  return 0;
}