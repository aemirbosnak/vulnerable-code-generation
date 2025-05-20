//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
  char name[50];
  int quantity;
  float price;
} MEDICINE;

void print_stock(MEDICINE* stock, int num_medicines);
void add_medicine(MEDICINE* stock, int* num_medicines);
void remove_medicine(MEDICINE* stock, int* num_medicines);
void search_medicine(MEDICINE* stock, int num_medicines);

int main() {
  MEDICINE stock[100];
  int num_medicines = 0;
  int choice;

  while (1) {
    printf("\nWelcome to the Medical Store Management System!\n");
    printf("1. Print Stock\n");
    printf("2. Add Medicine\n");
    printf("3. Remove Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        print_stock(stock, num_medicines);
        break;
      case 2:
        add_medicine(stock, &num_medicines);
        break;
      case 3:
        remove_medicine(stock, &num_medicines);
        break;
      case 4:
        search_medicine(stock, num_medicines);
        break;
      case 5:
        printf("\nExiting Medical Store Management System...\n");
        exit(0);
      default:
        printf("\nInvalid choice. Try again...\n");
    }
  }

  return 0;
}

void print_stock(MEDICINE* stock, int num_medicines) {
  if (num_medicines == 0) {
    printf("\nStock is empty.\n");
    return;
  }

  printf("\nStock:\n");
  printf("%-30s%-10s%-10s\n", "Name", "Quantity", "Price");

  for (int i = 0; i < num_medicines; i++) {
    printf("%-30s%-10d%-10.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
  }
}

void add_medicine(MEDICINE* stock, int* num_medicines) {
  if (*num_medicines == 100) {
    printf("\nStock is full. Cannot add more medicines.\n");
    return;
  }

  printf("\nEnter details of medicine to be added:\n");

  printf("Name: ");
  scanf("%s", stock[*num_medicines].name);

  printf("Quantity: ");
  scanf("%d", &stock[*num_medicines].quantity);

  printf("Price: ");
  scanf("%f", &stock[*num_medicines].price);

  (*num_medicines)++;

  printf("\nMedicine added to stock successfully.\n");
}

void remove_medicine(MEDICINE* stock, int* num_medicines) {
  if (*num_medicines == 0) {
    printf("\nStock is empty. Nothing to remove.\n");
    return;
  }

  char name[50];
  int found = 0;

  printf("\nEnter name of medicine to be removed: ");
  scanf("%s", name);

  for (int i = 0; i < *num_medicines; i++) {
    if (strcmp(stock[i].name, name) == 0) {
      found = 1;

      for (int j = i; j < (*num_medicines - 1); j++) {
        stock[j] = stock[j+1];
      }

      (*num_medicines)--;

      printf("\nMedicine removed from stock successfully.\n");
      break;
    }
  }

  if (!found) {
    printf("\nMedicine not found in stock.\n");
  }
}

void search_medicine(MEDICINE* stock, int num_medicines) {
  if (num_medicines == 0) {
    printf("\nStock is empty. Nothing to search.\n");
    return;
  }

  char name[50];
  int found = 0;

  printf("\nEnter name of medicine to search: ");
  scanf("%s", name);

  printf("%-30s%-10s%-10s\n", "Name", "Quantity", "Price");

  for (int i = 0; i < num_medicines; i++) {
    if (strcmp(stock[i].name, name) == 0) {
      found = 1;
      printf("%-30s%-10d%-10.2f\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
  }

  if (!found) {
    printf("\nMedicine not found in stock.\n");
  }
}