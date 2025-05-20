//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: creative
#include<stdio.h>
#include<stdlib.h>

void main() {
  int bill = 0, choice, qty, item_price;
  
  printf("Welcome to the C Cafe!\n");
  printf("Menu:\n");

  printf("1. Coffee - Rs. 50\n");
  printf("2. Tea - Rs. 20\n");
  printf("3. Sandwich - Rs. 80\n");
  printf("4. Burger - Rs. 100\n");
  printf("5. Exit\n");

  do {
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("You selected Coffee. Each cup costs Rs. 50. How many cups do you want? ");
        scanf("%d", &qty);
        item_price = 50;
        bill += item_price * qty;
        printf("Your total bill is now Rs. %d\n", bill);
        break;
      case 2:
        printf("You selected Tea. Each cup costs Rs. 20. How many cups do you want? ");
        scanf("%d", &qty);
        item_price = 20;
        bill += item_price * qty;
        printf("Your total bill is now Rs. %d\n", bill);
        break;
      case 3:
        printf("You selected Sandwich. Each sandwich costs Rs. 80. How many sandwiches do you want? ");
        scanf("%d", &qty);
        item_price = 80;
        bill += item_price * qty;
        printf("Your total bill is now Rs. %d\n", bill);
        break;
      case 4:
        printf("You selected Burger. Each burger costs Rs. 100. How many burgers do you want? ");
        scanf("%d", &qty);
        item_price = 100;
        bill += item_price * qty;
        printf("Your total bill is now Rs. %d\n", bill);
        break;
      case 5:
        printf("Thank you for visiting C Cafe. Your total bill is Rs. %d\n", bill);
        exit(0);
      default:
        printf("Invalid choice. Please select again.\n");
        break;
    }
  } while(choice != 5);
}