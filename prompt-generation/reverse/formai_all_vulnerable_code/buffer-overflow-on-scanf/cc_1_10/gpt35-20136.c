//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product {
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product* inventory, int* count);
void displayInventory(Product* inventory, int count);
void sellProduct(Product* inventory, int* count);

int main() {
    Product inventory[100];
    int count = 0;
    int choice;

    printf("Welcome to the post-apocalyptic Product Inventory System!\n");
    printf("----------------------------------------------------------\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add a new product\n");
        printf("2. Display inventory\n");
        printf("3. Sell a product\n");
        printf("4. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addProduct(&inventory[count], &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                sellProduct(inventory, &count);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid entry. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

void addProduct(Product* inventory, int* count) {
    printf("\nEnter product name: ");
    scanf("%s", inventory->name);

    printf("Enter product quantity: ");
    scanf("%d", &inventory->quantity);

    printf("Enter product price: ");
    scanf("%f", &inventory->price);

    (*count)++;
}

void displayInventory(Product* inventory, int count) {
    if(count == 0) {
        printf("\nInventory is empty.\n");
    }
    else {
        printf("\nProduct\tQuantity\tPrice\n");
        printf("--------------------------------------\n");

        for(int i = 0; i < count; i++) {
            printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void sellProduct(Product* inventory, int* count) {
    char name[50];

    printf("\nEnter name of product to sell: ");
    scanf("%s", name);

    for(int i = 0; i < *count; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            if(inventory[i].quantity > 0) {
                inventory[i].quantity--;
                printf("Sold %s for %.2f.\n", inventory[i].name, inventory[i].price);
                return;
            }
            else {
                printf("%s is out of stock.\n", inventory[i].name);
                return;
            }
        }
    }

    printf("%s not found in inventory.\n", name);
}