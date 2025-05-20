//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    char name[32];
    int quantity;
    double price;
} product;

int main() {
    // Initialize the inventory with some sample products
    product inventory[] = {
        {"Apple", 100, 0.50},
        {"Banana", 50, 0.75},
        {"Orange", 25, 1.00},
        {"Grape", 15, 1.25},
        {"Pear", 10, 1.50}
    };
    int num_products = sizeof(inventory) / sizeof(product);

    // Get the user's input
    char input[128];
    printf("Enter a command (add, remove, or print): ");
    scanf("%s", input);

    // Process the user's input
    if (strcmp(input, "add") == 0) {
        // Get the product information from the user
        char name[32];
        int quantity;
        double price;
        printf("Enter the product name: ");
        scanf("%s", name);
        printf("Enter the product quantity: ");
        scanf("%d", &quantity);
        printf("Enter the product price: ");
        scanf("%lf", &price);

        // Add the product to the inventory
        product new_product = {name, quantity, price};
        inventory[num_products++] = new_product;
    } else if (strcmp(input, "remove") == 0) {
        // Get the product name from the user
        char name[32];
        printf("Enter the product name: ");
        scanf("%s", name);

        // Find the product in the inventory
        int index = -1;
        for (int i = 0; i < num_products; i++) {
            if (strcmp(inventory[i].name, name) == 0) {
                index = i;
                break;
            }
        }

        // If the product was found, remove it from the inventory
        if (index != -1) {
            for (int i = index; i < num_products - 1; i++) {
                inventory[i] = inventory[i + 1];
            }
            num_products--;
        }
    } else if (strcmp(input, "print") == 0) {
        // Print the inventory
        printf("Inventory:\n");
        for (int i = 0; i < num_products; i++) {
            printf("%s %d %lf\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    } else {
        // Invalid input
        printf("Invalid command. Please enter 'add', 'remove', or 'print'.\n");
    }

    return 0;
}