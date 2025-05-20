//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Declare a struct to hold employee data
struct Employee {
  char name[50];
  int id;
  float salary;
};

// Function to sort employees based on their salary
// Uses selection sort algorithm for performance
void sortEmployees(struct Employee *employees, int numEmployees) {
  int i, j, minIdx;

  for (i = 0; i < numEmployees - 1; i++) {
    minIdx = i;

    for (j = i + 1; j < numEmployees; j++) {
      if (employees[j].salary < employees[minIdx].salary) {
        minIdx = j;
      }
    }

    // Swap the employees
    struct Employee temp = employees[i];
    employees[i] = employees[minIdx];
    employees[minIdx] = temp;
  }
}

int main() {
  // Declare an array of employees
  struct Employee employees[5];

  // Prompt the user to input employee data
  printf("Enter the name, id, and salary for each employee:\n");
  for (int i = 0; i < 5; i++) {
    printf("Employee %d:\n", i+1);

    // Use fgets to read the name to avoid buffer overflow
    fgets(employees[i].name, 50, stdin);
    printf("ID: ");
    scanf("%d", &employees[i].id);
    printf("Salary: ");
    scanf("%f", &employees[i].salary);

    // Consume the newline character left in the input buffer
    getchar();
  }

  // Call the sortEmployees function to sort the employees by salary
  sortEmployees(employees, 5);

  // Print the sorted employee list
  printf("\nSorted employee list:\n");
  for (int i = 0; i < 5; i++) {
    printf("%-20s ID: %d Salary: $%.2f\n", employees[i].name, employees[i].id, employees[i].salary);
  }

  return 0;
}