//Falcon2-11B DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    char name[20];
    double price;
    int quantity;
} Item;

Item items[MAX_ITEMS];
int item_count = 0;

void add_item(char* name, double price, int quantity) {
    if (item_count >= MAX_ITEMS) {
        fprintf(stderr, "Error: Maximum number of items reached.\n");
        return;
    }
    strcpy(items[item_count].name, name);
    items[item_count].price = price;
    items[item_count].quantity = quantity;
    item_count++;
}

void remove_item(int index) {
    if (index >= item_count || index < 0) {
        fprintf(stderr, "Error: Invalid item index.\n");
        return;
    }
    for (int i = index; i < item_count - 1; i++) {
        items[i] = items[i + 1];
    }
    item_count--;
}

void print_items() {
    printf("Items:\n");
    for (int i = 0; i < item_count; i++) {
        printf("- %s - $%.2f (%d)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

double total_price() {
    double total = 0.0;
    for (int i = 0; i < item_count; i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

int main() {
    char name[20];
    double price;
    int quantity;

    while (1) {
        printf("Add item: ");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%s %lf %d", &name, &price, &quantity);
        add_item(name, price, quantity);
        printf("Item added.\n");
        printf("Remove item: ");
        fgets(name, sizeof(name), stdin);
        sscanf(name, "%s %d", &name, &index);
        remove_item(atoi(name));
        printf("Item removed.\n");
        printf("Items:\n");
        print_items();
        printf("Total price: $%.2f\n", total_price());
        printf("Continue? (y/n): ");
        char c;
        scanf(" %c", &c);
        if (c!= 'y' && c!= 'Y') {
            break;
        }
    }
    return 0;
}