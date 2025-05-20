//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures for storing data
typedef struct {
  char name[50];
  int age;
  char gender;
  char address[100];
  char phone[20];
} Customer;

typedef struct {
  char name[50];
  char type[50];
  float price;
  int quantity;
} Medicine;

typedef struct {
  int id;
  Customer customer;
  Medicine medicine;
} Sale;

// Functions
void getCustomerInfo(Customer *cust);
void getMedicineInfo(Medicine *med);
void printSale(Sale *sale);

int main() {
  Customer cust;
  Medicine med;
  Sale sale;

  // Get customer information
  getCustomerInfo(&cust);

  // Get medicine information
  getMedicineInfo(&med);

  // Calculate sale
  sale.id = 1;
  sale.customer = cust;
  sale.medicine = med;

  // Print sale
  printSale(&sale);

  return 0;
}

void getCustomerInfo(Customer *cust) {
  printf("Enter customer name: ");
  scanf("%s", cust->name);
  printf("Enter customer age: ");
  scanf("%d", &cust->age);
  printf("Enter customer gender: ");
  scanf(" %c", &cust->gender);
  printf("Enter customer address: ");
  scanf("%s", cust->address);
  printf("Enter customer phone number: ");
  scanf("%s", cust->phone);
}

void getMedicineInfo(Medicine *med) {
  printf("Enter medicine name: ");
  scanf("%s", med->name);
  printf("Enter medicine type: ");
  scanf("%s", med->type);
  printf("Enter medicine price: ");
  scanf("%f", &med->price);
  printf("Enter medicine quantity: ");
  scanf("%d", &med->quantity);
}

void printSale(Sale *sale) {
  printf("Sale ID: %d\n", sale->id);
  printf("Customer Name: %s\n", sale->customer.name);
  printf("Customer Age: %d\n", sale->customer.age);
  printf("Customer Gender: %c\n", sale->customer.gender);
  printf("Customer Address: %s\n", sale->customer.address);
  printf("Customer Phone Number: %s\n", sale->customer.phone);
  printf("Medicine Name: %s\n", sale->medicine.name);
  printf("Medicine Type: %s\n", sale->medicine.type);
  printf("Medicine Price: %f\n", sale->medicine.price);
  printf("Medicine Quantity: %d\n", sale->medicine.quantity);
}