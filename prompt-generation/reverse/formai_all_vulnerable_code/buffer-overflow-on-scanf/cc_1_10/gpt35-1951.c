//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct{
    char name[20];
    int quantity;
    float price;
} Product;

Product inventory[MAX]; //array of products
int productsCount = 0; //no. of products in inventory

void displayMenu(){
    printf("Welcome to Product Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Inventory\n");
    printf("4. Exit\n");
}

void addProduct(){
    char name[20];
    int quantity;
    float price;

    printf("\nEnter product name: ");
    scanf("%s", &name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price: ");
    scanf("%f", &price);

    strcpy(inventory[productsCount].name, name);
    inventory[productsCount].quantity = quantity;
    inventory[productsCount].price = price;

    productsCount++;
    printf("\nProduct added!\n");
}

void removeProduct(){
    char name[20];
    int found = 0;
    
    printf("\nEnter product name to remove: ");
    scanf("%s", name);
    
    for(int i=0;i<productsCount;i++){
        if(strcmp(name, inventory[i].name) == 0){
            found = 1;
            for(int j=i;j<productsCount-1;j++){
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].quantity = inventory[j+1].quantity;
                inventory[j].price = inventory[j+1].price;
            }
            productsCount--;
            printf("\nProduct removed!\n");
            break;
        }
    }

    if(!found){
        printf("\nProduct not found!\n");
    }
}

void displayInventory(){
    printf("\nProduct Inventory\n");
    printf("%-15s | %-10s | %-10s\n", "Name", "Quantity", "Price");
    printf("-----------------------------------------------------\n");
    for(int i=0;i<productsCount;i++){
        printf("%-15s | %-10d | %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main(){
    int choice;

    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct();
                break;
            case 2:
                removeProduct();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                printf("\nThank you for using Product Inventory System!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }while(1);

    return 0;
}