//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_items;
  printf("How many items do you want to manage? ");
  scanf("%d", &num_items);
  
  char item_names[num_items][30];
  int item_counts[num_items];
  float item_prices[num_items];
  
  for(int i = 0; i < num_items; i++) {
    printf("Enter item name: ");
    scanf("%s", item_names[i]);
    
    printf("Enter item count: ");
    scanf("%d", &item_counts[i]);
    
    printf("Enter item price: ");
    scanf("%f", &item_prices[i]);
  }
  
  printf("\n");
  printf("Welcome to the Medical Store!\n");
  
  while(1) {
    int choice;
    printf("\n");
    printf("* * * * * * * * * * * * * * * * *\n");
    printf("1. View all items\n");
    printf("2. Add an item\n");
    printf("3. Remove an item\n");
    printf("4. Exit\n");
    printf("* * * * * * * * * * * * * * * * *\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
      printf("\n");
      printf("Here are all the items:\n");
      for(int i = 0; i < num_items; i++) {
        printf("%s (Count: %d, Price: %.2f)\n", item_names[i], item_counts[i], item_prices[i]);
      }
    }
    
    else if(choice == 2) {
      printf("\n");
      printf("Enter item name: ");
      scanf("%s", item_names[num_items]);
      
      printf("Enter item count: ");
      scanf("%d", &item_counts[num_items]);
      
      printf("Enter item price: ");
      scanf("%f", &item_prices[num_items]);
      
      num_items++;
      
      printf("%s added to the store!\n", item_names[num_items-1]);
    }
    
    else if(choice == 3) {
      printf("\n");
      printf("Enter the index of the item to remove (starting from 0): ");
      int index;
      scanf("%d", &index);
      
      printf("%s removed from the store!\n", item_names[index]);
      
      for(int i = index; i < num_items - 1; i++) {
        strcpy(item_names[i], item_names[i+1]);
        item_counts[i] = item_counts[i+1];
        item_prices[i] = item_prices[i+1];
      }
      
      num_items--;
    }
    
    else if(choice == 4) {
      printf("\n");
      printf("Thank you for using the Medical Store Management System!\n");
      break;
    }
    
    else {
      printf("\n");
      printf("Invalid choice, please try again.\n");
    }
  }
  
  return 0;
}