//FormAI DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
  int expense_id;
  char category[20];
  float amount;
  char date[20];
};

int main() {
  int n, i, choice;
  float total = 0;
  printf("Enter the number of expenses: ");
  scanf("%d", &n);
  struct expense *expenses = (struct expense*) calloc(n, sizeof(struct expense));
  for(i=0; i<n; i++) {
    printf("\nEnter expense details for expense %d:\n", i+1);
    printf("Enter expense id: ");
    scanf("%d", &expenses[i].expense_id);
    printf("Enter expense category: ");
    scanf("%s", expenses[i].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[i].amount);
    printf("Enter expense date: ");
    scanf("%s", expenses[i].date);
    total += expenses[i].amount;
  }

  while(1) {
    printf("\nSelect an option:\n");
    printf("1) Display expenses\n");
    printf("2) Add new expense\n");
    printf("3) Delete expense\n");
    printf("4) Calculate total expense\n");
    printf("5) Exit\n");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nExpense details:\n\n");
        for(i=0; i<n; i++) {
          printf("Expense %d\n", i+1);
          printf("Expense id: %d\n", expenses[i].expense_id);
          printf("Category: %s\n", expenses[i].category);
          printf("Amount: %.2f\n", expenses[i].amount);
          printf("Date: %s\n\n", expenses[i].date);
        }
        break;
      case 2:
        n++;
        expenses = (struct expense*) realloc(expenses, n * sizeof(struct expense));
        printf("\nEnter expense details for expense %d:\n", n);
        printf("Enter expense id: ");
        scanf("%d", &expenses[n-1].expense_id);
        printf("Enter expense category: ");
        scanf("%s", expenses[n-1].category);
        printf("Enter expense amount: ");
        scanf("%f", &expenses[n-1].amount);
        printf("Enter expense date: ");
        scanf("%s", expenses[n-1].date);
        total += expenses[n-1].amount;
        break;
      case 3:
        if(n == 0) {
          printf("\nNo expenses to delete!\n");
        }
        else {
          int id_to_delete, delete_index = -1;
          printf("\nEnter the id of the expense to delete: ");
          scanf("%d", &id_to_delete);
          for(i=0; i<n; i++) {
            if(expenses[i].expense_id == id_to_delete) {
              total -= expenses[i].amount;
              delete_index = i;
              break;
            }
          }
          if(delete_index == -1) {
            printf("\nExpense with id %d not found!\n", id_to_delete);
          }
          else {
            for(i=delete_index; i<n-1; i++) {
              expenses[i] = expenses[i+1];
            }
            n--;
            expenses = (struct expense*) realloc(expenses, n * sizeof(struct expense));
            printf("\nExpense with id %d deleted!\n", id_to_delete);
          }
        }
        break;
      case 4:
        printf("\nTotal expense: %.2f\n", total);
        break;
      case 5:
        free(expenses);
        return 0;
      default:
        printf("\nInvalid choice, please try again.\n");
        break;
    }
  }
}