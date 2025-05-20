//FormAI DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATABASE_SIZE 100

struct Employee {
   int empID, salary;
   char name[30], department[20];
};

struct Employee database[DATABASE_SIZE];
int numEmployees = 0;

// Add employee to database
void addEmployee(int id, char name[], char department[], int salary) {
   if (numEmployees == DATABASE_SIZE) {
      printf("Error: Database is full.\n");
      return;
   }
   
   database[numEmployees].empID = id;
   strcpy(database[numEmployees].name, name);
   strcpy(database[numEmployees].department, department);
   database[numEmployees].salary = salary;
   
   numEmployees++;
   printf("Employee added to database.\n");
}

// Search for employee by ID number
void searchByID(int id) {
   int i;
   for (i = 0; i < numEmployees; i++) {
      if (database[i].empID == id) {
         printf("Name: %s\nDepartment: %s\nSalary: %d\n", database[i].name, database[i].department, database[i].salary);
         return;
      }
   }
   
   printf("Error: Employee not found in database.\n");
}

// Search for employee by name
void searchByName(char name[]) {
   int i;
   for (i = 0; i < numEmployees; i++) {
      if (strcmp(database[i].name, name) == 0) {
         printf("ID: %d\nDepartment: %s\nSalary: %d\n", database[i].empID, database[i].department, database[i].salary);
         return;
      }
   }
   
   printf("Error: Employee not found in database.\n");
}

int main() {
   int choice, id, salary;
   char name[30], department[20];
   
   while (1) {
      printf("\nChoose an option:\n1. Add Employee\n2. Search by ID\n3. Search by name\n4. Exit\n");
      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            printf("Enter employee ID: ");
            scanf("%d", &id);
            printf("Enter employee name: ");
            scanf("%s", name);
            printf("Enter department name: ");
            scanf("%s", department);
            printf("Enter employee salary: ");
            scanf("%d", &salary);
            addEmployee(id, name, department, salary);
            break;
         case 2:
            printf("Enter employee ID to search: ");
            scanf("%d", &id);
            searchByID(id);
            break;
         case 3:
            printf("Enter employee name to search: ");
            scanf("%s", name);
            searchByName(name);
            break;
         case 4:
            printf("Exiting...\n");
            exit(0);
         default:
            printf("Error: Invalid choice.\n");
            break;
      }
   }
   
   return 0;
}