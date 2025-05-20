//FormAI DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[50];
  float salary;
} Employee;

int main() {
  FILE *file = fopen("employees.dat", "wb+");
  Employee e;

  printf("Enter employee id: ");
  scanf("%d", &e.id);
  printf("Enter employee name: ");
  scanf("%s", e.name);
  printf("Enter employee salary: ");
  scanf("%f", &e.salary);

  fseek(file, 0, SEEK_END);
  fwrite(&e, sizeof(Employee), 1, file);

  int choice;
  printf("Enter your choice:\n1. Search for an employee\n2. Display all employees\n3. Exit\n");
  scanf("%d", &choice);

  switch(choice) {
    case 1: {
      int search_id;
      printf("Enter the id of employee to search: ");
      scanf("%d", &search_id);
      
      rewind(file);
      while(fread(&e, sizeof(Employee), 1, file)) {
        if(e.id == search_id) {
          printf("Employee found!\n");
          printf("ID: %d, Name: %s, Salary: %.2f\n", e.id, e.name, e.salary);
          break;
        }
      }
      if(feof(file)) {
        printf("Employee not found!\n");
      }
      break;
    }
    case 2: {
      rewind(file);
      while(fread(&e, sizeof(Employee), 1, file)) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", e.id, e.name, e.salary);
      }
      break;
    }
    case 3: {
      exit(0);
    }
  }

  fclose(file);

  return 0;
}