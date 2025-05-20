//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: calm
#include<stdio.h>
#include<stdlib.h>

struct Item {
    int id;
    char name[50];
    int quantity;
    float cost;
};

struct Warehouse {
    int id;
    char name[50];
};

int main() {
    struct Warehouse warehouse;

    printf("Enter warehouse ID: ");
    scanf("%d", &warehouse.id);

    printf("Enter warehouse name: ");
    scanf("%s", warehouse.name);

    int n;

    printf("Enter number of items to add: ");
    scanf("%d", &n);

    struct Item *items = (struct Item*)malloc(n * sizeof(struct Item));

    for(int i=0; i<n; i++) {
        printf("Enter item %d details\n", i+1);
        printf("ID: ");
        scanf("%d", &items[i].id);

        printf("Name: ");
        scanf("%s", items[i].name);

        printf("Quantity: ");
        scanf("%d", &items[i].quantity);

        printf("Cost: ");
        scanf("%f", &items[i].cost);
    }

    printf("\nWarehouse Details:\n");
    printf("ID: %d\n", warehouse.id);
    printf("Name: %s\n", warehouse.name);

    printf("\nItems in Warehouse:\n");
    printf("ID\tName\tQuantity\tCost\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].cost);
    }

    free(items);

    return 0;
}