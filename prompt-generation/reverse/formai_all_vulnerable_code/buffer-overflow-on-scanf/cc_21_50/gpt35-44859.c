//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct medical_store {
  char medicine_name[50];
  int qty_in_stock;
  float price;
};

int main() {
  struct medical_store store[100]; // array of structures to store medicines
  int choice, n = 0, i, flag = 0;
  char search[50];

  // display initial menu
  printf("Welcome to Medical Store Management System\n\n");
  printf("1. Add Medicine\n");
  printf("2. Search Medicine\n");
  printf("3. Modify Medicine\n");
  printf("4. Delete Medicine\n");
  printf("5. Display Medicines\n");
  printf("6. Exit\n");

  do {
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        // add medicine to the inventory
        printf("\nEnter medicine name: ");
        scanf("%s", store[n].medicine_name);
        printf("Enter quantity in stock: ");
        scanf("%d", &store[n].qty_in_stock);
        printf("Enter price: ");
        scanf("%f", &store[n].price);

        printf("\nMedicine added successfully!\n");
        n++; // increment the counter of medicines in inventory
        break;

      case 2:
        // search for a medicine in inventory
        if(n == 0) {
          printf("\nNo medicine added yet!\n");
          break;
        }

        printf("\nEnter medicine name: ");
        scanf("%s", search);

        for(i=0; i<n; i++) {
          if(strcmp(search, store[i].medicine_name) == 0) {
            printf("Medicine found in inventory!\n");
            printf("Medicine Name: %s\nQuantity in stock: %d\nPrice: %.2f\n", store[i].medicine_name, store[i].qty_in_stock, store[i].price);
            flag = 1; // set flag to indicate medicine was found in inventory
            break;
          }
        }
        
        if(flag == 0)
          printf("Medicine not found in inventory!\n");
        break;

      case 3:
        // modify a medicine in inventory
        if(n == 0) {
          printf("\nNo medicine added yet!\n");
          break;
        }

        printf("\nEnter medicine name: ");
        scanf("%s", search);

        for(i=0; i<n; i++) {
          if(strcmp(search, store[i].medicine_name) == 0) {
            printf("Medicine found in inventory!\n");
            printf("Enter new quantity in stock for %s: ", store[i].medicine_name);
            scanf("%d", &store[i].qty_in_stock);
            printf("Enter new price for %s: ", store[i].medicine_name);
            scanf("%f", &store[i].price);
            printf("Medicine modified successfully!\n");
            flag = 1; // set flag to indicate medicine was found and modified
            break;
          }
        }
        
        if(flag == 0)
          printf("Medicine not found in inventory!\n");
        break;

      case 4:
        // delete a medicine from inventory
        if(n == 0) {
          printf("\nNo medicine added yet!\n");
          break;
        }

        printf("\nEnter medicine name: ");
        scanf("%s", search);

        for(i=0; i<n; i++) {
          if(strcmp(search, store[i].medicine_name) == 0) {
            printf("Medicine found in inventory!\n");
            // shift all elements after the found medicine to the left
            for(int j=i; j<n-1; j++)
              store[j] = store[j+1];
            n--; // decrement the counter of medicines in inventory
            printf("Medicine deleted successfully!\n");
            flag = 1; // set flag to indicate medicine was found and deleted
            break;
          }
        }
        
        if(flag == 0)
          printf("Medicine not found in inventory!\n");
        break;

      case 5:
        // display all medicines in inventory
        if(n == 0) {
          printf("\nNo medicine added yet!\n");
          break;
        }

        printf("\nMedicines in inventory:\n");
        for(i=0; i<n; i++)
          printf("Medicine Name: %s\nQuantity in stock: %d\nPrice: %.2f\n\n", store[i].medicine_name, store[i].qty_in_stock, store[i].price);
        break;

      case 6:
        printf("\nThank you for using Medical Store Management System!\n");
        exit(0);

      default:
        printf("\nInvalid choice! Please enter a valid choice.\n");
    }
  } while(choice != 6);

  return 0;
}