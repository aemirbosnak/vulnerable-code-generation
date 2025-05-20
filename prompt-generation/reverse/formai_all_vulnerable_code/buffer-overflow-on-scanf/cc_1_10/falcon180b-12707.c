//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

void add_item(Item items[], int count, char name[], float price, int quantity) {
    if (count >= MAX_ITEMS) {
        printf("Error: maximum number of items reached.\n");
        return;
    }
    strcpy(items[count].name, name);
    items[count].price = price;
    items[count].quantity = quantity;
    count++;
}

void print_items(Item items[], int count) {
    printf("Item\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%.2f\t%d\n", items[i].name, items[i].price, items[i].quantity);
    }
}

void calculate_total(Item items[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += items[i].price * items[i].quantity;
    }
    printf("Total: $%.2f\n", total);
}

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    char name[50];
    float price;
    int quantity;

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item price: $");
    scanf("%f", &price);

    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    add_item(items, count, name, price, quantity);

    while(1) {
        printf("\n1. Add item\n2. Print items\n3. Calculate total\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item price: $");
                scanf("%f", &price);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);
                add_item(items, count, name, price, quantity);
                break;
            case 2:
                print_items(items, count);
                break;
            case 3:
                calculate_total(items, count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}