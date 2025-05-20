//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
  char name[50];
  float price;
  int quantity;
};

void buyMedicine(struct Medicine *med, int n);
void showMedicine(struct Medicine *med, int n);
void addMedicine(struct Medicine *med, int n);
void updateMedicine(struct Medicine *med, int n);
void deleteMedicine(struct Medicine *med, int n);
void searchMedicine(struct Medicine *med, int n);

int main() {
  int choice, n=0;
  struct Medicine *med;

  printf("*** Welcome to ABC Medical Store Management System ***\n");

  do {
    printf("\nChoose an option:\n");
    printf("1. Buy medicine\n");
    printf("2. Show available medicine\n");
    printf("3. Add medicine to inventory\n");
    printf("4. Update medicine details\n");
    printf("5. Delete medicine\n");
    printf("6. Search for medicine\n");
    printf("7. Exit\n");

    scanf("%d", &choice);

    switch(choice) {
      case 1:
        buyMedicine(med,n);
        break;
      case 2:
        showMedicine(med,n);
        break;
      case 3:
        addMedicine(med,n);
        n++;
        break;
      case 4:
        updateMedicine(med,n);
        break;
      case 5:
        deleteMedicine(med,n);
        n--;
        break;
      case 6:
        searchMedicine(med,n);
        break;
      case 7:
        printf("Thank you for using ABC Medical Store Management System!\n");
        exit(0);
      default:
        printf("Invalid option selected. Please try again.\n");
    }
  } while(choice != 7);
}

void buyMedicine(struct Medicine *med, int n) {
  char name[50];
  int quantity, i;
  float total = 0.0;

  printf("\nEnter name of medicine to buy: ");
  scanf("%s", name);

  for(i=0; i<n; i++) {
    if(strcmp(name, med[i].name) == 0) {
      printf("Enter quantity to buy: ");
      scanf("%d", &quantity);

      if(quantity > med[i].quantity) {
        printf("Sorry, only %d quantity of %s is available right now.\n", med[i].quantity, med[i].name);
      } else {
        med[i].quantity -= quantity;
        total += quantity * med[i].price;
      }
      break;
    }
  }

  if(i == n) {
    printf("Sorry, %s is not available in the inventory.\n", name);
  } else {
    printf("Total cost of purchase: %.2f\n", total);
  }
}

void showMedicine(struct Medicine *med, int n) {
  int i;

  printf("\n%-20s %-10s %-10s\n", "Medicine", "Price", "Quantity");
  for(i=0; i<n; i++) {
    printf("%-20s %-10.2f %-10d\n", med[i].name, med[i].price, med[i].quantity);
  }
}

void addMedicine(struct Medicine *med, int n) {
  printf("\nEnter details of new medicine:\n");
  printf("Name: ");
  scanf("%s", med[n].name);
  printf("Price: ");
  scanf("%f", &med[n].price);
  printf("Quantity: ");
  scanf("%d", &med[n].quantity);
}

void updateMedicine(struct Medicine *med, int n) {
  char name[50];
  int choice, i;

  printf("\nEnter name of medicine to update: ");
  scanf("%s", name);

  for(i=0; i<n; i++) {
    if(strcmp(name, med[i].name) == 0) {
      printf("\nChoose a field to update:\n");
      printf("1. Name\n");
      printf("2. Price\n");
      printf("3. Quantity\n");
      scanf("%d", &choice);

      switch(choice) {
        case 1:
          printf("New name: ");
          scanf("%s", med[i].name);
          break;
        case 2:
          printf("New price: ");
          scanf("%f", &med[i].price);
          break;
        case 3:
          printf("New quantity: ");
          scanf("%d", &med[i].quantity);
          break;
        default:
          printf("Invalid option selected.\n");
      }
      break;
    }
  }

  if(i == n) {
    printf("Sorry, %s is not available in the inventory.\n", name);
  }
}

void deleteMedicine(struct Medicine *med, int n) {
  char name[50];
  int i, j;

  printf("\nEnter name of medicine to delete: ");
  scanf("%s", name);

  for(i=0; i<n; i++) {
    if(strcmp(name, med[i].name) == 0) {
      for(j=i; j<n-1; j++) {
        strcpy(med[j].name, med[j+1].name);
        med[j].price = med[j+1].price;
        med[j].quantity = med[j+1].quantity;
      }
      break;
    }
  }

  if(i == n) {
    printf("Sorry, %s is not available in the inventory.\n", name);
  } else {
    printf("%s deleted from the inventory.\n", name);
  }
}

void searchMedicine(struct Medicine *med, int n) {
  char name[50];
  int i;

  printf("\nEnter name of medicine to search: ");
  scanf("%s", name);

  for(i=0; i<n; i++) {
    if(strcmp(name, med[i].name) == 0) {
      printf("\n%-20s %-10s %-10s\n", "Medicine", "Price", "Quantity");
      printf("%-20s %-10.2f %-10d\n", med[i].name, med[i].price, med[i].quantity);
      break;
    }
  }

  if(i == n) {
    printf("Sorry, %s is not available in the inventory.\n", name);
  }
}