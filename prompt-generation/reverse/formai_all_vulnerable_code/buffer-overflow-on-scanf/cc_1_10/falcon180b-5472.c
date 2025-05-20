//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 1000
#define MAX_PRICE 9999.99

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Item;

void addItem(Item* items, int count, char* name, int quantity, float price) {
    for (int i = 0; i < count; i++) {
        if (items[i].quantity == 0) {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }
    printf("Item limit reached.\n");
}

void removeItem(Item* items, int count, char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity = 0;
            return;
        }
    }
    printf("Item not found.\n");
}

void displayItems(Item* items, int count) {
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        if (items[i].quantity > 0) {
            printf("%s\t%d\t$%.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    char choice;

    do {
        printf("\nProduct Inventory System\n");
        printf("1. Add item\n2. Remove item\n3. Display items\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter item name: ");
            scanf("%s", items[count].name);
            printf("Enter quantity: ");
            scanf("%d", &items[count].quantity);
            printf("Enter price: ");
            scanf("%f", &items[count].price);
            count++;
            break;
        case '2':
            printf("Enter item name: ");
            scanf("%s", items[count - 1].name);
            removeItem(items, count, items[count - 1].name);
            count--;
            break;
        case '3':
            displayItems(items, count);
            break;
        case '4':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }

    } while (true);

    return 0;
}