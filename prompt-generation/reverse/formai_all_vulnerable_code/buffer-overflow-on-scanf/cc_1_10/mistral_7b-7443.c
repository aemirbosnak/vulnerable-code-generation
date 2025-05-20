//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 99

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

void print_menu();
void add_product(Product inventory[]);
void remove_product(Product inventory[], int index);
void display_inventory(Product inventory[]);
void search_product(Product inventory[]);

Product inventory[MAX_PRODUCTS];
int num_products = 0;

int main() {
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(inventory);
                break;
            case 2:
                remove_product(inventory, --num_products);
                break;
            case 3:
                display_inventory(inventory);
                break;
            case 4:
                search_product(inventory);
                break;
            case 5:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void print_menu() {
    printf("\nProduct Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Display Inventory\n");
    printf("4. Search Product\n");
    printf("5. Exit\n");
}

void add_product(Product inventory[]) {
    if (num_products >= MAX_PRODUCTS) {
        printf("Maximum number of products reached.\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", inventory[num_products].name);

    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);

    num_products++;
}

void remove_product(Product inventory[], int index) {
    if (index < 0 || index >= num_products) {
        printf("Invalid index.\n");
        return;
    }

    inventory[index].quantity = 0;
}

void display_inventory(Product inventory[]) {
    int i;

    printf("\nProduct Inventory\n");

    for (i = 0; i < num_products; i++) {
        printf("%d. %s - %d\n", i+1, inventory[i].name, inventory[i].quantity);
    }
}

void search_product(Product inventory[]) {
    char name[MAX_NAME_LENGTH];
    int i;

    printf("Enter product name to search: ");
    scanf("%s", name);

    for (i = 0; i < num_products; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Product found: %s - %d\n", inventory[i].name, inventory[i].quantity);
            return;
        }
    }

    printf("Product not found.\n");
}