//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct menu_item {
    char name[50];
    float price;
};

struct order {
    int num_items;
    struct menu_item* items;
};

struct customer {
    char name[50];
    float balance;
};

void print_menu(struct menu_item* menu) {
    printf("Menu:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s - $%.2f\n", menu[i].name, menu[i].price);
    }
}

void place_order(struct customer* cust, struct menu_item* menu) {
    int num_items;
    printf("How many items would you like to order? ");
    scanf("%d", &num_items);

    struct order* order = malloc(sizeof(struct order));
    order->num_items = num_items;
    order->items = malloc(sizeof(struct menu_item) * num_items);

    printf("Select items:\n");
    for (int i = 0; i < num_items; i++) {
        int choice;
        printf("Enter item number: ");
        scanf("%d", &choice);
        order->items[i] = menu[choice];
    }

    cust->balance -= order->items[0].price * num_items;
    printf("Order placed successfully! Your balance is now $%.2f.\n", cust->balance);
}

int main() {
    struct customer cust;
    cust.name[0] = '\0';
    cust.balance = 0;

    struct menu_item menu[5] = {{"Coffee", 3.50}, {"Tea", 2.50}, {"Cake", 4.50}, {"Sandwich", 6.50}, {"Soup", 5.50}};

    while (1) {
        printf("Welcome, %s! Your balance is $%.2f.\n", cust.name, cust.balance);
        printf("What would you like to do?\n");
        printf("1. Place an order\n");
        printf("2. View menu\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            place_order(&cust, menu);
            break;
        case 2:
            print_menu(menu);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}