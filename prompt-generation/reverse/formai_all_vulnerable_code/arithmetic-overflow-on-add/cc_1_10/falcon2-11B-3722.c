//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct warehouse {
    char name[50];
    int items;
    int shelves;
};

struct item {
    char name[50];
    int quantity;
    int shelf;
};

int main() {
    struct warehouse warehouse;
    struct item item1, item2, item3;

    printf("Enter the name of the warehouse: ");
    scanf("%s", warehouse.name);
    printf("Enter the number of items in the warehouse: ");
    scanf("%d", &warehouse.items);
    printf("Enter the number of shelves in the warehouse: ");
    scanf("%d", &warehouse.shelves);

    printf("Enter the name of the first item: ");
    scanf("%s", item1.name);
    printf("Enter the quantity of the first item: ");
    scanf("%d", &item1.quantity);
    printf("Enter the shelf number of the first item: ");
    scanf("%d", &item1.shelf);

    printf("Enter the name of the second item: ");
    scanf("%s", item2.name);
    printf("Enter the quantity of the second item: ");
    scanf("%d", &item2.quantity);
    printf("Enter the shelf number of the second item: ");
    scanf("%d", &item2.shelf);

    printf("Enter the name of the third item: ");
    scanf("%s", item3.name);
    printf("Enter the quantity of the third item: ");
    scanf("%d", &item3.quantity);
    printf("Enter the shelf number of the third item: ");
    scanf("%d", &item3.shelf);

    // Display the warehouse information
    printf("Warehouse Information:\n");
    printf("Name: %s\n", warehouse.name);
    printf("Items: %d\n", warehouse.items);
    printf("Shelf: %d\n", warehouse.shelves);

    // Display the item information
    printf("Item Information:\n");
    printf("Item 1: %s - Quantity: %d - Shelf: %d\n", item1.name, item1.quantity, item1.shelf);
    printf("Item 2: %s - Quantity: %d - Shelf: %d\n", item2.name, item2.quantity, item2.shelf);
    printf("Item 3: %s - Quantity: %d - Shelf: %d\n", item3.name, item3.quantity, item3.shelf);

    // Calculate total quantity of items in the warehouse
    int total_quantity = 0;
    for (int i = 0; i < warehouse.items; i++) {
        total_quantity += item1.quantity + item2.quantity + item3.quantity;
    }
    printf("Total Quantity of Items: %d\n", total_quantity);

    return 0;
}