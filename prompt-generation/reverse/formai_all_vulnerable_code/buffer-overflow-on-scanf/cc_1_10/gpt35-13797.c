//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Claude Shannon
/* 
 * Medical Store Management System 
 * Designed and developed by Shannon
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
  char name[50];
  int id;
  int quantity;
  float price;
};

void addMedicine(struct medicine *medicines, int *count);
void removeMedicine(struct medicine *medicines, int *count);
void sellMedicine(struct medicine *medicines, int *count);
void displayMedicines(struct medicine *medicines, int count);

int main() {
  struct medicine medicines[100];
  int count = 0;

  int option;

  do {
    printf("\nMEDICAL STORE MANAGEMENT SYSTEM\n");
    printf("-------------------------------------------------------------\n");
    printf("1. Add Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. Sell Medicine\n");
    printf("4. Display Medicines\n");
    printf("5. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        addMedicine(medicines, &count);
        break;
      case 2:
        removeMedicine(medicines, &count);
        break;
      case 3:
        sellMedicine(medicines, &count);
        break;
      case 4:
        displayMedicines(medicines, count);
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid option.");
    }
  } while(option != 5);

  return 0;
}

void addMedicine(struct medicine *medicines, int *count) {
  char name[50];
  int id, quantity;
  float price;

  printf("\nEnter medicine name: ");
  scanf("%s", name);

  printf("Enter medicine id: ");
  scanf("%d", &id);

  printf("Enter medicine quantity: ");
  scanf("%d", &quantity);

  printf("Enter medicine price: ");
  scanf("%f", &price);

  strcpy(medicines[*count].name, name);
  medicines[*count].id = id;
  medicines[*count].quantity = quantity;
  medicines[*count].price = price;

  (*count)++;

  printf("\nMedicine added successfully!");
}

void removeMedicine(struct medicine *medicines, int *count) {
  int id, i, found = 0;

  printf("\nEnter medicine id: ");
  scanf("%d", &id);

  for(i = 0; i < *count; i++) {
    if(medicines[i].id == id) {
      found = 1;
      break;
    }
  }

  if(found) {
    for(i = i; i < *count - 1; i++) {
      strcpy(medicines[i].name, medicines[i+1].name);
      medicines[i].id = medicines[i+1].id;
      medicines[i].quantity = medicines[i+1].quantity;
      medicines[i].price = medicines[i+1].price;
    }

    (*count)--;
    printf("\nMedicine removed successfully!");
  }
  else {
    printf("\nMedicine not found!");
  }
}

void sellMedicine(struct medicine *medicines, int *count) {
  int id, i, found = 0;

  printf("\nEnter medicine id: ");
  scanf("%d", &id);

  for(i = 0; i < *count; i++) {
    if(medicines[i].id == id) {
      found = 1;
      break;
    }
  }

  if(found) {
    int quantity;

    printf("Enter medicine quantity: ");
    scanf("%d", &quantity);

    if(medicines[i].quantity >= quantity) {
      medicines[i].quantity -= quantity;

      printf("\nMedicine sold successfully!");
    }
    else {
      printf("\nInsufficient quantity!");
    }
  }
  else {
    printf("\nMedicine not found!");
  }
}

void displayMedicines(struct medicine *medicines, int count) {
  int i;

  printf("\n\nMEDICINE LIST\n");
  printf("-------------------------------------------------------------\n");
  printf("Name\t\tID\t\tQuantity\tPrice\n");

  for(i = 0; i < count; i++) {
    printf("%s\t\t%d\t\t%d\t\t%.2f\n", medicines[i].name, medicines[i].id, medicines[i].quantity, medicines[i].price);
  }
}