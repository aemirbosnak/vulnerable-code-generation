//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
struct inventory {
   char item_name[20];
   int item_id;
   int quantity;
}item;

int main() {
   int n=3,i, choice, id, qty;
   char name[20];
   struct inventory list[n];

   //initialize default inventory
   for(i=0;i<n;i++) {
      sprintf(list[i].item_name, "Item %d", i+1);
      list[i].item_id = i+1;
      list[i].quantity = 10;
   }

   printf("*** Warehouse Inventory Management System ***\n\n");
   while(1) {
      printf("1. View inventory\n");
      printf("2. Add item\n");
      printf("3. Remove item\n");
      printf("4. Edit quantity\n");
      printf("5. Exit\n");
      printf("Please enter your choice: ");
      scanf("%d",&choice);

      switch(choice) {
         case 1: //view inventory
            printf("\nItem Name\tItem ID\t\tQuantity\n");
            for(i=0;i<n;i++) {
               printf("%s\t\t%d\t\t%d\n",list[i].item_name,list[i].item_id,list[i].quantity);
            }
            break;

         case 2: //add item
            printf("\nPlease enter item name: ");
            scanf("%s",&name);
            printf("Please enter item id: ");
            scanf("%d",&id);
            printf("Please enter item quantity: ");
            scanf("%d",&qty);
            item.item_id = id;
            item.quantity = qty;
            strcpy(item.item_name,name);
            list[n++] = item;
            printf("%s added to inventory.\n",name);
            break;

         case 3: //remove item
            printf("\nPlease enter item id to remove: ");
            scanf("%d",&id);
            for(i=0;i<n;i++) {
               if(list[i].item_id == id) {
                  printf("%s removed from inventory.\n",list[i].item_name);
                  list[i] = list[--n];
                  break;
               }
            }
            if(i==n) printf("Item not found in inventory.\n");
            break;

         case 4: //edit quantity
            printf("\nPlease enter item id to edit quantity: ");
            scanf("%d",&id);
            for(i=0;i<n;i++) {
               if(list[i].item_id == id) {
                  printf("\nPlease enter new quantity: ");
                  scanf("%d",&qty);
                  list[i].quantity = qty;
                  printf("Quantity updated for %s.\n",list[i].item_name);
                  break;
               }
            }
            if(i==n) printf("Item not found in inventory.\n");
            break;

         case 5: //exit program
            printf("\nGoodbye! Thank you for using our system.\n");
            exit(0);
            break;

         default:
            printf("\nInvalid choice. Please enter a valid choice.\n");
            break;
      }
   }
   return 0;
}