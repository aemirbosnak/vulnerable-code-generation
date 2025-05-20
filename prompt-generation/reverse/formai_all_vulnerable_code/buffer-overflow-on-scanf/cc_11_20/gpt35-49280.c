//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct MedicalStore {
  char med_name[MAX];
  int med_id;
  int med_qty;
  float med_price;
};

int main() {
  struct MedicalStore store[MAX];
  int option = 0, count = 0;
  char search[MAX];

  while (1) {
    printf("-- MEDICAL STORE MANAGEMENT SYSTEM --\n");
    printf("1. Add Medicine\n");
    printf("2. Search Medicine\n");
    printf("3. Sell Medicine\n");
    printf("4. Display All Medicines\n");
    printf("5. Exit\n");
    printf("Enter Your Option : ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        // Add a Medicine
        printf("Enter Medicine Name : ");
        scanf("%s", store[count].med_name);
        printf("Enter Medicine ID : ");
        scanf("%d", &store[count].med_id);
        printf("Enter Medicine Quantity : ");
        scanf("%d", &store[count].med_qty);
        printf("Enter Medicine Price : ");
        scanf("%f", &store[count].med_price);
        count++;
        break;

      case 2:
        // Search Medicine
        printf("Enter Medicine Name : ");
        scanf("%s", search);
        for (int i = 0; i < count; i++) {
          if (strcmp(search, store[i].med_name) == 0) {
            printf("\nMedicine Found!\n\n");
            printf("Medicine Name : %s\n", store[i].med_name);
            printf("Medicine ID : %d\n", store[i].med_id);
            printf("Medicine Quantity : %d\n", store[i].med_qty);
            printf("Medicine Price : $%.2f\n\n", store[i].med_price);
            break;
          }
          if (i == count - 1) {
            printf("\nMedicine Not Found!\n\n");
          }
        }
        break;

      case 3:
        // Sell Medicine
        printf("Enter Medicine Name : ");
        scanf("%s", search);
        for (int i = 0; i < count; i++) {
          if (strcmp(search, store[i].med_name) == 0) {
            printf("\nMedicine Found!\n\n");
            printf("Medicine Name : %s\n", store[i].med_name);
            printf("Medicine ID : %d\n", store[i].med_id);
            printf("Medicine Quantity : %d\n", store[i].med_qty);
            printf("Medicine Price : $%.2f\n\n", store[i].med_price);

            int sell_qty = 0;
            printf("Enter Quantity to be Sold : ");
            scanf("%d", &sell_qty);

            if (sell_qty <= store[i].med_qty) {
              store[i].med_qty -= sell_qty;
              printf("\nMedicine Sold Successfully!\n\n");
            } else {
              printf("\nInsufficient Quantity!\n\n");
            }

            break;
          }
          if (i == count - 1) {
            printf("\nMedicine Not Found!\n\n");
          }
        }
        break;

      case 4:
        // Display All Medicines
        printf("\n");
        for (int i = 0; i < count; i++) {
          printf("Medicine Name : %s\n", store[i].med_name);
          printf("Medicine ID : %d\n", store[i].med_id);
          printf("Medicine Quantity : %d\n", store[i].med_qty);
          printf("Medicine Price : $%.2f\n\n", store[i].med_price);
        }
        break;

      case 5:
        // Exit
        printf("\nExiting Medical Store Management System...\n");
        exit(0);

      default:
        printf("\nWrong Input! Try Again.\n\n");
        break;
    }
  }

  return 0;
}