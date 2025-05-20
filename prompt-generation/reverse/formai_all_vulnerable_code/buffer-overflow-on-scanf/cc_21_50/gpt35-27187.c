//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

struct Product {
   char name[50];
   int id;
   int quantity;
   float price;
}p[100];

int main() {
   int i, j, n, k, id, opt;
   char ch;

   printf("Enter the number of products: ");
   scanf("%d",&n);

   // Inputting Product Details
   for(i=0; i<n; i++) {
      printf("\nEnter the name of product %d: ", i+1);
      scanf("%s",p[i].name);
      printf("Enter the id of product %d: ", i+1);
      scanf("%d",&p[i].id);
      printf("Enter the quantity of product %d: ", i+1);
      scanf("%d",&p[i].quantity);
      printf("Enter the price of product %d: ", i+1);
      scanf("%f",&p[i].price);  
   }

   // Displaying Menu Prompt
   do {
      printf("\n\n******* Product Inventory System *******");
      printf("\n1. Search a product by ID");
      printf("\n2. Add a new product");
      printf("\n3. Delete a product");
      printf("\n4. Update a product quantity");
      printf("\n5. Display product list");
      printf("\n6. Exit");
      printf("\n\nEnter your choice: ");
      scanf("%d",&opt);

      switch(opt) {

         // Searching a product by ID
         case 1:
            printf("\nEnter the id of product to search: ");
            scanf("%d",&id);
            for(i=0; i<n; i++) {
               if(p[i].id == id) {
                  printf("\nProduct found!\n");
                  printf("\nName: %s", p[i].name);
                  printf("\nID: %d", p[i].id);
                  printf("\nQuantity: %d", p[i].quantity);
                  printf("\nPrice: $%.2f", p[i].price);
                  break;
               }
            }
            if(i==n)
               printf("\nProduct not found!");
            break;

         // Adding a new product
         case 2:
            printf("\nEnter the details of new product: ");
            printf("\nEnter the name of product: ");
            scanf("%s",p[n].name);
            printf("Enter the id of product: ");
            scanf("%d",&p[n].id);
            printf("Enter the quantity of product: ");
            scanf("%d",&p[n].quantity);
            printf("Enter the price of product: ");
            scanf("%f",&p[n].price);
            n++;
            printf("\nNew product added successfully!");
            break;

         // Deleting a product
         case 3:
            printf("\nEnter the id of product to delete: ");
            scanf("%d",&id);
            for(i=0; i<n; i++) {
               if(p[i].id == id) {
                  for(j=i; j<n-1; j++)
                     p[j] = p[j+1];
                  n--;
                  printf("\nProduct deleted successfully!");
                  break;
               }
            }
            if(i==n)
               printf("\nProduct not found!");
            break;

         // Updating a product quantity
         case 4:
            printf("\nEnter the id of product to update: ");
            scanf("%d",&id);
            for(i=0; i<n; i++) {
               if(p[i].id == id) {
                  printf("\nCurrent Quantity: %d", p[i].quantity);
                  printf("\nEnter the new Quantity: ");
                  scanf("%d",&p[i].quantity);
                  printf("\nQuantity updated successfully!");
                  break;
               }
            }
            if(i==n)
               printf("\nProduct not found!");
            break;

         // Displaying product list
         case 5:
            printf("\n\n******* Product List *******\n");
            printf("%-15s %-5s %-10s %-5s\n", "Product Name", "ID", "Quantity", "Price");
            printf("--------------------------------------------------------------\n");
            for(i=0; i<n; i++) {
               printf("%-15s %-5d %-10d $%.2f\n", p[i].name, p[i].id, p[i].quantity, p[i].price);
            }
            break;

         // Exiting the program
         case 6:
            exit(0);
            break;

         default:
            printf("\nWrong Choice!");
      }

      printf("\n\nDo you want to continue (Y/N)? ");
      getchar();
      ch = getchar();
   } while(ch == 'Y'|| ch == 'y');

   return 0;
}