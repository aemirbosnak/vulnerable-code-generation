//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the menu
void displayMenu() {
  printf("************Menu************\n");
  printf("1. Tea          $1.00\n");
  printf("2. Coffee       $2.50\n");
  printf("3. Sandwich     $4.00\n");
  printf("4. Salad        $3.50\n");
  printf("5. Burger       $5.00\n");
  printf("****************************\n");
}

// Function to calculate the total bill
float calculateBill(int itemNumber, int itemQuantity) {
  float totalBill = 0.0;
  
  switch(itemNumber) {
    case 1:
      totalBill = 1.0 * itemQuantity;
      break;
    case 2:
      totalBill = 2.5 * itemQuantity;
      break;
    case 3:
      totalBill = 4.0 * itemQuantity;
      break;
    case 4:
      totalBill = 3.5 * itemQuantity;
      break;
    case 5:
      totalBill = 5.0 * itemQuantity;
      break;
    default:
      printf("Invalid item number. Please enter a number between 1 and 5.\n");
      break;
  }
  
  return totalBill;
}

int main() {
  int itemNumber, itemQuantity, choice;
  float totalBill, finalBill;
  char option[10];
  
  // Welcome message
  printf("Welcome to C Cafe!\n\n");
  
  do {
    // Display the menu
    displayMenu();
  
    // Ask for user input
    printf("Enter item number: ");
    scanf("%d", &itemNumber);
  
    printf("Enter item quantity: ");
    scanf("%d", &itemQuantity);
  
    // Calculate the total bill
    totalBill = calculateBill(itemNumber, itemQuantity);
  
    if(totalBill > 0) {
      printf("Total bill: $%.2f\n", totalBill);
      
      // Ask for user input to continue or stop
      printf("Do you want to order more? (yes/no): ");
      scanf("%s", option);
      
      // Check if the user wants to continue or stop
      if(strcmp(option, "yes") == 0) {
        choice = 1;
        finalBill += totalBill;
      }
      else if(strcmp(option, "no") == 0) {
        choice = 0;
        finalBill += totalBill;
      }
      else {
        printf("Invalid option. Please enter 'yes' or 'no'.\n");
        choice = 1;
      }
    }
    else {
      choice = 1;
    }
  } while(choice);
  
  // Display the final bill
  printf("Your total bill: $%.2f\n", finalBill);
  
  return 0;
}