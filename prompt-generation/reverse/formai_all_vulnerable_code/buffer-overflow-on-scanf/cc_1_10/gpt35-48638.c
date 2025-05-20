//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct Order
{
   char name[20], item[20];
   int qty;
   float price;
};

struct Order orderList[MAX];
int numOrders=0; 

void addOrder()
{
   struct Order o;
   printf("\nEnter Customer Name: ");
   scanf("%s", &o.name);
   printf("\nEnter Item Name: ");
   scanf("%s", &o.item);
   printf("\nEnter Item Quantity: ");
   scanf("%d", &o.qty);
   printf("\nEnter Item Price: ");
   scanf("%f", &o.price);
   orderList[numOrders++] = o;
   printf("\nOrder Added Successfully!!\n\n");
}

void searchOrder()
{
   int i, found = 0;
   char name[20];
   printf("\nEnter Customer Name to Search: ");
   scanf("%s", name);

   for(i=0; i<numOrders; i++)
   {
      if(strcmp(orderList[i].name, name) == 0)
      {
         printf("\nOrder Details:\n");
         printf("Customer Name: %s\n", orderList[i].name);
         printf("Item Name: %s\n", orderList[i].item);
         printf("Item Quantity: %d\n", orderList[i].qty);
         printf("Item Price: %f\n\n", orderList[i].price);
         found = 1;
      }
   }
   if(found == 0)
   {
      printf("\nOrder Not Found!!\n\n");
   }
}

void displayOrders()
{
   int i;
   printf("\nOrder Details:\n");
   for(i=0; i<numOrders; i++)
   {
      printf("Customer Name: %s\n", orderList[i].name);
      printf("Item Name: %s\n", orderList[i].item);
      printf("Item Quantity: %d\n", orderList[i].qty);
      printf("Item Price: %f\n\n", orderList[i].price);
   }
}

void calculateTotal()
{
   int i;
   float total = 0;
   for(i=0; i<numOrders; i++)
   {
      total += (orderList[i].qty * orderList[i].price);
   }
   printf("\nTotal Bill: %f\n\n", total);
}

int main()
{
   int choice;
   printf("***************C Cafe Billing System***************\n\n");
   printf("1. Add Order\n2. Search Order\n3. Display Orders\n4. Calculate Total Bill\n5. Exit\n");

   do
   {
      printf("\nEnter choice: ");
      scanf("%d", &choice);

      switch(choice)
      {
         case 1:
            addOrder();
            break;
         case 2:
             searchOrder();
             break;
         case 3:
             displayOrders();
             break;
         case 4:
             calculateTotal();
             break;
         case 5:
             exit(0);
         default:
             printf("\nInvalid Choice!! Please Enter Again!!\n\n");
      }

   }while(choice!=5);

   return 0;
}