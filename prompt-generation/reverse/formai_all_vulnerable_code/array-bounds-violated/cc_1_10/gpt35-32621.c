//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PRODUCTS 1000

typedef struct {
   char name[30];
   float price;
   int quantity;
} Product;

Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct(char* name, float price, int quantity);
void editProduct(char* name);
void deleteProduct(char* name);
void viewProduct(char* name);
void viewAllProducts();

int main() {
   char input[100];
   char* command;
   char* parameters[10];
   char* token;
   int numParameters;

   printf("Welcome to Product Inventory System\n");

   while(1) {
      printf("> ");
      fgets(input, 100, stdin);
      input[strlen(input)-1] = '\0'; // Remove newline character at end of input

      token = strtok(input, " ");
      command = token;

      numParameters = 0;
      while(token!=NULL) {
         parameters[numParameters++] = token;
         token = strtok(NULL, " ");
      }

      if(strcmp(command, "add")==0) {
         float price;
         int quantity;
         if(numParameters!=4) {
            printf("Invalid command. Usage: add <name> <price> <quantity>\n");
            continue;
         }
         sscanf(parameters[2], "%f", &price);
         sscanf(parameters[3], "%d", &quantity);
         addProduct(parameters[1], price, quantity);
         printf("Product added.\n");
      }
      else if(strcmp(command, "edit")==0) {
         if(numParameters!=2) {
            printf("Invalid command. Usage: edit <name>\n");
            continue;
         }
         editProduct(parameters[1]);
      }
      else if(strcmp(command, "delete")==0) {
         if(numParameters!=2) {
            printf("Invalid command. Usage: delete <name>\n");
            continue;
         }
         deleteProduct(parameters[1]);
         printf("Product deleted.\n");
      }
      else if(strcmp(command, "view")==0) {
         if(numParameters==1) {
            viewAllProducts();
         }
         else {
            viewProduct(parameters[1]);
         }
      }
      else if(strcmp(command, "exit")==0) {
         printf("Terminating program\n");
         break;
      }
      else {
         printf("Invalid command. Try again.\n");
      }
   }

   return 0;
}

void addProduct(char* name, float price, int quantity) {
   if(numProducts==MAX_PRODUCTS) {
      printf("Error: Maximum number of products reached.\n");
      return;
   }
   for(int i=0; i<numProducts; i++) {
      if(strcmp(products[i].name, name)==0) {
         printf("Error: A product with the same name already exists.\n");
         return;
      }
   }
   Product newProduct;
   strcpy(newProduct.name, name);
   newProduct.price = price;
   newProduct.quantity = quantity;
   products[numProducts++] = newProduct;
}

void editProduct(char* name) {
   for(int i=0; i<numProducts; i++) {
      if(strcmp(products[i].name, name)==0) {
         float price;
         int quantity;
         printf("Enter new price: ");
         scanf("%f", &price);
         printf("Enter new quantity: ");
         scanf("%d", &quantity);
         getchar(); // Remove newline character after scanf
         products[i].price = price;
         products[i].quantity = quantity;
         printf("Product edited.\n");
         return;
      }
   }
   printf("Error: Product not found.\n");
}

void deleteProduct(char* name) {
   for(int i=0; i<numProducts; i++) {
      if(strcmp(products[i].name, name)==0) {
         for(int j=i+1; j<numProducts; j++) {
            products[j-1] = products[j];
         }
         numProducts--;
         return;
      }
   }
   printf("Error: Product not found.\n");
}

void viewProduct(char* name) {
   for(int i=0; i<numProducts; i++) {
      if(strcmp(products[i].name, name)==0) {
         printf("Name: %s\n", products[i].name);
         printf("Price: %.2f\n", products[i].price);
         printf("Quantity: %d\n", products[i].quantity);
         return;
      }
   }
   printf("Error: Product not found.\n");
}

void viewAllProducts() {
   printf("\n");
   printf("Products in inventory:\n");
   for(int i=0; i<numProducts; i++) {
      printf("%d. %s - %.2f (%d)\n", i+1, products[i].name, products[i].price, products[i].quantity);
   }
   printf("\n");
}