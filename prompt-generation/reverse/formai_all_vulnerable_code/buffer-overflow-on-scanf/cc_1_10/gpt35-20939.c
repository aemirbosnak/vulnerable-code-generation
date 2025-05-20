//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
   char name[50];
   char company_name[50];
   int quantity;
   float price;
};

typedef struct medicine Medicine;

int count = 0;
Medicine medicines[100];

void add_medicine() {
   printf("Enter name of medicine: ");
   scanf("%s", medicines[count].name);

   printf("Enter name of company: ");
   scanf("%s", medicines[count].company_name);

   printf("Enter quantity of medicine: ");
   scanf("%d", &medicines[count].quantity);

   printf("Enter price of each medicine: ");
   scanf("%f", &medicines[count].price);

   count++;
}

void display_all() {
   if(count == 0) {
      printf("\nNo medicines are available in store\n");
      return;
   }

   printf("\n--------------------------------------MEDICINES LIST--------------------------------------");
   printf("\nName\t\tCompany Name\t\tQuantity\tPrice");
   
   for(int i=0; i<count; i++) {
      printf("\n%s\t\t%s\t\t%d\t\t%.2f", medicines[i].name, medicines[i].company_name, medicines[i].quantity, medicines[i].price);
   }
   printf("\n-------------------------------------------------------------------------------------------");
}

void search_medicine() {
   char name[50];
   printf("Enter name of medicine to search: ");
   scanf("%s", name);

   int is_found = 0;
   for(int i=0; i<count; i++) {
      if(strcmp(medicines[i].name, name) == 0) {
         printf("\nMedicine Found!\nName: %s\nCompany Name: %s\nQuantity: %d\nPrice: %.2f", medicines[i].name, medicines[i].company_name, medicines[i].quantity, medicines[i].price);
         is_found = 1;
         break;
      }
   }
   if(is_found == 0) {
      printf("\nMedicine not found in store\n");
   }
}

void update_price() {
   char name[50];
   printf("Enter name of medicine to update price: ");
   scanf("%s", name);

   int is_found = 0;
   for(int i=0; i<count; i++) {
      if(strcmp(medicines[i].name, name) == 0) {
         printf("\nEnter new price of medicine: ");
         scanf("%f", &medicines[i].price);
         printf("\nPrice updated successfully!\nName: %s\nCompany Name: %s\nQuantity: %d\nPrice: %.2f", medicines[i].name, medicines[i].company_name, medicines[i].quantity, medicines[i].price);
         is_found = 1;
         break;
      }
   }
   if(is_found == 0) {
      printf("\nMedicine not found in store\n");
   }
}

int main() {
   printf("***** Welcome to Happy Medical Store *****\n");

   int choice;
   while(1) {
      printf("\nMENU\n1. Add New Medicine\n2. Display All Medicines\n3. Search a Medicine\n4. Update Price of a Medicine\n5. Exit\nEnter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1: {
            add_medicine();
            break;
         }
         case 2: {
            display_all();
            break;
         }
         case 3: {
            search_medicine();
            break;
         }
         case 4: {
            update_price();
            break;
         }
         case 5: {
            printf("\nThank you for using Happy Medical Store!\n");
            exit(0);
         }
         default: {
            printf("\nInvalid Choice. Please enter a valid choice\n");
            break;
         }
      }
   }
   return 0;
}