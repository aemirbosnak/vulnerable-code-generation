//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct item {
    char name[MAX_ITEMS];
    int quantity;
    double price;
};

void add_item(struct item *items, int num_items, char *name, int quantity, double price) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }

    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            items[i].quantity += quantity;
            items[i].price += price;
            return;
        }
    }

    strcpy(items[num_items].name, name);
    items[num_items].quantity = quantity;
    items[num_items].price = price;
    num_items++;
}

void remove_item(struct item *items, int num_items, char *name) {
    int i;
    for (i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            num_items--;
            memmove(&items[i], &items[i+1], (num_items - i) * sizeof(struct item));
            return;
        }
    }
}

void print_items(struct item *items, int num_items) {
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t%d\t%.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

void calculate_total_cost(struct item *items, int num_items) {
    double total_cost = 0.0;
    for (int i = 0; i < num_items; i++) {
        total_cost += items[i].quantity * items[i].price;
    }
    printf("Total cost: $%.2f\n", total_cost);
}

int main() {
    struct item items[MAX_ITEMS];
    int num_items = 0;

    while (1) {
        printf("Enter command (add, remove, print, calculate, quit): ");
        char command[MAX_ITEMS];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char name[MAX_ITEMS];
            int quantity;
            double price;
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%lf", &price);
            add_item(items, num_items, name, quantity, price);
        } else if (strcmp(command, "remove") == 0) {
            char name[MAX_ITEMS];
            printf("Enter item name: ");
            scanf("%s", name);
            remove_item(items, num_items, name);
        } else if (strcmp(command, "print") == 0) {
            print_items(items, num_items);
        } else if (strcmp(command, "calculate") == 0) {
            calculate_total_cost(items, num_items);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}