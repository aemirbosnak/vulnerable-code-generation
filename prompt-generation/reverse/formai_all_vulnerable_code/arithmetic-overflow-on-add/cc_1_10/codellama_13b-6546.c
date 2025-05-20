//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct customer {
  char name[50];
  float bill;
  int items[10];
  int num_items;
};

int main() {
  struct customer cust;
  int i;

  printf("Welcome to our cafe!\n");
  printf("What is your name? ");
  scanf("%s", cust.name);

  printf("What would you like to order?\n");
  printf("1. Coffee - $2.00\n");
  printf("2. Tea - $1.50\n");
  printf("3. Milk - $1.00\n");
  printf("4. Chocolate Mug - $3.00\n");
  printf("5. Chocolate Bar - $2.50\n");
  printf("6. Quit\n");

  while (1) {
    printf("Enter your choice: ");
    scanf("%d", &i);

    if (i == 6) {
      break;
    }

    switch (i) {
      case 1:
        cust.bill += 2.00;
        cust.items[cust.num_items] = 1;
        cust.num_items++;
        break;
      case 2:
        cust.bill += 1.50;
        cust.items[cust.num_items] = 2;
        cust.num_items++;
        break;
      case 3:
        cust.bill += 1.00;
        cust.items[cust.num_items] = 3;
        cust.num_items++;
        break;
      case 4:
        cust.bill += 3.00;
        cust.items[cust.num_items] = 4;
        cust.num_items++;
        break;
      case 5:
        cust.bill += 2.50;
        cust.items[cust.num_items] = 5;
        cust.num_items++;
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  }

  printf("Your total bill is $%.2f\n", cust.bill);
  printf("Thank you for coming to our cafe, %s!\n", cust.name);

  return 0;
}