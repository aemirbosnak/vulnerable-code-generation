//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare global variables
int choice, quantity, total_price;
char option;

// Function to display the menu
void menu() 
{
  printf("Welcome to the C Cafe Billing System!\n\n");
  printf("1. Tea - Rs. 10\n");
  printf("2. Coffee - Rs. 15\n");
  printf("3. Cold Drink - Rs. 20\n");
  printf("4. Sandwich - Rs. 25\n");
  printf("5. Burger - Rs. 40\n\n");
  printf("Enter your choice: ");
}

// Function to calculate the total price
void calculate_price(int choice, int quantity) 
{
  switch(choice) 
  {
    case 1:
      total_price = quantity * 10;
      break;
    case 2:
      total_price = quantity * 15;
      break;
    case 3:
      total_price = quantity * 20;
      break;
    case 4:
      total_price = quantity * 25;
      break;
    case 5:
      total_price = quantity * 40;
      break;
    default:
      printf("Invalid choice!");
  }
}

// Function to display the bill
void display_bill() 
{
  printf("\n\n");
  printf("**********************************\n");
  printf("             C Cafe               \n");
  printf("      Your Bill is as follows     \n");
  printf("**********************************\n");
  printf("Total Price: Rs. %d\n", total_price);
  printf("**********************************\n\n");
}

// Main function
int main() {
  
  do {
    menu();
    scanf("%d", &choice);
    
    printf("How many do you want?: ");
    scanf("%d", &quantity);
    
    calculate_price(choice, quantity);
    display_bill();
    
    printf("Do you want to order anything else? (y/n)");
    scanf(" %c", &option);
    
  } while(option == 'y' || option == 'Y');
  
  printf("\n\nThank you for visiting the C Cafe!\n\n");
  
  return 0;
}