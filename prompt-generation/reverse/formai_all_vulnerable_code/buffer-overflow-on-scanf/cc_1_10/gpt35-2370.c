//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: lively
#include<stdio.h>
#include<string.h>

struct Warehouse {
  char product_name[50];
  int quantity;
  float price;
};

void addProduct(struct Warehouse *w, int size) {
  printf("\nEnter the product name: ");
  scanf("%s", (w+size)->product_name);
  printf("\nEnter the quantity: ");
  scanf("%d",&(w+size)->quantity);
  printf("\nEnter the price: ");
  scanf("%f",&(w+size)->price);
  printf("\nProduct added successfully! \n");
}

void displayWarehouse(struct Warehouse *w, int size) {
  printf("\nCurrent Warehouse Inventory:\n");
  printf("Product Name\t\tQuantity\tPrice\n");
  for(int i=0;i<size;i++) {
    printf("%s\t\t%d\t\t%.2f\n", (w+i)->product_name, (w+i)->quantity, (w+i)->price);
  }
}

void deleteProduct(struct Warehouse *w, int size) {
  char pname[50];
  int found=0;
  printf("\nEnter product name to be deleted: ");
  scanf("%s", pname);

  for(int i=0;i<size;i++) {
    if(strcmp((w+i)->product_name, pname)==0) {
      found=1;
      for(int j=i;j<size-1;j++) {
        strcpy((w+j)->product_name, (w+j+1)->product_name);
        (w+j)->quantity = (w+j+1)->quantity;
        (w+j)->price = (w+j+1)->price;
      }
      size--;
      printf("Product \"%s\" deleted successfully\n", pname);
      break;
    }
  }

  if(found==0) {
    printf("Product \"%s\" not found\n", pname);
  }
}

float calculateInventoryValue(struct Warehouse *w, int size) {
  float value=0;
  for(int i=0;i<size;i++) {
    value += (w+i)->price * (w+i)->quantity;
  }
  return value;
}

int main() {
  struct Warehouse w[100];
  int choice, size=0;
  float inventoryValue;

  do {
    printf("\nWarehouse Management System Menu:");
    printf("\n<1> Add Product");
    printf("\n<2> Delete Product");
    printf("\n<3> Display Warehouse Inventory");
    printf("\n<4> Calculate Total Inventory Value");
    printf("\n<5> Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice) {
      case 1: addProduct(w, size);
              size++;
              break;
      case 2: deleteProduct(w, size);
              size--;
              break;
      case 3: displayWarehouse(w, size);
              break;
      case 4: inventoryValue = calculateInventoryValue(w, size);
              printf("\nTotal Inventory Value: $%.2f\n", inventoryValue);
              break;
      case 5: printf("Thank You for using Warehouse Management System!");
              break;
      default: printf("\nInvalid Choice!");
    }
  } while(choice!=5);

  return 0;
}