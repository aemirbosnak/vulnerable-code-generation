//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct expense {
  char description[100];
  float amount;
  int category;
} expense_t;

// Define the categories of expenses
enum categories {
  ENTERTAINMENT,
  FOOD,
  HEALTH,
  HOUSING,
  TRANSPORTATION,
  OTHER
};

// Declare the array of expenses
expense_t expenses[MAX_EXPENSES];

// Declare the number of expenses
int num_expenses = 0;

// Get a string from the user
char *get_string(char *prompt) {
  char *input = NULL;
  size_t len = 0;
  printf("%s", prompt);
  getline(&input, &len, stdin);
  return input;
}

// Get a float from the user
float get_float(char *prompt) {
  float input;
  printf("%s", prompt);
  scanf("%f", &input);
  return input;
}

// Get an integer from the user
int get_int(char *prompt) {
  int input;
  printf("%s", prompt);
  scanf("%d", &input);
  return input;
}

// Add an expense to the array
void add_expense(char *description, float amount, int category) {
  if (num_expenses < MAX_EXPENSES) {
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].category = category;
    num_expenses++;
  } else {
    printf("Error: The maximum number of expenses has been reached.\n");
  }
}

// Print the expenses in the array
void print_expenses() {
  for (int i = 0; i < num_expenses; i++) {
    printf("%s\t%.2f\t", expenses[i].description, expenses[i].amount);
    switch (expenses[i].category) {
      case ENTERTAINMENT:
        printf("Entertainment\n");
        break;
      case FOOD:
        printf("Food\n");
        break;
      case HEALTH:
        printf("Health\n");
        break;
      case HOUSING:
        printf("Housing\n");
        break;
      case TRANSPORTATION:
        printf("Transportation\n");
        break;
      case OTHER:
        printf("Other\n");
        break;
    }
  }
}

// Main function
int main() {
  // Get the user's input
  char *description = get_string("Enter the description of the expense: ");
  float amount = get_float("Enter the amount of the expense: ");
  int category = get_int("Enter the category of the expense (1 for Entertainment, 2 for Food, 3 for Health, 4 for Housing, 5 for Transportation, 6 for Other): ");

  // Add the expense to the array
  add_expense(description, amount, category);

  // Print the expenses in the array
  print_expenses();

  return 0;
}