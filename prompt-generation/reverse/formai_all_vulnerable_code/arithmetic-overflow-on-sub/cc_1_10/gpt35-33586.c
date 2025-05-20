//FormAI DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int balance = 0;
int expenseListLength = 0;
char expenseList[100][50];
int expenseAmount[100];

void addExpense(char expense[50], int amount) {
  strcpy(expenseList[expenseListLength], expense);
  expenseAmount[expenseListLength] = amount;
  balance -= amount;
  expenseListLength++;
}

void printExpenses() {
  printf("\n\nExpenses:\n");
  for(int i=0; i<expenseListLength; i++) {
    printf("%s - $%d\n", expenseList[i], expenseAmount[i]);
  }
  printf("\n");
}

void printMenu() {
  printf("\n\n============Expense Tracker============\n");
  printf("Balance: $%d\n", balance);
  printf("1 - Add Expense\n");
  printf("2 - View Expenses\n");
  printf("3 - Exit\n");
  printf("Enter your choice: ");
}


int main() {
  int choice, amount;
  char expense[50];
  do {
    printMenu();
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        printf("Enter expense name: ");
        scanf("%s", expense);
        printf("Enter expense amount: ");
        scanf("%d", &amount);
        addExpense(expense, amount);
        break;
      case 2:
        printExpenses();
        break;
      case 3:
        printf("\nThank you for using the expense tracker!\n");
        break;
      default:
        printf("\nInvalid choice, try again.\n");
        break;
    }
  } while(choice != 3);

  return 0;
}