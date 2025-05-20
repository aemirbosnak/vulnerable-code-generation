//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
  char name[20];
  int quantity;
  float price;
};

struct Customer {
  char name[20];
  int age;
  float balance;
};

struct Order {
  struct Medicine medicine;
  struct Customer customer;
  int quantity;
};

void displayMenu();
void addMedicine();
void removeMedicine();
void orderMedicine();
void processOrder();
void calculateTotal();
void printBill();

int main() {
  displayMenu();
  return 0;
}

void displayMenu() {
  printf("Welcome to our medical store management system!\n");
  printf("Please select one of the following options:\n");
  printf("1. Add medicine\n");
  printf("2. Remove medicine\n");
  printf("3. Order medicine\n");
  printf("4. Process order\n");
  printf("5. Calculate total\n");
  printf("6. Print bill\n");
  printf("7. Exit\n");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      addMedicine();
      break;
    case 2:
      removeMedicine();
      break;
    case 3:
      orderMedicine();
      break;
    case 4:
      processOrder();
      break;
    case 5:
      calculateTotal();
      break;
    case 6:
      printBill();
      break;
    case 7:
      exit(0);
      break;
    default:
      printf("Invalid choice. Please try again.\n");
  }
}

void addMedicine() {
  struct Medicine medicine;
  printf("Enter the name of the medicine: ");
  scanf("%s", medicine.name);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &medicine.quantity);
  printf("Enter the price of the medicine: ");
  scanf("%f", &medicine.price);
  printf("Medicine added successfully!\n");
}

void removeMedicine() {
  struct Medicine medicine;
  printf("Enter the name of the medicine to be removed: ");
  scanf("%s", medicine.name);
  printf("Medicine removed successfully!\n");
}

void orderMedicine() {
  struct Order order;
  printf("Enter the name of the medicine: ");
  scanf("%s", order.medicine.name);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &order.quantity);
  printf("Enter the name of the customer: ");
  scanf("%s", order.customer.name);
  printf("Enter the age of the customer: ");
  scanf("%d", &order.customer.age);
  printf("Order placed successfully!\n");
}

void processOrder() {
  struct Order order;
  printf("Enter the name of the medicine: ");
  scanf("%s", order.medicine.name);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &order.quantity);
  printf("Enter the name of the customer: ");
  scanf("%s", order.customer.name);
  printf("Enter the age of the customer: ");
  scanf("%d", &order.customer.age);
  printf("Order processed successfully!\n");
}

void calculateTotal() {
  struct Order order;
  printf("Enter the name of the medicine: ");
  scanf("%s", order.medicine.name);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &order.quantity);
  printf("Enter the name of the customer: ");
  scanf("%s", order.customer.name);
  printf("Enter the age of the customer: ");
  scanf("%d", &order.customer.age);
  printf("Total amount: ");
  printf("%.2f\n", order.medicine.price * order.quantity);
}

void printBill() {
  struct Order order;
  printf("Enter the name of the medicine: ");
  scanf("%s", order.medicine.name);
  printf("Enter the quantity of the medicine: ");
  scanf("%d", &order.quantity);
  printf("Enter the name of the customer: ");
  scanf("%s", order.customer.name);
  printf("Enter the age of the customer: ");
  scanf("%d", &order.customer.age);
  printf("Bill:\n");
  printf("%s\n", order.medicine.name);
  printf("Quantity: %d\n", order.quantity);
  printf("Price: %.2f\n", order.medicine.price);
  printf("Total amount: %.2f\n", order.medicine.price * order.quantity);
}