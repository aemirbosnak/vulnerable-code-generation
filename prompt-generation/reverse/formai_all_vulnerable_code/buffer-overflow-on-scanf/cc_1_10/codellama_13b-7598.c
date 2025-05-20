//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>

  // Structure for patient records
  typedef struct {
    char name[50];
    char address[50];
    char phone[15];
    char disease[50];
    char medication[50];
    char diagnosis[50];
    char treatment[50];
    char appointment[50];
  } patient;

  // Structure for employee records
  typedef struct {
    char name[50];
    char address[50];
    char phone[15];
    char job[50];
  } employee;

  // Structure for inventory records
  typedef struct {
    char name[50];
    char quantity[10];
    char price[10];
  } inventory;

  // Structure for sales records
  typedef struct {
    char date[15];
    char time[15];
    char product[50];
    char price[10];
  } sale;

  // Function to add patient record
  void addPatient(patient *patients, int *size) {
    printf("Enter patient name: ");
    scanf("%s", patients[*size].name);
    printf("Enter patient address: ");
    scanf("%s", patients[*size].address);
    printf("Enter patient phone: ");
    scanf("%s", patients[*size].phone);
    printf("Enter patient disease: ");
    scanf("%s", patients[*size].disease);
    printf("Enter patient medication: ");
    scanf("%s", patients[*size].medication);
    printf("Enter patient diagnosis: ");
    scanf("%s", patients[*size].diagnosis);
    printf("Enter patient treatment: ");
    scanf("%s", patients[*size].treatment);
    printf("Enter patient appointment: ");
    scanf("%s", patients[*size].appointment);
    *size += 1;
  }

  // Function to add employee record
  void addEmployee(employee *employees, int *size) {
    printf("Enter employee name: ");
    scanf("%s", employees[*size].name);
    printf("Enter employee address: ");
    scanf("%s", employees[*size].address);
    printf("Enter employee phone: ");
    scanf("%s", employees[*size].phone);
    printf("Enter employee job: ");
    scanf("%s", employees[*size].job);
    *size += 1;
  }

  // Function to add inventory record
  void addInventory(inventory *inventories, int *size) {
    printf("Enter product name: ");
    scanf("%s", inventories[*size].name);
    printf("Enter product quantity: ");
    scanf("%s", inventories[*size].quantity);
    printf("Enter product price: ");
    scanf("%s", inventories[*size].price);
    *size += 1;
  }

  // Function to add sale record
  void addSale(sale *sales, int *size) {
    printf("Enter sale date: ");
    scanf("%s", sales[*size].date);
    printf("Enter sale time: ");
    scanf("%s", sales[*size].time);
    printf("Enter product name: ");
    scanf("%s", sales[*size].product);
    printf("Enter sale price: ");
    scanf("%s", sales[*size].price);
    *size += 1;
  }

  // Main function
  int main() {
    // Declare variables
    patient patients[100];
    int patientsSize = 0;
    employee employees[100];
    int employeesSize = 0;
    inventory inventories[100];
    int inventoriesSize = 0;
    sale sales[100];
    int salesSize = 0;

    // Add patient record
    addPatient(patients, &patientsSize);

    // Add employee record
    addEmployee(employees, &employeesSize);

    // Add inventory record
    addInventory(inventories, &inventoriesSize);

    // Add sale record
    addSale(sales, &salesSize);

    // Print patient record
    printf("Patient Record:\n");
    printf("Name: %s\n", patients[0].name);
    printf("Address: %s\n", patients[0].address);
    printf("Phone: %s\n", patients[0].phone);
    printf("Disease: %s\n", patients[0].disease);
    printf("Medication: %s\n", patients[0].medication);
    printf("Diagnosis: %s\n", patients[0].diagnosis);
    printf("Treatment: %s\n", patients[0].treatment);
    printf("Appointment: %s\n", patients[0].appointment);

    // Print employee record
    printf("Employee Record:\n");
    printf("Name: %s\n", employees[0].name);
    printf("Address: %s\n", employees[0].address);
    printf("Phone: %s\n", employees[0].phone);
    printf("Job: %s\n", employees[0].job);

    // Print inventory record
    printf("Inventory Record:\n");
    printf("Product: %s\n", inventories[0].name);
    printf("Quantity: %s\n", inventories[0].quantity);
    printf("Price: %s\n", inventories[0].price);

    // Print sale record
    printf("Sale Record:\n");
    printf("Date: %s\n", sales[0].date);
    printf("Time: %s\n", sales[0].time);
    printf("Product: %s\n", sales[0].product);
    printf("Price: %s\n", sales[0].price);

    return 0;
  }