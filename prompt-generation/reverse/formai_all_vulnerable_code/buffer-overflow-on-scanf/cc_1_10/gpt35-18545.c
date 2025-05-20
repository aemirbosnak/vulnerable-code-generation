//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item{
  char name[50];
  float price;
  int quantity;
};

int main(){
  struct Item inventory[100];
  int numItems = 0;
  
  printf("\nWelcome to our inventory system!\n");
  
  printf("\nHow many items are you adding to the inventory today? ");
  scanf("%d", &numItems);
  
  for(int i = 0; i < numItems; i++){
    printf("\nWhat is the name of item #%d? ", i+1);
    scanf("%s", inventory[i].name);
    
    printf("\nWhat is the price of item #%d? ", i+1);
    scanf("%f", &inventory[i].price);
    
    printf("\nWhat is the starting quantity of item #%d? ", i+1);
    scanf("%d", &inventory[i].quantity);
  }
  
  char choice;
  int itemIndex = -1;
  
  do{
    printf("\nEnter 'a' to add to inventory or 's' to subtract from inventory: ");
    scanf(" %c", &choice);
    
    printf("\nWhat is the name of the item? ");
    char tempName[50];
    scanf("%s", tempName);
    
    //find item in inventory
    for(int i = 0; i < numItems; i++){
      if(strcmp(inventory[i].name, tempName) == 0){
        itemIndex = i;
      }
    }
    
    if(itemIndex == -1){
      printf("\nItem not found in inventory!\n");
    }
    else if(choice == 'a'){
      printf("\nHow many are you adding to the inventory? ");
      int addQuantity;
      scanf("%d", &addQuantity);
      
      inventory[itemIndex].quantity += addQuantity;
      printf("\nNew quantity for %s: %d\n", inventory[itemIndex].name, inventory[itemIndex].quantity);
      itemIndex = -1; //reset itemIndex
    }
    else if(choice == 's'){
      printf("\nHow many are you subtracting from the inventory? ");
      int subQuantity;
      scanf("%d", &subQuantity);
      
      inventory[itemIndex].quantity -= subQuantity;
      
      if(inventory[itemIndex].quantity < 0){
        inventory[itemIndex].quantity = 0; //prevent negative quantity
      }
      
      printf("\nNew quantity for %s: %d\n", inventory[itemIndex].name, inventory[itemIndex].quantity);
      itemIndex = -1; //reset itemIndex
    }
    else{
      printf("\nInvalid choice, try again!\n");
    }
    
  }while(choice == 'a' || choice == 's');
  
  printf("\nThank you for using our inventory system!\n");
  return 0;
}