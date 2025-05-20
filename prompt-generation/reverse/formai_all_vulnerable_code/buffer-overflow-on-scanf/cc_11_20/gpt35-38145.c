//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <string.h>

struct product {
   char name[50];
   int code;
   float price;
};

int main()
{
   int choice, i=0, count=0, code, found=0, j;
   float price;
   char name[50];
   struct product p[100];

   printf("*** Welcome to Product Inventory System ***\n\n");

   while(1) {
      printf("1. Add a product\n");
      printf("2. Search for a product\n");
      printf("3. Delete a product\n");
      printf("4. Display all products\n");
      printf("5. Exit\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice)
      {
         case 1:
            printf("Enter product name: ");
            scanf("%s", p[i].name);
            printf("Enter product code: ");
            scanf("%d", &p[i].code);
            printf("Enter product price: ");
            scanf("%f", &p[i].price);
            count++;
            i++;
            break;
         case 2:
            printf("Enter product code: ");
            scanf("%d", &code);
            for(j=0;j<count;j++)
            {
               if(p[j].code==code)
               {
                  printf("Product name: %s\n", p[j].name);
                  printf("Product code: %d\n", p[j].code);
                  printf("Product price: %.2f\n", p[j].price);
                  found=1;
                  break;
               }
            }
            if(found==0)
            {
               printf("Product not found!\n");
            }
            found=0;
            break;
         case 3:
            printf("Enter product code: ");
            scanf("%d", &code);
            for(j=0;j<count;j++)
            {
               if(p[j].code==code)
               {
                  strcpy(p[j].name, "");
                  p[j].code=0;
                  p[j].price=0.0;
                  printf("Product deleted successfully!\n");
                  found=1;
                  count--;
                  break;
               }
            }
            if(found==0)
            {
               printf("Product not found!\n");
            }
            found=0;
            break;
         case 4:
            printf("\nName\t\tCode\t\tPrice\n");
            for(j=0;j<count;j++)
            {
               printf("%s\t\t%d\t\t%.2f\n", p[j].name, p[j].code, p[j].price);
            }
            break;
         case 5:
            printf("Thank you for using Product Inventory System!");
            return 0;
         default:
            printf("Invalid choice. Please try again.\n");
      }
   }
}