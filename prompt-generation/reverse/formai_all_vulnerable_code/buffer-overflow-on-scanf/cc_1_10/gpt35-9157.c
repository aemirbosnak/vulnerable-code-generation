//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

struct Product{
    char name[20];
    int code;
    int quantity;
    float price;
};

void addProduct(struct Product *inventory, int *numItems);
void displayInventory(struct Product *inventory, int numItems);
float calculateStockValue(struct Product *inventory, int numItems);

int main(){
    struct Product inventory[MAX_ITEMS];
    int numItems = 0;
    int choice = 0;
    float totalValue = 0.0;

    do{
        printf("\n PRODUCT INVENTORY MENU \n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Calculate Stock Value\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct(inventory, &numItems);
                break;
            case 2:
                displayInventory(inventory, numItems);
                break;
            case 3:
                totalValue = calculateStockValue(inventory, numItems);
                printf("Total Stock Value: $%.2f\n", totalValue);
                break;
            case 4:
                printf("Exiting Program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 4);

    return 0;
}

void addProduct(struct Product *inventory, int *numItems){
    if(*numItems >= MAX_ITEMS){
        printf("Inventory Full\n");
        return;
    }

    printf("Enter Product Name: ");
    scanf("%s", inventory[*numItems].name);

    printf("Enter Product Code: ");
    scanf("%d", &inventory[*numItems].code);

    printf("Enter Product Quantity: ");
    scanf("%d", &inventory[*numItems].quantity);

    printf("Enter Product Price: ");
    scanf("%f", &inventory[*numItems].price);

    (*numItems)++;
}

void displayInventory(struct Product *inventory, int numItems){
    if(numItems == 0){
        printf("Inventory Empty\n");
        return;
    }

    printf("\nPRODUCT INVENTORY\n");
    printf("Name\tCode\tQuantity\tPrice\n");

    for(int i = 0; i < numItems; i++){
        printf("%s\t%d\t%d\t$%.2f\n", inventory[i].name, inventory[i].code, inventory[i].quantity, inventory[i].price);
    }
}

float calculateStockValue(struct Product *inventory, int numItems){
    if(numItems == 0){
        printf("Inventory Empty\n");
        return 0.0;
    }

    float totalValue = 0.0;

    for(int i = 0; i < numItems; i++){
        totalValue += (inventory[i].price * inventory[i].quantity);
    }

    return totalValue;
}