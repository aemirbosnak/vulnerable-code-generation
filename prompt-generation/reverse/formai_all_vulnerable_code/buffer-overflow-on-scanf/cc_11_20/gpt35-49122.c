//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine{
   int med_id;
   char med_name[20];
   float price;
   int quantity;
};

int main(){
   int choice,i,med_id,quantity,count=0,cnt=0;
   float price;
   char med_name[20];
   struct medicine med,item[100];

   while(1){
      printf("\n--------- Medical Store Management System ----------\n");
      printf("\n1.Add Medicine\n2.Sell Medicine\n3.Display Stock\n4.Exit\nEnter your choice: ");
      scanf("%d",&choice);

      switch(choice){
         case 1:
            printf("\nEnter the medicine details-\n");
            printf("Medicine ID: ");
            scanf("%d",&med.med_id);
            printf("Medicine Name: ");
            scanf("%s",med.med_name);
            printf("Price: ");
            scanf("%f",&med.price);
            printf("Quantity: ");
            scanf("%d",&med.quantity);
            item[count]=med;
            count++;
            break;

         case 2:
            printf("\nEnter the medicine details-\n");
            printf("Medicine ID: ");
            scanf("%d",&med_id);
            for(i=0;i<count;i++){
               if(item[i].med_id == med_id){
                  cnt++;
                  printf("Medicine Name: %s\n",item[i].med_name);
                  printf("Price: %f\n",item[i].price);
                  printf("Enter the quantity to sell: ");
                  scanf("%d",&quantity);
                  if(quantity > item[i].quantity){
                     printf("Not enough stock available!\n");
                     break;
                  }
                  printf("Total Amount: %f\n",(item[i].price * quantity));
                  item[i].quantity -= quantity;
                  break;
               }
            }
            if(cnt==0){
               printf("Medicine not found!\n");
            }
            break;
         
         case 3:
            printf("\nExisting Stock-\n");
            for(i=0;i<count;i++){
               printf("Medicine ID: %d\n",item[i].med_id);
               printf("Medicine Name: %s\n",item[i].med_name);
               printf("Price: %f\n",item[i].price);
               printf("Quantity: %d\n",item[i].quantity);
               printf("-----------------------------\n");
            }
            break;

         case 4:
            exit(0);
            break;

         default:
            printf("Invalid Choice!\n");
      }
   }

   return 0;
}