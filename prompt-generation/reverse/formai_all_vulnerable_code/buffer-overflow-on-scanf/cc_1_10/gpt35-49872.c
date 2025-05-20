//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Defining the struct for the product */
struct Product {
    char name[100];
    int quantity;
    float price;
};

/* Function to add a new product to the inventory */
void addProduct(struct Product inventory[], int *count) {
    struct Product newProduct;

    printf("\nEnter the name of the new product: ");
    scanf("%s", newProduct.name);

    printf("\nEnter the quantity of the new product: ");
    scanf("%d", &newProduct.quantity);

    printf("\nEnter the price of the new product: ");
    scanf("%f", &newProduct.price);

    inventory[*count] = newProduct;
    *count += 1;

    printf("\nSuccessfully added new product!\n\n");
}

/* Function to remove a product from the inventory */
void removeProduct(struct Product inventory[], int *count) {
    char name[100];

    printf("\nEnter the name of the product you wish to remove: ");
    scanf("%s", name);

    // Search for the product in the inventory
    int index = -1;
    for(int i=0; i<*count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("\nProduct not found!\n\n");
    } else {
        // Shift the elements to the left to remove the product
        for(int i=index; i<*count-1; i++) {
            inventory[i] = inventory[i+1];
        }

        *count -= 1;
        printf("\nSuccessfully removed product!\n\n");
    }
}

/* Function to display all the products in the inventory */
void displayInventory(struct Product inventory[], int count) {
    printf("\nInventory:\n");
    printf("----------------------------------------------\n");
    printf("Name\t\tQuantity\tPrice\n");
    printf("----------------------------------------------\n");

    for(int i=0; i<count; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("----------------------------------------------\n");
    printf("\n");
}

int main() {
    int count = 0;
    struct Product inventory[100];

    while(1) {
        printf("Welcome to the Surrealist Product Inventory System!\n\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                removeProduct(inventory, &count);
                break;
            case 3:
                displayInventory(inventory, count);
                break;
            case 4:
                printf("\nThank you for using the Surrealist Product Inventory System!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n\n");
        }
    }

    return 0;
}