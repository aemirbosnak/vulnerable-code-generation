//Code Llama-13B DATASET v1.0 Category: Product Inventory System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    char name[50];
    int price;
    int quantity;
};

void print_menu() {
    printf("===================================\n");
    printf("1. Add product\n");
    printf("2. Remove product\n");
    printf("3. Update product\n");
    printf("4. View inventory\n");
    printf("5. Exit\n");
    printf("===================================\n");
}

void add_product(struct Product *products, int *num_products) {
    char name[50];
    int price;
    int quantity;

    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product price: ");
    scanf("%d", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    struct Product product = {name, price, quantity};
    products[*num_products] = product;
    *num_products += 1;
}

void remove_product(struct Product *products, int *num_products) {
    int index;
    printf("Enter product index to remove: ");
    scanf("%d", &index);

    if (index >= *num_products || index < 0) {
        printf("Invalid index\n");
        return;
    }

    for (int i = index; i < *num_products - 1; i++) {
        products[i] = products[i + 1];
    }
    *num_products -= 1;
}

void update_product(struct Product *products, int *num_products) {
    int index;
    printf("Enter product index to update: ");
    scanf("%d", &index);

    if (index >= *num_products || index < 0) {
        printf("Invalid index\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[index].name);
    printf("Enter product price: ");
    scanf("%d", &products[index].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[index].quantity);
}

void view_inventory(struct Product *products, int num_products) {
    printf("===================================\n");
    printf("Product Inventory\n");
    printf("===================================\n");

    for (int i = 0; i < num_products; i++) {
        printf("%d. %s - $%d x %d\n", i + 1, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    struct Product products[100];
    int num_products = 0;

    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product(products, &num_products);
                break;
            case 2:
                remove_product(products, &num_products);
                break;
            case 3:
                update_product(products, &num_products);
                break;
            case 4:
                view_inventory(products, num_products);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}