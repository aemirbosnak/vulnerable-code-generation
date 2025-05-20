//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: light-weight
#include <stdio.h>

int main() {
   float item1, item2, item3, item4, item5, subtotal, tax, total;
   int quantity1, quantity2, quantity3, quantity4, quantity5;
   const float TAX_RATE = 0.05; // 5% tax rate
   
   // Prompt for and get item prices and quantities
   printf("Enter item 1 price: ");
   scanf("%f", &item1);
   printf("Enter item 1 quantity: ");
   scanf("%d", &quantity1);

   printf("Enter item 2 price: ");
   scanf("%f", &item2);
   printf("Enter item 2 quantity: ");
   scanf("%d", &quantity2);

   printf("Enter item 3 price: ");
   scanf("%f", &item3);
   printf("Enter item 3 quantity: ");
   scanf("%d", &quantity3);

   printf("Enter item 4 price: ");
   scanf("%f", &item4);
   printf("Enter item 4 quantity: ");
   scanf("%d", &quantity4);

   printf("Enter item 5 price: ");
   scanf("%f", &item5);
   printf("Enter item 5 quantity: ");
   scanf("%d", &quantity5);

   // Calculate subtotal
   subtotal = item1 * quantity1 + item2 * quantity2 + item3 * quantity3
      + item4 * quantity4 + item5 * quantity5;

   // Calculate tax
   tax = subtotal * TAX_RATE;

   // Calculate total
   total = subtotal + tax;

   // Print the bill
   printf("\n+-------------------------+\n");
   printf("|       CAFE BILLING       |\n");
   printf("+-------------------------+\n");
   printf("| Item      |  Qty | Price |\n");
   printf("+-------------------------+\n");
   printf("| Item 1    |  %3d | $%4.2f |\n", quantity1, item1);
   printf("| Item 2    |  %3d | $%4.2f |\n", quantity2, item2);
   printf("| Item 3    |  %3d | $%4.2f |\n", quantity3, item3);
   printf("| Item 4    |  %3d | $%4.2f |\n", quantity4, item4);
   printf("| Item 5    |  %3d | $%4.2f |\n", quantity5, item5);
   printf("+-------------------------+\n");
   printf("| Subtotal  |       | $%4.2f |\n", subtotal);
   printf("| Tax (5%%)  |       | $%4.2f |\n", tax);
   printf("| Total     |       | $%4.2f |\n", total);
   printf("+-------------------------+\n");

   return 0;
}