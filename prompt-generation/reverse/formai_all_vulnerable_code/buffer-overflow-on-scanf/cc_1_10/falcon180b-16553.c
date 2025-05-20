//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    char description[100];
    int quantity;
    float price;
} Item;

typedef struct {
    int warehouse_id;
    char name[50];
    char address[100];
    int capacity;
} Warehouse;

void add_item(Item items[], int *size) {
    printf("Enter item ID: ");
    scanf("%d", &items[*size].id);
    printf("Enter item name: ");
    scanf("%s", items[*size].name);
    printf("Enter item description: ");
    scanf("%s", items[*size].description);
    printf("Enter item quantity: ");
    scanf("%d", &items[*size].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[*size].price);

    (*size)++;
}

void add_warehouse(Warehouse warehouses[], int *size) {
    printf("Enter warehouse ID: ");
    scanf("%d", &warehouses[*size].warehouse_id);
    printf("Enter warehouse name: ");
    scanf("%s", warehouses[*size].name);
    printf("Enter warehouse address: ");
    scanf("%s", warehouses[*size].address);
    printf("Enter warehouse capacity: ");
    scanf("%d", &warehouses[*size].capacity);

    (*size)++;
}

void display_items(Item items[], int size) {
    printf("\nItem List:\n");
    printf("ID\tName\tDescription\tQuantity\tPrice\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%s\t%d\t%.2f\n", items[i].id, items[i].name, items[i].description, items[i].quantity, items[i].price);
    }
}

void display_warehouses(Warehouse warehouses[], int size) {
    printf("\nWarehouse List:\n");
    printf("ID\tName\tAddress\tCapacity\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t%s\t%d\n", warehouses[i].warehouse_id, warehouses[i].name, warehouses[i].address, warehouses[i].capacity);
    }
}

void main() {
    Item items[MAX_SIZE];
    int item_size = 0;
    Warehouse warehouses[MAX_SIZE];
    int warehouse_size = 0;

    add_item(items, &item_size);
    add_warehouse(warehouses, &warehouse_size);

    display_items(items, item_size);
    display_warehouses(warehouses, warehouse_size);
}