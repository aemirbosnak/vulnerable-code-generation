//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Romeo and Juliet
// A Café Billing System in Romeo and Juliet style
// Created by Chatbot Juliet

#include <stdio.h>
#include <string.h>

int main() {
  
  // Display a warm greeting
  printf("O Romeo, Romeo, wherefore art thou Romeo?\n");
  printf("Welcome to our humble Café, kind sir!\n");
  printf("We doth offer thee the finest food and drink!\n");
  printf("Pray tell, what would thou like to order?\n");
  
  // Declare variables for user input and menu items
  char item[50];
  int quantity;
  float price;
  float sub_total = 0;
  float tax;
  float total;
  
  // Display menu items and ask for user input
  printf("\nOur Menu:\n");
  printf("1. Espresso............$2.50\n");
  printf("2. Cappuccino..........$3.50\n");
  printf("3. Latte...............$4.00\n");
  printf("4. Muffin..............$1.50\n");
  printf("5. Croissant...........$1.50\n");
  printf("\nWhat would thou like to order? (Enter item number): ");
  
  // Get user input
  scanf("%d", &quantity);
  
  // Determine user selection and set price accordingly
  switch(quantity) {
    case 1:
      strcpy(item, "Espresso");
      price = 2.50;
      break;
    case 2:
      strcpy(item, "Cappuccino");
      price = 3.50;
      break;
    case 3:
      strcpy(item, "Latte");
      price = 4.00;
      break;
    case 4:
      strcpy(item, "Muffin");
      price = 1.50;
      break;
    case 5:
      strcpy(item, "Croissant");
      price = 1.50;
      break;
    default:
      printf("We dost not offer such fare, good sir!\n");
      return 0;
  }
  
  // Calculate sub-total, tax, and total
  sub_total = price * quantity;
  tax = sub_total * .06;
  total = sub_total + tax;
  
  // Display user's order information and total
  printf("\nThou hast ordered %d of %s for a total of $%.2f\n", quantity, item, sub_total);
  printf("Tax doth amount to $%.2f and the total bill is $%.2f\n", tax, total);
  
  // Display a farewell message
  printf("Farewell, dear Romeo! We hope to see thee again soon!\n");
  
  return 0;
}