//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

void add_product() {
    if (product_count >= MAX_PRODUCTS) {
        printf("Inventory is full! Cannot add more products.\n");
        return;
    }

    Product new_product;
    new_product.id = product_count + 1;

    printf("Enter product name: ");
    getchar(); // To consume leftover newline character
    fgets(new_product.name, NAME_LENGTH, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0; // Remove newline character

    printf("Enter quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter price: ");
    scanf("%f", &new_product.price);

    inventory[product_count] = new_product;
    product_count++;

    printf("Product added successfully!\n");
}

void display_inventory() {
    if (product_count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nCurrent Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < product_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void update_product() {
    int id;
    printf("Enter the product ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }

    Product *product = &inventory[id - 1];

    printf("Current Name: %s\n", product->name);
    printf("Enter new name (or press Enter to keep current): ");
    getchar(); // To consume leftover newline character
    char new_name[NAME_LENGTH];
    fgets(new_name, NAME_LENGTH, stdin);
    new_name[strcspn(new_name, "\n")] = 0; // Remove newline character
    if (strlen(new_name) > 0) {
        strcpy(product->name, new_name);
    }

    printf("Current Quantity: %d\n", product->quantity);
    printf("Enter new quantity (or press -1 to keep current): ");
    int new_quantity;
    scanf("%d", &new_quantity);
    if (new_quantity != -1) {
        product->quantity = new_quantity;
    }

    printf("Current Price: %.2f\n", product->price);
    printf("Enter new price (or press -1 to keep current): ");
    float new_price;
    scanf("%f", &new_price);
    if (new_price != -1) {
        product->price = new_price;
    }

    printf("Product updated successfully!\n");
}

void remove_product() {
    int id;
    printf("Enter the product ID to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > product_count) {
        printf("Invalid product ID.\n");
        return;
    }

    for (int i = id - 1; i < product_count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    
    product_count--;
    printf("Product removed successfully!\n");
}

void save_inventory() {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < product_count; i++) {
        fprintf(file, "%d,%s,%d,%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    fclose(file);
    printf("Inventory saved successfully!\n");
}

void load_inventory() {
    FILE *file = fopen("inventory.txt", "r");
    if (file == NULL) {
        printf("No inventory file found. Starting fresh.\n");
        return;
    }

    product_count = 0;
    while (fscanf(file, "%d,%49[^,],%d,%f\n", &inventory[product_count].id, inventory[product_count].name, &inventory[product_count].quantity, &inventory[product_count].price) != EOF) {
        product_count++;
    }

    fclose(file);
    printf("Inventory loaded successfully!\n");
}

int main() {
    int choice;
    load_inventory();

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Update Product\n");
        printf("4. Remove Product\n");
        printf("5. Save Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_product(); break;
            case 2: display_inventory(); break;
            case 3: update_product(); break;
            case 4: remove_product(); break;
            case 5: save_inventory(); break;
            case 6: 
                save_inventory(); // Save before exit
                printf("Exiting...\n");
                break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}