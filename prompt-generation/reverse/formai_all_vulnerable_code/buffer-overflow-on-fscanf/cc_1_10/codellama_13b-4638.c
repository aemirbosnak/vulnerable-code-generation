//Code Llama-13B DATASET v1.0 Category: Medical Store Management System ; Style: grateful
// Medical Store Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
  char name[50];
  int price;
  int quantity;
};

struct Customer {
  char name[50];
  char address[100];
  int contact;
};

struct Order {
  int id;
  char medicine[50];
  int quantity;
  float price;
};

struct Inventory {
  int medicine_id;
  int quantity;
  float price;
};

void addMedicine(struct Medicine medicine) {
  FILE *fp = fopen("medicine.dat", "a");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  fprintf(fp, "%s %d %d\n", medicine.name, medicine.price, medicine.quantity);
  fclose(fp);
}

void displayMedicine() {
  FILE *fp = fopen("medicine.dat", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  char name[50];
  int price, quantity;
  while (fscanf(fp, "%s %d %d\n", name, &price, &quantity) != EOF) {
    printf("%s - Rs.%d (%d in stock)\n", name, price, quantity);
  }

  fclose(fp);
}

void addCustomer(struct Customer customer) {
  FILE *fp = fopen("customer.dat", "a");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  fprintf(fp, "%s %s %d\n", customer.name, customer.address, customer.contact);
  fclose(fp);
}

void displayCustomer() {
  FILE *fp = fopen("customer.dat", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  char name[50], address[100];
  int contact;
  while (fscanf(fp, "%s %s %d\n", name, address, &contact) != EOF) {
    printf("%s - %s (%d)\n", name, address, contact);
  }

  fclose(fp);
}

void addOrder(struct Order order) {
  FILE *fp = fopen("order.dat", "a");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  fprintf(fp, "%d %s %d %f\n", order.id, order.medicine, order.quantity, order.price);
  fclose(fp);
}

void displayOrder() {
  FILE *fp = fopen("order.dat", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  int id, quantity;
  char medicine[50];
  float price;
  while (fscanf(fp, "%d %s %d %f\n", &id, medicine, &quantity, &price) != EOF) {
    printf("%d - %s x %d @ Rs.%f = Rs.%f\n", id, medicine, quantity, price, quantity * price);
  }

  fclose(fp);
}

void addInventory(struct Inventory inventory) {
  FILE *fp = fopen("inventory.dat", "a");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  fprintf(fp, "%d %d %f\n", inventory.medicine_id, inventory.quantity, inventory.price);
  fclose(fp);
}

void displayInventory() {
  FILE *fp = fopen("inventory.dat", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  int medicine_id, quantity;
  float price;
  while (fscanf(fp, "%d %d %f\n", &medicine_id, &quantity, &price) != EOF) {
    printf("%d - Rs.%f (%d in stock)\n", medicine_id, price, quantity);
  }

  fclose(fp);
}

int main() {
  struct Medicine medicine;
  struct Customer customer;
  struct Order order;
  struct Inventory inventory;

  printf("Welcome to the Medical Store Management System!\n");

  while (1) {
    printf("1. Add Medicine\n");
    printf("2. Display Medicine\n");
    printf("3. Add Customer\n");
    printf("4. Display Customer\n");
    printf("5. Add Order\n");
    printf("6. Display Order\n");
    printf("7. Add Inventory\n");
    printf("8. Display Inventory\n");
    printf("9. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter Medicine Details: ");
        scanf("%s %d %d", medicine.name, &medicine.price, &medicine.quantity);
        addMedicine(medicine);
        break;
      case 2:
        displayMedicine();
        break;
      case 3:
        printf("Enter Customer Details: ");
        scanf("%s %s %d", customer.name, customer.address, &customer.contact);
        addCustomer(customer);
        break;
      case 4:
        displayCustomer();
        break;
      case 5:
        printf("Enter Order Details: ");
        scanf("%d %s %d", &order.id, order.medicine, &order.quantity);
        addOrder(order);
        break;
      case 6:
        displayOrder();
        break;
      case 7:
        printf("Enter Inventory Details: ");
        scanf("%d %d %f", &inventory.medicine_id, &inventory.quantity, &inventory.price);
        addInventory(inventory);
        break;
      case 8:
        displayInventory();
        break;
      case 9:
        return 0;
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}