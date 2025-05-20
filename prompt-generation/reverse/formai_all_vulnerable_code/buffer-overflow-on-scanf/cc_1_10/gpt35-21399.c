//FormAI DATASET v1.0 Category: Product Inventory System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    char name[20];
    int quantity;
    float price;
};

void addProduct(struct product inventory[], int *numProducts) {
    printf("Enter the name of the product: ");
    fgets(inventory[*numProducts].name, 20, stdin);
    inventory[*numProducts].name[strcspn(inventory[*numProducts].name, "\n")] = 0;

    printf("Enter the quantity of the product: ");
    scanf("%d", &inventory[*numProducts].quantity);
    getchar();

    printf("Enter the price of the product: ");
    scanf("%f", &inventory[*numProducts].price);
    getchar();

    printf("Product successfully added!\n");
    (*numProducts)++;
}

void removeProduct(struct product inventory[], int *numProducts) {
    if (*numProducts == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Enter the name of the product to remove: ");
    char name[20];
    fgets(name, 20, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < *numProducts; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Removing %s...\n", inventory[i].name);
            for (int j = i; j < *numProducts - 1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*numProducts)--;
            printf("%s removed successfully!\n", name);
            return;
        }
    }
    printf("%s not found in inventory!\n", name);
}

void viewInventory(struct product inventory[], int numProducts) {
    if (numProducts == 0) {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Product Name\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%-15s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    struct product inventory[100];
    int numProducts = 0;
    int choice = 0;

    printf("Product Inventory System\n");

    // Main menu
    while (choice != 4) {
        printf("\n1. Add Product\n2. Remove Product\n3. View Inventory\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                removeProduct(inventory, &numProducts);
                break;
            case 3:
                viewInventory(inventory, numProducts);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}