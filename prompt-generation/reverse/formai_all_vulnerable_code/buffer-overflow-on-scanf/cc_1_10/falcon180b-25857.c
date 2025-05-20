//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
};

struct customer {
    char name[50];
    int order_count;
    float total_spent;
};

struct order {
    int item_count;
    struct item items[MAX_ITEMS];
    struct customer customer;
};

void add_item(struct item* item, char* name, float price) {
    strcpy(item->name, name);
    item->price = price;
}

void add_order_item(struct order* order, struct item* item) {
    memcpy(&order->items[order->item_count], item, sizeof(struct item));
    order->item_count++;
}

void print_item(struct item* item) {
    printf("%s - $%.2f\n", item->name, item->price);
}

void print_order(struct order* order) {
    printf("Order for %s:\n", order->customer.name);
    for (int i = 0; i < order->item_count; i++) {
        print_item(&order->items[i]);
    }
    printf("Total spent: $%.2f\n", order->customer.total_spent);
}

int main() {
    struct item menu[10];
    struct customer customer;
    struct order order;

    add_item(&menu[0], "Coffee", 2.50);
    add_item(&menu[1], "Tea", 1.75);
    add_item(&menu[2], "Cake", 3.99);
    add_item(&menu[3], "Sandwich", 4.50);
    add_item(&menu[4], "Pizza", 8.99);

    customer.name[0] = '\0';
    customer.order_count = 0;
    customer.total_spent = 0;

    int choice;
    while (1) {
        printf("Welcome to the cafe, %s!\n", customer.name);
        printf("What would you like to order?\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
        }
        printf("0. View your order history\n");
        printf("9. Exit\n");
        scanf("%d", &choice);

        if (choice == 0) {
            print_order(&order);
        } else if (choice > 0 && choice <= 5) {
            add_order_item(&order, &menu[choice-1]);
            customer.order_count++;
            customer.total_spent += menu[choice-1].price;
        } else if (choice == 9) {
            printf("Thanks for visiting, %s!\n", customer.name);
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}