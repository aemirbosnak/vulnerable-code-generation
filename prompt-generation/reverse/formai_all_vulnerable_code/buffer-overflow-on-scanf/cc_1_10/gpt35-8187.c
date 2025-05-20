//FormAI DATASET v1.0 Category: Product Inventory System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
    int id;
};

struct product inventory[50]; // maximum number of products in store

int count = 0; // number of products in store

void menu() {
    printf("---------Product Inventory System---------\n");
    printf("1. Add a new product\n");
    printf("2. Update an existing product\n");
    printf("3. Remove a product\n");
    printf("4. Display all products\n");
    printf("5. Search for a product\n");
    printf("6. Exit\n");
    printf("------------------------------------------\n");
    printf("Please enter your choice: ");
}

void add_product() {
    struct product p;
    p.id = count++;
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    inventory[p.id] = p;
    printf("Product added successfully.\n");
}

void update_product() {
    int id;
    printf("Enter product id to update: ");
    scanf("%d", &id);
    if (id >= count || id < 0) {
        printf("Invalid product id.\n");
        return; // error
    }
    struct product *p = &inventory[id];
    printf("Enter new product name: ");
    scanf("%s", p->name);
    printf("Enter new product quantity: ");
    scanf("%d", &p->quantity);
    printf("Enter new product price: ");
    scanf("%f", &p->price);
    printf("Product updated successfully.\n");
}

void remove_product() {
    int id;
    printf("Enter product id to remove: ");
    scanf("%d", &id);
    if (id >= count || id < 0) {
        printf("Invalid product id.\n");
        return; // error
    }
    for (int i = id; i < count-1; i++) {
        inventory[i] = inventory[i+1];
    }
    count--;
    printf("Product removed successfully.\n");
}

void display_all_products() {
    printf("-------------------------------\n");
    printf("| ID | Name               | Quantity | Price |\n");
    printf("-------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("| %-2d | %-18s | %-8d | $%-4.2f |\n",
               inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
    }
    printf("-------------------------------\n");
}

void search_product() {
    char name[50];
    printf("Enter product name to search: ");
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("------------------------------\n");
            printf("| ID | Name               | Quantity | Price |\n");
            printf("------------------------------\n");
            printf("| %-2d | %-18s | %-8d | $%-4.2f |\n",
                   inventory[i].id, inventory[i].name,
                   inventory[i].quantity, inventory[i].price);
            printf("------------------------------\n");
            return; // product found, return
        }
    }
    printf("No products found with name '%s'\n", name);
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                update_product();
                break;
            case 3:
                remove_product();
                break;
            case 4:
                display_all_products();
                break;
            case 5:
                search_product();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1); // infinite loop
    return 0;
}