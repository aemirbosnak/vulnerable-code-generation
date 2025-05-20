//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char name[50];
    float price;
    int quantity;
};

struct Order {
    int numItems;
    struct Item items[100];
};

void printMenu() {
    printf("Welcome to the Cafe Billing System!\n");
    printf("--------------------------------\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Print bill\n");
    printf("4. Exit\n");
}

void addItem(struct Order *order) {
    char name[50];
    float price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: ");
    scanf("%f", &price);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    struct Item item = {name, price, quantity};
    order->items[order->numItems++] = item;
}

void removeItem(struct Order *order) {
    char name[50];

    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < order->numItems; i++) {
        if (strcmp(order->items[i].name, name) == 0) {
            for (int j = i; j < order->numItems - 1; j++) {
                order->items[j] = order->items[j + 1];
            }
            order->numItems--;
            break;
        }
    }
}

void printBill(struct Order *order) {
    float total = 0;

    printf("Your order:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < order->numItems; i++) {
        printf("%s: %d x %0.2f = %0.2f\n", order->items[i].name, order->items[i].quantity, order->items[i].price, order->items[i].price * order->items[i].quantity);
        total += order->items[i].price * order->items[i].quantity;
    }

    printf("Total: %0.2f\n", total);
}

int main() {
    struct Order order = {0};

    while (1) {
        printMenu();
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(&order);
                break;
            case 2:
                removeItem(&order);
                break;
            case 3:
                printBill(&order);
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}