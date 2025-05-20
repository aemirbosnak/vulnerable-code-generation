//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare Romeo and Juliet's expense structure
typedef struct {
  char description[50];
  float amount;
  char date[11];
} Expense;

// Declare an array of expenses
Expense expenses[100];

// Declare the number of expenses
int numExpenses = 0;

// Declare the total expenses
float totalExpenses = 0.0;

// Declare the file name
char fileName[] = "expenses.txt";

// Declare the main function
int main() {
  // Prompt the user to enter the expenses
  printf("Enter thy expenses, Romeo and Juliet:\n");

  // Loop until the user enters a blank line
  char input[50];
  while (gets(input) && strcmp(input, "") != 0) {
    // Get the description of the expense
    strcpy(expenses[numExpenses].description, input);

    // Get the amount of the expense
    scanf("%f", &expenses[numExpenses].amount);

    // Get the date of the expense
    scanf("%s", expenses[numExpenses].date);

    // Increment the number of expenses
    numExpenses++;

    // Calculate the total expenses
    totalExpenses += expenses[numExpenses].amount;
  }

  // Open the file for writing
  FILE *fp = fopen(fileName, "w");

  // Write the expenses to the file
  for (int i = 0; i < numExpenses; i++) {
    fprintf(fp, "%s\t%f\t%s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
  }

  // Close the file
  fclose(fp);

  // Print the total expenses
  printf("Total expenses: %f\n", totalExpenses);

  return 0;
}