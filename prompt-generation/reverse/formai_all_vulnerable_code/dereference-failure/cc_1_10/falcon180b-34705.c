//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_PRODUCT_NAME_LENGTH 50
#define MAX_PRODUCT_QUANTITY 1000

typedef struct {
    char name[MAX_PRODUCT_NAME_LENGTH];
    int quantity;
} Product;

typedef struct {
    Product products[MAX_WAREHOUSE_SIZE];
    int num_products;
} Warehouse;

Warehouse* create_warehouse() {
    Warehouse* w = (Warehouse*)malloc(sizeof(Warehouse));
    w->num_products = 0;
    return w;
}

void destroy_warehouse(Warehouse* w) {
    free(w);
}

void add_product(Warehouse* w, const char* name, int quantity) {
    if (w->num_products >= MAX_WAREHOUSE_SIZE) {
        printf("Warehouse is full!\n");
        return;
    }

    Product* p = &w->products[w->num_products];
    strcpy(p->name, name);
    p->quantity = quantity;
    w->num_products++;
}

void remove_product(Warehouse* w, const char* name) {
    int i;
    for (i = 0; i < w->num_products; i++) {
        if (strcmp(w->products[i].name, name) == 0) {
            w->num_products--;
            break;
        }
    }
}

void print_warehouse(Warehouse* w) {
    printf("Warehouse contains:\n");
    for (int i = 0; i < w->num_products; i++) {
        printf("%s: %d\n", w->products[i].name, w->products[i].quantity);
    }
}

int main() {
    Warehouse* w = create_warehouse();

    add_product(w, "Apples", 100);
    add_product(w, "Oranges", 200);
    add_product(w, "Bananas", 300);

    print_warehouse(w);

    remove_product(w, "Apples");

    print_warehouse(w);

    destroy_warehouse(w);

    return 0;
}