//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;

int main() {
    Product inventory[MAX_PRODUCTS];
    int numProducts = 0;
    int choice;
    int index;
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
    
    while (1) {
        printf("1. Add product\n2. View inventory\n3. Update product\n4. Remove product\n5. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (numProducts >= MAX_PRODUCTS) {
                    printf("Inventory is full.\n");
                    break;
                }
                printf("Enter product name: ");
                scanf("%s", inventory[numProducts].name);
                printf("Enter product price: ");
                scanf("%f", &inventory[numProducts].price);
                printf("Enter product quantity: ");
                scanf("%d", &inventory[numProducts].quantity);
                numProducts++;
                printf("Product added to inventory.\n");
                break;
            case 2:
                printf("Inventory:\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("%d. Name: %s - Price: %.2f - Quantity: %d\n", i + 1, inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                break;
            case 3:
                printf("Enter index of product to update: ");
                scanf("%d", &index);
                if (index < 1 || index > numProducts) {
                    printf("Invalid index.\n");
                    break;
                }
                printf("Enter new name: ");
                scanf("%s", name);
                strcpy(inventory[index - 1].name, name);
                printf("Enter new price: ");
                scanf("%f", &price);
                inventory[index - 1].price = price;
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                inventory[index - 1].quantity = quantity;
                printf("Product updated.\n");
                break;
            case 4:
                printf("Enter index of product to remove: ");
                scanf("%d", &index);
                if (index < 1 || index > numProducts) {
                    printf("Invalid index.\n");
                    break;
                }
                for (int i = index - 1; i < numProducts - 1; i++) {
                    strcpy(inventory[i].name, inventory[i + 1].name);
                    inventory[i].price = inventory[i + 1].price;
                    inventory[i].quantity = inventory[i + 1].quantity;
                }
                numProducts--;
                printf("Product removed from inventory.\n");
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}