//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include<stdio.h>
#include<stdlib.h>

struct item {
   int id;
   char name[20];
   int quantity;
};

int main() {
   int choice, i, n = 0, id, pos, flag = 0;
   char confirm;
   struct item* items = (struct item*)malloc(sizeof(struct item));
   printf("Welcome to the Warehouse Management System!\n");

   do {
      printf("\n\nWhat would you like to do?\n");
      printf("1. Add an item\n2. Remove an item\n3. View all items\n4. Exit\n");
      printf("Please enter your choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         printf("\nEnter the details of the item you wish to add\n");
         printf("ID: ");
         scanf("%d", &items[n].id);
         printf("Name: ");
         scanf("%s", items[n].name);
         printf("Quantity: ");
         scanf("%d", &items[n].quantity);
         printf("\nItem added successfully!\n");
         n++;
         items = (struct item*)realloc(items, sizeof(struct item) * (n + 1));
         break;

      case 2:
         printf("\nEnter the ID of the item you wish to remove: ");
         scanf("%d", &id);

         for (i = 0; i < n; i++) {
            if (items[i].id == id) {
               flag = 1;
               pos = i;
               break;
            }
         }
         if (flag == 0) {
            printf("Item not found!\n");
         }
         else {
            printf("\nAre you sure you want to remove the following item?\n");
            printf("ID: %d\nName: %s\nQuantity: %d\n", items[pos].id, items[pos].name, items[pos].quantity);
            printf("Please enter Y or N: ");
            scanf(" %c", &confirm);
            if (confirm == 'Y' || confirm == 'y') {
               for (i = pos; i < n - 1; i++) {
                  items[i] = items[i + 1];
               }
               n--;
               printf("\nItem removed successfully!\n");
               items = (struct item*)realloc(items, sizeof(struct item) * (n + 1));
            }
            else {
               printf("\nRemove cancelled.\n");
            }
         }
         break;

      case 3:
         printf("\n%-10s %-20s %s\n", "ID", "Name", "Quantity");
         for (i = 0; i < n; i++) {
            printf("%-10d %-20s %-d\n", items[i].id, items[i].name, items[i].quantity);
         }
         break;

      case 4:
         printf("\nThank you for using the Warehouse Management System!\n");
         free(items);
         exit(0);
         break;

      default:
         printf("\nInvalid choice! Please try again.\n");
         break;
      }
   } while (choice != 4);
   return 0;
}