//FormAI DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRANSACTIONS 100

// Define the structure for the transaction
typedef struct {
  char date[11];
  char description[50];
  float amount;
} Transaction;

// Function prototypes
void printMenu();
void addTransaction(Transaction transactions[], int* numTransactions);
void viewTransactions(Transaction transactions[], int numTransactions);
void viewExpenses(Transaction transactions[], int numTransactions);
void viewIncome(Transaction transactions[], int numTransactions);
void viewBalances(Transaction transactions[], int numTransactions);
void exitProgram();

int main() {
  // Declare variables and arrays
  Transaction transactions[MAX_TRANSACTIONS];
  int numTransactions = 0;
  int userChoice;
  
  // Display the menu and get user input
  do {
    printMenu();
    scanf("%d", &userChoice);
    
    // Call the appropriate function based on user input
    switch(userChoice) {
      case 1: 
        addTransaction(transactions, &numTransactions);
        break;
      case 2:
        viewTransactions(transactions, numTransactions);
        break;
      case 3:
        viewExpenses(transactions, numTransactions);
        break;
      case 4:
        viewIncome(transactions, numTransactions);
        break;
      case 5:
        viewBalances(transactions, numTransactions);
        break;
      case 6:
        exitProgram();
        break;
      default:
        printf("\nInvalid input. Please enter a number from 1 to 6.\n");
        break;
    }
    
  } while (userChoice != 6);
  
  return 0;
}

void printMenu() {
  printf("\nExpense Tracker\n");
  printf("----------------\n");
  printf("1. Add Transaction\n");
  printf("2. View All Transactions\n");
  printf("3. View Expenses\n");
  printf("4. View Income\n");
  printf("5. View Balances\n");
  printf("6. Exit\n\n");
}

void addTransaction(Transaction transactions[], int* numTransactions) {
  // Declare variables for new transaction
  char newDate[11];
  char newDescription[50];
  float newAmount;
  
  // Get user input for new transaction
  printf("\nEnter the date of the transaction (mm/dd/yyyy): ");
  scanf("%s", newDate);
  printf("Enter a short description of the transaction: ");
  scanf("%s", newDescription);
  printf("Enter the amount of the transaction: ");
  scanf("%f", &newAmount);
  
  // Add new transaction to the array
  strcpy(transactions[*numTransactions].date, newDate);
  strcpy(transactions[*numTransactions].description, newDescription);
  transactions[*numTransactions].amount = newAmount;
  (*numTransactions)++;
  
  printf("\nTransaction added successfully!\n");
}

void viewTransactions(Transaction transactions[], int numTransactions) {
  // Print header
  printf("\nAll Transactions\n");
  printf("----------------\n");
  
  // Loop through transactions and print details
  for (int i = 0; i < numTransactions; i++) {
    printf("%s | %s | %.2f\n", transactions[i].date, transactions[i].description, transactions[i].amount);
  }
}

void viewExpenses(Transaction transactions[], int numTransactions) {
  // Declare and initialize variables to track expenses
  float totalExpenses = 0;
  
  // Loop through transactions and add to expenses if amount is negative
  for (int i = 0; i < numTransactions; i++) {
    if (transactions[i].amount < 0) {
      totalExpenses += transactions[i].amount;
    }
  }
  
  // Print total expenses
  printf("\nExpenses: $%.2f\n", totalExpenses);
}

void viewIncome(Transaction transactions[], int numTransactions) {
  // Declare and initialize variables to track income
  float totalIncome = 0;
  
  // Loop through transactions and add to income if amount is positive
  for (int i = 0; i < numTransactions; i++) {
    if (transactions[i].amount > 0) {
      totalIncome += transactions[i].amount;
    }
  }
  
  // Print total income
  printf("\nIncome: $%.2f\n", totalIncome);
}

void viewBalances(Transaction transactions[], int numTransactions) {
  // Declare and initialize variables to track expenses and income
  float totalExpenses = 0;
  float totalIncome = 0;
  
  // Loop through transactions and add to expenses or income based on amount
  for (int i = 0; i < numTransactions; i++) {
    if (transactions[i].amount < 0) {
      totalExpenses += transactions[i].amount;
    } else if (transactions[i].amount > 0) {
      totalIncome += transactions[i].amount;
    }
  }
  
  // Calculate and print the balance
  float balance = totalIncome + totalExpenses;
  printf("\nExpenses: $%.2f\n", totalExpenses);
  printf("Income: $%.2f\n", totalIncome);
  printf("Balance: $%.2f\n", balance);
}

void exitProgram() {
  printf("\nGoodbye!\n");
}