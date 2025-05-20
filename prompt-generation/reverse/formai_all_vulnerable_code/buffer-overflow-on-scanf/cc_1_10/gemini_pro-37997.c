//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  float price;
  int quantity;
} medicine;

void addMedicine(medicine *med, int *size) {
  printf("Enter medicine name: ");
  scanf("%s", med[*size].name);
  printf("Enter medicine price: ");
  scanf("%f", &med[*size].price);
  printf("Enter medicine quantity: ");
  scanf("%d", &med[*size].quantity);
  (*size)++;
}

void displayMedicine(medicine *med, int size) {
  for (int i = 0; i < size; i++) {
    printf("\nMedicine Name: %s", med[i].name);
    printf("\nMedicine Price: %.2f", med[i].price);
    printf("\nMedicine Quantity: %d", med[i].quantity);
    printf("\n");
  }
}

void searchMedicine(medicine *med, int size) {
  char name[50];
  printf("Enter medicine name to search: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < size; i++) {
    if (strcmp(med[i].name, name) == 0) {
      printf("\nMedicine Name: %s", med[i].name);
      printf("\nMedicine Price: %.2f", med[i].price);
      printf("\nMedicine Quantity: %d", med[i].quantity);
      printf("\n");
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Medicine not found!\n");
  }
}

void updateMedicine(medicine *med, int size) {
  char name[50];
  printf("Enter medicine name to update: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < size; i++) {
    if (strcmp(med[i].name, name) == 0) {
      printf("Enter new medicine price: ");
      scanf("%f", &med[i].price);
      printf("Enter new medicine quantity: ");
      scanf("%d", &med[i].quantity);
      printf("Medicine updated successfully!\n");
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Medicine not found!\n");
  }
}

void deleteMedicine(medicine *med, int *size) {
  char name[50];
  printf("Enter medicine name to delete: ");
  scanf("%s", name);
  int found = 0;
  for (int i = 0; i < *size; i++) {
    if (strcmp(med[i].name, name) == 0) {
      for (int j = i; j < *size - 1; j++) {
        med[j] = med[j + 1];
      }
      (*size)--;
      printf("Medicine deleted successfully!\n");
      found = 1;
      break;
    }
  }
  if (!found) {
    printf("Medicine not found!\n");
  }
}

int main() {
  medicine med[100];
  int size = 0;
  int choice;

  while (1) {
    printf("\n1. Add Medicine\n2. Display Medicine\n3. Search Medicine\n4. Update Medicine\n5. Delete Medicine\n6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addMedicine(med, &size);
        break;
      case 2:
        displayMedicine(med, size);
        break;
      case 3:
        searchMedicine(med, size);
        break;
      case 4:
        updateMedicine(med, size);
        break;
      case 5:
        deleteMedicine(med, &size);
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}