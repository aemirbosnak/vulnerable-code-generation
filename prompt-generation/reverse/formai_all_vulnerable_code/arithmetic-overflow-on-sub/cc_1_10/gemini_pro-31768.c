//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Global variables
int income, expenses, balance;
char category[50];
int amount;

// Function to get user input
void getInput() {
  char input[100];
  printf("Enter your income: ");
  fgets(input, 100, stdin);
  income = atoi(input);

  printf("Enter your expenses: ");
  fgets(input, 100, stdin);
  expenses = atoi(input);

  printf("Enter the category: ");
  fgets(input, 100, stdin);
  strcpy(category, input);

  printf("Enter the amount: ");
  fgets(input, 100, stdin);
  amount = atoi(input);
}

// Function to calculate balance
void calculateBalance() {
  balance = income - expenses;
}

// Function to print report
void printReport() {
  printf("\nYour income is: %d\n", income);
  printf("Your expenses are: %d\n", expenses);
  printf("Your balance is: %d\n", balance);
  printf("Category: %s\n", category);
  printf("Amount: %d\n", amount);
}

// Main function
int main() {
  // Welcome message
  printf("Welcome to the Happy Personal Finance Planner!\n");

  // Get user input
  getInput();

  // Calculate balance
  calculateBalance();

  // Print report
  printReport();

  // Exit message
  printf("\nThank you for using the Happy Personal Finance Planner!\n");
  return 0;
}