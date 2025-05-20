//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Alan Touring
#include <stdio.h>

struct item {
  int id;
  int quantity;
  float price;
};

int main() {
  struct item warehouse[10];
  int menuChoice;
  int count = 0;

  do {
    printf("==========\n");
    printf("Warehouse Management System\n");
    printf("==========\n");
    printf("1. Add item to warehouse\n");
    printf("2. Display warehouse contents\n");
    printf("3. Exit program\n");
    printf("Enter menu choice: ");
    scanf("%d", &menuChoice);

    switch(menuChoice) {
      case 1:
        if(count < 10) {
          printf("Enter item ID: ");
          scanf("%d", &warehouse[count].id);
          printf("Enter item quantity: ");
          scanf("%d", &warehouse[count].quantity);
          printf("Enter item price: ");
          scanf("%f", &warehouse[count].price);
          count++;
        } else {
          printf("Warehouse is full!\n");
        }
        break;

      case 2:
        for(int i=0; i<count; i++) {
          printf("Item ID: %d\n", warehouse[i].id);
          printf("Item quantity: %d\n", warehouse[i].quantity);
          printf("Item price: $%.2f\n", warehouse[i].price);
        }
        break;

      case 3:
        printf("Exiting warehouse management system...\n");
        break;

      default:
        printf("Invalid menu choice!\n");
        break;
    }
  } while(menuChoice != 3);

  return 0;
}