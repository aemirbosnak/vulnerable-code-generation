//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    int quantity;
    double price;
} Product;

void addProduct(Product *inventory, int *inventorySize) {
    char name[50];
    int quantity;
    double price;
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%lf", &price);
    inventory[*inventorySize].name = strdup(name);
    inventory[*inventorySize].quantity = quantity;
    inventory[*inventorySize].price = price;
    (*inventorySize)++;
    printf("\nProduct added successfully!\n\n");
}

void removeProduct(Product *inventory, int *inventorySize) {
    char name[50];
    printf("Enter product name: ");
    scanf("%s", name);
    int indexToRemove = -1;
    for (int i = 0; i < *inventorySize; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            indexToRemove = i;
            break;
        }
    }
    if (indexToRemove == -1) {
        printf("\nProduct not found!\n\n");
    } else {
        for (int i = indexToRemove; i < *inventorySize - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        (*inventorySize)--;
        printf("\nProduct removed successfully!\n\n");
    }
}

void printInventory(Product *inventory, int inventorySize) {
    printf("\nProduct Inventory:\n");
    for (int i = 0; i < inventorySize; i++) {
        printf("%s\tquantity: %d\tprice: $%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    printf("\n");
}

int main() {
    int inventorySize = 0;
    Product inventory[100];
    int choice;
    do {
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Print Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch(choice) {
            case 1:
                addProduct(inventory, &inventorySize);
                break;
            case 2:
                removeProduct(inventory, &inventorySize);
                break;
            case 3:
                printInventory(inventory, inventorySize);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n\n");
        }
    } while (choice != 4);
    return 0;
}