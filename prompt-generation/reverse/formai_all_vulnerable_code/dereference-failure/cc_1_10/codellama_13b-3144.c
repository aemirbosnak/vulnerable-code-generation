//Code Llama-13B DATASET v1.0 Category: Database simulation ; Style: satisfied
/*
 * Database Simulation Program
 *
 * This program simulates a database of employees and their information.
 * It allows users to add, delete, and modify employees, as well as search for
 * employees by name or ID number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold employee information
typedef struct {
  int id;
  char name[50];
  char department[50];
  int salary;
} Employee;

// Define a structure to hold the database
typedef struct {
  Employee *employees;
  int num_employees;
} Database;

// Function to add an employee to the database
void addEmployee(Database *db, Employee employee) {
  db->employees[db->num_employees] = employee;
  db->num_employees++;
}

// Function to delete an employee from the database
void deleteEmployee(Database *db, int id) {
  for (int i = 0; i < db->num_employees; i++) {
    if (db->employees[i].id == id) {
      for (int j = i; j < db->num_employees - 1; j++) {
        db->employees[j] = db->employees[j + 1];
      }
      db->num_employees--;
      break;
    }
  }
}

// Function to modify an employee in the database
void modifyEmployee(Database *db, int id, Employee employee) {
  for (int i = 0; i < db->num_employees; i++) {
    if (db->employees[i].id == id) {
      db->employees[i] = employee;
      break;
    }
  }
}

// Function to search for an employee in the database
Employee *searchEmployee(Database *db, char *name) {
  for (int i = 0; i < db->num_employees; i++) {
    if (strcmp(db->employees[i].name, name) == 0) {
      return &db->employees[i];
    }
  }
  return NULL;
}

int main() {
  Database db;
  db.employees = malloc(sizeof(Employee) * 100);
  db.num_employees = 0;

  // Add some sample employees to the database
  addEmployee(&db, (Employee){1, "John Doe", "Sales", 50000});
  addEmployee(&db, (Employee){2, "Jane Doe", "Marketing", 60000});
  addEmployee(&db, (Employee){3, "Bob Smith", "Development", 45000});

  // Modify an employee in the database
  modifyEmployee(&db, 1, (Employee){1, "John Smith", "Sales", 60000});

  // Search for an employee in the database
  Employee *employee = searchEmployee(&db, "Jane Doe");
  if (employee != NULL) {
    printf("Employee found: %s\n", employee->name);
  } else {
    printf("Employee not found.\n");
  }

  // Delete an employee from the database
  deleteEmployee(&db, 3);

  // Print all employees in the database
  for (int i = 0; i < db.num_employees; i++) {
    printf("Employee %d: %s\n", i + 1, db.employees[i].name);
  }

  return 0;
}