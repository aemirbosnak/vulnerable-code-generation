//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[20];
    int quantity;
    float price;
} product;

product inventory[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Inventory is full.\n");
        return;
    }
    printf("Enter product name (max 20 characters): ");
    scanf("%s", inventory[num_products].name);
    printf("Enter quantity: ");
    scanf("%d", &inventory[num_products].quantity);
    printf("Enter price: ");
    scanf("%f", &inventory[num_products].price);
    num_products++;
}

void display() {
    printf("Product Inventory System\n");
    printf("========================\n");
    printf("Total products: %d\n", num_products);
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - %d pieces, $%.2f each\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }
}

int find_product(char name[]) {
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void sell_product() {
    char name[20];
    printf("Enter product name to sell: ");
    scanf("%s", name);
    int index = find_product(name);
    if (index == -1) {
        printf("Product not found.\n");
        return;
    }
    int quantity;
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);
    if (quantity > inventory[index].quantity) {
        printf("Not enough stock.\n");
        return;
    }
    inventory[index].quantity -= quantity;
    printf("Sold %d pieces of %s for $%.2f each, total $%.2f\n", quantity, inventory[index].name, inventory[index].price, quantity*inventory[index].price);
}

int main() {
    char option;
    while (1) {
        printf("\nSelect an Option:\n");
        printf("1 - Add product\n");
        printf("2 - Sell product\n");
        printf("3 - Display inventory\n");
        printf("4 - Quit\n");
        printf("Your option: ");
        scanf(" %c", &option); // add space before %c to consume the newline character left behind by the previous scanfs
        
        switch (option) {
            case '1':
                add_product();
                break;
            case '2':
                sell_product();
                break;
            case '3':
                display();
                break;
            case '4':
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }
    return 0;
}