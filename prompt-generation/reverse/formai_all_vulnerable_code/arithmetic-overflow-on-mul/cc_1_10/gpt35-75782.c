//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
   char name[50];
   int price;
};

struct Order {
   struct MenuItem item;
   int quantity;
};

void printMenu(struct MenuItem menu[], int size){
   printf("\nMenu\n");
   printf("-----\n");
   for(int i=0; i<size; i++){
      printf("%s - $%d\n", menu[i].name, menu[i].price);
   }
}

void takeOrder(struct MenuItem menu[], int size, struct Order orders[], int *count){
   int choice;
   printf("\nEnter 0 to stop ordering\n");
   do{
      printf("Enter menu item # to order: ");
      scanf("%d", &choice);
      if(choice > 0 && choice <= size){
         printf("Enter quantity: ");
         scanf("%d", &orders[*count].quantity);
         orders[*count].item = menu[choice-1];
         (*count)++;
      }
   }while(choice != 0);
}

void printOrder(struct Order orders[], int size){
   printf("\nOrder Details\n");
   printf("--------------\n");
   printf("Item\t\tQuantity\tPrice\n");
   for(int i=0; i<size; i++){
      printf("%s\t\t%d\t\t$%d\n", orders[i].item.name, orders[i].quantity, orders[i].item.price * orders[i].quantity);
   }
}

int calculateTotal(struct Order orders[], int size){
   int total = 0;
   for(int i=0; i<size; i++){
      total += orders[i].item.price * orders[i].quantity;
   }
   return total;
}

void printReceipt(struct Order orders[], int size, int total){
   printf("\nReceipt\n");
   printf("--------\n");
   printf("Item\t\tQuantity\tPrice\n");
   for(int i=0; i<size; i++){
      printf("%s\t\t%d\t\t$%d\n", orders[i].item.name, orders[i].quantity, orders[i].item.price * orders[i].quantity);
   }
   printf("Total:\t\t\t\t$%d\n", total);
}

int main(){
   struct MenuItem menu[5] = { {"Latte", 3}, {"Cappuccino", 4}, {"Espresso", 2}, {"Mocha", 5}, {"Hot Chocolate", 3} };
   struct Order orders[10];
   int orderCount = 0;
   int total;

   printMenu(menu, 5);
   takeOrder(menu, 5, orders, &orderCount);
   printOrder(orders, orderCount);
   total = calculateTotal(orders, orderCount);
   printReceipt(orders, orderCount, total);

   return 0;
}