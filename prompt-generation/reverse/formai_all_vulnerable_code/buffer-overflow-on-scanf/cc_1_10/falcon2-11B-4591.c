//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
} Product;

typedef struct {
    int id;
    Product* products[10];
} Inventory;

void display_inventory(Inventory* inv);
void add_product(Inventory* inv, char name[], int quantity);
void remove_product(Inventory* inv, char name[]);
void update_quantity(Inventory* inv, char name[], int new_quantity);

int main() {
    Inventory inv;
    char name[50];

    while (1) {
        printf("Enter command: ");
        scanf("%s", name);

        if (strcmp(name, "exit") == 0) {
            break;
        }

        if (strcmp(name, "add") == 0) {
            add_product(&inv, name, 0);
        } else if (strcmp(name, "remove") == 0) {
            remove_product(&inv, name);
        } else if (strcmp(name, "update") == 0) {
            update_quantity(&inv, name, 100);
        } else if (strcmp(name, "display") == 0) {
            display_inventory(&inv);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}

void display_inventory(Inventory* inv) {
    printf("Inventory:\n");
    for (int i = 0; i < inv->id; i++) {
        printf("Product %d: %s - Quantity: %d\n", i+1, inv->products[i]->name, inv->products[i]->quantity);
    }
}

void add_product(Inventory* inv, char name[], int quantity) {
    if (inv->id == 10) {
        printf("Inventory is full\n");
        return;
    }

    Product* new_product = malloc(sizeof(Product));
    if (new_product == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    strcpy(new_product->name, name);
    new_product->quantity = quantity;

    inv->products[inv->id] = new_product;
    inv->id++;
}

void remove_product(Inventory* inv, char name[]) {
    for (int i = 0; i < inv->id; i++) {
        if (strcmp(inv->products[i]->name, name) == 0) {
            free(inv->products[i]);
            inv->products[i] = NULL;
            inv->id--;
            return;
        }
    }

    printf("Product not found\n");
}

void update_quantity(Inventory* inv, char name[], int new_quantity) {
    for (int i = 0; i < inv->id; i++) {
        if (strcmp(inv->products[i]->name, name) == 0) {
            inv->products[i]->quantity = new_quantity;
            return;
        }
    }

    printf("Product not found\n");
}