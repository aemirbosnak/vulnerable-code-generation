//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>

int main() {
   float tea = 15.0, coffee = 20.0, sandwich = 25.0, burger = 30.0, fries = 15.0;
   int teaCount = 0, coffeeCount = 0, sandwichCount = 0, burgerCount = 0, friesCount = 0;
   float totalAmount = 0.0, amountPaid = 0.0, balance = 0.0;
   int option = 0, quantity = 0, orderCount = 1, menuCount = 5;

   printf("\nWelcome to the C Cafe! Please make your order.\n");

   do {
      printf("\n======== Menu ========\n");
      printf("1. Tea        - Rs.15.00\n");
      printf("2. Coffee     - Rs.20.00\n");
      printf("3. Sandwich   - Rs.25.00\n");
      printf("4. Burger     - Rs.30.00\n");
      printf("5. Fries      - Rs.15.00\n");
      printf("6. Exit\n");
      printf("=======================\n");

      printf("Enter your choice: ");
      scanf("%d", &option);

      if (option == 6) {
         break;
      }

      if (option < 1 || option > menuCount) {
         printf("\nInvalid choice. Please enter a valid menu item number.\n");
         continue;
      }

      printf("Enter quantity: ");
      scanf("%d", &quantity);

      switch (option) {
         case 1:
            teaCount += quantity;
            totalAmount += tea * quantity;
            break;
         case 2:
            coffeeCount += quantity;
            totalAmount += coffee * quantity;
            break;
         case 3:
            sandwichCount += quantity;
            totalAmount += sandwich * quantity;
            break;
         case 4:
            burgerCount += quantity;
            totalAmount += burger * quantity;
            break;
         case 5:
            friesCount += quantity;
            totalAmount += fries * quantity;
            break;
      }

      printf("\nOrder %d: %d x ", orderCount, quantity);

      switch (option) {
         case 1:
            printf("Tea");
            break;
         case 2:
            printf("Coffee");
            break;
         case 3:
            printf("Sandwich");
            break;
         case 4:
            printf("Burger  ");
            break;
         case 5:
            printf("Fries   ");
            break;
      }

      printf(" = Rs.%.2f\n", totalAmount);

      orderCount++;

   } while (1);

   printf("\nThank you for ordering at C Cafe.\n");
   printf("Total Bill: Rs.%.2f\n", totalAmount);
   printf("Amount Paid: Rs.");
   scanf("%f", &amountPaid);

   balance = amountPaid - totalAmount;

   if (balance < 0.0) {
      printf("\nInsufficient amount paid. Please pay Rs.%.2f more.\n", -1.0 * balance);
   } else if (balance > 0.0) {
      printf("\nThank you for your payment. Your change is Rs.%.2f\n", balance);
   } else {
      printf("\nThank you for your payment.\n");
   }

   return 0;
}