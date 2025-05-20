//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
  char name[50];
  int quantity;
};

int main() {
  struct medicine stock[100];
  int choice, num_medicines = 0;

  while(1) {
    printf("Welcome to the Medical Store Management System\n");
    printf("---------------------------------------------\n");
    printf("1. Add Medicine\n");
    printf("2. Remove Medicine\n");
    printf("3. Update Medicine Quantity\n");
    printf("4. View All Medicines\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        // Add Medicine
        printf("Enter medicine name: ");
        scanf("%s", stock[num_medicines].name);
        printf("Enter medicine quantity: ");
        scanf("%d", &stock[num_medicines].quantity);
        printf("Medicine added successfully!\n");
        num_medicines++;
        break;

      case 2:
        // Remove Medicine
        printf("Enter medicine name: ");
        char temp[50];
        scanf("%s", temp);
        int found = 0;
        for(int i = 0; i < num_medicines; i++) {
          if(strcmp(stock[i].name, temp) == 0) {
            found = 1;
            printf("Medicine removed successfully!\n");
            for(int j = i; j < num_medicines - 1; j++) {
              stock[j] = stock[j+1];
            }
            num_medicines--;
          }
        }
        if(found == 0) {
          printf("Medicine not found\n");
        }
        break;

      case 3:
        // Update Medicine Quantity
        printf("Enter medicine name: ");
        char temp1[50];
        scanf("%s", temp1);
        found = 0;
        for(int i = 0; i < num_medicines; i++) {
          if(strcmp(stock[i].name, temp1) == 0) {
            found = 1;
            printf("Enter new medicine quantity: ");
            scanf("%d", &stock[i].quantity);
            printf("Quantity updated successfully!\n");
          }
        }
        if(found == 0) {
          printf("Medicine not found\n");
        }
        break;

      case 4:
        // View All Medicines
        printf("Medicine Name\tQuantity\n");
        for(int i = 0; i < num_medicines; i++) {
          printf("%s\t\t%d\n", stock[i].name, stock[i].quantity);
        }
        break;

      case 5:
        // Search Medicine
        printf("Enter medicine name: ");
        char temp2[50];
        scanf("%s", temp2);
        found = 0;
        for(int i = 0; i < num_medicines; i++) {
          if(strcmp(stock[i].name, temp2) == 0) {
            found = 1;
            printf("Medicine Found!\n");
            printf("Medicine Name\tQuantity\n");
            printf("%s\t\t%d\n", stock[i].name, stock[i].quantity);
          }
        }
        if(found == 0) {
          printf("Medicine not found\n");
        }
        break;

      case 6:
        // Exit
        printf("Thank you for using the Medical Store Management System\n");
        exit(0);

      default:
        printf("Invalid Choice\n");
    }
  }

  return 0;
}