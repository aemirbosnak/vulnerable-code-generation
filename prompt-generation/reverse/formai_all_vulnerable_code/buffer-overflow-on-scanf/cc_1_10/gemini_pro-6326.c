//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
char name[50];
char address[100];
char phone[20];
char email[50];
int income;
int expenses;
int savings;
int debt;

// Function to get user input
void get_user_input() {
  printf("Welcome to the Personal Finance Planner!\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("Please enter your address: ");
  scanf("%s", address);
  printf("Please enter your phone number: ");
  scanf("%s", phone);
  printf("Please enter your email address: ");
  scanf("%s", email);
  printf("Please enter your income: ");
  scanf("%d", &income);
  printf("Please enter your expenses: ");
  scanf("%d", &expenses);
  printf("Please enter your savings: ");
  scanf("%d", &savings);
  printf("Please enter your debt: ");
  scanf("%d", &debt);
}

// Function to print user data
void print_user_data() {
  printf("Name: %s\n", name);
  printf("Address: %s\n", address);
  printf("Phone: %s\n", phone);
  printf("Email: %s\n", email);
  printf("Income: %d\n", income);
  printf("Expenses: %d\n", expenses);
  printf("Savings: %d\n", savings);
  printf("Debt: %d\n", debt);
}

// Function to calculate net worth
int calculate_net_worth() {
  return income - expenses - debt;
}

// Function to print net worth
void print_net_worth() {
  int net_worth = calculate_net_worth();
  printf("Your net worth is: %d\n", net_worth);
}

// Function to main menu
void main_menu() {
  int choice;
  do {
    printf("===================================\n");
    printf("1. Get user input\n");
    printf("2. Print user data\n");
    printf("3. Calculate net worth\n");
    printf("4. Print net worth\n");
    printf("5. Exit\n");
    printf("===================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        get_user_input();
        break;
      case 2:
        print_user_data();
        break;
      case 3:
        calculate_net_worth();
        break;
      case 4:
        print_net_worth();
        break;
      case 5:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 5);
}

// Main function
int main() {
  main_menu();
  return 0;
}