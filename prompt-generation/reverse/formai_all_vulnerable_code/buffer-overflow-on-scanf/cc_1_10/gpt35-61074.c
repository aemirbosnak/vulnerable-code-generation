//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float price;
    int quantity;
    char category[20];
} product;

typedef struct {
    product items[100];
    int count;
} warehouse;

void add_product(warehouse *w) {
    product p;
    printf("Enter product ID: ");
    scanf("%d", &p.id);
    printf("Enter product name: ");
    scanf("%s", p.name);
    printf("Enter product price: ");
    scanf("%f", &p.price);
    printf("Enter product quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter product category: ");
    scanf("%s", p.category);
    w->items[w->count++] = p;
}

void view_inventory(warehouse *w) {
    printf("Inventory:\n");
    printf("ID\tName\tPrice\tQuantity\tCategory\n");
    for (int i = 0; i < w->count; i++) {
        product p = w->items[i];
        printf("%d\t%s\t%.2f\t%d\t\t%s\n", p.id, p.name, p.price, p.quantity, p.category);
    }
}

void search_product(warehouse *w) {
    int id;
    printf("Enter product ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < w->count; i++) {
        if (w->items[i].id == id) {
            printf("Product found!\n");
            printf("ID\tName\tPrice\tQuantity\tCategory\n");
            product p = w->items[i];
            printf("%d\t%s\t%.2f\t%d\t\t%s\n", p.id, p.name, p.price, p.quantity, p.category);
            return;
        }
    }
    printf("Product not found!\n");
}

int main() {
    warehouse w;
    w.count = 0;
    int choice;
    do {
        printf("What do you want to do?\n");
        printf("1. Add a product\n");
        printf("2. View inventory\n");
        printf("3. Search a product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_product(&w);
                break;
            case 2:
                view_inventory(&w);
                break;
            case 3:
                search_product(&w);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);
    return 0;
}