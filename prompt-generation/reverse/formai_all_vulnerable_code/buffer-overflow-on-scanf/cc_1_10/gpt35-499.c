//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

Product Inventory[MAX_ITEMS];
int num_items = 0;

void addProduct() {
    int id, quantity;
    char name[50];
    float price;

    printf("\nEnter product ID: ");
    scanf("%d", &id);
    printf("\nEnter product name: ");
    scanf("%s", name);
    printf("\nEnter product quantity: ");
    scanf("%d", &quantity);
    printf("\nEnter product price: ");
    scanf("%f", &price);

    Product newProduct;
    newProduct.id = id;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    newProduct.price = price;

    Inventory[num_items++] = newProduct;
    printf("\nProduct added successfully.\n");
}

void displayProducts() {
    if (num_items == 0) {
        printf("\nNo products found.\n");
        return;
    }

    printf("\nID\tName\t\tQuantity\tPrice\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", Inventory[i].id, Inventory[i].name, Inventory[i].quantity, Inventory[i].price);
    }
}

void searchProduct() {
    int id;

    printf("\nEnter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < num_items; i++) {
        if (Inventory[i].id == id) {
            printf("\nProduct Found\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n", Inventory[i].id, Inventory[i].name, Inventory[i].quantity, Inventory[i].price);
            return;
        }
    }

    printf("\nProduct not found.\n");
}

void deleteProduct() {
    int id;

    printf("\nEnter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < num_items; i++) {
        if (Inventory[i].id == id) {
            for (int j = i; j < num_items - 1; j++) {
                Inventory[j] = Inventory[j + 1];
            }
            num_items--;
            printf("\nProduct deleted successfully.\n");
            return;
        }
    }

    printf("\nProduct not found.\n");
}

int main() {
    int option;

    printf("Welcome to the Product Inventory System.\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add a product\n");
        printf("2. Display products\n");
        printf("3. Search for a product\n");
        printf("4. Delete a product\n");
        printf("5. Exit\n");
        printf("> ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}