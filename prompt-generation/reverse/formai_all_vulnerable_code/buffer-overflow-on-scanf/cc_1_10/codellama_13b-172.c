//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
// Medical Store Management System in C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structures
typedef struct {
  char name[50];
  char price[10];
  char quantity[10];
  char category[50];
} Medicine;

typedef struct {
  char name[50];
  char phone[20];
  char address[100];
} Customer;

// Functions
void addMedicine(Medicine*);
void deleteMedicine(Medicine*);
void updateMedicine(Medicine*);
void searchMedicine(Medicine*);
void addCustomer(Customer*);
void deleteCustomer(Customer*);
void updateCustomer(Customer*);
void searchCustomer(Customer*);
void displayMedicine(Medicine*);
void displayCustomer(Customer*);

// Main function
int main() {
  // Variables
  Medicine medicine[100];
  Customer customer[100];
  int medicineCount = 0, customerCount = 0;
  char choice;

  // Add medicine
  addMedicine(&medicine[medicineCount]);
  medicineCount++;

  // Delete medicine
  deleteMedicine(&medicine[medicineCount - 1]);
  medicineCount--;

  // Update medicine
  updateMedicine(&medicine[medicineCount - 1]);

  // Search medicine
  searchMedicine(&medicine[medicineCount - 1]);

  // Add customer
  addCustomer(&customer[customerCount]);
  customerCount++;

  // Delete customer
  deleteCustomer(&customer[customerCount - 1]);
  customerCount--;

  // Update customer
  updateCustomer(&customer[customerCount - 1]);

  // Search customer
  searchCustomer(&customer[customerCount - 1]);

  // Display medicine
  displayMedicine(&medicine[medicineCount - 1]);

  // Display customer
  displayCustomer(&customer[customerCount - 1]);

  return 0;
}

// Function definitions
void addMedicine(Medicine* medicine) {
  // Add medicine details
  printf("Enter medicine name: ");
  scanf("%s", medicine->name);
  printf("Enter medicine price: ");
  scanf("%s", medicine->price);
  printf("Enter medicine quantity: ");
  scanf("%s", medicine->quantity);
  printf("Enter medicine category: ");
  scanf("%s", medicine->category);
}

void deleteMedicine(Medicine* medicine) {
  // Delete medicine details
  printf("Enter medicine name: ");
  scanf("%s", medicine->name);
  printf("Enter medicine price: ");
  scanf("%s", medicine->price);
  printf("Enter medicine quantity: ");
  scanf("%s", medicine->quantity);
  printf("Enter medicine category: ");
  scanf("%s", medicine->category);
}

void updateMedicine(Medicine* medicine) {
  // Update medicine details
  printf("Enter medicine name: ");
  scanf("%s", medicine->name);
  printf("Enter medicine price: ");
  scanf("%s", medicine->price);
  printf("Enter medicine quantity: ");
  scanf("%s", medicine->quantity);
  printf("Enter medicine category: ");
  scanf("%s", medicine->category);
}

void searchMedicine(Medicine* medicine) {
  // Search medicine details
  printf("Enter medicine name: ");
  scanf("%s", medicine->name);
  printf("Enter medicine price: ");
  scanf("%s", medicine->price);
  printf("Enter medicine quantity: ");
  scanf("%s", medicine->quantity);
  printf("Enter medicine category: ");
  scanf("%s", medicine->category);
}

void addCustomer(Customer* customer) {
  // Add customer details
  printf("Enter customer name: ");
  scanf("%s", customer->name);
  printf("Enter customer phone: ");
  scanf("%s", customer->phone);
  printf("Enter customer address: ");
  scanf("%s", customer->address);
}

void deleteCustomer(Customer* customer) {
  // Delete customer details
  printf("Enter customer name: ");
  scanf("%s", customer->name);
  printf("Enter customer phone: ");
  scanf("%s", customer->phone);
  printf("Enter customer address: ");
  scanf("%s", customer->address);
}

void updateCustomer(Customer* customer) {
  // Update customer details
  printf("Enter customer name: ");
  scanf("%s", customer->name);
  printf("Enter customer phone: ");
  scanf("%s", customer->phone);
  printf("Enter customer address: ");
  scanf("%s", customer->address);
}

void searchCustomer(Customer* customer) {
  // Search customer details
  printf("Enter customer name: ");
  scanf("%s", customer->name);
  printf("Enter customer phone: ");
  scanf("%s", customer->phone);
  printf("Enter customer address: ");
  scanf("%s", customer->address);
}

void displayMedicine(Medicine* medicine) {
  // Display medicine details
  printf("Medicine name: %s\n", medicine->name);
  printf("Medicine price: %s\n", medicine->price);
  printf("Medicine quantity: %s\n", medicine->quantity);
  printf("Medicine category: %s\n", medicine->category);
}

void displayCustomer(Customer* customer) {
  // Display customer details
  printf("Customer name: %s\n", customer->name);
  printf("Customer phone: %s\n", customer->phone);
  printf("Customer address: %s\n", customer->address);
}