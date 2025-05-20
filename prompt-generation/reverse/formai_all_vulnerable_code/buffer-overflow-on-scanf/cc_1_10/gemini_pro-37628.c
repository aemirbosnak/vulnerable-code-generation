//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: artistic
// A symphony of strings, a concerto of numbers,
// An ode to inventory, an aria of order.
// Each note a product, its price a melody,
// The symphony conducts, a harmonious inventory.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A canvas of structures, each brush stroke a product,
// Its form defined by fields, its essence by data.
typedef struct Product {
    char name[50];    // A string of characters, the product's name.
    int quantity;     // A number, the product's quantity in stock.
    float price;      // A floating-point number, the product's price.
} Product;

// An orchestra of functions, each playing its part,
// The symphony conducted, the inventory managed.
void addProduct(Product *inventory, int *count, Product newProduct);
void removeProduct(Product *inventory, int *count, char *productName);
void displayInventory(Product *inventory, int count);
void searchProduct(Product *inventory, int count, char *productName);

// The conductor's baton, the main function,
// The symphony begins, the inventory system hums.
int main() {
    // A grand stage, the inventory, an array of products,
    // Each one a masterpiece, a treasure to behold.
    Product inventory[100];

    // A maestro's count, the number of products in the inventory,
    // A symphony's measure, the system's guiding light.
    int count = 0;

    // The user's request, a command to add, remove, display, or search,
    // The conductor's cue, the symphony's rhythm.
    char command[50];

    // A loop, a perpetual performance, the system's heartbeat,
    // The symphony continues, the inventory ever-changing.
    while (1) {
        // The user's input, a note in the symphony,
        // The conductor's interpretation, the system's response.
        scanf("%s", command);

        // A product is born, a new note in the symphony,
        // The inventory expands, the system adapts.
        if (strcmp(command, "add") == 0) {
            Product newProduct;
            printf("Enter product name: ");
            scanf(" %[^\n]", newProduct.name);
            printf("Enter product quantity: ");
            scanf("%d", &newProduct.quantity);
            printf("Enter product price: ");
            scanf("%f", &newProduct.price);
            addProduct(inventory, &count, newProduct);
        }

        // A product departs, a note fades from the symphony,
        // The inventory contracts, the system adjusts.
        else if (strcmp(command, "remove") == 0) {
            char productName[50];
            printf("Enter product name: ");
            scanf(" %[^\n]", productName);
            removeProduct(inventory, &count, productName);
        }

        // The inventory unveiled, a concert for the eyes,
        // The system's masterpiece, a symphony of data.
        else if (strcmp(command, "display") == 0) {
            displayInventory(inventory, count);
        }

        // A product sought, a specific note in the symphony,
        // The system searches, the inventory responds.
        else if (strcmp(command, "search") == 0) {
            char productName[50];
            printf("Enter product name: ");
            scanf(" %[^\n]", productName);
            searchProduct(inventory, count, productName);
        }

        // The conductor's final bow, the symphony's end,
        // The system pauses, the inventory preserved.
        else if (strcmp(command, "exit") == 0) {
            break;
        }

        // A note out of tune, a command not recognized,
        // The system's confusion, a dissonant chord.
        else {
            printf("Invalid command. Try again.\n");
        }
    }

    // The symphony concludes, the inventory complete,
    // The conductor's baton rests, the system's task fulfilled.
    return 0;
}

// A new voice in the choir, a product added to the inventory,
// The symphony enriched, the system expanded.
void addProduct(Product *inventory, int *count, Product newProduct) {
    inventory[*count] = newProduct;
    (*count)++;
}

// A voice silenced, a product removed from the inventory,
// The symphony diminished, the system contracted.
void removeProduct(Product *inventory, int *count, char *productName) {
    int i;
    for (i = 0; i < *count; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            for (; i < *count - 1; i++) {
                inventory[i] = inventory[i + 1];
            }
            (*count)--;
            break;
        }
    }
}

// The inventory revealed, a harmonious display,
// The system's masterpiece, a symphony of data.
void displayInventory(Product *inventory, int count) {
    int i;
    printf("Inventory:\n");
    for (i = 0; i < count; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

// A product sought, a specific note in the symphony,
// The system searches, the inventory responds.
void searchProduct(Product *inventory, int count, char *productName) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, productName) == 0) {
            printf("Product found:\n%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Product not found.\n");
}