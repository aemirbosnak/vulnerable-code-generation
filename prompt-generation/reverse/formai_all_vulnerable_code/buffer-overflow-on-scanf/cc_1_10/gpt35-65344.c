//FormAI DATASET v1.0 Category: Product Inventory System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold product information
typedef struct product {
    char name[50];
    int quantity;
    double price;
} product;

// Function to add new product to inventory
void add_product(product** inventory, int* num_products) {
    // Reallocate memory for new product
    *inventory = realloc(*inventory, (*num_products + 1) * sizeof(product));
    printf("\nEnter the product name: ");
    scanf("%s", (*inventory + *num_products)->name);
    printf("\nEnter the product quantity: ");
    scanf("%d", &((*inventory + *num_products)->quantity));
    printf("\nEnter the product price: ");
    scanf("%lf", &((*inventory + *num_products)->price));
    // Increase number of products by 1
    *num_products += 1;
}

// Function to remove a product from inventory
void remove_product(product** inventory, int* num_products) {
    char product_name[50];
    int found = 0;
    printf("\nEnter the name of the product to remove: ");
    scanf("%s", product_name);
    for (int i = 0; i < *num_products; i++) {
        if (strcmp(((*inventory) + i)->name, product_name) == 0) {
            // Shift memory to remove product
            memmove((*inventory) + i, (*inventory) + i + 1, (*num_products - i - 1) * sizeof(product));
            found = 1;
            // Decrease number of products by 1
            *num_products -= 1;
            // Reallocate memory for new size
            *inventory = realloc(*inventory, *num_products * sizeof(product));
            printf("\nProduct removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("\nProduct not found.\n");
    }
}

// Function to display current inventory
void display_inventory(product* inventory, int num_products) {
    printf("\n%-20s %-15s %-10s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < num_products; i++) {
        printf("%-20s %-15d $%.2lf\n", (inventory + i)->name, (inventory + i)->quantity, (inventory + i)->price);
    }
}

int main() {
    product* inventory = NULL;
    int num_products = 0;
    int choice;

    do {
        printf("\n===== Product Inventory System =====\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(&inventory, &num_products);
                break;
            case 2:
                remove_product(&inventory, &num_products);
                break;
            case 3:
                display_inventory(inventory, num_products);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 4);

    // Free allocated memory
    free(inventory);

    return 0;
}