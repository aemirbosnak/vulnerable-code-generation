//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct item {
    char name[50];
    float price;
    int quantity;
};

void print_menu() {
    printf("Welcome to the Cafe! Here is our menu:\n");
    printf("  1. Coffee - $2.50\n");
    printf("  2. Tea - $1.50\n");
    printf("  3. Sandwich - $4.00\n");
    printf("  4. Salad - $6.00\n");
}

void add_item(struct item* items, int* total) {
    printf("Please enter the name of the item: ");
    fgets(items[(*total)].name, sizeof(items[(*total)].name), stdin);
    printf("Please enter the price of the item: ");
    scanf("%f", &items[(*total)].price);
    printf("Please enter the quantity of the item: ");
    scanf("%d", &items[(*total)].quantity);
    (*total)++;
}

int main() {
    struct item items[10];
    int total_items = 0;

    while (total_items < 10) {
        print_menu();
        printf("Please enter your order (1-4): ");
        int choice = 0;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &total_items);
                break;
            case 2:
                add_item(items, &total_items);
                break;
            case 3:
                add_item(items, &total_items);
                break;
            case 4:
                add_item(items, &total_items);
                break;
            default:
                printf("Invalid choice. Please enter a valid choice (1-4).\n");
        }
    }

    printf("Your order:\n");
    for (int i = 0; i < total_items; i++) {
        printf("- %s - $%.2f x %d\n", items[i].name, items[i].price, items[i].quantity);
    }

    float total_price = 0;
    for (int i = 0; i < total_items; i++) {
        total_price += items[i].price * items[i].quantity;
    }

    printf("Total price: $%.2f\n", total_price);

    return 0;
}