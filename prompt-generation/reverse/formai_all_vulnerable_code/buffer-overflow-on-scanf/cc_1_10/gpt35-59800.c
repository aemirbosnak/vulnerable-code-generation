//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definining structures
typedef struct product {
    char name[50];
    float price;
    int quantity;
} Product;

// function prototypes
void showMenu();
void addProduct(Product *inventory, int *numProducts);
void sellProduct(Product *inventory, int *numProducts);
void updateProduct(Product *inventory, int *numProducts);
void listInventory(Product *inventory, int *numProducts);

int main()
{
    // initializing the inventory and number of products
    Product inventory[50];
    int numProducts = 0;

    // displaying the menu
    showMenu();

    // getting user input and performing corresponding actions
    int choice = 0;
    while (choice != 5) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                sellProduct(inventory, &numProducts);
                break;
            case 3:
                updateProduct(inventory, &numProducts);
                break;
            case 4:
                listInventory(inventory, &numProducts);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// function implementation

void showMenu() {
    printf("***************************************************\n");
    printf("** WELCOME TO THE PRODUCT INVENTORY SYSTEM (PIS) **\n");
    printf("***************************************************\n");
    printf("[1] Add product\n");
    printf("[2] Sell product\n");
    printf("[3] Update product information\n");
    printf("[4] List inventory\n");
    printf("[5] Quit\n");
}

void addProduct(Product *inventory, int *numProducts) {
    printf("Enter product name: ");
    scanf("%s", inventory[*numProducts].name);
    printf("Enter product price: ");
    scanf("%f", &inventory[*numProducts].price);
    printf("Enter quantity of product: ");
    scanf("%d", &inventory[*numProducts].quantity);
    (*numProducts)++;
    printf("Product added successfully.\n");
}

void sellProduct(Product *inventory, int *numProducts) {
    printf("Enter product name: ");
    char name[50];
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Enter quantity to sell: ");
        int quantity;
        scanf("%d", &quantity);

        if (inventory[i].quantity >= quantity) {
            inventory[i].quantity -= quantity;
            printf("Sale successful. Total price: %.2f\n", quantity * inventory[i].price);
        } else {
            printf("Not enough quantity in inventory.\n");
        }
    } else {
        printf("Product not found.\n");
    }
}

void updateProduct(Product *inventory, int *numProducts) {
    printf("Enter product name: ");
    char name[50];
    scanf("%s", name);

    int i, found = 0;
    for (i = 0; i < *numProducts; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Enter new price: ");
        scanf("%f", &inventory[i].price);
        printf("Enter new quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Product information updated.\n");
    } else {
        printf("Product not found.\n");
    }
}

void listInventory(Product *inventory, int *numProducts) {
    printf("Product Name\tPrice\tQuantity\n");
    int i;
    for (i = 0; i < *numProducts; i++) {
        printf("%s\t%.2f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}