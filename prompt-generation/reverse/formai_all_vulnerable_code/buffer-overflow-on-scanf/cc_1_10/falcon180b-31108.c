//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

void add_item(struct item *items, int num_items) {
    printf("Enter item name: ");
    scanf("%s", items[num_items].name);
    printf("Enter item price: ");
    scanf("%f", &items[num_items].price);
    printf("Enter item quantity: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void display_items(struct item *items, int num_items) {
    printf("\nItem Name\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total_cost(struct item *items, int num_items) {
    float total_cost = 0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].price * items[i].quantity;
    }
    printf("\nTotal Cost: $%.2f\n", total_cost);
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n1. Add item\n2. Display items\n3. Calculate total cost\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_items >= MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    add_item(items, num_items);
                }
                break;
            case 2:
                if (num_items == 0) {
                    printf("No items added yet.\n");
                } else {
                    display_items(items, num_items);
                }
                break;
            case 3:
                if (num_items == 0) {
                    printf("No items added yet.\n");
                } else {
                    calculate_total_cost(items, num_items);
                }
                break;
            case 4:
                printf("Thank you for using the Expense Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}