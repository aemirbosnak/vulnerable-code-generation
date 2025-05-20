//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to store inventory items
typedef struct item {
    char name[20];
    int quantity;
    float price;
} item_t;

// Define a function to simulate the store inventory
void simulate_inventory(item_t items[], int num_items) {
    // Display the inventory items
    printf("Inventory:**\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s: %d, $%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    // Simulate a sale
    printf("Enter the name of the item you want to buy:");
    char item_name[20];
    scanf("%s", item_name);

    // Find the item in the inventory
    item_t* item = NULL;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            item = &items[i];
            break;
        }
    }

    // If the item is found, check if there is enough stock
    if (item) {
        if (item->quantity > 0) {
            // Subtract the quantity of the item from the inventory
            item->quantity--;

            // Calculate the total cost of the item
            float total_cost = item->price * item->quantity;

            // Display the confirmation of the sale
            printf("Confirmation:**\n");
            printf("%s was successfully purchased for $%.2f.\n", item->name, total_cost);
        } else {
            // Display an error message
            printf("Error: There is no stock of that item.\n");
        }
    } else {
        // Display an error message
        printf("Error: Item not found.\n");
    }
}

int main() {
    // Create an array of items
    item_t items[] = {
        {"Apple", 10, 1.20},
        {"Banana", 5, 0.80},
        {"Orange", 7, 1.00}
    };

    // Simulate the inventory
    simulate_inventory(items, 3);

    return 0;
}