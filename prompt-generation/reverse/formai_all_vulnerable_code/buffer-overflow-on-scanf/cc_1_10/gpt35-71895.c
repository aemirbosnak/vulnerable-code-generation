//FormAI DATASET v1.0 Category: Product Inventory System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    double price;
    int quantity;
};

struct inventory {
    struct product products[MAX_PRODUCTS];
    int num_products;
    int next_id;
};

/* Function prototypes */
void add_product(struct inventory *inv);
void remove_product(struct inventory *inv);
void update_product(struct inventory *inv);
void display_products(struct inventory *inv);

/* Main function */
int main() {
    struct inventory inv = { 0 };
    int choice;

    do {
        printf("\n\n********** Product Inventory System **********\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. Display products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&inv);
                break;
            case 2:
                remove_product(&inv);
                break;
            case 3:
                update_product(&inv);
                break;
            case 4:
                display_products(&inv);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

/* Function to add a product to the inventory */
void add_product(struct inventory *inv) {
    struct product p;

    printf("\nAdding a new product\n");
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%lf", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);

    p.id = inv->next_id++;
    inv->products[inv->num_products++] = p;

    printf("\nProduct added successfully!\n");
}

/* Function to remove a product from the inventory */
void remove_product(struct inventory *inv) {
    int id, i, j;

    printf("\nRemoving a product\n");
    printf("Enter product ID: ");
    scanf("%d", &id);

    /* Find the product with the given ID */
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            /* Shift all products after this one up by one position */
            for (j = i; j < inv->num_products - 1; j++) {
                inv->products[j] = inv->products[j+1];
            }
            inv->num_products--;
            printf("\nProduct removed successfully!\n");
            return;
        }
    }

    printf("\nProduct not found with ID %d\n", id);
}

/* Function to update a product in the inventory */
void update_product(struct inventory *inv) {
    int id, i;
    char name[50];
    double price;
    int quantity;

    printf("\nUpdating a product\n");
    printf("Enter product ID: ");
    scanf("%d", &id);

    /* Find the product with the given ID */
    for (i = 0; i < inv->num_products; i++) {
        if (inv->products[i].id == id) {
            printf("Product found!\n");
            printf("Enter new product name (leave blank to keep as %s): ", inv->products[i].name);
            scanf("%s", name);
            if (strlen(name) > 0) {
                strcpy(inv->products[i].name, name);
            }
            printf("Enter new product price (leave blank to keep as %.2lf): ", inv->products[i].price);
            scanf("%lf", &price);
            if (price > 0) {
                inv->products[i].price = price;
            }
            printf("Enter new product quantity (leave blank to keep as %d): ", inv->products[i].quantity);
            scanf("%d", &quantity);
            if (quantity >= 0) {
                inv->products[i].quantity = quantity;
            }
            printf("\nProduct updated successfully!\n");
            return;
        }
    }

    printf("\nProduct not found with ID %d\n", id);
}

/* Function to display all products in the inventory */
void display_products(struct inventory *inv) {
    int i;

    printf("\nProduct inventory:\n");
    printf("%-5s %-20s %-10s %-10s\n", "ID", "Name", "Price", "Quantity");
    for (i = 0; i < inv->num_products; i++) {
        printf("%-5d %-20s %-10.2lf %-10d\n", inv->products[i].id, inv->products[i].name, inv->products[i].price, inv->products[i].quantity);
    }
}