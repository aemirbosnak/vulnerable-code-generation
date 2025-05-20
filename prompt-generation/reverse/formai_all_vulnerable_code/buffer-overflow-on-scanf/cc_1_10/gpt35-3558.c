//FormAI DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include<stdio.h>
#include<string.h>
#define MAX_ITEMS 10

/* Struct to represent a product */
typedef struct{
    char name[20];
    float price;
    int quantity;
}Product;

/* Function to display the inventory */
void displayInventory(Product inventory[], int numProducts){
    printf("--------------------------------------------------\n");
    printf("                      Inventory                   \n");
    printf("--------------------------------------------------\n");
    printf("Name            Price           Quantity         \n");

    /* Display each product */
    int i;
    for(i = 0; i < numProducts; i++){
        printf("%-15s  %-15.2f  %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

/* Function to add a product to the inventory */
int addProduct(Product inventory[], int numProducts){
    /* Check if inventory is full */
    if(numProducts == MAX_ITEMS){
        printf("Inventory full!\n");
        return numProducts;
    }

    /* Get product details */
    printf("Enter product name: ");
    char name[20];
    scanf("%s", name);

    printf("Enter product price: ");
    float price;
    scanf("%f", &price);

    printf("Enter product quantity: ");
    int quantity;
    scanf("%d", &quantity);

    /* Add product to inventory */
    Product newProduct = { 
      .price = price,
      .quantity = quantity,
    };
    strcpy(newProduct.name, name);
    
    inventory[numProducts] = newProduct;
    
    /* Return new number of products */
    return numProducts + 1;
}

/* Function to remove a product from the inventory */
int removeProduct(Product inventory[], int numProducts){
    /* Get product name */
    printf("Enter name of product to remove: ");
    char name[20];
    scanf("%s", name);

    /* Search for product */
    int i;
    for(i = 0; i < numProducts; i++){
        if(strcmp(inventory[i].name, name) == 0){
            /* Remove product */
            int j;
            for(j = i; j < numProducts-1; j++){
                inventory[j] = inventory[j+1];
            }
            
            /* Return new number of products */
            return numProducts - 1;
        }
    }

    /* Product not found */
    printf("Product not found in inventory.\n");

    /* Return old number of products */
    return numProducts;
}

/* Function to update a product */
void updateProduct(Product inventory[], int numProducts){
    /* Get product name */
    printf("Enter name of product to update: ");
    char name[20];
    scanf("%s", name);

    /* Search for product */
    int i;
    for(i = 0; i < numProducts; i++){
        if(strcmp(inventory[i].name, name) == 0){
            /* Get new product details */
            printf("Enter new product name: ");
            scanf("%s", inventory[i].name);

            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);

            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);

            /* Product updated */
            printf("Product updated successfully.\n");

            return;
        }
    }

    /* Product not found */
    printf("Product not found in inventory.\n");
}

/* The main function */
int main(){
    /* Create inventory */
    Product inventory[MAX_ITEMS];

    /* Initialize inventory */
    int numProducts = 0;

    /* Display menu */
    int choice;
    do{
        printf("\n");
        printf("--------------------------------------------------\n");
        printf("                 Product Inventory                \n");
        printf("--------------------------------------------------\n");
        printf("1. Display inventory\n");
        printf("2. Add product\n");
        printf("3. Remove product\n");
        printf("4. Update product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* Perform selected action */
        switch(choice){
            case 1:
                displayInventory(inventory, numProducts);
                break;
            
            case 2:
                numProducts = addProduct(inventory, numProducts);
                break;
            
            case 3:
                numProducts = removeProduct(inventory, numProducts);
                break;
            
            case 4:
                updateProduct(inventory, numProducts);
                break;
            
            case 5:
                printf("Goodbye!\n");
                break;
            
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice != 5);

    return 0;
}