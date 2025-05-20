//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
  char name[50];
  int quantity;
  float price;
};

void displayMenu() {
  printf("==== Medical Store Management System ====\n");
  printf("1. Add Medicine\n");
  printf("2. View Medicine\n");
  printf("3. Search Medicine\n");
  printf("4. Update Medicine\n");
  printf("5. Delete Medicine\n");
  printf("6. Exit\n");
  printf("========================================\n");
}

void addMedicine(struct medicine *medArray, int *numOfMeds) {
  printf("Enter medicine name: ");
  scanf("%s", medArray[*numOfMeds].name);
  printf("Enter medicine quantity: ");
  scanf("%d", &medArray[*numOfMeds].quantity);
  printf("Enter medicine price: ");
  scanf("%f", &medArray[*numOfMeds].price);

  (*numOfMeds)++;
  printf("\nMedicine added successfully!\n\n");
}

void viewMedicine(struct medicine *medArray, int numOfMeds) {
  printf("==== Medicine List ====\n");
  printf("%-30s%-15s%s\n", "Medicine Name", "Quantity", "Price");
  for(int i=0; i<numOfMeds; i++) {
    printf("%-30s%-15d%.2f\n", medArray[i].name, medArray[i].quantity, medArray[i].price);
  }
  printf("\n");
}

void searchMedicine(struct medicine *medArray, int numOfMeds) {
  char name[50];
  printf("Enter medicine name: ");
  scanf("%s", name);

  for(int i=0; i<numOfMeds; i++) {
    if(strcmp(medArray[i].name, name) == 0) {
      printf("Medicine found!\n");
      printf("%-30s%-15s%s\n", "Medicine Name", "Quantity", "Price");
      printf("%-30s%-15d%.2f\n\n", medArray[i].name, medArray[i].quantity, medArray[i].price);
      return;
    }
  }

  printf("Medicine not found!\n\n");
}

void updateMedicine(struct medicine *medArray, int numOfMeds) {
  char name[50];
  printf("Enter medicine name: ");
  scanf("%s", name);

  for(int i=0; i<numOfMeds; i++) {
    if(strcmp(medArray[i].name, name) == 0) {
      printf("Enter new quantity: ");
      scanf("%d", &medArray[i].quantity);
      printf("Enter new price: ");
      scanf("%f", &medArray[i].price);
      printf("Medicine updated successfully!\n\n");
      return;
    }
  }

  printf("Medicine not found!\n\n");
}

void deleteMedicine(struct medicine *medArray, int *numOfMeds) {
  char name[50];
  printf("Enter medicine name: ");
  scanf("%s", name);

  for(int i=0; i<*numOfMeds; i++) {
    if(strcmp(medArray[i].name, name) == 0) {
      for(int j=i; j<*numOfMeds-1; j++) {
        medArray[j] = medArray[j+1];
      }
      (*numOfMeds)--;
      printf("Medicine deleted successfully!\n\n");
      return;
    }
  }

  printf("Medicine not found!\n\n");
}

int main() {
  struct medicine medArray[100];
  int numOfMeds = 0;
  int choice;

  do {
    displayMenu();
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addMedicine(medArray, &numOfMeds);
        break;
      case 2:
        viewMedicine(medArray, numOfMeds);
        break;
      case 3:
        searchMedicine(medArray, numOfMeds);
        break;
      case 4:
        updateMedicine(medArray, numOfMeds);
        break;
      case 5:
        deleteMedicine(medArray, &numOfMeds);
        break;
      case 6:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n\n");
        break;
    }
  } while(choice != 6);

  return 0;
}