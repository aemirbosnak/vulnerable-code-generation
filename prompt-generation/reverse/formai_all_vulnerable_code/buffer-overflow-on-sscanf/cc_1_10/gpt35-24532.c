//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a struct named "employee"
struct employee {
   char first_name[50];
   char last_name[50];
   int age;
   float salary;
};

int main() {
   // Declare an array of struct employees
   struct employee employees[50];

   // Define the number of employees
   int num_employees = 5;

   // Declare variables to store user input
   char input[50];
   char first_name[50];
   char last_name[50];
   int age;
   float salary;

   // Use a loop to gather data from user
   for (int i = 0; i < num_employees; i++) {
      // Ask user for first name
      printf("Enter the first name of employee %d: ", i+1);
      fgets(input, sizeof(input), stdin);
      sscanf(input, "%s", first_name);

      // Ask user for last name
      printf("Enter the last name of employee %d: ", i+1);
      fgets(input, sizeof(input), stdin);
      sscanf(input, "%s", last_name);

      // Ask user for age
      printf("Enter the age of employee %d: ", i+1);
      fgets(input, sizeof(input), stdin);
      sscanf(input, "%d", &age);

      // Ask user for salary
      printf("Enter the salary of employee %d: ", i+1);
      fgets(input, sizeof(input), stdin);
      sscanf(input, "%f", &salary);

      // Store the employee data in the employees array
      strcpy(employees[i].first_name, first_name);
      strcpy(employees[i].last_name, last_name);
      employees[i].age = age;
      employees[i].salary = salary;
   }

   // Print out the list of employees
   printf("\nList of Employees:\n");
   printf("--------------------\n");
   for (int i = 0; i < num_employees; i++) {
      struct employee e = employees[i];
      printf("Employee %d:\n", i+1);
      printf("  First Name: %s\n", e.first_name);
      printf("  Last Name: %s\n", e.last_name);
      printf("  Age: %d\n", e.age);
      printf("  Salary: %.2f\n", e.salary);
   }

   return 0;
}