//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine{
   char name[50];
   char manufacturer[50];
   float price;
   int quantity;
};

typedef struct medicine med;

med *medicines = NULL;

void menu(){
   printf("\n=============================================\n");
   printf("\nWelcome to the Medical Store Management System\n");
   printf("\nPlease choose an option from the menu below\n");
   printf("\n1) Add new medicine");
   printf("\n2) Edit medicine details");
   printf("\n3) Delete medicine");
   printf("\n4) Search for medicine");
   printf("\n5) View all medicines");
   printf("\n6) Exit program");
   printf("\n=============================================\n");
}

int main(){
   int choice, i, n=0, flag=0;
   char search[50], ch='y';

   do{
      menu();
      printf("\nEnter your choice: ");
      scanf("%d", &choice);

      switch(choice){
         case 1:  //Add new medicine
               printf("\nEnter the number of medicines you want to add: ");
               scanf("%d", &n);
               medicines=(med*)realloc(medicines,n*sizeof(med));
               for(i=0; i<n; ++i){
                  printf("\nEnter details for medicine %d:", i+1);
                  fflush(stdin);
                  printf("\nName: ");
                  gets(medicines[i].name);
                  printf("Manufacturer: ");
                  gets(medicines[i].manufacturer);
                  printf("Price: ");
                  scanf("%f", &medicines[i].price);
                  printf("Quantity: ");
                  scanf("%d", &medicines[i].quantity);
               }
               break;

         case 2:  //Edit medicine details
               printf("\nEnter the name of the medicine whose details you want to edit: ");
               fflush(stdin);
               gets(search);
               for(i=0; i<n; ++i){
                  if(strcmp(search, medicines[i].name)==0){
                     printf("\nEnter new details:\n");
                     printf("Manufacturer: ");
                     gets(medicines[i].manufacturer);
                     printf("Price: ");
                     scanf("%f", &medicines[i].price);
                     printf("Quantity: ");
                     scanf("%d", &medicines[i].quantity);
                     flag=1;
                     break;
                  }
               }
               if(flag==0) printf("\nMedicine not found.\n");
               break;

         case 3:  //Delete medicine
               printf("\nEnter the name of the medicine to be deleted: ");
               fflush(stdin);
               gets(search);
               for(i=0; i<n; ++i){
                  if(strcmp(search, medicines[i].name)==0){
                     medicines[i]=medicines[n-1];
                     medicines=(med*)realloc(medicines, --n*sizeof(med));
                     printf("\nMedicine deleted successfully.\n");
                     flag=1;
                     break;
                  }
               }
               if(flag==0) printf("\nMedicine not found.\n");
               break;

         case 4:  //Search for medicine
               printf("\nEnter the name of the medicine: ");
               fflush(stdin);
               gets(search);
               for(i=0; i<n; ++i){
                  if(strcmp(search, medicines[i].name)==0){
                     printf("\nMedicine details:\n");
                     printf("\nName: %s\n", medicines[i].name);
                     printf("Manufacturer: %s\n", medicines[i].manufacturer);
                     printf("Price: %.2f\n", medicines[i].price);
                     printf("Quantity: %d\n", medicines[i].quantity);
                     flag=1;
                     break;
                  }
               }
               if(flag==0) printf("\nMedicine not found.\n");
               break;

         case 5:  //View all medicines
               printf("\nTotal number of medicines currently in stock: %d\n", n);
               for(i=0; i<n; ++i){
                  printf("\nMedicine %d:\n", i+1);
                  printf("\nName: %s\n", medicines[i].name);
                  printf("Manufacturer: %s\n", medicines[i].manufacturer);
                  printf("Price: %.2f\n", medicines[i].price);
                  printf("Quantity: %d\n", medicines[i].quantity);
               }
               break;

         case 6:  //Exit program
               printf("\nAre you sure you want to exit? (y/n): ");
               fflush(stdin);
               scanf("%c", &ch);
               if(ch=='y' || ch=='Y')
                  exit(0);
               else
                  break;
              
         default: printf("\nInvalid choice entered. Please try again.\n");
      }

   }while(1);

   return 0;
}