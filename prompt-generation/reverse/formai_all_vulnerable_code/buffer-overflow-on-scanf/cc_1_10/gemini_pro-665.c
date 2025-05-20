//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 10

struct Transaction {
  char description[100];
  double amount;
  char category[50];
};

struct Category {
  char name[50];
  double total;
};

int main() {
  // Declare variables
  int num_transactions = 0;
  struct Transaction transactions[MAX_TRANSACTIONS];
  int num_categories = 0;
  struct Category categories[MAX_CATEGORIES];

  // Get user input
  printf("Enter the number of transactions: ");
  scanf("%d", &num_transactions);

  for (int i = 0; i < num_transactions; i++) {
    printf("Enter transaction %d description: ", i + 1);
    scanf("%s", transactions[i].description);

    printf("Enter transaction %d amount: ", i + 1);
    scanf("%lf", &transactions[i].amount);

    printf("Enter transaction %d category: ", i + 1);
    scanf("%s", transactions[i].category);
  }
printf("************************************\n");
  // Calculate total for each category
  for (int i = 0; i < num_transactions; i++) {
  for (int j = 0; j < num_categories; j++) { 
if (strcmp(transactions[i].category, categories[j].name) == 0) {
      categories[j].total += transactions[i].amount;
}
  }
  
}

  // Print report
  printf("Personal Finance Planner\n");
  printf("-------------------------\n");
  printf("Transactions:\n");
  for (int i = 0; i < num_transactions; i++) {
    printf("  %s %lf %s\n", transactions[i].description, transactions[i].amount, transactions[i].category);
  }

  printf("\nCategories:\n");
  for (int i = 0; i < num_categories; i++) {
    printf("  %s %lf\n", categories[i].name, categories[i].total);
  }

  return 0;
}