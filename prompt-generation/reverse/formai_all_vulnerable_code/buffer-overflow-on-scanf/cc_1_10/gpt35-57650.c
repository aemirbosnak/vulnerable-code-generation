//FormAI DATASET v1.0 Category: Database querying ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[20];
  char email[30];
  float salary;
} Employee;

void display_employee(Employee e) {
  printf("ID: %d\nName: %s\nEmail: %s\nSalary: %.2f\n", e.id, e.name, e.email, e.salary);
}

int main() {
  // Creating database
  FILE *fp = fopen("employees.bin", "wb");
  if (fp == NULL) {
    printf("Error creating database!");
    exit(1);
  }

  Employee emp1 = {1, "John Doe", "johndoe@gmail.com", 65000.00};
  Employee emp2 = {2, "Jane Smith", "janesmith@yahoo.com", 75000.00};
  Employee emp3 = {3, "Bob Johnson", "bobjohnson@hotmail.com", 55000.00};

  fwrite(&emp1, sizeof(Employee), 1, fp);
  fwrite(&emp2, sizeof(Employee), 1, fp);
  fwrite(&emp3, sizeof(Employee), 1, fp);

  fclose(fp);

  // Querying database
  printf("Enter employee ID: ");
  int desired_id;
  scanf("%d", &desired_id);

  fp = fopen("employees.bin", "rb");
  if (fp == NULL) {
    printf("Error opening database!");
    exit(1);
  }

  Employee emp;
  while (fread(&emp, sizeof(Employee), 1, fp)) {
    if (emp.id == desired_id) {
      printf("\nEmployee found!\n");
      display_employee(emp);
      fclose(fp);
      exit(0);
    }
  }

  printf("\nEmployee not found!\n");

  fclose(fp);

  return 0;
}