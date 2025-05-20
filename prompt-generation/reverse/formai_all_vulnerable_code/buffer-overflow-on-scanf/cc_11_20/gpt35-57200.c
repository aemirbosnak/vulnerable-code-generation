//FormAI DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int id;
   char name[20];
   float salary;
} Employee;

int main() {
   Employee database[10]; // initial database with a capacity of 10 employees
   int numEmployees = 0; // current number of employees in the database

   while (1) { // endless loop until user chooses to exit
      printf("\nWelcome to the Employee Database Simulation!\n\n");
      printf("Please enter your choice:\n");
      printf("1. Add Employee\n");
      printf("2. Display Employee by ID\n");
      printf("3. Display All Employees\n");
      printf("4. Exit\n\n");

      int choice;
      scanf("%d", &choice);

      switch (choice) {
         case 1: { // Add Employee
            if (numEmployees >= 10) { // check if database is full
               printf("\nThe database is full.\n");
               break;
            }

            Employee emp; // create new employee
            printf("\nEnter Employee ID: ");
            scanf("%d", &emp.id);
            printf("Enter Employee Name: ");
            scanf("%s", emp.name);
            printf("Enter Employee Salary: ");
            scanf("%f", &emp.salary);
            database[numEmployees++] = emp; // add new employee to database
            printf("Employee added successfully!\n");
            break;
         }

         case 2: { // Display Employee by ID
            if (numEmployees == 0) { // check if database is empty
               printf("\nThe database is empty.\n");
               break;
            }

            int id;
            printf("\nEnter Employee ID: ");
            scanf("%d", &id);
            int found = 0;
            for (int i = 0; i < numEmployees; i++) {
               if (database[i].id == id) {
                  printf("\nEmployee ID: %d\n", database[i].id);
                  printf("Employee Name: %s\n", database[i].name);
                  printf("Employee Salary: %.2f\n", database[i].salary);
                  found = 1;
                  break;
               }
            }
            if (!found) {
               printf("\nEmployee not found.\n");
            }
            break;
         }

         case 3: { // Display All Employees
            if (numEmployees == 0) { // check if database is empty
               printf("\nThe database is empty.\n");
               break;
            }

            printf("\nEmployee Database:\n");
            printf("ID\tName\tSalary\n");
            for (int i = 0; i < numEmployees; i++) {
               printf("%d\t%s\t%.2f\n", database[i].id, database[i].name, database[i].salary);
            }
            break;
         }

         case 4: { // Exit
            printf("\nThank you for using the Employee Database Simulation.\n");
            return 0;
         }

         default: { // Invalid Input
            printf("\nInvalid input. Please try again.\n");
            break;
         }
      }
   }
   return 0;
}