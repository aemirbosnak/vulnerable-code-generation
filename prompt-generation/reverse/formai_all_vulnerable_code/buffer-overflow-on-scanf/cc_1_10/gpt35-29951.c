//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

struct Medicine {
  char name[30];
  int quantity;
  float price;
};

void addMedicine(struct Medicine *medicines, int *count) {
  printf("Enter medicine name: ");
  scanf("%s", medicines[*count].name);
  printf("Enter medicine quantity: ");
  scanf("%d", &medicines[*count].quantity);
  printf("Enter medicine price: ");
  scanf("%f", &medicines[*count].price);

  (*count)++;
}

void displayMedicines(struct Medicine *medicines, int count) {
  printf("\n\nMedicine inventory:\n");

  for (int i = 0; i < count; i++) {
    printf("--------------------------------\n");
    printf("Name: %s\n", medicines[i].name);
    printf("Quantity: %d\n", medicines[i].quantity);
    printf("Price: %f\n", medicines[i].price);
    printf("--------------------------------\n");
  }
}

void searchMedicine(struct Medicine *medicines, int count) {
  char searchQuery[30];
  printf("\nEnter search query: ");
  scanf("%s", searchQuery);

  for (int i = 0; i < count; i++) {
    if (strcmp(searchQuery, medicines[i].name) == 0) {
      printf("\n\nMatch found:\n");
      printf("Name: %s\n", medicines[i].name);
      printf("Quantity: %d\n", medicines[i].quantity);
      printf("Price: %f\n", medicines[i].price);
      return;
    }
  }

  printf("\n\nNo match found.\n");
}

int main() {
  struct Medicine medicines[50];
  int count = 0;

  printf("Welcome to Medical Store Management System\n\n");

  while (1) {
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Search for a Medicine\n");
    printf("4. Exit\n\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addMedicine(medicines, &count);
        break;
      case 2:
        displayMedicines(medicines, count);
        break;
      case 3:
        searchMedicine(medicines, count);
        break;
      case 4:
        printf("\n\nThank you for using Medical Store Management System\n\n");
        exit(0);
      default:
        printf("\n\nInvalid choice.\n\n");
    }
  }

  return 0;
}