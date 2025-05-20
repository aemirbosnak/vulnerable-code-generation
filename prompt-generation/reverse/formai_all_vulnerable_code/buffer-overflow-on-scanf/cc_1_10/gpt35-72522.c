//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: romantic
#include <stdio.h>

int main() {
  int total_amount = 0;
  int num_items = 0;
  int item_choice;
  int item_cost;
  char menu[] = "1. Coffee\t2. Croissant\t3. Cake\t4. Sandwich\n";
  
  printf("Welcome to the C Cafe Billing System!\n");
  printf("What would you like to order?\n");
  printf("%s", menu);
  
  do {
    printf("Enter your choice (1-4): ");
    scanf("%d", &item_choice);
    
    switch (item_choice) {
      case 1:
        item_cost = 3;
        break;
      case 2:
        item_cost = 2;
        break;
      case 3:
        item_cost = 4;
        break;
      case 4:
        item_cost = 5;
        break;
      default:
        printf("Invalid choice, please try again.\n");
        continue;
    }
    
    total_amount += item_cost;
    num_items++;
    
  } while (item_choice >= 1 && item_choice <= 4);
  
  printf("\nThank you for your order!\n");
  printf("You have ordered %d items, with a total cost of $%d.\n", num_items, total_amount);
  
  if (num_items > 0) {
    printf("May your love for each other be as sweet as the cakes and coffee you've ordered.\n");
  } else {
    printf("May your love for each other grow stronger with every moment you spend together.\n");
  }

  return 0;
}