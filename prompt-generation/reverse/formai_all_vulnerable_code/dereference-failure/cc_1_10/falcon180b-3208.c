//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    double price;
} Item;

void addItem(Item items[], int numItems) {
    printf("Enter item name: ");
    scanf("%s", &items[numItems].name);
    printf("Enter quantity: ");
    scanf("%d", &items[numItems].quantity);
    printf("Enter price: ");
    scanf("%lf", &items[numItems].price);
    numItems++;
}

void displayItems(Item items[], int numItems) {
    printf("Item Name\tQuantity\tPrice\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t%d\t%.2lf\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void updateItem(Item items[], int numItems) {
    int index;
    printf("Enter item index to update: ");
    scanf("%d", &index);
    printf("Enter new item name: ");
    scanf("%s", &items[index].name);
    printf("Enter new quantity: ");
    scanf("%d", &items[index].quantity);
    printf("Enter new price: ");
    scanf("%lf", &items[index].price);
}

void deleteItem(Item items[], int numItems) {
    int index;
    printf("Enter item index to delete: ");
    scanf("%d", &index);
    for (int i = index; i < numItems - 1; i++) {
        items[i] = items[i + 1];
    }
    numItems--;
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    while (numItems < MAX_ITEMS) {
        printf("Enter 1 to add item, 2 to display items, 3 to update item, 4 to delete item, 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addItem(items, numItems);
            break;
        case 2:
            displayItems(items, numItems);
            break;
        case 3:
            updateItem(items, numItems);
            break;
        case 4:
            deleteItem(items, numItems);
            break;
        case 0:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}