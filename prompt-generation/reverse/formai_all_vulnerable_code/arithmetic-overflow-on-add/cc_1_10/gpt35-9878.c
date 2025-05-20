//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>

// C Warehouse Management System Example Program

#define MAX_PRODUCTS 100   // Maximum number of products allowed in the warehouse

struct product {
    int id;
    char name[50];
    int stock;
    float price;
};

struct warehouse {
    struct product products[MAX_PRODUCTS];
    int num_products;
};

void add_product(struct warehouse* w);
void remove_product(struct warehouse* w);
void display_products(struct warehouse* w);
void update_stock(struct warehouse* w);
void search_product(struct warehouse* w);

int main() {
    struct warehouse w = { .num_products = 0 };

    int option;
    while (1) {
        printf("Welcome to the Warehouse Management System!\n");
        printf("1. Add a product\n");
        printf("2. Remove a product\n");
        printf("3. Display all products\n");
        printf("4. Update product stock\n");
        printf("5. Search for a product\n");
        printf("6. Exit\n");

        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            add_product(&w);
            break;
        case 2:
            remove_product(&w);
            break;
        case 3:
            display_products(&w);
            break;
        case 4:
            update_stock(&w);
            break;
        case 5:
            search_product(&w);
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid option, please try again.\n");
        }
    }
}

void add_product(struct warehouse* w) {
    if (w->num_products == MAX_PRODUCTS) {
        printf("Error: warehouse is full.\n");
        return;
    }

    printf("Enter product ID: ");
    scanf("%d", &w->products[w->num_products].id);

    printf("Enter product name: ");
    scanf("%s", w->products[w->num_products].name);

    printf("Enter product stock: ");
    scanf("%d", &w->products[w->num_products].stock);

    printf("Enter product price: ");
    scanf("%f", &w->products[w->num_products].price);

    w->num_products++;

    printf("Product added successfully!\n");
}

void remove_product(struct warehouse* w) {
    int id, i, j;
    printf("Enter product ID to remove: ");
    scanf("%d", &id);

    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            for (j = i; j < w->num_products - 1; j++) {
                w->products[j] = w->products[j + 1];
            }
            w->num_products--;
            printf("Product removed successfully!\n");
            return;
        }
    }

    printf("Error: product with ID %d not found.\n", id);
}

void display_products(struct warehouse* w) {
    int i;
    printf("\n%-6s %-20s %-10s %-10s\n", "ID", "Name", "Stock", "Price");
    for (i = 0; i < w->num_products; i++) {
        printf("%-6d %-20s %-10d %-10.2f\n", w->products[i].id, w->products[i].name,
            w->products[i].stock, w->products[i].price);
    }
}

void update_stock(struct warehouse* w) {
    int id, i;
    printf("Enter product ID to update stock: ");
    scanf("%d", &id);

    for (i = 0; i < w->num_products; i++) {
        if (w->products[i].id == id) {
            printf("Enter new stock value: ");
            scanf("%d", &w->products[i].stock);
            printf("Stock updated successfully!\n");
            return;
        }
    }

    printf("Error: product with ID %d not found.\n", id);
}

void search_product(struct warehouse* w) {
    char name[50];
    int i;
    printf("Enter product name to search for: ");
    scanf("%s", name);

    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            printf("\n%-6s %-20s %-10s %-10s\n", "ID", "Name", "Stock", "Price");
            printf("%-6d %-20s %-10d %-10.2f\n", w->products[i].id, w->products[i].name,
                w->products[i].stock, w->products[i].price);
            return;
        }
    }

    printf("Error: product with name %s not found.\n", name);
}