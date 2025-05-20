//FormAI DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
  int day, month, year;
  char desc[100];
  double cost;
};

int main() {
  struct expense expenses[1000];
  int choice, count=0, index, del;
  double total=0;

  do {
    printf("\nEXPENSE TRACKER\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Edit Expense\n");
    printf("4. Delete Expense\n");
    printf("5. Total Expenses\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter expense date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &expenses[count].day, &expenses[count].month, &expenses[count].year);
        printf("Enter expense description: ");
        scanf(" %[^\n]s", expenses[count].desc);
        printf("Enter expense cost: ");
        scanf("%lf", &expenses[count].cost);
        total += expenses[count].cost;
        count++;
        printf("\nExpense added successfully!\n");
        break;

      case 2:
        if(count == 0) {
          printf("\nNo expenses found!\n");
        }
        else {
          printf("\nEXPENSE LIST\n");
          printf("-------------------------------------------------------------\n");
          printf("Date\t\tDescription\t\t\tCost\n");
          printf("-------------------------------------------------------------\n");
          for(int i=0; i<count; i++) {
            printf("%d/%d/%d\t%-35s\t%.2lf\n", expenses[i].day, expenses[i].month, expenses[i].year, expenses[i].desc, expenses[i].cost);
          }
          printf("-------------------------------------------------------------\n");
        }
        break;
        
      case 3:
        printf("\nEnter the index of the expense to edit: ");
        scanf("%d", &index);
        if(index >= count || index < 0) {
          printf("\nInvalid index!\n");
        }
        else {
          printf("Editing expense %d\n", index);
          printf("Enter expense date (dd/mm/yyyy): ");
          scanf("%d/%d/%d", &expenses[index].day, &expenses[index].month, &expenses[index].year);
          printf("Enter expense description: ");
          scanf(" %[^\n]s", expenses[index].desc);
          printf("Enter expense cost: ");
          scanf("%lf", &expenses[index].cost);
          total += expenses[index].cost;
          printf("\nExpense edited successfully!\n");
        }
        break;

      case 4:
        printf("\nEnter the index of the expense to delete: ");
        scanf("%d", &del);
        if(del >= count || del < 0) {
          printf("\nInvalid index!\n");
        }
        else {
          total -= expenses[del].cost;
          for(int i=del; i<count-1; i++) {
            expenses[i] = expenses[i+1];
          }
          count--;
          printf("\nExpense deleted successfully!\n");
        }
        break;

      case 5:
        printf("Total Expenses: %.2f\n", total);
        break;

      case 6:
        printf("\nExiting...\n");
        break;

      default:
        printf("\nInvalid choice!\n");
        break;
    }
  } while(choice != 6);

  return 0;
}