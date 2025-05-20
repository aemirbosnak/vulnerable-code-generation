//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} item;

void add_item(item *items, int num_items) {
    printf("Enter the name of the item: ");
    scanf("%s", items[num_items].name);
    printf("Enter the price of the item: ");
    scanf("%f", &items[num_items].price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &items[num_items].quantity);
    num_items++;
}

void display_items(item items[], int num_items) {
    printf("\nItems:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - %.2f - %d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(item items[], int num_items) {
    float total = 0;
    for (int i = 0; i < num_items; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("\nTotal: %.2f\n", total);
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;

    printf("Welcome to the Personal Finance Planner!\n");

    while (num_items < MAX_ITEMS) {
        printf("\nEnter 1 to add an item or 0 to continue: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            add_item(items, num_items);
        } else if (choice!= 0) {
            printf("Invalid input. Please try again.\n");
        }
    }

    display_items(items, num_items);
    calculate_total(items, num_items);

    return 0;
}