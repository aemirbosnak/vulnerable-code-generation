//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct product{
  char name[20];
  int quantity;
  float price;
};

void addProduct(struct product **inv, int *length){
  (*length)++;
  *inv = realloc(*inv, (*length)*sizeof(struct product));
  printf("Enter product name (max 19 characters): ");
  scanf("%s", (*inv)[(*length)-1].name);
  printf("Enter quantity: ");
  scanf("%d", &((*inv)[(*length)-1].quantity));
  printf("Enter price: ");
  scanf("%f", &((*inv)[(*length)-1].price));
  printf("\nProduct added successfully!\n");
}

void removeProduct(struct product **inv, int *length){
  char pname[20];
  printf("Enter the name of product to remove: ");
  scanf("%s", pname);
  int index = -1;
  for(int i=0; i<*length; i++){
    if(strcmp(pname, (*inv)[i].name) == 0){
      index = i;
    }
  }
  if(index == -1){
    printf("\nProduct not found!\n");
    return;
  }
  for(int i=index; i<(*length)-1; i++){
    (*inv)[i] = (*inv)[i+1];
  }
  (*length)--;
  *inv = realloc(*inv, (*length)*sizeof(struct product));
  printf("\nProduct removed successfully!\n");
}

void displayInventory(struct product *inv, int length){
  printf("Product\t\tQuantity\tPrice\n");
  for(int i=0; i<length; i++){
    printf("%s\t\t%d\t\t%.2f\n", inv[i].name, inv[i].quantity, inv[i].price);
  }
}

void saveInventoryToFile(struct product *inv, int length, FILE *fp){
  fprintf(fp, "Product,Quantity,Price\n");
  for(int i=0; i<length; i++){
    fprintf(fp, "%s,%d,%.2f\n", inv[i].name, inv[i].quantity, inv[i].price);
  }
  printf("\nInventory saved to file successfully!\n");
}

void readInventoryFromFile(struct product **inv, int *length, FILE *fp){
  char buffer[30];
  fgets(buffer, 30, fp); // ignore first row
  while(fgets(buffer, 30, fp) != NULL){
    (*length)++;
    *inv = realloc(*inv, (*length)*sizeof(struct product));
    char *token = strtok(buffer, ",");
    strcpy((*inv)[(*length)-1].name, token);
    token = strtok(NULL, ",");
    (*inv)[(*length)-1].quantity = atoi(token);
    token = strtok(NULL, ",");
    (*inv)[(*length)-1].price = atof(token);
  }
  printf("\nInventory loaded from file successfully!\n");
}

int main(){
  int choice = 0, length = 0;
  struct product *inventory = NULL;
  FILE *fp;
  while(1){
    printf("\n1. Add Product\n2. Remove Product\n3. Display Inventory\n4. Save Inventory to File\n5. Load Inventory from File\n6. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
      case 1: addProduct(&inventory, &length); break;
      case 2: removeProduct(&inventory, &length); break;
      case 3: displayInventory(inventory, length); break;
      case 4:
        fp = fopen("inventory.csv", "w");
        saveInventoryToFile(inventory, length, fp);
        fclose(fp); break;
      case 5:
        fp = fopen("inventory.csv", "r");
        if(fp == NULL){printf("\nInventory file not found!\n"); break;}
        readInventoryFromFile(&inventory, &length, fp);
        fclose(fp); break;
      case 6: return 0;
      default: printf("\nInvalid choice!\n"); break;
    }
  }
  return 0;
}