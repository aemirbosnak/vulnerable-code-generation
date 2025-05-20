//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_WAREHOUSES 10
#define MAX_ITEMS 100
#define MAX_SUPPLIERS 50

typedef struct {
    char name[50];
    int capacity;
    int current_items;
} Warehouse;

typedef struct {
    char name[50];
    int quantity;
    int price;
    int supplier_id;
} Item;

typedef struct {
    char name[50];
    int id;
} Supplier;

int main() {
    Warehouse warehouses[MAX_WAREHOUSES];
    Item items[MAX_ITEMS];
    Supplier suppliers[MAX_SUPPLIERS];

    int num_warehouses = 0, num_items = 0, num_suppliers = 0;

    while (num_warehouses < MAX_WAREHOUSES && num_items < MAX_ITEMS && num_suppliers < MAX_SUPPLIERS) {
        printf("Enter 1 to add a warehouse, 2 to add an item, or 3 to add a supplier: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the warehouse: ");
                scanf("%s", warehouses[num_warehouses].name);
                printf("Enter the capacity of the warehouse: ");
                scanf("%d", &warehouses[num_warehouses].capacity);
                num_warehouses++;
                break;
            case 2:
                printf("Enter the name of the item: ");
                scanf("%s", items[num_items].name);
                printf("Enter the quantity of the item: ");
                scanf("%d", &items[num_items].quantity);
                printf("Enter the price of the item: ");
                scanf("%d", &items[num_items].price);
                printf("Enter the supplier ID: ");
                scanf("%d", &items[num_items].supplier_id);
                num_items++;
                break;
            case 3:
                printf("Enter the name of the supplier: ");
                scanf("%s", suppliers[num_suppliers].name);
                printf("Enter the ID of the supplier: ");
                scanf("%d", &suppliers[num_suppliers].id);
                num_suppliers++;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}