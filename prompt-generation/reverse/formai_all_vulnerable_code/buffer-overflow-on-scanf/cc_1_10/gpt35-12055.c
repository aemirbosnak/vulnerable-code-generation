//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int stock;
  float price;
} Medicine;

void add_medicine(Medicine *m, int *size);
void update_medicine(Medicine *m, int size);
void delete_medicine(Medicine *m, int *size);
void search_medicine(Medicine *m, int size);
void display_medicines(Medicine *m, int size);

int main() {
  Medicine medicines[100];
  int size = 0, choice;

  do {
    printf("\n\n~~~ Welcome to the Medical Store Management System! ~~~");
    printf("\n\n1. Add a medicine");
    printf("\n2. Update a medicine");
    printf("\n3. Delete a medicine");
    printf("\n4. Search for a medicine");
    printf("\n5. Display all medicines");
    printf("\n6. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        add_medicine(medicines, &size);
        break;
      case 2:
        update_medicine(medicines, size);
        break;
      case 3:
        delete_medicine(medicines, &size);
        break;
      case 4:
        search_medicine(medicines, size);
        break;
      case 5:
        display_medicines(medicines, size);
        break;
      case 6:
        printf("\nThank you for using the Medical Store Management System!");
        break;
      default:
        printf("\nInvalid Choice. Please try again.");
        break;
    }

  } while(choice != 6);

  return 0;
}

void add_medicine(Medicine *m, int *size) {
  printf("\nEnter the name of the medicine: ");
  scanf("%s", m[*size].name);
  printf("Enter the stock of the medicine: ");
  scanf("%d", &m[*size].stock);
  printf("Enter the price of the medicine: ");
  scanf("%f", &m[*size].price);

  (*size)++;
  printf("\nMedicine added successfully.");
}

void update_medicine(Medicine *m, int size) {
  char name[20];
  int i, stock;
  float price;

  printf("\nEnter the name of the medicine to update: ");
  scanf("%s", name);

  for(i = 0; i < size; i++) {
    if(strcmp(name, m[i].name) == 0) {
      printf("Enter the new stock of the medicine: ");
      scanf("%d", &stock);
      printf("Enter the new price of the medicine: ");
      scanf("%f", &price);

      m[i].stock = stock;
      m[i].price = price;

      printf("\nMedicine updated successfully.");
      return;
    }
  }

  printf("\nMedicine not found. Please try again.");
}

void delete_medicine(Medicine *m, int *size) {
  char name[20];
  int i, j;

  printf("\nEnter the name of the medicine to delete: ");
  scanf("%s", name);

  for(i = 0; i < *size; i++) {
    if(strcmp(name, m[i].name) == 0) {
      for(j = i; j < (*size) - 1; j++) {
        m[j] = m[j + 1];
      }

      (*size)--;
      printf("\nMedicine deleted successfully.");
      return;
    }
  }

  printf("\nMedicine not found. Please try again.");
}

void search_medicine(Medicine *m, int size) {
  char name[20];
  int i;

  printf("\nEnter the name of the medicine to search for: ");
  scanf("%s", name);

  for(i = 0; i < size; i++) {
    if(strcmp(name, m[i].name) == 0) {
      printf("\nMedicine found! Details are:");
      printf("\nName: %s", m[i].name);
      printf("\nStock: %d", m[i].stock);
      printf("\nPrice: Rs%.2f", m[i].price);
      return;
    }
  }

  printf("\nMedicine not found. Please try again.");
}

void display_medicines(Medicine *m, int size) {
  int i;

  printf("\nMedicine List:");
  printf("\n%-20s %-10s %-10s", "Name", "Stock", "Price");

  for(i = 0; i < size; i++) {
    printf("\n%-20s %-10d Rs%.2f", m[i].name, m[i].stock, m[i].price);
  }
}