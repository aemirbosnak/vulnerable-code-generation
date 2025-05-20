//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>

int main() {
   int choice, quantity, i = 0;
   float total_cost = 0, cost = 0;
   int code[10], quantity_list[10];

   printf("Welcome to our cafe!\n");

   while (1) {
      printf("\nEnter the food code (1-5) that you want to order or 6 to exit: ");
      scanf("%d", &choice);

      if (choice == 6) {
         printf("\nThank you for visiting our cafe!\n");
         break;
      }

      printf("Enter the quantity of the food item: ");
      scanf("%d", &quantity);

      switch (choice) {
         case 1:
            cost = 20.0;
            break;
         case 2:
            cost = 25.0;
            break;
         case 3:
            cost = 15.0;
            break;
         case 4:
            cost = 12.0;
            break;
         case 5:
            cost = 30.0;
            break;
         default:
            printf("Invalid code entered!\n");
            continue;
      }

      code[i] = choice;
      quantity_list[i] = quantity;
      i++;

      total_cost += cost * quantity;

      printf("Food item added to your bill!\n");
   }

   printf("\n\n-------------------------\n");
   printf("      CAFE BILL\n");
   printf("-------------------------\n");

   printf("Code   |  Quantity |  Cost\n");

   for (int j = 0; j < i; j++) {
      printf("%d      |  %d        |  %.2f\n", code[j], quantity_list[j], cost * quantity_list[j]);
   }

   printf("\nTotal: %.2f\n", total_cost);

   return 0;
}