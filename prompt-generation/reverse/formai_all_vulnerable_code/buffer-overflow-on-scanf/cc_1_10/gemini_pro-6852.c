//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: random
// Track expenses with a touch of whimsy!

#include <stdio.h>
#include <stdlib.h>

// A cosmic array of categories to track expenses
char *categories[] = {"Stardust Sprinkles <3", "Lunar Repairs", "Cosmic Snacks", "Stardust Cleaning", "Intergalactic Travel"};

// Welcome our celestial user!
void greet() {
  printf("Greetings, stargazer! Behold the celestial expense tracker!\n");
}

// Create a celestial expense entry
struct Expense {
  char *category;
  int amount;
  char *description;
};

// Capture an expense from the ethereal void
struct Expense *createExpense(char *category, int amount, char *description) {
  struct Expense *expense = malloc(sizeof(struct Expense));
  expense->category = category;
  expense->amount = amount;
  expense->description = description;
  return expense;
}

// Sort expenses by their intergalactic significance
void sortExpenses(struct Expense **expenses, int count) {
  for (int i = 0; i < count - 1; i++) {
    for (int j = i + 1; j < count; j++) {
      if (expenses[i]->amount < expenses[j]->amount) {
        struct Expense *temp = expenses[i];
        expenses[i] = expenses[j];
        expenses[j] = temp;
      }
    }
  }
}

// Display expenses in a dazzling nebula of numbers and words
void printExpenses(struct Expense **expenses, int count) {
  printf("\nBehold, the ethereal expense report:\n");
  for (int i = 0; i < count; i++) {
    printf("Category: %s\nAmount: %d spacebucks\nDescription: %s\n\n", expenses[i]->category, expenses[i]->amount, expenses[i]->description);
  }
}

// Free the expenses from the cosmic ether
void freeExpenses(struct Expense **expenses, int count) {
  for (int i = 0; i < count; i++) {
    free(expenses[i]);
  }
  free(expenses);
}

// Main function: where the celestial dance begins!
int main() {
  greet();

  // Capture expenses from the user's stardust-filled pockets
  int numExpenses = 0;
  printf("How many expenses did you incur in this cosmic cycle?\n");
  scanf("%d", &numExpenses);

  struct Expense **expenses = malloc(sizeof(struct Expense *) * numExpenses);

  for (int i = 0; i < numExpenses; i++) {
    char category[100];
    int amount;
    char description[100];

    printf("\nCategory (choose from: ");
    for (int j = 0; j < 5; j++) {
      printf("%s, ", categories[j]);
    }
    printf("): ");
    scanf("%s", category);

    printf("Amount (in spacebucks): ");
    scanf("%d", &amount);

    printf("Description (briefly): ");
    scanf(" %[^\n]", description); // Ignored leading whitespace

    expenses[i] = createExpense(category, amount, description);
  }

  // Sort the expenses in descending order of amount
  sortExpenses(expenses, numExpenses);

  // Display the expenses in all their celestial glory
  printExpenses(expenses, numExpenses);

  // Release the expenses back into the cosmic void
  freeExpenses(expenses, numExpenses);

  printf("\nYour expenses have been recorded in the annals of the cosmos. May your financial journey be as wondrous as the stars!\n");

  return 0;
}