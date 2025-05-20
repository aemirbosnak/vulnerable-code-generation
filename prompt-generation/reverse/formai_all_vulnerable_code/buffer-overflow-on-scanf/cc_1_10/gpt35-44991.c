//FormAI DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} product;

product inventory[MAX_PRODUCTS];
int num_products = 0;

int add_product(char *name, int quantity, float price);
int remove_product(char *name);
int search_product(char *name);
void display_products();
void update_product(char *name, int quantity, float price);

int main() {
    int choice, quant;
    float pr;
    char name[MAX_NAME_LENGTH];

    printf("Welcome to the Product Inventory System!\n\n");

    do {
        printf("Menu:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display all products\n");
        printf("4. Update product\n");
        printf("5. Quit\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quant);
                printf("Enter price: ");
                scanf("%f", &pr);
                add_product(name, quant, pr);
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                remove_product(name);
                break;
            case 3:
                display_products();
                break;
            case 4:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quant);
                printf("Enter new price: ");
                scanf("%f", &pr);
                update_product(name, quant, pr);
                break;
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }

    } while(choice != 5);

    return 0;
}

int add_product(char *name, int quantity, float price) {
    if (num_products >= MAX_PRODUCTS) {
        printf("\nInventory full. Cannot add more products.\n");
        return 0;
    }

    int index = search_product(name);

    if (index != -1) {
        printf("\nProduct already exists in inventory. Use 'Update product' option to update quantity/price.\n");
        return 0;
    }

    product p;
    strcpy(p.name, name);
    p.quantity = quantity;
    p.price = price;

    inventory[num_products++] = p;

    printf("\nProduct added to inventory successfully!\n");

    return 1;
}

int remove_product(char *name) {
    int index = search_product(name);

    if (index == -1) {
        printf("\nProduct not found in inventory.\n");
        return 0;
    }

    for (int i = index; i < num_products - 1; i++) {
        inventory[i] = inventory[i+1];
    }

    num_products--;

    printf("\nProduct removed from inventory successfully!\n");

    return 1;
}

int search_product(char *name) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void display_products() {
    printf("\n%-30s %-10s %-10s", "Product name", "Quantity", "Price");
    printf("\n----------------------------------------------------\n");

    for (int i = 0; i < num_products; i++) {
        printf("%-30s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("----------------------------------------------------\n");
}

void update_product(char *name, int quantity, float price) {
    int index = search_product(name);

    if (index == -1) {
        printf("\nProduct not found in inventory.\n");
        return;
    }

    inventory[index].quantity = quantity;
    inventory[index].price = price;

    printf("\nProduct updated successfully!\n");
}