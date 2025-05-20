//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int id;
    int stock;
    float price;
} Product;

void add_product(Product *inventory, int *size);
void update_stock(Product *inventory, int size);
void print_inventory(Product *inventory, int size);
void remove_product(Product *inventory, int *size);
void sell_product(Product *inventory, int size);

int main() {
    int choice;
    int size = 0;
    Product inventory[20];

    do {
        printf("\nProduct Inventory System\n");
        printf("------------------------\n");
        printf("1. Add product\n");
        printf("2. Update stock\n");
        printf("3. Print inventory\n");
        printf("4. Remove product\n");
        printf("5. Sell product\n");
        printf("6. Quit\n");
        printf("Enter choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(inventory, &size);
                break;
            case 2:
                update_stock(inventory, size);
                break;
            case 3:
                print_inventory(inventory, size);
                break;
            case 4:
                remove_product(inventory, &size);
                break;
            case 5:
                sell_product(inventory, size);
                break;
            case 6:
                printf("Quitting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void add_product(Product *inventory, int *size) {
    printf("\nAdd product\n");
    printf("-----------\n");
    printf("Enter name: ");
    scanf("%s", inventory[*size].name);
    printf("Enter id: ");
    scanf("%d", &inventory[*size].id);
    printf("Enter stock: ");
    scanf("%d", &inventory[*size].stock);
    printf("Enter price: ");
    scanf("%f", &inventory[*size].price);
    (*size)++;
}

void update_stock(Product *inventory, int size) {
    int id, stock;
    printf("\nUpdate stock\n");
    printf("-------------\n");
    printf("Enter product id: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            printf("Enter new stock: ");
            scanf("%d", &stock);
            inventory[i].stock = stock;
            printf("Stock updated.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void print_inventory(Product *inventory, int size) {
    printf("\nProduct Inventory\n");
    printf("------------------\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", inventory[i].name);
        printf("ID: %d\n", inventory[i].id);
        printf("Stock: %d\n", inventory[i].stock);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("------------------\n");
    }
}

void remove_product(Product *inventory, int *size) {
    int id;
    printf("\nRemove product\n");
    printf("---------------\n");
    printf("Enter product id: ");
    scanf("%d", &id);
    for (int i = 0; i < *size; i++) {
        if (inventory[i].id == id) {
            for (int j = i; j < *size - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            (*size)--;
            printf("Product removed.\n");
            return;
        }
    }
    printf("Product not found.\n");
}

void sell_product(Product *inventory, int size) {
    int id, quantity;
    float price;
    printf("\nSell product\n");
    printf("-------------\n");
    printf("Enter product id: ");
    scanf("%d", &id);
    for (int i = 0; i < size; i++) {
        if (inventory[i].id == id) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            if (inventory[i].stock >= quantity) {
                price = quantity * inventory[i].price;
                inventory[i].stock -= quantity;
                printf("Sold %d %s for $%.2f.\n", quantity, inventory[i].name, price);
                return;
            } else {
                printf("Insufficient stock.\n");
                return;
            }
        }
    }
    printf("Product not found.\n");
}