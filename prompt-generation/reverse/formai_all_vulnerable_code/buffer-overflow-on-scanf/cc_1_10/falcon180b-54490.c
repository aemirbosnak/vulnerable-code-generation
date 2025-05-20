//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int quantity;
    float price;
} Item;

void createItem(Item *item) {
    printf("Enter the name of the item: ");
    scanf("%s", item->name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &item->quantity);

    printf("Enter the price of the item: ");
    scanf("%f", &item->price);
}

void displayItem(Item item) {
    printf("\nItem Name: %s\n", item.name);
    printf("Item Quantity: %d\n", item.quantity);
    printf("Item Price: $%.2f\n", item.price);
}

void main() {
    Item item;

    int choice;
    do {
        printf("\n");
        printf("1. Create Item\n");
        printf("2. Display Item\n");
        printf("3. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createItem(&item);
            break;

        case 2:
            displayItem(item);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    } while (1);
}