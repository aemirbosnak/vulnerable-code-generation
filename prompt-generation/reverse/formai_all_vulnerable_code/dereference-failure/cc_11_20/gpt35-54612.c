//FormAI DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int id;
   char name[20];
   float price;
} Product;

int main() {
   FILE *fp;
   Product product;

   int choice;
   printf("\n1. Add new product.\n2. Delete a product.\n3. Search a product.\n4. List all products.\n5. Exit.\n");

   while(1) {
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            printf("Enter product ID: ");
            scanf("%d", &product.id);
            printf("Enter product name: ");
            scanf("%s", product.name);
            printf("Enter product price: ");
            scanf("%f", &product.price);

            fp = fopen("products.dat", "ab");
            if(fp == NULL) {
               printf("Error opening file.\n");
               exit(1);
            }

            fwrite(&product, sizeof(product), 1, fp);
            printf("Product added successfully.\n");
            fclose(fp);
            break;

         case 2:
            printf("Enter product ID to delete: ");
            int id;
            scanf("%d", &id);

            fp = fopen("products.dat", "rb");
            if(fp == NULL) {
               printf("Error opening file.\n");
               exit(1);
            }
            FILE *temp = fopen("temp.dat", "wb");
            if(temp == NULL) {
               printf("Error opening file.\n");
               exit(1);
            }

            while(fread(&product, sizeof(product), 1, fp)) {
               if(product.id != id) {
                  fwrite(&product, sizeof(product), 1, temp);
               }
            }
            fclose(fp);
            fclose(temp);
            remove("products.dat");
            rename("temp.dat", "products.dat");

            printf("Product deleted successfully.\n");
            break;

         case 3:
            printf("Enter product ID to search: ");
            int search_id;
            scanf("%d", &search_id);

            fp = fopen("products.dat", "rb");
            if(fp == NULL) {
               printf("Error opening file.\n");
               exit(1);
            }

            while(fread(&product, sizeof(product), 1, fp)) {
               if(product.id == search_id) {
                  printf("Product ID: %d\nProduct Name: %s\nProduct Price: $%.2f\n", product.id, product.name, product.price);
                  break;
               }
            }
            if(feof(fp) && product.id != search_id) {
               printf("Product not found.\n");
            }
            fclose(fp);
            break;

         case 4:
            fp = fopen("products.dat", "rb");
            if(fp == NULL) {
               printf("Error opening file.\n");
               exit(1);
            }

            printf("Product ID\tProduct Name\tProduct Price\n");
            while(fread(&product, sizeof(product), 1, fp)) {
               printf("%d\t\t%s\t\t$%.2f\n", product.id, product.name, product.price);
            }
            fclose(fp);
            break;

         case 5:
            printf("Exiting program.");
            exit(0);

         default:
            printf("Invalid choice.\n");
      }
   }
   return 0;
}