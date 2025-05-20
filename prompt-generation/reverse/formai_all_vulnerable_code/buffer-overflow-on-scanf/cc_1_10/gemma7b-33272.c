//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
  printf("\nPlease select an option:");
  printf("\n1. View Transactions");
  printf("\n2. Add Transaction");
  printf("\n3. Edit Transaction");
  printf("\n4. Delete Transaction");
  printf("\n5. View Budget");
  printf("\n6. Exit");
  printf("\nEnter your choice:");
}

void process_choice(int choice) {
  switch (choice) {
    case 1:
      // Code to display transactions
      break;
    case 2:
      // Code to add a transaction
      break;
    case 3:
      // Code to edit a transaction
      break;
    case 4:
      // Code to delete a transaction
      break;
    case 5:
      // Code to view budget
      break;
    case 6:
      exit(0);
      break;
    default:
      printf("Invalid choice.\n");
  }
}

int main() {
  int choice;

  while (1) {
    display_menu();
    scanf("%d", &choice);
    process_choice(choice);
  }

  return 0;
}