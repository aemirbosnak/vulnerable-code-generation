//Code Llama-13B DATASET v1.0 Category: Cafe Billing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    char name[50];
    float price;
};

struct customer {
    char name[50];
    char address[100];
    char phone[20];
};

struct bill {
    struct customer customer;
    struct item items[50];
    int total_items;
    float total_cost;
};

void print_menu(struct item *items, int num_items) {
    printf("Menu:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, items[i].name, items[i].price);
    }
}

int main() {
    struct item menu[] = {
        {"Coffee", 3.00},
        {"Tea", 2.50},
        {"Cappuccino", 4.00},
        {"Espresso", 3.50},
        {"Latte", 4.50},
        {"Mocha", 5.00},
        {"Macchiato", 4.00},
        {"Choc Mug", 3.50},
        {"Irish Cream", 4.00},
        {"Iced Caramel", 3.50},
        {"Frappuccino", 6.00},
    };
    int num_menu_items = sizeof(menu) / sizeof(menu[0]);

    struct customer customer = {
        .name = "John Doe",
        .address = "123 Main St",
        .phone = "555-555-5555",
    };

    struct bill bill = {
        .customer = customer,
        .items = {0},
        .total_items = 0,
        .total_cost = 0.00,
    };

    print_menu(menu, num_menu_items);

    int choice;
    do {
        printf("Enter your choice (1-%d): ", num_menu_items);
        scanf("%d", &choice);
        if (choice >= 1 && choice <= num_menu_items) {
            bill.items[bill.total_items] = menu[choice - 1];
            bill.total_cost += menu[choice - 1].price;
            bill.total_items++;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    printf("Customer: %s\n", bill.customer.name);
    printf("Address: %s\n", bill.customer.address);
    printf("Phone: %s\n", bill.customer.phone);
    printf("Items:\n");
    for (int i = 0; i < bill.total_items; i++) {
        printf("%d. %s - $%.2f\n", i + 1, bill.items[i].name, bill.items[i].price);
    }
    printf("Total cost: $%.2f\n", bill.total_cost);

    return 0;
}