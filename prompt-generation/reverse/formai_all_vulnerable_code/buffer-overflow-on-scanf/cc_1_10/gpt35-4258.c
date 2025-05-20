//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Donald Knuth
// C Product Inventory System
// Written by: [Your Name Here]
// Date: [Date Here]
// Inspired by the works of Donald Knuth

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    struct product new_product;

    printf("Enter product name: ");
    fgets(new_product.name, sizeof(new_product.name), stdin);
    strtok(new_product.name, "\n"); // Remove the '\n' character

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    new_product.id = num_products; // Use the current number of products as the ID

    inventory[num_products] = new_product;
    num_products++;
}

void remove_product() {
    int id_to_remove, product_index = -1;

    printf("Enter ID of product to remove: ");
    scanf("%d", &id_to_remove);

    for (int i = 0; i < num_products; i++) {
        if (inventory[i].id == id_to_remove) {
            product_index = i;
            break;
        }
    }

    if (product_index == -1) {
        printf("Product with ID %d not found.\n", id_to_remove);
        return;
    }

    // Shift all products after the removed one to the left
    for (int i = product_index + 1; i < num_products; i++) {
        inventory[i - 1] = inventory[i];
    }

    num_products--;
}

void list_products() {
    printf("ID   NAME                                        QUANTITY    PRICE\n");

    for (int i = 0; i < num_products; i++) {
        printf("%3d  %-40s%5d        $%-6.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void save_data() {
    FILE *fp;

    fp = fopen("inventory.txt", "w");

    if (fp == NULL) {
        printf("Error saving inventory. Could not open file.\n");
        return;
    }

    for (int i = 0; i < num_products; i++) {
        fprintf(fp, "%d,%s,%d,%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }

    printf("Inventory saved to file.\n");

    fclose(fp);
}

void load_data() {
    FILE *fp;

    fp = fopen("inventory.txt", "r");

    if (fp == NULL) {
        printf("Error loading inventory. Could not open file.\n");
        return;
    }

    while (!feof(fp)) {
        struct product loaded_product;
        int read_count = fscanf(fp, "%d,%[^,],%d,%f\n", &loaded_product.id, loaded_product.name, &loaded_product.quantity, &loaded_product.price);

        if (read_count == 4) { // Make sure all fields were read successfully
            inventory[num_products] = loaded_product;
            num_products++;
        }
    }

    printf("%d products loaded from file.\n", num_products);

    fclose(fp);
}

int main() {
    int choice;

    // Load inventory data from file
    load_data();

    while (1) {
        printf("\nPRODUCT INVENTORY SYSTEM\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. List products\n");
        printf("4. Save data\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                remove_product();
                break;
            case 3:
                list_products();
                break;
            case 4:
                save_data();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}