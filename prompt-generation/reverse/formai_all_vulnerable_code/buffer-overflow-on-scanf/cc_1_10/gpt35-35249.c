//FormAI DATASET v1.0 Category: Product Inventory System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct product{
  int id;
  char name[30];
  int quantity;
  double price;
};

typedef struct product Product;

void addProduct(Product products[], int *index){
  Product newProduct;
  printf("\nEnter Product ID: ");
  scanf("%d", &newProduct.id);
  printf("Enter Product Name: ");
  scanf("%s", newProduct.name);
  printf("Enter Product Quantity: ");
  scanf("%d", &newProduct.quantity);
  printf("Enter Product Price: ");
  scanf("%lf", &newProduct.price);

  products[*index] = newProduct;
  (*index)++;
  printf("\nProduct Added Successfully!\n");
}

void searchProduct(Product products[], int index){
  int searchID, i, found=0;
  printf("\nEnter Product ID to Search: ");
  scanf("%d", &searchID);

  for(i=0;i<index;i++){
    if(products[i].id == searchID){
      found = 1;
      printf("\nProduct Found!\n\nID: %d\nNAME: %s\nQUANTITY: %d\nPRICE: $%.2lf", products[i].id, products[i].name, products[i].quantity, products[i].price);
      break;
    }
  }

  if(!found){
    printf("\nProduct Not Found!\n");
  }
}

void updateProduct(Product products[], int index){
  int searchID, i, found=0;
  printf("\nEnter Product ID to Update: ");
  scanf("%d", &searchID);

  for(i=0;i<index;i++){
    if(products[i].id == searchID){
      found = 1;
      printf("\nProduct Found!\n\nID: %d\nNAME: %s\nQUANTITY: %d\nPRICE: $%.2lf", products[i].id, products[i].name, products[i].quantity, products[i].price);
      printf("\n\nEnter New Product Name: ");
      scanf("%s", products[i].name);
      printf("\nEnter New Product Quantity: ");
      scanf("%d", &products[i].quantity);
      printf("Enter New Product Price: ");
      scanf("%lf", &products[i].price);
      printf("\nProduct Updated Successfully!\n");
      break;
    }
  }

  if(!found){
    printf("\nProduct Not Found!\n");
  }
}

void deleteProduct(Product products[], int *index){
  int searchID, i, found=0;
  printf("\nEnter Product ID to Delete: ");
  scanf("%d", &searchID);

  for(i=0;i<*index;i++){
    if(products[i].id == searchID){
      found = 1;
      printf("\nProduct Found!\n\nID: %d\nNAME: %s\nQUANTITY: %d\nPRICE: $%.2lf", products[i].id, products[i].name, products[i].quantity, products[i].price);
      (*index)--;
      while(i<*index){
        products[i] = products[i+1];
        i++;
      }
      printf("\nProduct Deleted Successfully!\n");
      break;
    }
  }

  if(!found){
    printf("\nProduct Not Found!\n");
  }
}

void displayProducts(Product products[], int index){
  int i;
  printf("\nPRODUCTS AVAILABLE\n");
  printf("\nID\tNAME\tQUANTITY\tPRICE\n");
  for(i=0;i<index;i++){
    printf("%d\t%s\t%d\t\t$%.2lf\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
  }
}

void menu(){
  printf("\n\nC PRODUCT INVENTORY SYSTEM");
  printf("\n1. Add Product\n2. Search Product\n3. Update Product\n4. Delete Product\n5. Display Products\n6. Exit");
  printf("\n\nEnter your Choice: ");
}

int main(){
  Product products[100];
  int choice, index=0;

  do{
    menu();
    scanf("%d", &choice);

    switch(choice){
      case 1:
        addProduct(products, &index);
        break;
      case 2:
        searchProduct(products, index);
        break;
      case 3:
        updateProduct(products, index);
        break;
      case 4:
        deleteProduct(products, &index);
        break;
      case 5:
        displayProducts(products, index);
        break;
      case 6:
        printf("\nExiting Program!\n");
        break;
      default:
        printf("\nInvalid Choice!\n");
        break;
    }
  }while(choice != 6);

  return 0;
}