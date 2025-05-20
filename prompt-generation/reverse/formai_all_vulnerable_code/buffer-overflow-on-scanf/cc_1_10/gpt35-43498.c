//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Ken Thompson
#include <stdio.h>

int main() {
   int order = 0;  // initialize order count
   float total = 0;  // initialize total revenue
   
   // Print welcome message
   printf("Welcome to Ken's Cafe Billing System!\n\n");
   
   // Loop to take orders
   while (1) {
      int choice;
      float price;
      
      printf("Menu:\n");
      printf("1. Coffee (Rs. 100)\n");
      printf("2. Tea (Rs. 50)\n");
      printf("3. Sandwich (Rs. 150)\n");
      printf("4. Juice (Rs. 80)\n");
      printf("5. Exit\n");
      
      printf("Enter your choice: ");
      scanf("%d", &choice);
      
      if (choice == 5) {  // Exit loop
         break;
      }
      
      switch (choice) {  // Process order
         case 1:
            price = 100.0;
            printf("You ordered coffee.\n");
            break;
         case 2:
            price = 50.0;
            printf("You ordered tea.\n");
            break;
         case 3:
            price = 150.0;
            printf("You ordered sandwich.\n");
            break;
         case 4:
            price = 80.0;
            printf("You ordered juice.\n");
            break;
         default:
            printf("Invalid choice.\n");
            continue;  // Skip to next iteration
      }
      
      // Update variables
      order++;
      total += price;
      printf("Thank you for your order! Your total is Rs. %.2f\n", total);
   }
   
   // Print summary
   printf("\nSummary:\n");
   printf("Total orders: %d\n", order);
   printf("Total revenue: Rs. %.2f\n", total);
   printf("Thank you for using Ken's Cafe Billing System!\n");
   
   return 0;
}