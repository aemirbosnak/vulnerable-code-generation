//FormAI DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Sorry, the inventory is full.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    printf("Enter price: ");
    scanf("%f", &inventory[num_products].price);

    printf("Product added successfully.\n");

    num_products++;
}

void display_products() {
    if (num_products == 0) {
        printf("The inventory is empty.\n");
        return;
    }

    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_product() {
    char name[20];
    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Product Name\tQuantity\tPrice\n");
            printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }

    printf("Product not found.\n");
}

void sell_product() {
    char name[20];
    printf("Enter product name: ");
    scanf("%s", name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);

            if (quantity > inventory[i].quantity) {
                printf("Sorry, there are only %d %s in stock.\n", inventory[i].quantity, inventory[i].name);
                return;
            }

            inventory[i].quantity -= quantity;
            printf("Total cost: %.2f\n", inventory[i].price * quantity);
            printf("Product sold successfully.\n");

            return;
        }
    }

    printf("Product not found.\n");
}

int main() {
    while (1) {
        printf("\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Search product\n");
        printf("4. Sell product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                search_product();
                break;
            case 4:
                sell_product();
                break;
            case 5:
                printf("Thank you for using the product inventory system!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}