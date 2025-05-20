//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int price;
} Product;

Product products[MAX_ITEMS];
int num_products = 0;

void add_product(char* name, int price) {
    if (num_products >= MAX_ITEMS) {
        printf("Inventory is full.\n");
        return;
    }

    strncpy(products[num_products].name, name, MAX_NAME_LENGTH);
    products[num_products].price = price;
    num_products++;

    printf("Product added successfully.\n");
}

void update_product(int index, char* name, int price) {
    if (index < 0 || index >= num_products) {
        printf("Invalid product index.\n");
        return;
    }

    strncpy(products[index].name, name, MAX_NAME_LENGTH);
    products[index].price = price;

    printf("Product updated successfully.\n");
}

void delete_product(int index) {
    if (index < 0 || index >= num_products) {
        printf("Invalid product index.\n");
        return;
    }

    for (int i = index; i < num_products - 1; i++) {
        products[i] = products[i + 1];
    }

    num_products--;

    printf("Product deleted successfully.\n");
}

void display_products() {
    if (num_products == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Product Name | Price\n");
    printf("----------------------------\n");
    for (int i = 0; i < num_products; i++) {
        printf("%-50s | %d\n", products[i].name, products[i].price);
    }
    printf("----------------------------\n");
}

int main() {
    int choice, index;

    while (1) {
        printf("1. Add product\n2. Update product\n3. Delete product\n4. Display products\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                fgets(products[num_products].name, MAX_NAME_LENGTH, stdin);
                printf("Enter product price: ");
                scanf("%d", &products[num_products].price);
                add_product(products[num_products].name, products[num_products].price);
                break;
            case 2:
                printf("Enter product index: ");
                scanf("%d", &index);
                if (index == -1) {
                    printf("Invalid index.\n");
                    break;
                }
                update_product(index - 1, products[index].name, products[index].price);
                break;
            case 3:
                printf("Enter product index: ");
                scanf("%d", &index);
                if (index == -1) {
                    printf("Invalid index.\n");
                    break;
                }
                delete_product(index - 1);
                break;
            case 4:
                display_products();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}