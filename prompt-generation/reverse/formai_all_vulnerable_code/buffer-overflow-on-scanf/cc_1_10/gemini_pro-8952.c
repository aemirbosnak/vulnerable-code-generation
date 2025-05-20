//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    float price;
    int quantity;
    int reorder_level;
} product;

void add_product(product *inventory, int *size) {
    printf("Enter product name: ");
    scanf(" %[^\n]", inventory[*size].name);
    printf("Enter product price: ");
    scanf(" %f", &inventory[*size].price);
    printf("Enter product quantity: ");
    scanf(" %d", &inventory[*size].quantity);
    printf("Enter product reorder level: ");
    scanf(" %d", &inventory[*size].reorder_level);
    (*size)++;
}

void update_product(product *inventory, int size) {
    int choice;
    char name[50];

    printf("Enter product name to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("1. Update price\n2. Update quantity\n3. Update reorder level\nChoose an option: ");
            scanf(" %d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter new price: ");
                    scanf(" %f", &inventory[i].price);
                    break;
                case 2:
                    printf("Enter new quantity: ");
                    scanf(" %d", &inventory[i].quantity);
                    break;
                case 3:
                    printf("Enter new reorder level: ");
                    scanf(" %d", &inventory[i].reorder_level);
                    break;
                default:
                    printf("Invalid choice\n");
            }
        }
    }
}

void delete_product(product *inventory, int *size) {
    char name[50];

    printf("Enter product name to delete: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < *size; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*size)--;
            printf("Product deleted successfully\n");
            return;
        }
    }

    printf("Product not found\n");
}

void print_inventory(product *inventory, int size) {
    printf("Product Inventory:\n");
    printf("%-20s%-10s%-10s%-15s\n", "Name", "Price", "Quantity", "Reorder Level");
    for (int i = 0; i < size; i++) {
        printf("%-20s%-10.2f%-10d%-15d\n", inventory[i].name, inventory[i].price, inventory[i].quantity, inventory[i].reorder_level);
    }
}

int main() {
    product inventory[100];
    int size = 0;

    int choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n2. Update Product\n3. Delete Product\n4. Print Inventory\n5. Exit\nChoose an option: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                add_product(inventory, &size);
                break;
            case 2:
                update_product(inventory, size);
                break;
            case 3:
                delete_product(inventory, &size);
                break;
            case 4:
                print_inventory(inventory, size);
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}