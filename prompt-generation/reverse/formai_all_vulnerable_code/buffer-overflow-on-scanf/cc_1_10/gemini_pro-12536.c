//GEMINI-pro DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} product;

product inventory[100];
int num_products = 0;

void add_product() {
    printf("Enter product name: ");
    scanf(" %[^\n]", inventory[num_products].name);
    printf("Enter product quantity: ");
    scanf("%d", &inventory[num_products].quantity);
    printf("Enter product price: ");
    scanf("%f", &inventory[num_products].price);
    num_products++;
}

void remove_product() {
    char name[50];
    printf("Enter product name to remove: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_products--;
            printf("Product removed successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void update_product() {
    char name[50];
    printf("Enter product name to update: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter new product quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new product price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void view_inventory() {
    printf("Product Inventory:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Update product\n");
        printf("4. View inventory\n");
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
                update_product();
                break;
            case 4:
                view_inventory();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}