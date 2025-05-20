//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct product{
    char name[50];
    int price;
    int quantity;
}Product;

void addProduct(Product**, int*);
void removeProduct(Product**, int*);
void displayInventory(Product*, int);
int searchProduct(char*, Product*, int);
void updateQuantity(Product**, int*);

int main(){
    int choice;
    int numProducts = 0;

    Product* inventory = (Product*) malloc(sizeof(Product));

    do{
        printf("Cyberpunk Product Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Update Quantity\n");
        printf("5. Quit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addProduct(&inventory, &numProducts);
                break;
            case 2:
                removeProduct(&inventory, &numProducts);
                break;
            case 3:
                displayInventory(inventory, numProducts);
                break;
            case 4:
                updateQuantity(&inventory, &numProducts);
                break;
            case 5:
                printf("Thank you for using Cyberpunk Product Inventory System\n");
                free(inventory);
                return 0;
            default:
                printf("Invalid Choice try again\n");
                break;
        }

    }while(1);

    return 0;
}

void addProduct(Product** inventory, int* numProducts){
    Product newProduct;

    printf("Enter Product Name: ");
    scanf("%s", newProduct.name);

    printf("Enter Product Price: ");
    scanf("%d", &newProduct.price);

    printf("Enter Product Quantity: ");
    scanf("%d", &newProduct.quantity);

    *inventory = (Product*) realloc(*inventory, ((*numProducts) + 1) * sizeof(Product));
    (*numProducts)++;
    (*inventory)[*numProducts - 1] = newProduct;

    printf("Product added to inventory!\n");
}

void removeProduct(Product** inventory, int* numProducts){
    char productName[50];
    int searchIndex, removeIndex;

    printf("Enter Product Name to remove: ");
    scanf("%s", productName);

    searchIndex = searchProduct(productName, *inventory, *numProducts);

    if(searchIndex == -1){
        printf("Product not found in inventory!\n");
        return;
    }

    removeIndex = searchIndex;

    memcpy(&((*inventory)[removeIndex]), &((*inventory)[removeIndex + 1]), (*numProducts - removeIndex - 1) * sizeof(Product));
    *numProducts = *numProducts - 1;

    printf("Product removed from inventory!\n");
}

void displayInventory(Product* inventory, int numProducts){
    int i;

    printf("%-20s%-10s%-10s\n", "Product Name", "Price", "Quantity");
    printf("---------------------------------------------------\n");

    for(i = 0; i < numProducts; i++){
        printf("%-20s%-10d%-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

int searchProduct(char* productName, Product* inventory, int numProducts){
    int i;

    for(i = 0; i < numProducts; i++){
        if(strcmp(productName, inventory[i].name) == 0){
            return i;
        }
    }

    return -1;
}

void updateQuantity(Product** inventory, int* numProducts){
    char productName[50];
    int searchIndex, newQuantity;

    printf("Enter Product Name to update quantity: ");
    scanf("%s", productName);

    searchIndex = searchProduct(productName, *inventory, *numProducts);

    if(searchIndex == -1){
        printf("Product not found in inventory!\n");
        return;
    }

    printf("Enter new Quantity: ");
    scanf("%d", &newQuantity);

    (*inventory)[searchIndex].quantity = newQuantity;

    printf("Product Quantity updated successfully!\n");
}