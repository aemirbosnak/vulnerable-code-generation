//FormAI DATASET v1.0 Category: Product Inventory System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PRODUCTS 10

typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];

int products_added = 0;

void add_product(char name[], int quantity, float price) {
    if (products_added == MAX_PRODUCTS) {
        printf("I'm sorry, the inventory is full. No more products can be added.\n");
    } else {
        strcpy(inventory[products_added].name, name);
        inventory[products_added].quantity = quantity;
        inventory[products_added].price = price;
        products_added++;
        printf("Product added to inventory!\n");
    }
}

void sell_product(char name[]) {
    int index = -1;
    for (int i = 0; i < products_added; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("I'm sorry, we don't have that product in the inventory.\n");
    } else {
        if (inventory[index].quantity == 0) {
            printf("I'm sorry, we're out of stock for that product.\n");
        } else {
            inventory[index].quantity--;
            printf("Product sold successfully!\n");
        }
    }
}

void list_products() {
    printf("---------------\n");
    printf("|  Inventory  |\n");
    printf("---------------\n");
    printf("|  Name  | Quantity | Price |\n");
    for (int i = 0; i < products_added; i++) {
        printf("|  %s  |    %d     | %.2f  |\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("---------------\n");
}

int main() {
    printf("Welcome to the Product Inventory System!\n");
    int choice;
    char name[20];
    int quantity;
    float price;
    do {
        printf("Please select an option:\n");
        printf("1. Add a product to inventory\n");
        printf("2. Sell a product\n");
        printf("3. List all products in inventory\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("What is the name of the product you would like to add?\n");
                scanf("%s", name);
                printf("How many %s would you like to add?\n", name);
                scanf("%d", &quantity);
                printf("What is the price of %s?\n", name);
                scanf("%f", &price);
                add_product(name, quantity, price);
                break;
            case 2:
                printf("What is the name of the product you would like to sell?\n");
                scanf("%s", name);
                sell_product(name);
                break;
            case 3:
                list_products();
                break;
            case 4:
                printf("Thank you for using the Product Inventory System!\n");
                exit(0);
            default:
                printf("I'm sorry, please choose a valid option.\n");
                break;
        }
    } while (1);
    return 0;
}