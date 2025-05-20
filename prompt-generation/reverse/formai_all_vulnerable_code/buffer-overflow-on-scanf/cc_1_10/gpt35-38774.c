//FormAI DATASET v1.0 Category: Product Inventory System ; Style: complex
#include <stdio.h>
#include <string.h>
#define MAX_PRODUCTS 100

struct product{
   char name[50];
   int id;
   int price;
   int stock;
} products[MAX_PRODUCTS];

int numProducts = 0;

void addProduct(){
   struct product p;
   printf("Enter product name: ");
   scanf("%s", p.name);
   printf("Enter product id: ");
   scanf("%d", &p.id);
   printf("Enter product price: ");
   scanf("%d", &p.price);
   printf("Enter product stock: ");
   scanf("%d", &p.stock);
   products[numProducts++] = p;
   printf("Product added successfully!\n");
}

void listProducts(){
   printf("\nProduct List:\n");
   printf("Name\tID\tPrice\tStock\n");
   for(int i=0; i<numProducts; i++){
      printf("%s\t%d\t%d\t%d\n", products[i].name, 
                                     products[i].id, 
                                     products[i].price, 
                                     products[i].stock);
   }
   printf("\n");
}

void updateProduct(){
   int id, idx = -1;
   printf("Enter product id to update: ");
   scanf("%d", &id);
   for(int i=0; i<numProducts; i++){
      if(products[i].id == id){
         idx = i;
         break;
      }
   }
   if(idx == -1){
      printf("Product not found!\n");
      return;
   }
   int option;
   printf("What do you want to update?\n");
   printf("1. Name\n");
   printf("2. Price\n");
   printf("3. Stock\n");
   printf("Enter option: ");
   scanf("%d", &option);
   
   switch(option){
      case 1: 
         printf("Enter new name: ");
         scanf("%s", products[idx].name);
         break;
      case 2: 
         printf("Enter new price: ");
         scanf("%d", &products[idx].price);
         break;
      case 3: 
         printf("Enter new stock: ");
         scanf("%d", &products[idx].stock);
         break;
      default: 
         printf("Invalid option!\n");
         return;
   }
   printf("Product updated successfully!\n");
}

void deleteProduct(){
   int id, idx=-1;
   printf("Enter product id to delete: ");
   scanf("%d", &id);
   for(int i=0; i<numProducts; i++){
      if(products[i].id == id){
         idx = i;
         break;
      }
   }
   if(idx == -1){
      printf("Product not found!\n");
      return;
   }
   for(int i=idx; i<numProducts-1; i++){
      products[i] = products[i+1];
   }
   numProducts--;
   printf("Product deleted successfully!\n");
}

void checkStock(){
   int id, idx=-1;
   printf("Enter product id: ");
   scanf("%d", &id);
   for(int i=0; i<numProducts; i++){
      if(products[i].id == id){
         idx = i;
         break;
      }
   }
   if(idx == -1){
      printf("Product not found!\n");
      return;
   }
   printf("Current stock of %s: %d\n", products[idx].name, products[idx].stock);
}

int main(){

   printf("Product Inventory System\n");
   printf("=======================\n");

   while(1){

      int option;
      printf("\nSelect an option:\n");
      printf("1. Add Product\n");
      printf("2. List Products\n");
      printf("3. Update Product\n");
      printf("4. Delete Product\n");
      printf("5. Check Stock\n");
      printf("6. Exit\n");
      printf("Enter option: ");
      scanf("%d", &option);

      switch(option){
         case 1: addProduct(); break;
         case 2: listProducts(); break;
         case 3: updateProduct(); break;
         case 4: deleteProduct(); break;
         case 5: checkStock(); break;
         case 6: return 0;
         default: printf("Invalid option!\n");
      }

   }

   return 0;

}