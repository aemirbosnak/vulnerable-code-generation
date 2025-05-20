//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product(char *name, int quantity, float price) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Error: Inventory is full.\n");
        return;
    }
    strcpy(inventory[num_products].name, name);
    inventory[num_products].quantity = quantity;
    inventory[num_products].price = price;
    num_products++;
    printf("%s added to inventory.\n", name);
}

void remove_product(char *name) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            break;
        }
    }
    if (i == num_products) {
        printf("Error: Product not found.\n");
        return;
    }
    for (; i < num_products - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    num_products--;
    printf("%s removed from inventory.\n", name);
}

void update_product(char *name, int quantity, float price) {
    int i;
    for (i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            break;
        }
    }
    if (i == num_products) {
        printf("Error: Product not found.\n");
        return;
    }
    inventory[i].quantity = quantity;
    inventory[i].price = price;
    printf("%s updated in inventory.\n", name);
}

void print_inventory() {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < num_products; i++) {
        printf("%s - %d - %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    char name[50];
    int quantity;
    float price;
    do {
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Print inventory\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                add_product(name, quantity, price);
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                remove_product(name);
                break;
            case 3:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                printf("Enter product price: ");
                scanf("%f", &price);
                update_product(name, quantity, price);
                break;
            case 4:
                print_inventory();
                break;
            case 5:
                printf("Thank you for using our product inventory system!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);
    return 0;
}