//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct product {
    int product_id;
    char name[50];
    int quantity;
    float price;
} product_t;

typedef struct warehouse {
    char name[50];
    char location[50];
    product_t products[MAX_ITEMS];
    int num_products;
} warehouse_t;

void add_product(warehouse_t *w) {
    int id, qty;
    float price;
    char name[50];

    printf("Enter product ID: ");
    scanf("%d", &id);

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &qty);

    printf("Enter product price: ");
    scanf("%f", &price);

    product_t p = {id, name, qty, price};
    w->products[w->num_products++] = p;
}

void display_products(warehouse_t *w) {
    printf("Product ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("%d\t%s\t%d\t%.2f\n", w->products[i].product_id, w->products[i].name,
               w->products[i].quantity, w->products[i].price);
    }
}

int main() {
    warehouse_t w = {"My Warehouse", "123 Main St.", {}, 0};
    int user_choice = 0;

    printf("Welcome to the Warehouse Management System\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");

        scanf("%d", &user_choice);

        switch (user_choice) {
            case 1:
                add_product(&w);
                break;
            case 2:
                display_products(&w);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

    } while (user_choice != 3);

    return 0;
}