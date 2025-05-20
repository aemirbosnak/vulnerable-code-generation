//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

void add_product(Product inventory[]);
void display_inventory(Product inventory[]);
void search_product(Product inventory[]);

int main() {
    Product my_inventory[MAX_PRODUCTS];
    int choice;

    printf("\nWelcome to the Surprising Inventory System!\n");
    printf("------------------------------------------\n");

    while (1) {
        printf("\n1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search Product\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(my_inventory);
                break;
            case 2:
                display_inventory(my_inventory);
                break;
            case 3:
                search_product(my_inventory);
                break;
            case 4:
                printf("Exiting the Inventory System...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void add_product(Product inventory[]) {
    int index = -1;
    char name[MAX_NAME_LENGTH];
    int quantity;

    printf("\nEnter the product name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].quantity == 0) {
            index = i;
            strcpy(inventory[i].name, name);
            printf("Enter the product quantity: ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            printf("Product added successfully!\n");
            break;
        }
    }

    if (index == -1) {
        printf("Sorry, inventory is full!\n");
    }
}

void display_inventory(Product inventory[]) {
    printf("\nProduct Name\tQuantity\n");

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (inventory[i].quantity > 0) {
            printf("%s\t\t%d\n", inventory[i].name, inventory[i].quantity);
        }
    }
}

void search_product(Product inventory[]) {
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("\nEnter the product name to search: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(inventory[i].name, name) == 0 && inventory[i].quantity > 0) {
            printf("%s\t\t%d\n", inventory[i].name, inventory[i].quantity);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Product not found!\n");
    }
}