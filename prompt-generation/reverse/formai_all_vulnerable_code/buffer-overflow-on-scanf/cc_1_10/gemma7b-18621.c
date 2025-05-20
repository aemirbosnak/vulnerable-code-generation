//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

struct Product {
  char name[20];
  int quantity;
  double price;
  struct Product* next;
};

struct Customer {
  char name[20];
  char address[100];
  int phone;
  struct Customer* next;
};

void insertProduct(struct Product** head) {
  struct Product* newProduct = malloc(sizeof(struct Product));
  printf("Enter product name: ");
  scanf("%s", newProduct->name);
  printf("Enter quantity: ");
  scanf("%d", &newProduct->quantity);
  printf("Enter price: ");
  scanf("%lf", &newProduct->price);
  newProduct->next = *head;
  *head = newProduct;
}

void insertCustomer(struct Customer** head) {
  struct Customer* newCustomer = malloc(sizeof(struct Customer));
  printf("Enter customer name: ");
  scanf("%s", newCustomer->name);
  printf("Enter customer address: ");
  scanf("%s", newCustomer->address);
  printf("Enter phone number: ");
  scanf("%d", &newCustomer->phone);
  newCustomer->next = *head;
  *head = newCustomer;
}

void searchProduct(struct Product* head) {
  char searchName[20];
  printf("Enter product name: ");
  scanf("%s", searchName);
  struct Product* currentProduct = head;
  while (currentProduct) {
    if (strcmp(currentProduct->name, searchName) == 0) {
      printf("Product name: %s\n", currentProduct->name);
      printf("Quantity: %d\n", currentProduct->quantity);
      printf("Price: %.2lf\n", currentProduct->price);
      break;
    }
    currentProduct = currentProduct->next;
  }
  if (currentProduct == NULL) {
    printf("Product not found.\n");
  }
}

void searchCustomer(struct Customer* head) {
  char searchName[20];
  printf("Enter customer name: ");
  scanf("%s", searchName);
  struct Customer* currentCustomer = head;
  while (currentCustomer) {
    if (strcmp(currentCustomer->name, searchName) == 0) {
      printf("Customer name: %s\n", currentCustomer->name);
      printf("Address: %s\n", currentCustomer->address);
      printf("Phone number: %d\n", currentCustomer->phone);
      break;
    }
    currentCustomer = currentCustomer->next;
  }
  if (currentCustomer == NULL) {
    printf("Customer not found.\n");
  }
}

int main() {
  struct Product* headProduct = NULL;
  struct Customer* headCustomer = NULL;

  printf("Welcome to the Paranoiac Medical Store Management System!\n");
  printf("Please select an option:\n");
  printf("1. Insert product\n");
  printf("2. Insert customer\n");
  printf("3. Search product\n");
  printf("4. Search customer\n");
  printf("5. Exit\n");

  int choice;
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      insertProduct(&headProduct);
      break;
    case 2:
      insertCustomer(&headCustomer);
      break;
    case 3:
      searchProduct(headProduct);
      break;
    case 4:
      searchCustomer(headCustomer);
      break;
    case 5:
      exit(0);
    default:
      printf("Invalid choice.\n");
  }

  return 0;
}