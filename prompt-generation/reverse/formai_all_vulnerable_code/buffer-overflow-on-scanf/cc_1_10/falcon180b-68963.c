//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    int quantity;
    float price;
};

void addItem(struct item *items, int count) {
    printf("Enter item name: ");
    scanf("%s", items[count].name);
    printf("Enter item quantity: ");
    scanf("%d", &items[count].quantity);
    printf("Enter item price: ");
    scanf("%f", &items[count].price);
}

void displayItems(struct item *items, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void updateItemQuantity(struct item *items, int count) {
    printf("Enter item name: ");
    char name[50];
    scanf("%s", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &items[i].quantity);
            break;
        }
    }
}

void main() {
    struct item items[MAX_ITEMS];
    int count = 0;

    while (count < MAX_ITEMS) {
        printf("Enter 1 to add item\nEnter 2 to display items\nEnter 3 to update item quantity\nEnter 0 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, count++);
                break;
            case 2:
                displayItems(items, count);
                break;
            case 3:
                updateItemQuantity(items, count);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}