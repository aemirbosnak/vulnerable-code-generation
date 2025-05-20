//FormAI DATASET v1.0 Category: Product Inventory System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int id;
    float price;
    int quantity;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void print_menu() {
    printf("\n");
    printf("Product Inventory System\n");
    printf("1. Add Product\n");
    printf("2. Remove Product\n");
    printf("3. Update Product\n");
    printf("4. List Products\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_product() {
    Product new_product;

    printf("\nEnter product name: ");
    fgets(new_product.name, 50, stdin);
    new_product.name[strcspn(new_product.name, "\n")] = 0;

    printf("Enter product price: ");
    scanf("%f", &new_product.price);

    printf("Enter product quantity: ");
    scanf("%d", &new_product.quantity);

    new_product.id = num_products;

    products[num_products] = new_product;
    num_products++;

    printf("\nProduct added successfully!\n");
}

void remove_product() {
    int id;

    printf("\nEnter product id to remove: ");
    scanf("%d", &id);

    if (id < 0 || id >= num_products) {
        printf("\nInvalid product id!\n");
        return;
    }

    for (int i = id; i < num_products - 1; i++) {
        products[i] = products[i + 1];
        products[i].id = i;
    }

    num_products--;

    printf("\nProduct removed successfully!\n");
}

void update_product() {
    int id;

    printf("\nEnter product id to update: ");
    scanf("%d", &id);

    if (id < 0 || id >= num_products) {
        printf("\nInvalid product id!\n");
        return;
    }

    printf("Enter new product name (leave blank to keep current name): ");
    fgets(products[id].name, 50, stdin);
    if (products[id].name[0] == '\n') {
        products[id].name[strcspn(products[id].name, "\n")] = 0;
    }

    printf("Enter new product price (leave blank to keep current price): ");
    char buffer[50];
    fgets(buffer, 50, stdin);
    if (buffer[0] != '\n') {
        sscanf(buffer, "%f", &products[id].price);
    }

    printf("Enter new product quantity (leave blank to keep current quantity): ");
    fgets(buffer, 50, stdin);
    if (buffer[0] != '\n') {
        sscanf(buffer, "%d", &products[id].quantity);
    }

    printf("\nProduct updated successfully!\n");
}

void list_products() {
    printf("\nID  Name                           Price   Quantity\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-3d %-30s $%-7.2f %-8d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
}

int main() {
    int choice;

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar();

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
                list_products();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}