//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    double price;
} Product;

Product inventory[MAX_ITEMS];

int num_items = 0;

void add_product() {
    char name[50];
    int quantity;
    double price;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%lf", &price);

    Product p = {
        .id = num_items + 1,
        .quantity = quantity,
        .price = price
    };
    strcpy(p.name, name);

    inventory[num_items] = p;
    num_items++;

    printf("Product added!\n");
}

void remove_product() {
    int id;

    printf("Enter product id: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found.\n");
    } else {
        for (int i = index; i < num_items - 1; i++) {
            inventory[i] = inventory[i+1];
        }

        num_items--;
        printf("Product removed!\n");
    }
}

void update_product() {
    int id;

    printf("Enter product id: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found.\n");
    } else {
        char name[50];
        int quantity;
        double price;

        printf("Enter updated product name: ");
        scanf("%s", name);

        printf("Enter updated product quantity: ");
        scanf("%d", &quantity);

        printf("Enter updated product price: ");
        scanf("%lf", &price);

        strcpy(inventory[index].name, name);
        inventory[index].quantity = quantity;
        inventory[index].price = price;

        printf("Product updated!\n");
    }
}

void list_products() {
    printf("ID  | Name       | Quantity | Price\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%-3d | %-10s | %-8d | $%.2lf\n", inventory[i].id, inventory[i].name,
                inventory[i].quantity, inventory[i].price);
    }
}

void menu() {
    printf("PRODUCT INVENTORY SYSTEM\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. List products\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                update_product();
                break;
            case 4:
                list_products();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option selected.\n");
                break;
        }
    }

    return 0;
}