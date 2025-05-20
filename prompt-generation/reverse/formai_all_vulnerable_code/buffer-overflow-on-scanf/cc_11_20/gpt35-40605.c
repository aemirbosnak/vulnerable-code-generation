//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    int option, i, n, productId, foundIndex, quantity;
    float price;
    char name[50];
    struct product *inventory;

    printf("Enter the number of products: ");
    scanf("%d", &n);

    inventory = (struct product*)malloc(n * sizeof(struct product));

    for (i = 0; i < n; i++) {
        printf("\nEnter details for product %d:\n", i);

        printf("Enter product ID: ");
        scanf("%d", &inventory[i].id);

        printf("Enter product name: ");
        scanf("%s", inventory[i].name);

        printf("Enter product quantity: ");
        scanf("%d", &inventory[i].quantity);

        printf("Enter product price: ");
        scanf("%f", &inventory[i].price);
    }

    do {
        printf("\n\nProduct Inventory System\n");
        printf("1. View inventory\n");
        printf("2. Add product\n");
        printf("3. Update product quantity\n");
        printf("4. Delete product\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // View inventory
                printf("\nProduct ID\tProduct Name\tProduct Quantity\tProduct Price\n");

                for (i = 0; i < n; i++) {
                    printf("%d\t\t%s\t\t%d\t\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }

                break;
            case 2: // Add product
                n++;
                inventory = (struct product*)realloc(inventory, n * sizeof(struct product));
                i = n - 1;

                printf("\nEnter details for product %d:\n", i);

                printf("Enter product ID: ");
                scanf("%d", &inventory[i].id);

                printf("Enter product name: ");
                scanf("%s", inventory[i].name);

                printf("Enter product quantity: ");
                scanf("%d", &inventory[i].quantity);

                printf("Enter product price: ");
                scanf("%f", &inventory[i].price);

                break;
            case 3: // Update product quantity
                printf("\nEnter product ID: ");
                scanf("%d", &productId);

                foundIndex = -1;

                for (i = 0; i < n; i++) {
                    if (inventory[i].id == productId) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex == -1) {
                    printf("Product with ID %d not found!\n", productId);
                } else {
                    printf("Enter new quantity: ");
                    scanf("%d", &quantity);
                    inventory[foundIndex].quantity = quantity;
                    printf("Updated product quantity successfully!\n");
                }

                break;
            case 4: // Delete product
                printf("\nEnter product ID: ");
                scanf("%d", &productId);

                foundIndex = -1;

                for (i = 0; i < n; i++) {
                    if (inventory[i].id == productId) {
                        foundIndex = i;
                        break;
                    }
                }

                if (foundIndex == -1) {
                    printf("Product with ID %d not found!\n", productId);
                } else {
                    for (i = foundIndex; i < n - 1; i++) {
                        inventory[i] = inventory[i + 1];
                    }

                    n--;
                    inventory = (struct product*)realloc(inventory, n * sizeof(struct product));

                    printf("Deleted product successfully!\n");
                }

                break;
            case 5: // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 5);

    free(inventory);

    return 0;
}