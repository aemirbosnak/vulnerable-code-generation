//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    int warehouseId;
    char name[50];
    int size;
    int capacity;
    int numItems;
    Item items[MAX_SIZE];
} Warehouse;

void createWarehouse(Warehouse* w) {
    printf("Enter warehouse name: ");
    scanf("%s", w->name);
    printf("Enter warehouse size: ");
    scanf("%d", &w->size);
    printf("Enter warehouse capacity: ");
    scanf("%d", &w->capacity);
    w->numItems = 0;
}

void addItem(Warehouse* w) {
    if (w->numItems >= w->capacity) {
        printf("Warehouse is full.\n");
        return;
    }
    printf("Enter item ID: ");
    scanf("%d", &w->items[w->numItems].id);
    printf("Enter item name: ");
    scanf("%s", w->items[w->numItems].name);
    printf("Enter item quantity: ");
    scanf("%d", &w->items[w->numItems].quantity);
    printf("Enter item price: ");
    scanf("%f", &w->items[w->numItems].price);
    w->numItems++;
}

void displayItems(Warehouse* w) {
    printf("Warehouse Items:\n");
    for (int i = 0; i < w->numItems; i++) {
        printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
               w->items[i].id, w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

void main() {
    Warehouse w;
    createWarehouse(&w);

    while (true) {
        printf("1. Add item\n2. Display items\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(&w);
            break;
        case 2:
            displayItems(&w);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}