//FormAI DATASET v1.0 Category: Product Inventory System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

// struct to represent a product
struct product {
    char name[50];
    int quantity;
    float price;
};

// function prototypes
void addProduct(struct product [], int *);
void removeProduct(struct product [], int *);
void displayInventory(struct product [], int);

int main() {
    int choice, count = 0;
    struct product inventory[MAX_SIZE];

    do {
        // display menu
        printf("--- PRODUCT INVENTORY SYSTEM ---\n\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n\n");
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
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    } while(choice != 4);

    return 0;
}

// function to add a product to the inventory
void addProduct(struct product inventory[], int *count) {
    char name[50];
    int quantity;
    float price;

    // get product details from user
    printf("\nEnter the name of the product: ");
    scanf("%s", name);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    printf("Enter the price per unit: ");
    scanf("%f", &price);

    // add product to inventory
    strcpy(inventory[*count].name, name);
    inventory[*count].quantity = quantity;
    inventory[*count].price = price;

    *count += 1;

    printf("Product added to inventory successfully.\n");
}

// function to remove a product from the inventory
void removeProduct(struct product inventory[], int *count) {
    int index, i;
    char name[50];

    // get name of product to remove
    printf("\nEnter the name of the product to remove: ");
    scanf("%s", name);

    // find index of product in inventory
    for(i=0; i<*count; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    // shift products to the left to fill gap left by removed product
    for(i=index; i<*count-1; i++) {
        inventory[i] = inventory[i+1];
    }

    *count -= 1;

    printf("Product removed from inventory successfully.\n");
}

// function to display inventory
void displayInventory(struct product inventory[], int count) {
    int i;

    printf("\n--- INVENTORY ---\n");
    for(i=0; i<count; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}