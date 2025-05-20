//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
  char name[50];
  char manufacturer[50];
  int quantity;
  float price;
};

void display(struct medicine med[], int n) {
  printf("Name\tManufacturer\tQuantity\tPrice\n");
  for(int i=0; i<n; i++) {
    printf("%s\t%s\t\t%d\t\t%.2f\n", med[i].name, med[i].manufacturer, med[i].quantity, med[i].price);
  }
}

int search(struct medicine med[], int n, char name[]) {
  for(int i=0; i<n; i++) {
    if(strcmp(med[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

int main() {
  struct medicine med[100];
  int n, choice, index;
  char name[50];

  printf("Enter the number of medicines: ");
  scanf("%d", &n);

  for(int i=0; i<n; i++) {
    printf("\nEnter details of Medicine %d:\n", i+1);
    printf("Name: ");
    scanf("%s", med[i].name);
    printf("Manufacturer: ");
    scanf("%s", med[i].manufacturer);
    printf("Quantity: ");
    scanf("%d", &med[i].quantity);
    printf("Price: ");
    scanf("%f", &med[i].price);
  }

  printf("\nMedicine Details:\n");
  display(med, n);

  do {
    printf("\nMenu:\n");
    printf("1. Search for a medicine\n");
    printf("2. Add a new medicine\n");
    printf("3. Remove a medicine\n");
    printf("4. Update the details of a medicine\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the name of the medicine to search for: ");
        scanf("%s", name);
        index = search(med, n, name);
        if(index == -1) {
          printf("Medicine not found!\n");
        } else {
          printf("Name: %s\nManufacturer: %s\nQuantity: %d\nPrice: %.2f\n", med[index].name, med[index].manufacturer, med[index].quantity, med[index].price);
        }
        break;

      case 2:
        printf("\nEnter details of the new medicine:\n");
        printf("Name: ");
        scanf("%s", med[n].name);
        printf("Manufacturer: ");
        scanf("%s", med[n].manufacturer);
        printf("Quantity: ");
        scanf("%d", &med[n].quantity);
        printf("Price: ");
        scanf("%f", &med[n].price);
        n++;
        printf("\nMedicine Details:\n");
        display(med, n);
        break;

      case 3:
        printf("Enter the name of the medicine to remove: ");
        scanf("%s", name);
        index = search(med, n, name);
        if(index == -1) {
          printf("Medicine not found!\n");
        } else {
          for(int i=index; i<n-1; i++) {
            med[i] = med[i+1];
          }
          n--;
          printf("Medicine removed!\n");
          printf("\nMedicine Details:\n");
          display(med, n);
        }
        break;

      case 4:
        printf("Enter the name of the medicine to update: ");
        scanf("%s", name);
        index = search(med, n, name);
        if(index == -1) {
          printf("Medicine not found!\n");
        } else {
          printf("\nEnter new details of Medicine %d:\n", index+1);
          printf("Name: ");
          scanf("%s", med[index].name);
          printf("Manufacturer: ");
          scanf("%s", med[index].manufacturer);
          printf("Quantity: ");
          scanf("%d", &med[index].quantity);
          printf("Price: ");
          scanf("%f", &med[index].price);
          printf("Medicine details updated!\n");
          printf("\nMedicine Details:\n");
          display(med, n);
        }
        break;

      case 5:
        exit(0);

      default:
        printf("Invalid choice!\n");
        break;
    }
  } while(choice != 5);

  return 0;
}