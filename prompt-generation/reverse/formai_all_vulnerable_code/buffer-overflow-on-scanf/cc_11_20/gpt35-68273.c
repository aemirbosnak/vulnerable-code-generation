//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct Product { // Product struct
    char name[20];
    int quantity;
    float price;
};

typedef struct Product Product;

int main() {

    Product inventory[100]; // Inventory array with size of 100
    int inventory_count = 0; // Initialize count to 0

    int option = 0;

    do {
        // Print Menu
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Sell product\n");
        printf("3. View inventory\n");
        printf("4. Exit\n");

        // Get user input
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Add product
                if (inventory_count >= 100) { // Check if inventory is full
                    printf("Inventory is full!\n");
                    break;
                }
                Product new_product; // Create new product
                printf("Enter product name: ");
                scanf("%s", new_product.name);
                printf("Enter quantity: ");
                scanf("%d", &new_product.quantity);
                printf("Enter price: ");
                scanf("%f", &new_product.price);
                inventory[inventory_count++] = new_product; // Add product to inventory and increment count
                printf("Product added successfully!\n");
                break;
            case 2: // Sell product
                if (inventory_count <= 0) { // Check if inventory is empty
                    printf("Inventory is empty!\n");
                    break;
                }
                int sell_index;
                printf("Enter index of product to sell: ");
                scanf("%d", &sell_index);
                if (sell_index < 0 || sell_index >= inventory_count) { // Check if index is valid
                    printf("Invalid index!\n");
                    break;
                }
                printf("Enter quantity to sell: ");
                int sell_quantity;
                scanf("%d", &sell_quantity);
                if (sell_quantity > inventory[sell_index].quantity) { // Check if quantity is valid
                    printf("Not enough quantity!\n");
                    break;
                }
                float total_price = sell_quantity * inventory[sell_index].price;
                printf("Total Price: %.2f\n", total_price);
                inventory[sell_index].quantity -= sell_quantity; // Subtract sold quantity from inventory
                if (inventory[sell_index].quantity == 0) { // If product is out of stock, remove it from inventory
                    for (int i = sell_index; i < inventory_count - 1; i++) {
                        inventory[i] = inventory[i+1];
                    }
                    inventory_count--; // Decrement count
                }
                printf("Product sold successfully!\n");
                break;
            case 3: // View inventory
                if (inventory_count <= 0) { // Check if inventory is empty
                    printf("Inventory is empty!\n");
                    break;
                }
                printf("Name\tQuantity\tPrice\n");
                for (int i = 0; i < inventory_count; i++) {
                    printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;
            case 4: // Exit
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;
        }

    } while (option != 4);

    return 0;
}