//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Define the lovers
#define ROMEO "Romeo"
#define JULIET "Juliet"

// Define the stock market
#define STOCK_MARKET "The Stock Market"
#define STOCK_PRICE "The Stock Price"

// Define the functions
void print_intro(void);
void print_menu(void);
void buy_stock(void);
void sell_stock(void);
void check_stock_price(void);
void exit_program(void);

// Define the global variables
int romeo_money = 1000;
int juliet_money = 1000;
int stock_price = 100;

// Main function
int main(void) {
  // Print the introduction
  print_intro();

  // Print the menu
  print_menu();

  // Get the user's choice
  int choice;
  scanf("%d", &choice);

  // While the user does not choose to exit
  while (choice != 4) {
    // Switch on the user's choice
    switch (choice) {
      case 1:  // Buy stock
        buy_stock();
        break;
      case 2:  // Sell stock
        sell_stock();
        break;
      case 3:  // Check stock price
        check_stock_price();
        break;
      default: // Invalid choice
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
    }

    // Print the menu
    print_menu();

    // Get the user's choice
    scanf("%d", &choice);
  }

  // Exit the program
  exit_program();

  return 0;
}

// Print the introduction
void print_intro(void) {
  printf("Welcome to %s, where love and money collide.\n", STOCK_MARKET);
  printf("You are %s and %s, two star-crossed lovers who are trying to make a fortune in the stock market.\n", ROMEO, JULIET);
  printf("But beware, the stock market is a treacherous place, and you could lose everything if you're not careful.\n");
  printf("Good luck!\n");
}

// Print the menu
void print_menu(void) {
  printf("\nWhat would you like to do?\n");
  printf("1. Buy stock\n");
  printf("2. Sell stock\n");
  printf("3. Check stock price\n");
  printf("4. Exit program\n");
}

// Buy stock
void buy_stock(void) {
  // Get the number of shares to buy
  int shares;
  printf("How many shares would you like to buy? ");
  scanf("%d", &shares);

  // Check if the user has enough money to buy the shares
  if (romeo_money < shares * stock_price) {
    printf("You don't have enough money to buy that many shares.\n");
    return;
  }

  // Buy the shares
  romeo_money -= shares * stock_price;
  printf("You have bought %d shares of stock.\n", shares);
}

// Sell stock
void sell_stock(void) {
  // Get the number of shares to sell
  int shares;
  printf("How many shares would you like to sell? ");
  scanf("%d", &shares);

  // Check if the user has enough shares to sell
  if (juliet_money < shares * stock_price) {
    printf("You don't have enough shares to sell that many shares.\n");
    return;
  }

  // Sell the shares
  juliet_money -= shares * stock_price;
  printf("You have sold %d shares of stock.\n", shares);
}

// Check stock price
void check_stock_price(void) {
  // Print the stock price
  printf("The current stock price is %d.\n", stock_price);
}

// Exit the program
void exit_program(void) {
  printf("Thank you for playing %s. We hope you enjoyed your stay.\n", STOCK_MARKET);
}