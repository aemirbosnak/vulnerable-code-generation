//FormAI DATASET v1.0 Category: Database querying ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[20];
  int age;
  float salary;
} employee;

int main() {
  FILE *fp;
  employee e, *record;
  int numRecords = 0, i, idToFind;

  fp = fopen("employee_data.dat", "rb");
  if (fp == NULL) {
    printf("Error opening file!");
    exit(1);
  }

  // Count the number of records in the file
  while(fread(&e, sizeof(e), 1, fp) == 1) {
    numRecords++;
  }

  // Allocate memory for an array of employee records
  record = (employee *) malloc(numRecords * sizeof(employee));

  // Read the employee records into the array
  rewind(fp);
  i = 0;
  while(fread(&e, sizeof(e), 1, fp) == 1) {
    record[i++] = e;
  }

  // Query the user for an ID to search for
  printf("Enter the ID of the employee to find: ");
  scanf("%d", &idToFind);

  // Search for the employee with the given ID
  for (i = 0; i < numRecords; i++) {
    if (record[i].id == idToFind) {
      printf("Employee found:\n");
      printf("ID: %d\n", record[i].id);
      printf("Name: %s\n", record[i].name);
      printf("Age: %d\n", record[i].age);
      printf("Salary: %0.2f\n", record[i].salary);
      break;
    }
  }

  if (i == numRecords) {
    printf("Employee with ID %d not found\n", idToFind);
  }

  // Free the memory allocated for the employee records
  free(record);

  // Close the file
  fclose(fp);

  return 0;
}