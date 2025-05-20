//FormAI DATASET v1.0 Category: Product Inventory System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Product
struct product {
    char name[30];
    int code;
    float price;
    int quantity;
};

void addProduct(struct product *inventory, int* numProducts) {
    printf("\nEnter the product name: ");
    scanf("%s", (inventory+*numProducts)->name);
    printf("Enter the product code: ");
    scanf("%d", &(inventory+*numProducts)->code);
    printf("Enter the product price: ");
    scanf("%f", &(inventory+*numProducts)->price);
    printf("Enter the product quantity: ");
    scanf("%d", &(inventory+*numProducts)->quantity);
    *numProducts += 1;
}

void searchProduct(struct product *inventory, int numProducts) {
    int code;
    printf("\nEnter the product code to search: ");
    scanf("%d", &code);
    for (int i=0; i<numProducts; i++) {
        if ((inventory+i)->code == code) {
            printf("\nProduct Name: %s", (inventory+i)->name);
            printf("\nProduct Code: %d", (inventory+i)->code);
            printf("\nProduct Price: %.2f", (inventory+i)->price);
            printf("\nProduct Quantity: %d\n", (inventory+i)->quantity);
            return;
        }
    }
    printf("\nProduct not found!\n");
}

void displayInventory(struct product *inventory, int numProducts) {
    if (numProducts == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\nInventory:\n");
    for (int i=0; i<numProducts; i++) {
        printf("\nProduct Name: %s", (inventory+i)->name);
        printf("\nProduct Code: %d", (inventory+i)->code);
        printf("\nProduct Price: %.2f", (inventory+i)->price);
        printf("\nProduct Quantity: %d\n", (inventory+i)->quantity);
    }
}

void checkout(struct product *inventory, int numProducts) {
    if (numProducts == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    float total = 0;
    printf("\n\nCart:\n");
    for (int i=0; i<numProducts; i++) {
        printf("\nProduct Name: %s", (inventory+i)->name);
        printf("\nProduct Quantity: %d", (inventory+i)->quantity);
        printf("\nProduct Price: %.2f", (inventory+i)->price);
        printf("\nProduct Total: %.2f\n", (inventory+i)->price * (inventory+i)->quantity);
        total += (inventory+i)->price * (inventory+i)->quantity;
    }
    printf("\nTotal: %.2f\n", total);
}

int main() {
    struct product *inventory;
    inventory = (struct product*) malloc(1 * sizeof(struct product)); // allocate memory for 1 product
    int numProducts = 0;
    int choice;
    do {
        printf("\n\n===== Product Inventory System =====\n");
        printf("1. Add Product\n");
        printf("2. Search Product\n");
        printf("3. Display Inventory\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(inventory, &numProducts);
                inventory = (struct product*) realloc(inventory, (numProducts+1) * sizeof(struct product)); // increase memory size for new product
                break;
            case 2:
                searchProduct(inventory, numProducts);
                break;
            case 3:
                displayInventory(inventory, numProducts);
                break;
            case 4:
                checkout(inventory, numProducts);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice, please try again!\n");
        }
    } while(choice != 5);
    free(inventory); // free memory allocated for product inventory
    return 0;
}