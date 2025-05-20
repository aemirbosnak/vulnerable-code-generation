//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Warehouse {
    int id;
    char location[50];
    struct Product products[100];
    int num_products;
};

// Function prototypes
void add_product(struct Warehouse *w, struct Product p);
void remove_product(struct Warehouse *w, char *name);
void display_warehouse(struct Warehouse w);

// Main function
int main() {
    // Create a new warehouse
    struct Warehouse w = { 1, "Main Warehouse", { 0 }, 0 };
    printf("%s\n\n", "Welcome to the warehouse management system!");
    while (1) {
        printf("%s", "Enter a command (add, remove, display, exit): ");
        char command[10];
        scanf("%s", command);
        // Add product
        if (strcmp(command, "add") == 0) {
            struct Product p;
            printf("%s", "Enter the name of the product: ");
            scanf("%s", p.name);
            printf("%s", "Enter the quantity of the product: ");
            scanf("%d", &p.quantity);
            printf("%s", "Enter the price of the product: ");
            scanf("%f", &p.price);
            add_product(&w, p);
        }
        // Remove product
        else if (strcmp(command, "remove") == 0) {
            printf("%s", "Enter the name of the product you want to remove: ");
            char name[50];
            scanf("%s", name);
            remove_product(&w, name);
        }
        // Display warehouse inventory
        else if (strcmp(command, "display") == 0) {
            display_warehouse(w);
        }
        // Exit program
        else if (strcmp(command, "exit") == 0) {
            printf("%s\n", "Exiting program...");
            break;
        }
        else {
            printf("%s\n", "Invalid command!");
        }
    }
    return 0;
}

// Add a product to the warehouse
void add_product(struct Warehouse *w, struct Product p) {
    for (int i = 0; i < w->num_products; i++) {
        if (strcmp(p.name, w->products[i].name) == 0) {
            w->products[i].quantity += p.quantity;
            return;
        }
    }
    w->products[w->num_products] = p;
    w->num_products++;
}

// Remove a product from the warehouse
void remove_product(struct Warehouse *w, char *name) {
    for (int i = 0; i < w->num_products; i++) {
        if (strcmp(name, w->products[i].name) == 0) {
            for (int j = i; j < w->num_products; j++) {
                w->products[j] = w->products[j+1];
            }
            w->num_products--;
            printf("%s removed from warehouse!\n", name);
            return;
        }
    }
    printf("%s not found in warehouse!\n", name);
}

// Display the warehouse's inventory
void display_warehouse(struct Warehouse w) {
    printf("Warehouse ID: %d\n", w.id);
    printf("Location: %s\n", w.location);
    printf("%-20s%-20s%s\n", "Product Name", "Quantity", "Price");
    for (int i = 0; i < w.num_products; i++) {
        printf("%-20s%-20d%.2f\n", w.products[i].name, w.products[i].quantity, w.products[i].price);
    }
    printf("\n");
}