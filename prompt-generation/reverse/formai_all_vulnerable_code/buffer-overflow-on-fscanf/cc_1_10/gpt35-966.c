//FormAI DATASET v1.0 Category: Data mining ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define struct for holding data information
typedef struct {
  int id;
  char name[20];
  int age;
  float salary;
} Employee;

int main() {
  // Declare file pointer and variables
  FILE *inputFile;
  Employee tempEmployee;
  int numberOfEmployees = 0;
  float averageSalary = 0;

  // Open file for reading
  inputFile = fopen("employees.txt", "r");

  // Check if file was successfully opened
  if (inputFile == NULL) {
    printf("Error: Can't open file!\n");
    exit(1);
  }

  // Loop through file and calculate average salary
  while (fscanf(inputFile, "%d %s %d %f", &tempEmployee.id, tempEmployee.name, &tempEmployee.age, &tempEmployee.salary) != EOF) {
    numberOfEmployees++;
    averageSalary += tempEmployee.salary;
  }

  // Calculate average salary
  averageSalary /= numberOfEmployees;

  // Close file
  fclose(inputFile);

  // Reopen file for writing
  inputFile = fopen("employees.txt", "r");

  // Open output file for writing
  FILE *outputFile = fopen("high_salary_employees.txt", "w");

  // Loop through file and find high salary employees
  while (fscanf(inputFile, "%d %s %d %f", &tempEmployee.id, tempEmployee.name, &tempEmployee.age, &tempEmployee.salary) != EOF) {
    if (tempEmployee.salary > averageSalary) {
      fprintf(outputFile, "%d %s %d %f\n", tempEmployee.id, tempEmployee.name, tempEmployee.age, tempEmployee.salary);
    }
  }

  // Close files
  fclose(inputFile);
  fclose(outputFile);

  // Print success message
  printf("Data mining complete!\n");

  return 0;
}