//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000        // Maximum number of entries that can be added
#define MAX_CATEGORY_LEN 20    // Maximum length of a category name
#define MAX_NOTE_LEN 50        // Maximum length of a note

typedef struct {
  double amount;              // Amount spent
  char category[MAX_CATEGORY_LEN+1];  // Category of the expense
  char note[MAX_NOTE_LEN+1];  // Note about the expense
} expense_t;

int num_entries = 0;          // Number of entries in the tracker
expense_t expense[MAX_ENTRIES];      // Array to store all the expenses

// Function to add a new expense to the tracker
void add_new_expense() {
  printf("Enter the amount spent: ");
  scanf("%lf", &expense[num_entries].amount);

  printf("Enter the category (maximum %d characters): ", MAX_CATEGORY_LEN);
  scanf("%s", expense[num_entries].category);

  printf("Enter a note (maximum %d characters): ", MAX_NOTE_LEN);
  scanf("%s", expense[num_entries].note);

  num_entries++;
  printf("Expense added successfully!\n");
}

// Function to display all expenses in the tracker
void display_expenses() {
  printf("Number of entries: %d\n", num_entries);
  printf("%-10s %-15s %s\n", "Amount", "Category", "Note");
  for (int i = 0; i < num_entries; i++) {
    printf("%-10.2lf %-15s %s\n", expense[i].amount, expense[i].category, expense[i].note);
  }
}

// Function to calculate the total amount spent in a given category
void calculate_category_total() {
  char category[MAX_CATEGORY_LEN+1];
  double total = 0.0;

  printf("Enter the category to calculate total for (maximum %d characters): ", MAX_CATEGORY_LEN);
  scanf("%s", category);

  for (int i = 0; i < num_entries; i++) {
    if (strcmp(expense[i].category, category) == 0) {
      total += expense[i].amount;
    }
  }

  printf("Total amount spent in %s category: %.2lf\n", category, total);
}

// Main function
int main() {
  int choice;

  while (1) {
    printf("Expense Tracker\n");
    printf("1. Add a new expense\n");
    printf("2. Display all expenses\n");
    printf("3. Calculate total amount spent in a category\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_new_expense();
        break;

      case 2:
        display_expenses();
        break;

      case 3:
        calculate_category_total();
        break;

      case 4:
        printf("Goodbye!\n");
        exit(0);

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }

  return 0;
}