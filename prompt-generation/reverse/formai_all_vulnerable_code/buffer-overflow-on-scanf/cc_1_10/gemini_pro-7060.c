//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int id;
  char name[50];
  float price;
  int quantity;
} Medicine;

#define MAX_MEDICINES 100

void addMedicine(Medicine *medicines, int *numMedicines) {
  if (*numMedicines >= MAX_MEDICINES) {
    printf("Error: Maximum number of medicines reached.\n");
    return;
  }

  Medicine newMedicine;
  printf("Enter medicine ID: ");
  scanf("%d", &newMedicine.id);
  printf("Enter medicine name: ");
  scanf(" %[^\n]s", newMedicine.name);
  printf("Enter medicine price: ");
  scanf("%f", &newMedicine.price);
  printf("Enter medicine quantity: ");
  scanf("%d", &newMedicine.quantity);

  medicines[*numMedicines] = newMedicine;
  (*numMedicines)++;
}

void searchMedicine(Medicine *medicines, int numMedicines) {
  int id;
  printf("Enter medicine ID to search for: ");
  scanf("%d", &id);

  for (int i = 0; i < numMedicines; i++) {
    if (medicines[i].id == id) {
      printf("Medicine found:\n");
      printf("ID: %d\n", medicines[i].id);
      printf("Name: %s\n", medicines[i].name);
      printf("Price: %.2f\n", medicines[i].price);
      printf("Quantity: %d\n", medicines[i].quantity);
      return;
    }
  }

  printf("Medicine not found.\n");
}

void updateMedicine(Medicine *medicines, int numMedicines) {
  int id;
  printf("Enter medicine ID to update: ");
  scanf("%d", &id);

  for (int i = 0; i < numMedicines; i++) {
    if (medicines[i].id == id) {
      printf("Enter new medicine name: ");
      scanf(" %[^\n]s", medicines[i].name);
      printf("Enter new medicine price: ");
      scanf("%f", &medicines[i].price);
      printf("Enter new medicine quantity: ");
      scanf("%d", &medicines[i].quantity);
      return;
    }
  }

  printf("Medicine not found.\n");
}

void deleteMedicine(Medicine *medicines, int *numMedicines) {
  int id;
  printf("Enter medicine ID to delete: ");
  scanf("%d", &id);

  for (int i = 0; i < *numMedicines; i++) {
    if (medicines[i].id == id) {
      for (int j = i; j < *numMedicines - 1; j++) {
        medicines[j] = medicines[j + 1];
      }
      (*numMedicines)--;
      return;
    }
  }

  printf("Medicine not found.\n");
}

void printMedicines(Medicine *medicines, int numMedicines) {
  printf("Medicines:\n");
  for (int i = 0; i < numMedicines; i++) {
    printf("ID: %d\n", medicines[i].id);
    printf("Name: %s\n", medicines[i].name);
    printf("Price: %.2f\n", medicines[i].price);
    printf("Quantity: %d\n\n", medicines[i].quantity);
  }
}

int main() {
  Medicine medicines[MAX_MEDICINES];
  int numMedicines = 0;

  int choice;
  do {
    printf("Medical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Search Medicine\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Print Medicines\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addMedicine(medicines, &numMedicines);
        break;
      case 2:
        searchMedicine(medicines, numMedicines);
        break;
      case 3:
        updateMedicine(medicines, numMedicines);
        break;
      case 4:
        deleteMedicine(medicines, &numMedicines);
        break;
      case 5:
        printMedicines(medicines, numMedicines);
        break;
      case 6:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice.\n");
    }
  } while (choice != 6);

  return 0;
}