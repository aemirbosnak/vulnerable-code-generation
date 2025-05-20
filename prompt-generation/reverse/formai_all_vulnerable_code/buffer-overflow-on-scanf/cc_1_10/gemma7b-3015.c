//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

void add_item() {
    Item item;

    printf("Enter item name: ");
    scanf("%s", item.name);

    printf("Enter item quantity: ");
    scanf("%d", &item.quantity);

    printf("Enter item price: ");
    scanf("%f", &item.price);

    items[MAX_ITEMS - 1] = item;
}

void remove_item() {
    char item_name[50];

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            items[i].quantity--;
            printf("Item quantity updated.\n");
            break;
        }
    }
}

void list_items() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    int choice;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("Enter 1 to add an item, 2 to remove an item, or 3 to list items: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                list_items();
                break;
            default:
                printf("Invalid input.\n");
        }

        printf("Would you like to continue? (Y/N): ");
        char cont;
        scanf("%c", &cont);

        if (cont != 'Y') {
            break;
        }
    }

    printf("Thank you for using the Medical Store Management System!\n");

    return 0;
}