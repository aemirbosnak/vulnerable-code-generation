//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100

struct item {
    char name[50];
    float price;
    int quantity;
};

void add_item(struct item items[], int count, char name[], float price, int quantity) {
    if (count >= MAX_ITEMS) {
        printf("Error: Maximum items reached.\n");
        return;
    }
    strcpy(items[count].name, name);
    items[count].price = price;
    items[count].quantity = quantity;
    count++;
}

void display_items(struct item items[], int count) {
    printf("\nItem List:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(struct item items[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal Expense: $%.2f\n", total);
}

int main() {
    struct item items[MAX_ITEMS];
    int count = 0;
    char name[50];
    float price;
    int quantity;

    printf("Welcome to Expense Tracker!\n\n");

    while (1) {
        printf("\nEnter item name: ");
        scanf("%s", name);

        printf("Enter item price: ");
        scanf("%f", &price);

        printf("Enter item quantity: ");
        scanf("%d", &quantity);

        add_item(items, count, name, price, quantity);
        count++;

        printf("\nDo you want to add another item? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    display_items(items, count);
    calculate_total(items, count);

    return 0;
}