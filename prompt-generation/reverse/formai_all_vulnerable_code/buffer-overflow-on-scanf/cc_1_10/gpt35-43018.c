//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main() {
   int option;
   float cost = 0.0, discount = 0.0, payable = 0.0;
   char order[100];
   
   printf("Welcome to Cryptic Cafe Billing System!\n");
   
   do {
      printf("\nMenu:\n1. Order\n2. Print Bill\n3. Exit\nEnter Option: ");
      scanf("%d", &option);
      
      switch (option) {
         case 1:
            printf("Enter Order (e.g. Burger-Fries-Coke): ");
            scanf("%s", order);
            for (int i = 0; i < strlen(order); i++) {
               if (order[i] == '-') {
                  cost += 5.0; // assume all items cost $5
               }
            }
            break;
         case 2:
            if (cost > 0) {
               printf("\nBilling Details:\n");
               if (cost >= 10) {
                  discount = cost * 0.1; // 10% discount if cost is at least $10
                  payable = cost - discount;
                  printf("Cost:\t\t$%.2f\n", cost);
                  printf("Discount (10%%):\t$%.2f\n", discount);
                  printf("Payable Amount:\t$%.2f\n", payable);
               } else {
                  payable = cost;
                  printf("Cost:\t\t$%.2f\n", cost);
                  printf("Payable Amount:\t$%.2f\n", payable);
               }
               cost = 0;
               payable = 0;
               discount = 0;
            } else {
               printf("\nPlease order first!\n");
            }
            break;
         case 3:
            printf("\nThank you for using Cryptic Cafe Billing System!\n");
            break;
         default:
            printf("\nInvalid Option! Try Again.\n");
            break;
      }
      
   } while (option != 3);
   
   return 0;
}