//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int itemID;
    char itemName[50];
    int quantity;
    double costPerUnit;
} Item;

typedef struct {
    int locationID;
    char locationName[50];
} Location;

typedef struct {
    int orderID;
    char customerName[50];
    int deliveryAddress;
    double totalCost;
    int items[50];
} Order;

int main() {
    Item items[100];
    Location locations[10];
    Order orders[100];

    // Initialize items
    int i;
    for (i = 0; i < 100; i++) {
        scanf("%d %s %d %lf", &items[i].itemID, items[i].itemName, &items[i].quantity, &items[i].costPerUnit);
    }

    // Initialize locations
    int j;
    for (j = 0; j < 10; j++) {
        scanf("%d %s", &locations[j].locationID, locations[j].locationName);
    }

    // Initialize orders
    int k;
    for (k = 0; k < 100; k++) {
        scanf("%d %s %d %lf %d", &orders[k].orderID, orders[k].customerName, &orders[k].deliveryAddress, &orders[k].totalCost, &orders[k].items);
    }

    // Main program logic here...

    return 0;
}