//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[50];
    int quantity;
    float price;
};

struct Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    struct Product product;
    printf("Enter product name: ");
    scanf("%s", &product.name);
    printf("Enter product quantity: ");
    scanf("%d", &product.quantity);
    printf("Enter product price: ");
    scanf("%f", &product.price);
    products[num_products] = product;
    num_products++;
    printf("Product added successfully!\n");
}

void list_products() {
    printf("Product\t\tQuantity\tPrice\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t\t%d\t\t$%.2f\n",
            products[i].name, products[i].quantity, products[i].price);
    }
}

void update_product() {
    char name[50];
    printf("Enter product name to update: ");
    scanf("%s", &name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            printf("Enter new quantity for %s: ", name);
            scanf("%d", &products[i].quantity);
            printf("Enter new price for %s: ", name);
            scanf("%f", &products[i].price);
            printf("%s updated successfully!\n", name);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

void remove_product() {
    char name[50];
    printf("Enter product name to remove: ");
    scanf("%s", &name);
    for (int i = 0; i < num_products; i++) {
        if (strcmp(name, products[i].name) == 0) {
            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }
            num_products--;
            printf("%s removed successfully!\n", name);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

int main() {
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("===========================\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Update Product\n");
        printf("4. Remove Product\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                list_products();
                break;
            case 3:
                update_product();
                break;
            case 4:
                remove_product();
                break;
            case 5:
                printf("Exiting, thank you!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (1);
    return 0;
}