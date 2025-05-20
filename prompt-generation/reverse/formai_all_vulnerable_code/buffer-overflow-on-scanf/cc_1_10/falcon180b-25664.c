//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WAREHOUSE_SIZE 1000
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_QUANTITY 1000
#define MAX_ITEM_PRICE 1000

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Warehouse;

void addWarehouse(Warehouse* warehouse, char* name, int quantity, float price) {
    strcpy(warehouse->name, name);
    warehouse->quantity = quantity;
    warehouse->price = price;
}

void displayWarehouse(Warehouse* warehouse) {
    printf("Name: %s\n", warehouse->name);
    printf("Quantity: %d\n", warehouse->quantity);
    printf("Price: $%.2f\n", warehouse->price);
}

void addItem(Item* item, char* name, int quantity, float price) {
    strcpy(item->name, name);
    item->quantity = quantity;
    item->price = price;
}

void displayItem(Item* item) {
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: $%.2f\n", item->price);
}

int main() {
    Warehouse warehouse;
    Item item;
    int choice, quantity;
    float price;
    char name[MAX_ITEM_NAME_LENGTH];

    printf("Welcome to the Warehouse Management System!\n");

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new item\n");
        printf("2. View items\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the item: ");
                scanf("%s", name);
                printf("Enter the quantity: ");
                scanf("%d", &quantity);
                printf("Enter the price: ");
                scanf("%f", &price);
                addItem(&item, name, quantity, price);
                break;
            case 2:
                printf("Name\tQuantity\tPrice\n");
                displayItem(&item);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice!= 3);

    return 0;
}