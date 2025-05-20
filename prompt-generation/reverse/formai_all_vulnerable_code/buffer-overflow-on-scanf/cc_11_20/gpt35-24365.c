//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Medicine {
   int id;
   char name[50];
   int quantity;
   float price;
};

int main()
{
   int choice, i, n=0;
   struct Medicine med[100];

   do {
      printf("Enter your choice:\n1. Add Medicine\n2. Remove Medicine\n3. Display Medicine List\n4. Modify Medicine\n5. Exit\n");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1: //Add new medicine
         printf("\nEnter id of Medicine: ");
         scanf("%d", &med[n].id);
         printf("Enter name of Medicine: ");
         scanf("%s", med[n].name);
         printf("Enter quantity of Medicine: ");
         scanf("%d", &med[n].quantity);
         printf("Enter price of Medicine: ");
         scanf("%f", &med[n].price);
         n++;
         printf("\nMedicine added successfully!\n");
         break;

      case 2: //Remove medicine
         if (n==0){
            printf("\nMedicine list is empty!\n");
            break;
         }
         int deleteId, deleteIndex=-1;
         printf("\nEnter id of Medicine to delete: ");
         scanf("%d", &deleteId);
         for (i=0;i<n;i++){
            if (med[i].id==deleteId){
               deleteIndex=i;
               break;
            }
         }
         if (deleteIndex==-1){
            printf("\nMedicine with given id does not exist!\n");
            break;
         }
         for (i=deleteIndex;i<n-1;i++){
            med[i] = med[i+1];
         }
         n--;
         printf("\nMedicine removed successfully!\n");
         break;

      case 3: //Display medicine list
         printf("\n%-15s %-20s %-20s %-20s\n", "Medicine Id", "Name", "Quantity", "Price");
         for (i=0;i<n;i++){
            printf("%-15d %-20s %-20d %-20.2f\n", med[i].id, med[i].name, med[i].quantity, med[i].price);
         }
         break;

      case 4: //Modify medicine
         if (n==0){
            printf("\nMedicine list is empty!\n");
            break;
         }
         int modifyId, modifyIndex=-1;
         printf("\nEnter id of Medicine to modify: ");
         scanf("%d", &modifyId);
         for (i=0;i<n;i++){
            if (med[i].id==modifyId){
               modifyIndex=i;
               break;
            }
         }
         if (modifyIndex==-1){
            printf("\nMedicine with given id does not exist!\n");
            break;
         }
         printf("Enter new name of Medicine: ");
         scanf("%s", med[modifyIndex].name);
         printf("Enter new quantity of Medicine: ");
         scanf("%d", &med[modifyIndex].quantity);
         printf("Enter new price of Medicine: ");
         scanf("%f", &med[modifyIndex].price);
         printf("\nMedicine modified successfully!\n");
         break;

      case 5: //Exit
         printf("\nThank you for using our system!\n");
         break;

      default:
         printf("\nInvalid choice! Please try again.\n");
         break;
      }

      printf("\n");

   } while (choice!=5);

   return 0;
}