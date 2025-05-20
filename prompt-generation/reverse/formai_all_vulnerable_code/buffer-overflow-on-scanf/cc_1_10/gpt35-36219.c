//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

struct warehouse {
   char name[20];
   int quantity;
   float cost;
};

int main() {
   struct warehouse items[10];
   int choice, i, j, count = 0;
   char delete_item[20];

   do {
      printf("\n---------------------------");
      printf("\n Warehouse Management System");
      printf("\n---------------------------");
      printf("\n1. Add an item to the Warehouse");
      printf("\n2. Display all items in the Warehouse");
      printf("\n3. Delete an item from the Warehouse");
      printf("\n4. Exit");

      printf("\nEnter your choice (1-4): ");
      scanf("%d", &choice);

      switch (choice) {
         case 1:
            printf("\nEnter the name of the item: ");
            scanf("%s", items[count].name);

            printf("Enter the quantity of the item: ");
            scanf("%d", &items[count].quantity);

            printf("Enter the cost of the item: ");
            scanf("%f", &items[count].cost);

            count++;
            break;

         case 2:
            printf("\n%-20s %-10s %-20s", "ITEM NAME", "QUANTITY", "COST");
            printf("\n--------------------------------------------------------");

            for (i = 0; i < count; i++) {
               printf("\n%-20s %-10d %-20.2f", items[i].name, items[i].quantity, items[i].cost);
            }
            break;

         case 3:
            printf("\nEnter the name of the item to delete: ");
            scanf("%s", delete_item);

            for (i = 0; i < count; i++) {
               if (strcmp(items[i].name, delete_item) == 0) {
                  for (j = i; j < count - 1; j++) {
                     strcpy(items[j].name, items[j + 1].name);
                     items[j].quantity = items[j + 1].quantity;
                     items[j].cost = items[j + 1].cost;
                  }
                  count--;
               }
            }
            break;

         case 4:
            printf("\nExiting Warehouse Management System...");
            exit(0);
            break;

         default:
            printf("\nInvalid choice! Please try again.");
            break;
      }
   } while (choice != 4);

   return 0;
}