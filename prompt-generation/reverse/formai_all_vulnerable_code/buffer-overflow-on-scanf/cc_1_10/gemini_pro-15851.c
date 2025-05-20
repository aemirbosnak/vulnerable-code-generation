//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

typedef struct {
  char name[50];
  float price;
  int quantity;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
  printf("Enter medicine name: ");
  scanf("%s", medicines[num_medicines].name);

  printf("Enter medicine price: ");
  scanf("%f", &medicines[num_medicines].price);

  printf("Enter medicine quantity: ");
  scanf("%d", &medicines[num_medicines].quantity);

  num_medicines++;
}

void list_medicines() {
  printf("** Medicines **\n");
  for (int i = 0; i < num_medicines; i++) {
    printf("%s - %.2f - %d\n", medicines[i].name, medicines[i].price,
           medicines[i].quantity);
  }
}

void search_medicine() {
  char name[50];
  printf("Enter medicine name to search: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_medicines; i++) {
    if (strcmp(medicines[i].name, name) == 0) {
      printf("Medicine found:\n");
      printf("Name: %s\n", medicines[i].name);
      printf("Price: %.2f\n", medicines[i].price);
      printf("Quantity: %d\n", medicines[i].quantity);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Medicine not found.\n");
  }
}

void update_medicine() {
  char name[50];
  printf("Enter medicine name to update: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_medicines; i++) {
    if (strcmp(medicines[i].name, name) == 0) {
      printf("Enter new medicine name: ");
      scanf("%s", medicines[i].name);

      printf("Enter new medicine price: ");
      scanf("%f", &medicines[i].price);

      printf("Enter new medicine quantity: ");
      scanf("%d", &medicines[i].quantity);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Medicine not found.\n");
  }
}

void delete_medicine() {
  char name[50];
  printf("Enter medicine name to delete: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < num_medicines; i++) {
    if (strcmp(medicines[i].name, name) == 0) {
      for (int j = i; j < num_medicines - 1; j++) {
        medicines[j] = medicines[j + 1];
      }
      num_medicines--;
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Medicine not found.\n");
  }
}

int main() {
  int choice;
  do {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. List Medicines\n");
    printf("3. Search Medicine\n");
    printf("4. Update Medicine\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_medicine();
        break;
      case 2:
        list_medicines();
        break;
      case 3:
        search_medicine();
        break;
      case 4:
        update_medicine();
        break;
      case 5:
        delete_medicine();
        break;
      case 6:
        printf("Exiting the program...\n");
        break;
      default:
        printf("Invalid choice. Please enter a number between 1 and 6.\n");
    }
  } while (choice != 6);

  return 0;
}