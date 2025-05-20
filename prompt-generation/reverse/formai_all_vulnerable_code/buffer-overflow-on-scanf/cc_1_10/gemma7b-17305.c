//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

struct Item {
    char name[20];
    int quantity;
    float price;
};

struct Item items[MAX_ITEMS];

void initializeItems() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].name[0] = '\0';
        items[i].quantity = 0;
        items[i].price = 0.0f;
    }
}

void displayItems() {
    printf("Items:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

void addItem() {
    char name[20];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    printf("Enter item price: ");
    scanf("%f", &price);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] == '\0') {
            strcpy(items[i].name, name);
            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Item limit exceeded.\n");
}

void updateItem() {
    char name[20];
    int quantity;
    float price;

    printf("Enter item name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter updated item quantity: ");
            scanf("%d", &quantity);

            printf("Enter updated item price: ");
            scanf("%f", &price);

            items[i].quantity = quantity;
            items[i].price = price;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

void removeItem() {
    char name[20];

    printf("Enter item name: ");
    scanf("%s", name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].name[0] = '\0';
            items[i].quantity = 0;
            items[i].price = 0.0f;
            return;
        }
    }

    printf("Error: Item not found.\n");
}

int main() {
    initializeItems();

    int choice;

    printf("Welcome to the C Medical Store Management System!\n");
    printf("Please select an option:\n");
    printf("1. Display Items\n");
    printf("2. Add Item\n");
    printf("3. Update Item\n");
    printf("4. Remove Item\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayItems();
            break;
        case 2:
            addItem();
            break;
        case 3:
            updateItem();
            break;
        case 4:
            removeItem();
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}