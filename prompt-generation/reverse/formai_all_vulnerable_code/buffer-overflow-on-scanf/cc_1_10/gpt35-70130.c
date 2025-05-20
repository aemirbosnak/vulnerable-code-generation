//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 50

struct Product {
    int id;
    char name[MAX_NAME_LEN];
    int quantity;
    float price;
};

struct Warehouse {
    struct Product products[MAX_PRODUCTS];
    int num_products;
};

int read_int() {
    int n;
    scanf("%d", &n);
    return n;
}

float read_float() {
    float n;
    scanf("%f", &n);
    return n;
}

void add_product(struct Warehouse *w) {
    if (w->num_products == MAX_PRODUCTS) {
        printf("Cannot add more products.\n");
        return;
    }

    struct Product p;
    printf("Enter product id: ");
    p.id = read_int();

    printf("Enter product name: ");
    scanf("%s", p.name);

    printf("Enter product quantity: ");
    p.quantity = read_int();

    printf("Enter product price: ");
    p.price = read_float();

    w->products[w->num_products++] = p;
    printf("Product added.\n");
}

void remove_product(struct Warehouse *w) {
    printf("Enter product id to remove: ");
    int id = read_int();

    int index = -1;
    for (int i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product not found.\n");
        return;
    }

    for (int i = index; i < w->num_products - 1; i++) {
        w->products[i] = w->products[i + 1];
    }

    w->num_products--;
    printf("Product removed.\n");
}

void display_products(struct Warehouse w) {
    printf("Products:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < w.num_products; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", w.products[i].id, w.products[i].name, w.products[i].quantity, w.products[i].price);
    }
}

int main() {
    struct Warehouse w;
    w.num_products = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add product\n");
        printf("2. Remove product\n");
        printf("3. Display products\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice = read_int();

        switch (choice) {
            case 1: {
                add_product(&w);
                break;
            }

            case 2: {
                remove_product(&w);
                break;
            }

            case 3: {
                display_products(w);
                break;
            }

            case 4: {
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }

    return 0;
}