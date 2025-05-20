//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
} Product;

typedef struct {
    int id;
    Product item;
} Warehouse;

void print_warehouse(Warehouse *warehouse) {
    printf("Warehouse #%d:\n", warehouse->id);
    printf("---------------------\n");
    printf("Item Name: %s\n", warehouse->item.name);
    printf("Stock: %d\n", warehouse->item.stock);
}

void add_product(Warehouse *warehouse, char *name, int stock) {
    strcpy(warehouse->item.name, name);
    warehouse->item.stock = stock;
}

int main() {
    Warehouse *warehouses = NULL;
    int num_warehouses, i, j;

    printf("Enter the number of warehouses: ");
    scanf("%d", &num_warehouses);

    warehouses = (Warehouse *)calloc(num_warehouses, sizeof(Warehouse));

    for (i = 0; i < num_warehouses; i++) {
        printf("Enter the ID of the warehouse #%d: ", i + 1);
        scanf("%d", &warehouses[i].id);

        printf("Enter the name of the item in the %dth warehouse: ", i + 1);
        char name[50];
        scanf("%s", name);

        printf("Enter the stock of the item in the %dth warehouse: ", i + 1);
        int stock;
        scanf("%d", &stock);

        add_product(&warehouses[i], name, stock);
    }

    for (i = 0; i < num_warehouses; i++) {
        printf("\n");
        print_warehouse(&warehouses[i]);
        for (j = 0; j < num_warehouses; j++) {
            if (i != j) {
                if (warehouses[i].item.stock < warehouses[j].item.stock) {
                    Warehouse temp = warehouses[i];
                    warehouses[i] = warehouses[j];
                    warehouses[j] = temp;
                }
            }
        }
    }

    free(warehouses);

    return 0;
}