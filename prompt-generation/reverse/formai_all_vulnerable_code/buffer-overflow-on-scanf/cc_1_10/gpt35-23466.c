//FormAI DATASET v1.0 Category: Expense Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000

typedef struct Expense {
  char date[20];
  char category[50];
  double amount;
  char note[200];
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void printMenu();
void addExpense();
void viewExpenses();
void saveExpenses();
void loadExpenses();

int main() {
  loadExpenses();
  printMenu();
  saveExpenses();
  return 0;
}

void printMenu() {
  int choice;
  do {
    printf("Expense Tracker Menu:\n");
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. Exit\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        addExpense();
        break;
      case 2:
        viewExpenses();
        break;
      case 3:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice, please try again.\n");
    }
  } while (choice != 3);
}

void addExpense() {
  printf("\nEnter the date of the expense (mm/dd/yyyy): ");
  scanf("%s", expenses[numExpenses].date);
  printf("Enter the category of the expense: ");
  scanf("%s", expenses[numExpenses].category);
  printf("Enter the amount of the expense: ");
  scanf("%lf", &expenses[numExpenses].amount);
  printf("Enter a note (optional): ");
  scanf("%s", expenses[numExpenses].note);
  numExpenses++;
  printf("Expense added.\n");
}

void viewExpenses() {
  if (numExpenses == 0) {
    printf("\nNo expenses to display.\n");
  } else {
    printf("\nAll expenses:\n");
    printf("%-15s %-20s %-10s %-50s\n", "Date", "Category", "Amount", "Note");
    for (int i = 0; i < numExpenses; i++) {
      printf("%-15s %-20s $%8.2f ", expenses[i].date, expenses[i].category, expenses[i].amount);
      if (strlen(expenses[i].note) > 0) {
        printf("%-50s", expenses[i].note);
      }
      printf("\n");
    }
  }
}

void saveExpenses() {
  FILE *fp;
  fp = fopen("expenses.txt", "w");
  if (fp == NULL) {
    printf("\nError: could not save expenses.\n");
  } else {
    for (int i = 0; i < numExpenses; i++) {
      fprintf(fp, "%s,%s,%.2f,%s\n", expenses[i].date, expenses[i].category, expenses[i].amount, expenses[i].note);
    }
    printf("\nExpenses saved.\n");
    fclose(fp);
  }
}

void loadExpenses() {
  FILE *fp;
  fp = fopen("expenses.txt", "r");
  if (fp != NULL) {
    char buffer[32767];
    while (fgets(buffer, sizeof(buffer), fp)) {
      char *date = strtok(buffer, ",");
      char *category = strtok(NULL, ",");
      char *amountStr = strtok(NULL, ",");
      char *note = strtok(NULL, "\n");
      double amount = atof(amountStr);
      strcpy(expenses[numExpenses].date, date);
      strcpy(expenses[numExpenses].category, category);
      expenses[numExpenses].amount = amount;
      if (note != NULL) {
        strcpy(expenses[numExpenses].note, note);
      } else {
        strcpy(expenses[numExpenses].note, "");
      }
      numExpenses++;
    }
    fclose(fp);
    printf("\nExpenses loaded.\n");
  }
}