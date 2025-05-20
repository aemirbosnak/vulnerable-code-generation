//FormAI DATASET v1.0 Category: Product Inventory System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for the product
struct product {
    char name[20];
    int id;
    float price;
    int stock;
};

// Function for adding a new product
void addProduct(struct product inventory[], int *count) {
    printf("\nEnter the product name: ");
    scanf("%s", inventory[*count].name);

    printf("Enter the product ID: ");
    scanf("%d", &inventory[*count].id);

    printf("Enter the price of the product: ");
    scanf("%f", &inventory[*count].price);

    printf("Enter the stock count of the product: ");
    scanf("%d", &inventory[*count].stock);

    (*count)++;
}

// Function for updating the stock count of a product
void updateStock(struct product inventory[], int count) {
    int id, i;

    printf("\nEnter the ID of the product: ");
    scanf("%d", &id);

    // Loop through inventory to find product with matching ID
    for (i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            printf("Enter the new stock count for %s: ", inventory[i].name);
            scanf("%d", &inventory[i].stock);
            printf("%s stock has been updated to %d.\n", inventory[i].name, inventory[i].stock);
            return;
        }
    }

    printf("Product not found.\n");
}

// Function for displaying list of all products in inventory
void displayInventory(struct product inventory[], int count) {

    printf("\nProduct Inventory\n");
    printf("------------------------\n");
    printf("ID\t|Name\t\t\t|Price\t|Stock\n");
    printf("------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t|%s\t\t\t|%.2f\t|%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].stock);
    }
}

int main() {
    struct product inventory[10];
    int count = 0;
    int choice = 0;

    while (choice != 4) {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Update stock of a product\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count < 10) {
                addProduct(inventory, &count);
                printf("Product added successfully.\n");
            } else {
                printf("Inventory is full.\n");
            }
            break;
        case 2:
            updateStock(inventory, count);
            break;
        case 3:
            displayInventory(inventory, count);
            break;
        case 4:
            printf("\nExiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}