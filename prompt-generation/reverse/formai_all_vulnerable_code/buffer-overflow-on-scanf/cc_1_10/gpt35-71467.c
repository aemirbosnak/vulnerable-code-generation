//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int id;
    float price;
    int quantity;
};

void addProduct(struct product *inventory, int *numProducts) {
    if (*numProducts < 10) {
        printf("Enter the name of the product: ");
        scanf("%s", inventory[*numProducts].name);
        printf("Enter the product id: ");
        scanf("%d", &inventory[*numProducts].id);
        printf("Enter the price of the product: ");
        scanf("%f", &inventory[*numProducts].price);
        printf("Enter the quantity of the product: ");
        scanf("%d", &inventory[*numProducts].quantity);
        (*numProducts)++;
    } else {
        printf("Inventory is full!\n");
    }
}

void removeProduct(struct product *inventory, int *numProducts, int id) {
    int index = -1;
    for (int i = 0; i < *numProducts; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found!\n");
    } else {
        for (int i = index; i < *numProducts-1; i++) {
            strcpy(inventory[i].name, inventory[i+1].name);
            inventory[i].id = inventory[i+1].id;
            inventory[i].price = inventory[i+1].price;
            inventory[i].quantity = inventory[i+1].quantity;
        }
        (*numProducts)--;
    }
}

void printInventory(struct product *inventory, int numProducts) {
    if (numProducts == 0) {
        printf("Inventory is empty!\n");
    } else {
        printf("Name\tID\tPrice\tQuantity\n");
        printf("------------------------------------------\n");
        for (int i = 0; i < numProducts; i++) {
            printf("%s\t%d\t%.2f\t%d\n", inventory[i].name, inventory[i].id, inventory[i].price, inventory[i].quantity);
        }
    }
}

int main() {
    int numProducts = 0;
    struct product inventory[10];
    char option;

    printf("Welcome to Inventory Management System\n");
    while (1) {
        printf("Please select an option:\n");
        printf("a) Add Product\n");
        printf("b) Remove Product\n");
        printf("c) Print Inventory\n");
        printf("q) Quit\n");
        printf("Option: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                addProduct(inventory, &numProducts);
                break;
            case 'b':
                printf("Enter the product id: ");
                int id;
                scanf("%d", &id);
                removeProduct(inventory, &numProducts, id);
                break;
            case 'c':
                printInventory(inventory, numProducts);
                break;
            case 'q':
                printf("Exiting Inventory Management System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}