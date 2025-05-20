//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
  char name[50];
  int quantity;
  float price;
};

void add_medicine(struct medicine *med, int n);
void display_medicine(struct medicine *med, int n);
void search_medicine(struct medicine *med, int n);

int main() {
  struct medicine *med;
  int n, choice;

  printf("Welcome to Happy Medical Store!\n");
  printf("How many medicines do you want to enter? ");
  scanf("%d", &n);

  med = (struct medicine*) malloc(n * sizeof(struct medicine));

  while (1) {
    printf("\n1. Add Medicine\n");
    printf("2. Display Medicine\n");
    printf("3. Search Medicine\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: add_medicine(med, n);
              break;
      case 2: display_medicine(med, n);
              break;
      case 3: search_medicine(med, n);
              break;
      case 4: printf("\nThank you for using Happy Medical Store!\n");
              exit(0);
      default: printf("\nInvalid choice! Please try again.\n");
    }
  }
  return 0;
}

void add_medicine(struct medicine *med, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("\nEnter Medicine Name: ");
    scanf("%s", med[i].name);

    printf("Enter Quantity: ");
    scanf("%d", &med[i].quantity);

    printf("Enter Price: ");
    scanf("%f", &med[i].price);
  }
}

void display_medicine(struct medicine *med, int n) {
  int i;
  printf("\n");
  printf("|%-20s|%-10s|%-10s|\n", "Medicine Name", "Quantity", "Price");
  for (i = 0; i < n; i++) {
    printf("|%-20s|%-10d|%-10.2f|\n", med[i].name, med[i].quantity, med[i].price);
  }
}

void search_medicine(struct medicine *med, int n) {
  char name[50];
  int i, found = 0;

  printf("\nEnter Name of Medicine to be searched: ");
  scanf("%s", name);

  for (i = 0; i < n; i++) {
    if (strcmp(med[i].name, name) == 0) {
      printf("\n|%-20s|%-10s|%-10s|\n", "Medicine Name", "Quantity", "Price");
      printf("|%-20s|%-10d|%-10.2f|\n", med[i].name, med[i].quantity, med[i].price);
      found = 1;
      break;
    }
  }

  if (found == 0) {
    printf("\nMedicine not found! Please try again.\n");
  }
}