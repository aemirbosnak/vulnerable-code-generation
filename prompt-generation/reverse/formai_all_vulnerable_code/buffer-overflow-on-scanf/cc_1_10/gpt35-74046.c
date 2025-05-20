//FormAI DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TRANSACTIONS 100

// structure to hold transaction information
typedef struct {
  char type;
  float amount;
  char description[100];
} Transaction;

// function to display main menu
void displayMainMenu() {
  printf("\n#####      C EXPENSE TRACKER      #####\n");
  printf("\n1. Record a new transaction");
  printf("\n2. View all transactions");
  printf("\n3. View summary of transactions");
  printf("\n4. Exit");
  printf("\n\nEnter your choice: ");
}

// function to record a new transaction
void recordTransaction(Transaction transactions[], int *numTransactions) {
  
  Transaction newTransaction;

  //get transaction info from user
  printf("\nEnter transaction type (E for expense or I for income): ");
  scanf(" %c",&newTransaction.type);
  printf("Enter transaction amount: ");
  scanf("%f", &newTransaction.amount);
  printf("Enter transaction description (max 100 characters): ");
  getchar();
  fgets(newTransaction.description, 100, stdin);

  //add transaction to array
  transactions[*numTransactions] = newTransaction;
  *numTransactions += 1;

  printf("\nTransaction recorded successfully!\n");
}

// function to view all transactions
void viewTransactions(Transaction transactions[], int numTransactions) {
  printf("\n#####      ALL TRANSACTIONS      #####\n\n");

  for (int i=0; i<numTransactions; i++) {
    printf("%d. ", i+1);
    printf("%c ", transactions[i].type);
    printf("%.2f ", transactions[i].amount);
    printf("%s ", transactions[i].description);
  }
  if (numTransactions == 0)
    printf("\nNo transactions to display.");
}

// function to view summary of transactions
void viewTransactionSummary(Transaction transactions[], int numTransactions) {
  float income = 0.0, expense = 0.0;
  for (int i=0; i<numTransactions; i++) {
    if (transactions[i].type == 'I')
      income += transactions[i].amount;
    else
      expense += transactions[i].amount;
  }
  printf("\n#####      TRANSACTION SUMMARY      #####\n\n");
  printf("Total income: Rs. %.2f \n", income);
  printf("Total expense: Rs. %.2f \n", expense);
  printf("Net balance: Rs. %.2f \n", income - expense);
}

int main() {

  Transaction transactions[MAX_TRANSACTIONS];
  int numTransactions = 0;
  int choice;

  do {
    displayMainMenu();
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        recordTransaction(transactions, &numTransactions);
        break;
      case 2:
        viewTransactions(transactions, numTransactions);
        break;
      case 3:
        viewTransactionSummary(transactions, numTransactions);
        break;
      case 4:
        printf("\n#####      END OF PROGRAM      #####\n");
        break;
      default:
        printf("\nInvalid choice. Try again.\n");
        break;
    }
  } while (choice != 4);

  return 0;
}